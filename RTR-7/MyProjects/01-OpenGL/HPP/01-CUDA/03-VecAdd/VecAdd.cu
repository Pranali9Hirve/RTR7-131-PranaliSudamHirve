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
// const int iNumberOfArrayElements = 5;
const int iNumberOfArrayElements = 11444777;

// Host arrays (CPU)
float* hostInput1 = NULL;
float* hostInput2 = NULL;
float* hostOutput = NULL;
float* gold = NULL;  // sure accurate ast kiva benchmarking dyaych ast tr tyala gold mhantat

// Device arrays
float* deviceInput1 = NULL;
float* deviceInput2 = NULL;
float* deviceOutput = NULL;

float timeOnCPU = 0.0f;
float timeOnGPU = 0.0f;

// CUDA kernel
__global__ void vecAddGPU(float* in1, float* in2, float* out, int len)
{
    // Code
    int psh_i = blockIdx.x * blockDim.x + threadIdx.x; // linear representation -> row*width+column
    
    if (psh_i < len)
    {
        out[psh_i] = in1[psh_i] + in2[psh_i];
    }
}

// Entry point function
int main(void)
{
    // function declarations
    void fillFloatArrayWithRandomNumbers(float*, int);
    void vecAddCPU(const float*, const float*, float*, int);
    void cleanup(void);

    // Variable declarations
    int size = iNumberOfArrayElements * sizeof(float);
    cudaError_t result = cudaSuccess;

    // Code
    // host memory allocation
    hostInput1 = (float*)malloc(size);
    if (hostInput1 == NULL)
    {
        printf("Host Memory Allocation is failed for hostInput1 array. \n");
        cleanup();
        exit(EXIT_FAILURE);
    }

    hostInput2 = (float*)malloc(size);
    if (hostInput2 == NULL)
    {
        printf("Host Memory Allocation is failed for hostInput2 array. \n");
        cleanup();
        exit(EXIT_FAILURE);
    }

    hostOutput = (float*)malloc(size);
    if (hostOutput == NULL)
    {
        printf("Host Memory Allocation is failed for hostOutput array. \n");
        cleanup();
        exit(EXIT_FAILURE);
    }

    gold = (float*)malloc(size);
    if (gold == NULL)
    {
        printf("Host Memory Allocation is failed for gold array. \n");
        cleanup();
        exit(EXIT_FAILURE);
    }

    // filling values into host arrays
    fillFloatArrayWithRandomNumbers(hostInput1, iNumberOfArrayElements);
    fillFloatArrayWithRandomNumbers(hostInput2, iNumberOfArrayElements);

    // Device Memory allocation
    result = cudaMalloc((void**)&deviceInput1, size);
    if (result != cudaSuccess)
    {
        printf("Device memory allocation is failed for deviceInput1 array.\n");
        cleanup();
        exit(EXIT_FAILURE);
    }

    result = cudaMalloc((void**)&deviceInput2, size);
    if (result != cudaSuccess)
    {
        printf("Device memory allocation is failed for deviceInput2 array.\n");
        cleanup();
        exit(EXIT_FAILURE);
    }

    result = cudaMalloc((void**)&deviceOutput, size);
    if (result != cudaSuccess)
    {
        printf("Device memory allocation is failed for deviceOutput array.\n");
        cleanup();
        exit(EXIT_FAILURE);
    }

    // Copy data from host arrays into device arrays
    result = cudaMemcpy(deviceInput1, hostInput1, size, cudaMemcpyHostToDevice);

    if (result != cudaSuccess)
    {
        printf("Host to Devicedata copy is failed for deviceInput1 array.\n");
        cleanup();
        exit(EXIT_FAILURE);
    }

    result = cudaMemcpy(deviceInput2, hostInput2, size, cudaMemcpyHostToDevice);

    if (result != cudaSuccess)
    {
        printf("Host to Devicedata copy is failed for deviceInput1 array.\n");
        cleanup();
        exit(EXIT_FAILURE);
    }

    // CUDA kernel configuration
    dim3 dimGrid = dim3((int)ceil((float)iNumberOfArrayElements/256.0f), 1, 1); //constructor(5, 1, 1) -> x axis vr 5 block tayar kr, y vr kahi nako mhanun default 1,  z vr kahi nako mhanun default 1
    dim3 dimBlock = dim3(256, 1, 1);

    // dim3 dimGrid = dim3(1, 1, 1);
    // dim3 dimBlock = dim3(iNumberOfArrayElements, 1, 1); // 1 block ani 5 lok

    // CUDA kernel for vector addition
    StopWatchInterface* timer = NULL;
    sdkCreateTimer(&timer);
    sdkStartTimer(&timer);

    vecAddGPU <<<dimGrid, dimBlock>>> (deviceInput1, deviceInput2, deviceOutput, iNumberOfArrayElements);

    sdkStopTimer(&timer);
    timeOnGPU = sdkGetTimerValue(&timer);
    sdkDeleteTimer(&timer);
    timer = NULL;

    // copy data from device array into host array
    result = cudaMemcpy(hostOutput, deviceOutput, size, cudaMemcpyDeviceToHost);

    if (result != cudaSuccess)
    {
        printf("Device to Host data copy is failed for hostOutput array.\n");
        cleanup();
        exit(EXIT_FAILURE);
    }

    // Vector addition on host
    vecAddCPU(hostInput1, hostInput2, gold, iNumberOfArrayElements);

    // Comparison
    const float epsilon = 0.000001f;
    int breakValue = -1;
    bool bAccuracy = true;

    for (int i=0; i< iNumberOfArrayElements; i++)
    {
        float val1 = gold[i];
        float val2 = hostOutput[i];
        if (fabs(val1 - val2) > epsilon)
        {
            bAccuracy = false;
            breakValue = i;
            break;
        }
    }

    char str[128];
    if (bAccuracy == false)
    {
        sprintf(str, "Comparison of CPU and GPU Vector Addition is not within accuracy of 0.000001 at array index %d", breakValue);
    }
    else
    {
        sprintf(str, "Comparison of CPU and GPU Vector Addition is within accuracy of 0.000001 at array index %d", breakValue);
    }

    // Output
    printf("Array1 begins from 0th index %.6f to %dth index %.6f\n", hostInput1[0], iNumberOfArrayElements -1, hostInput1[iNumberOfArrayElements - 1]);
    printf("Array2 begins from 0th index %.6f to %dth index %.6f\n", hostInput2[0], iNumberOfArrayElements -1, hostInput2[iNumberOfArrayElements - 1]);
    printf("CUDA kernel grid dimension = %d, %d, %d and Block dimension = %d, %d, %d\n", dimGrid.x, dimGrid.y, dimGrid.z, dimBlock.x, dimBlock.y, dimBlock.z);
    printf("Output Array begins from 0th index %.6f to %dth index %.6f\n", hostOutput[0], iNumberOfArrayElements -1, hostOutput[iNumberOfArrayElements - 1]);
    printf("Time taken for Vector Addition on CPU = %.6f\n", timeOnCPU);
    printf("Time taken for Vector Addition on GPU = %.6f\n", timeOnGPU);
    printf("%s\n", str);

    // cleanup
    cleanup();

    return(0);
}

