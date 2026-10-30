#include<stdio.h>

int main(void)
{
    // Function Declarations
    void PrintCUDADeviceProperties(void);

    // Code
    PrintCUDADeviceProperties();
}

void PrintCUDADeviceProperties(void)
{
    // Code
    printf("CUDA Information: \n");
    printf("============================================================\n");

    cudaError_t ret_cuda_rt;
    int psh_dev_count;
    ret_cuda_rt = cudaGetDeviceCount(&psh_dev_count);
    if (ret_cuda_rt != cudaSuccess)
    {
        printf("CUDA Runtime API Error - cudaGetDeviceCount() Failed Due To %s. \n", cudaGetErrorString(ret_cuda_rt));
    }
    else if (psh_dev_count == 0)
    {
        printf("There is no CUDA supported Device on this System.\n");
        return;
    }
    else
    {
        printf("Total Number of CUDA supporting GPU Device/Devices on this System = %d\n", psh_dev_count);
        for (int psh_i = 0; psh_i < psh_dev_count; psh_i++)
        {
            cudaDeviceProp psh_dev_prop;
            int driverVersion = 0, runtimeVersion = 0;
            int clockRate = 0;

            ret_cuda_rt = cudaGetDeviceProperties(&psh_dev_prop, psh_i);

            if (ret_cuda_rt != cudaSuccess)
            {
                printf("%s in %s at line %d\n", cudaGetErrorString(ret_cuda_rt), __FILE__, __LINE__);
                return;
            }
            printf("\n");
            cudaDriverGetVersion(&driverVersion);
            cudaRuntimeGetVersion(&runtimeVersion);
            cudaDeviceGetAttribute(&clockRate, cudaDevAttrClockRate, 0);
            printf("******** CUDA DRIVER AND RUNTIME INFORMATION ********\n");
            printf("=====================================================\n");

            printf("CUDA Driver Version: %d.%d\n", driverVersion / 1000, (driverVersion % 100) / 10);

            printf("CUDA Runtime Version: %d.%d\n", runtimeVersion / 1000, (runtimeVersion % 100) / 10);

            printf("\n");

            printf("=====================================================\n");
            printf("********** GPU DEVICE GENERAL INFORMATION ***********\n");
            printf("=====================================================\n");

            printf("GPU Device Number: %d\n", psh_i);

            printf("GPU Device Name: %s\n", psh_dev_prop.name);

            printf("GPU Device Compute Capability: %d.%d\n", psh_dev_prop.major, psh_dev_prop.minor);

            printf("GPU Device Clock Rate: %d\n", clockRate);

            printf("GPU Device Type: ");

            if (psh_dev_prop.integrated)
                printf("Integrated ( On-Board )\n");
            else
                printf("Discrete ( Card )\n");

            printf("\n");

            printf("********** GPU DEVICE MEMORY INFORMATION ************\n");
            printf("=====================================================\n");

            printf("GPU Device Total Memory : %.0f GB = %.0f MB = %llu Bytes\n",
                ((float)psh_dev_prop.totalGlobalMem / 1048576.0f) / 1024.0f,
                (float)psh_dev_prop.totalGlobalMem / 1048576.0f,
                (unsigned long long)psh_dev_prop.totalGlobalMem);

            printf("GPU Device Constant Memory: %lu Bytes\n",
                (unsigned long)psh_dev_prop.totalConstMem);

            printf("GPU Device Shared Memory Per SMProcessor: %lu\n",
                (unsigned long)psh_dev_prop.sharedMemPerBlock);

            printf("\n");

            printf("****** GPU DEVICE MULTIPROCESSOR INFORMATION ******\n");
            printf("=====================================================\n");

            printf("GPU Device Number Of SMProcessors: %d\n",
             psh_dev_prop.multiProcessorCount);

            printf("GPU Device Number Of Registers Per SMProcessor : %d\n",
             psh_dev_prop.regsPerBlock);

            printf("\n");

            printf("************ GPU DEVICE THREAD INFORMATION ************\n");
            printf("========================================================\n");

            printf("GPU Device Maximum Number Of Threads Per SMProcessor : %d\n", psh_dev_prop.maxThreadsPerMultiProcessor);

            printf("GPU Device Maximum Number Of Threads Per Block: %d\n", psh_dev_prop.maxThreadsPerBlock);

            printf("GPU Device Threads In Warp: %d\n", psh_dev_prop.warpSize);

            printf("GPU Device Maximum Thread Dimensions: ( %d, %d, %d )\n", psh_dev_prop.maxThreadsDim[0],
                psh_dev_prop.maxThreadsDim[1], psh_dev_prop.maxThreadsDim[2]);

            printf("GPU Device Maximum Grid Dimensions: ( %d, %d, %d )\n", psh_dev_prop.maxGridSize[0],
                psh_dev_prop.maxGridSize[1], psh_dev_prop.maxGridSize[2]);

            printf("\n");

            printf("************ GPU DEVICE DRIVER INFORMATION ************\n");
            printf("=======================================================\n");

            printf("GPU Device has ECC support: %s\n", psh_dev_prop.ECCEnabled ? "Enabled" : "Disabled");

            #if defined(WIN32) || defined(_WIN32) || defined(WIN64) || defined(_WIN64)

                printf("GPU Device CUDA Driver Mode ( TCC Or WDDM ): %s\n", psh_dev_prop.tccDriver
                        ? "TCC ( Tesla Compute Cluster Driver )"
                        : "WDDM ( Windows Display Driver Model )");

            #endif

            printf("***************************************************************"
                "************\n");
        }
    }  
}
