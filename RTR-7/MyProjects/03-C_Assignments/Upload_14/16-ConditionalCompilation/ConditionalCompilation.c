#include<stdio.h>

// Change value and see the output. Also comment this line number 34 and see the output.
#define PSH_MY_PI_VERSION 3

#ifdef PSH_MY_PI_VERSION

#if PSH_MY_PI_VERSION <= 0
    #define PSH_MY_PI 3.14
#elif PSH_MY_PI_VERSION == 1
    #define PSH_MY_PI 3.1415
#elif PSH_MY_PI_VERSION == 2
    #define PSH_MY_PI 3.141592
#elif PSH_MY_PI_VERSION == 3
    #define PSH_MY_PI 3.14159265
#elif PSH_MY_PI_VERSION == 4
    #define PSH_MY_PI 3.1415926535
#elif PSH_MY_PI_VERSION == 5
    #define PSH_MY_PI 3.141592653589
#else
    #define PSH_MY_PI 3.141592653589793
#endif // for #if
#endif // for #ifdef

#ifndef PSH_MY_PI_VERSION
    #define PSH_MY_PI 0.0
#endif

int main(void)
{
    // Code
    printf("\n\n");
    printf("Hello World !!\n\n");

    printf("PI version selected = %d\n", PSH_MY_PI_VERSION);
    printf("PI value = %.15lf\n", PSH_MY_PI);
    return(0);
}
