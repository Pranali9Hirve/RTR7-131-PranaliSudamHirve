// !6 steps Algorith
// General Header 
// CUDA related Header file declarations
// Global variavle decl
// CUDA kernel definition
// Entry point finc main
// Local user defined fun decl
// memory allocation for host/CPU arrays
// initialization of host/cpu arrays
// Device memory allocation for device arrays
// Coping data from host input arrays to device input arrays
// grid and block configuration
// call to CUDA kernel
// getting output data from device
// Displaying the result
// call to clean up  
// definition od cliean up function

// standard header
#include<stdio.h>

// cuda headers - for cuda functionality
#include<cuda.h>
#include "helper_timer.h"

// global variables
// macros
#define BLOCK_WIDTH 32

// Host arrays (CPU)
int* psh_hostInput1 = NULL;
int* psh_hostInput2 = NULL;
int* psh_hostOutput = NULL;
int* psh_gold = NULL;     // Reference output (CPU result)

// Device arrays (GPU)
int* psh_deviceInput1 = NULL;
int* psh_deviceInput2 = NULL;
int* psh_deviceOutput = NULL;

// Execution time
float psh_timeOnCPU = 0.0f;
float psh_timeOnGPU = 0.0f;

// CUDA kernel
__global__ void matMulGPU(int *A,int *B,int *C,int numARows,int numAColumns,int numBColumns,int numCColumns)
{
    // variable declarations
    int row=blockIdx.y * blockDim.y + threadIdx.y;
    int column=blockIdx.x * blockDim.x + threadIdx.x;
    // code
    if((row < numARows) && (column < numBColumns))
    {
        int value=0.0;
        for(int k=0; k < numAColumns; k++)
        {
            int a=A[row * numAColumns + k];
            int b=B[k * numBColumns + column];
            value += a*b;
        }
        C[row * numCColumns + column]=value;
    }
}

int main(int argc,char *argv[])
{
    // function declarations
    void InitA(int *data,int,int);
    void InitB(int *data,int,int);
    void matMulCPU(int*, int*, int*, int, int, int, int);
    void cleanup(void);

    // variable declarations
    int numARows=BLOCK_WIDTH;
    int numAColumns=BLOCK_WIDTH;
    int numBRows=BLOCK_WIDTH;
    int numBColumns=BLOCK_WIDTH;

    int numCRows=numARows;
    int numCColumns=numBColumns;

    int numGoldRows=numARows;
    int numGoldColumns=numBColumns;

    int sizeA = numARows * numAColumns * sizeof(int);
    int sizeB = numBRows * numBColumns * sizeof(int);
    int sizeC = numCRows * numCColumns * sizeof(int);
    int sizeGold = numGoldRows * numGoldColumns * sizeof(int);

    cudaError_t result = cudaSuccess;

    // code
    // host memory allocation
    psh_hostInput1=(int *)malloc(sizeA);
    if(psh_hostInput1==NULL)
    {
        printf("Host Memory allocation is failed for psh_hostInput1 matrix.\n");
        cleanup();
        exit(EXIT_FAILURE);
    }

    psh_hostInput2=(int *)malloc(sizeB);
    if(psh_hostInput2==NULL)
    {
        printf("Host Memory allocation is failed for psh_hostInput2 matrix.\n");
        cleanup();
        exit(EXIT_FAILURE);
    }

    psh_hostOutput=(int *)malloc(sizeC);
    if(psh_hostOutput== NULL)
    {
        printf("Host Memory allocation is failed for psh_hostOutput matrix.\n");
        cleanup();
        exit(EXIT_FAILURE);
    }

    psh_gold=(int *)malloc(sizeGold);
    if(psh_gold== NULL)
    {
        printf("Host Memory allocation is failed for psh_gold matrix.\n");
        cleanup();
        exit(EXIT_FAILURE);
    }

    // printing matrix dimensions and sizes
    printf("The Dimensions Of Matrix 'psh_hostInput1' Are : %d x %d\n",numARows,numAColumns);
    printf("The Dimensions Of Matrix 'psh_hostInput2' Are : %d x %d\n",numBRows,numBColumns);
    printf("The Dimensions Of Matrix 'psh_hostOutput' Are : %d x %d\n",numCRows,numCColumns);
    printf("The Dimensions Of Matrix 'psh_gold' Are : %d x %d\n",numGoldRows,numGoldColumns);

    printf("Size Of Matrix psh_hostInput1 = %d\n",sizeA);
    printf("Size Of Matrix psh_hostInput2 = %d\n",sizeB);
    printf("Size Of Matrix psh_hostOutput = %d\n",sizeC);

    printf("Size Of Matrix psh_gold = %d\n",sizeGold);

    // fill source matrices
    InitA(psh_hostInput1,numARows,numAColumns);
    InitB(psh_hostInput2,numBRows,numBColumns);

    // device memory allocation
    result=cudaMalloc((void **)&psh_deviceInput1,sizeA);
    if(result!=cudaSuccess)
    {
        printf("Device Memory allocation is failed for psh_deviceInput1 matrix.\n");
        cleanup();
        exit(EXIT_FAILURE);
    }

    result=cudaMalloc((void **)&psh_deviceInput2,sizeB);
    if(result!=cudaSuccess)
    {
        printf("Device Memory allocation is failed for psh_deviceInput2 matrix.\n");
        cleanup();
        exit(EXIT_FAILURE);
    }

    result=cudaMalloc((void **)&psh_deviceOutput,sizeC);
    if(result!=cudaSuccess)
    {
        printf("Device Memory allocation is failed for psh_deviceOutput matrix.\n");
        cleanup();
        exit(EXIT_FAILURE);
    }

    // copy data from host matrices into device matrices
    result=cudaMemcpy(psh_deviceInput1,psh_hostInput1,sizeA,cudaMemcpyHostToDevice);
    if(result!=cudaSuccess)
    {
        printf("Host to Device Data Copy is failed for psh_deviceInput1 matrix.\n");
        cleanup();
        exit(EXIT_FAILURE);
    }

    result=cudaMemcpy(psh_deviceInput2,psh_hostInput2,sizeB,cudaMemcpyHostToDevice);
    if(result!=cudaSuccess)
    {
        printf("Host to Device Data Copy is failed for psh_deviceInput2 matrix.\n");
        cleanup();
        exit(EXIT_FAILURE);
    }

    // CUDA kernel configuration
    dim3 dimGrid=dim3(ceil((int)numBColumns/(int)BLOCK_WIDTH),ceil((int)numARows/(int)BLOCK_WIDTH),1);
    dim3 dimBlock=dim3(BLOCK_WIDTH,BLOCK_WIDTH,1);

    // CUDA kernel for matrix multiplication
    StopWatchInterface* timer = NULL;
    sdkCreateTimer(&timer);
    sdkStartTimer(&timer);

    matMulGPU <<<dimGrid, dimBlock >>>(psh_deviceInput1, psh_deviceInput2, psh_deviceOutput, numARows, numAColumns, numBColumns, numCColumns);

    sdkStopTimer(&timer);
    psh_timeOnGPU = sdkGetTimerValue(&timer);
    sdkDeleteTimer(&timer);
    timer = NULL;

    // copy data from device matrix into host matrix
    result=cudaMemcpy(psh_hostOutput,psh_deviceOutput,sizeC,cudaMemcpyDeviceToHost);
    if(result!=cudaSuccess)
    {
        printf("Device to Host Data Copy is failed for psh_hostOutput matrix.\n");
        cleanup();
        exit(EXIT_FAILURE);
    }

    // matrix multiplication on host
    matMulCPU(psh_hostInput1, psh_hostInput2, psh_gold, numARows, numAColumns, numBColumns, numCColumns);

    // comparison
    int breakValue = -1;
    bool bAccuracy = true;
    for (int i = 0; i < numCRows * numCColumns; i++)
    {
        int val1 = psh_gold[i];
        int val2 = psh_hostOutput[i];
        if (val1 != val2)
        {
            bAccuracy = false;
            breakValue = i;
            break;
        }
    }

    char str[128];
    if (bAccuracy == false)
        sprintf(str, "Comparison of CPU and GPU Matrix Multiplication is not accurate at array index %d", breakValue);
    else
        sprintf(str, "Comparison of CPU and GPU Matrix Multiplication is accurate");

    printf("Time taken for Matrix Multiplication on CPU = %.6f\n", psh_timeOnCPU);
    printf("Time taken for Matrix Multiplication on GPU = %.6f\n", psh_timeOnGPU);
    printf("%s\n", str);

    // cleanup
    cleanup();

    return(0);
}