void fillFloatArrayWithRandomNumbers(float* arr, int len)
{
    // Code
    const float fscale = 1.0f / (float)RAND_MAX;
    for (int i=0; i<len; i++)
    {
        arr[i] = fscale * rand();
    }
}

void vecAddCPU(const float* arr1, const float* arr2, float* out, int len)
{
    // code
    StopWatchInterface* timer = NULL;
    sdkCreateTimer(&timer);
    sdkStartTimer(&timer);
    for (int i=0; i<len; i++)
    {
        out[i] = arr1[i] + arr2[i];
    }
    sdkStopTimer(&timer);
    timeOnCPU = sdkGetTimerValue(&timer);
    sdkDeleteTimer(&timer);
    timer = NULL;
}

void cleanup(void)
{
    // Code
    if (deviceOutput)
    {
        cudaFree(deviceOutput);
        deviceOutput = NULL;
    }

    if (deviceInput2)
    {
        cudaFree(deviceInput2);
        deviceInput2 = NULL;
    }

    if (deviceInput1)
    {
        cudaFree(deviceInput1);
        deviceInput1 = NULL;
    }

    if (gold)
    {
        cudaFree(gold);
        gold = NULL;
    }

    if (hostOutput)
    {
        cudaFree(hostOutput);
        hostOutput = NULL;
    }


    if (hostInput2)
    {
        cudaFree(hostInput2);
        hostInput2 = NULL;
    }

    if (hostInput1)
    {
        cudaFree(hostInput1);
        hostInput1 = NULL;
    }
}
