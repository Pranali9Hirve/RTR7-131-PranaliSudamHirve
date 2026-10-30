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

// global variables
const int iNumberOfArrayElements = 5;

// Host arrays (CPU)
float* hostInput1 = NULL;
float* hostInput2 = NULL;

float* hostOutput = NULL;

// Device arrays
float* deviceInput1 = NULL;
float* deviceInput2 = NULL;
float* deviceOutput = NULL;

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

    // filling values into host arrays
    hostInput1[0] = 101.0;
    hostInput1[1] = 102.0; 
    hostInput1[2] = 103.0; 
    hostInput1[3] = 104.0; 
    hostInput1[4] = 105.0;
    
    hostInput2[0] = 201.0;
    hostInput2[1] = 202.0; 
    hostInput2[2] = 203.0; 
    hostInput2[3] = 204.0; 
    hostInput2[4] = 205.0;

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

    dim3 dimGrid = dim3(iNumberOfArrayElements, 1, 1); //constructor(5, 1, 1) -> x axis vr 5 block tayar kr, y vr kahi nako mhanun default 1,  z vr kahi nako mhanun default 1
    dim3 dimBlock = dim3(1, 1, 1);

    // dim3 dimGrid = dim3(1, 1, 1);
    // dim3 dimBlock = dim3(iNumberOfArrayElements, 1, 1); // 1 block ani 5 lok

    // CUDA kernel for vector addition
    vecAddGPU <<<dimGrid, dimBlock>>> (deviceInput1, deviceInput2, deviceOutput, iNumberOfArrayElements);

    // copy data from device array into host array
    result = cudaMemcpy(hostOutput, deviceOutput, size, cudaMemcpyDeviceToHost);

    if (result != cudaSuccess)
    {
        printf("Device to Host data copy is failed for hostOutput array.\n");
        cleanup();
        exit(EXIT_FAILURE);
    }

    // Vector addition on host
    for (int psh_i = 0; psh_i < iNumberOfArrayElements; psh_i++)
    {
        printf("%f + %f = %f\n", hostInput1[psh_i], hostInput2[psh_i], hostOutput[psh_i]);
    }

    // cleanup
    cleanup();

    return(0);
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