void InitA(int *data,int row,int col)
{
    int num=1;
    // code
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            *(data + i * col + j)=num;
            num++;
        }
    }
}

void InitB(int *data,int row,int col)
{
    int num=BLOCK_WIDTH;
    // code
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            *(data + i * col + j)=num;
            num--;
        }
    }
}

void matMulCPU(int* A, int* B, int* C, int numARows, int numAColumns, int numBColumns, int numCColumns)
{
    // code
    StopWatchInterface* timer = NULL;
    sdkCreateTimer(&timer);
    sdkStartTimer(&timer);

    for (int i = 0; i < numARows; ++i)
    {
        for (int j = 0; j < numBColumns; ++j)
        {
            int value = 0.0f;
            for (int k = 0; k < numAColumns; ++k)
            {
                int a = A[i * numAColumns + k];
                int b = B[k * numBColumns + j];
                value += a * b;
            }
            C[i * numCColumns + j] = value;
        }
    }

    sdkStopTimer(&timer);
    psh_timeOnCPU = sdkGetTimerValue(&timer);
    sdkDeleteTimer(&timer);
    timer = NULL;
}

void cleanup(void)
{
    // code
    if (psh_deviceOutput)
    {
        cudaFree(psh_deviceOutput);
        psh_deviceOutput = NULL;
    }

    if (psh_deviceInput2)
    {
        cudaFree(psh_deviceInput2);
        psh_deviceInput2 = NULL;
    }

    if (psh_deviceInput1)
    {
        cudaFree(psh_deviceInput1);
        psh_deviceInput1 = NULL;
    }

    if (psh_gold)
    {
        free(psh_gold);
        psh_gold = NULL;
    }

    if (psh_hostOutput)
    {
        free(psh_hostOutput);
        psh_hostOutput = NULL;
    }

    if (psh_hostInput2)
    {
        free(psh_hostInput2);
        psh_hostInput2 = NULL;
    }

    if (psh_hostInput1)
    {
        free(psh_hostInput1);
        psh_hostInput1 = NULL;
    }
}
