#include <stdio.h>

//Global Typedef
typedef int PSH_MY_INT; // "type" int has re"def"ined as PSH_MY_INT...Now, "PSH_MY_INT" can be treated just like "int"

int main(void)
{
    //Function Prototype
    PSH_MY_INT Add(PSH_MY_INT, PSH_MY_INT);

    //Typedefs
    typedef int PSH_MY_INT; //"type" int has re"def"ined as PSH_MY_INT...Now, 
    //"PSH_MY_INT" can be treated just like "int"
    typedef float PSH_PVG_FLOAT; //"type" Float has re"def"ined as PSH_PVG_FLOAT...Now, 
    //"MY_FLOAT" can be treated just like "Float"
    typedef char PSH_CHARACTER; //"type" Char has re"def"ined as PSH_CHARACTER...Now, 
    //"PSH_CHARACTER" can be treated just like "char"
     typedef double PSH_MY_DOUBLE; //"type" double has re"def"ined as MY_DOUBLE...Now, 
    //"MY_DOUBLE" can be treated just like "double"

    // ****** JUST LIKE IN Win32SDK !!! ******
    typedef unsigned int PSH_UINT;
    typedef PSH_UINT PSH_HANDLE;
    typedef PSH_HANDLE PSH_HWND;
    typedef PSH_HANDLE PSH_HINSTANCE;

    //variable declarations
    PSH_MY_INT psh_a = 10, psh_i;
    PSH_MY_INT psh_iArray[] = { 9,18,27,36,54,63,72,81,90 };

    PSH_PVG_FLOAT psh_f_pvg = 30.9f;
    const PSH_PVG_FLOAT psh_f_pvg_pi = 3.14f;

    PSH_CHARACTER psh_ch = '*';
    PSH_CHARACTER psh_chArray_01[] = "Hello";
    PSH_CHARACTER psh_chArray_02[] = {"RTR"};

    PSH_MY_DOUBLE psh_d = 8.041997;

    //***** JUST RANDOM NUMBERS - THEY HAVE NOTHING TO DO WITH ANY WINDOWS 
    //HANDLE OR INSTANCE HANDLE !!! This is just for understanding ******
    PSH_UINT psh_unit=3456;
    PSH_HANDLE psh_handle=987;
    PSH_HWND psh_hwnd=9876;
    PSH_HINSTANCE psh_hInstance = 14466;

    //code
    printf ("\n\n");
    printf ("Type PSH_MY_INT variable psh_a = %d\n", psh_a);

    printf("\n\n");

    for (psh_i=0; psh_i < (sizeof(psh_iArray)/sizeof(int)); psh_i++)
    {
        printf("Type PSH_MY_INT array variable IArray[%d] = %d\n", psh_i, psh_iArray[psh_i]);
    }
    printf ("\n\n");

    printf ("TYPE PSH_PVG_FLOAT variable psh_f = %f\n", psh_f_pvg);
    printf ("TYPE PSH_PVG_FLOAT constant psh_f_pvg_pi = %f\n", psh_f_pvg_pi);

    printf ("\n");
    printf ("TYPE MY_DOUBLE variable d = %lf\n", psh_d);

    printf ("\n");
    printf ("TYPE PSH_CHARACTER variable psh_ch = %c\n", psh_ch);

    printf ("\n");
    printf ("TYPE PSH_CHARACTER Array variable chArray = %s\n", psh_chArray_01);

    printf ("\n");
    for (psh_i = 0; psh_i < (sizeof(psh_chArray_02) / sizeof(psh_chArray_02[0])); psh_i++)
    {
        printf ("%c\t", psh_chArray_02[psh_i]);
    }
    
    printf ("\n\n");
    printf ("type UINT variable uint = %u\n", psh_unit);
    printf ("type HANDLE variable handle = %u\n", psh_handle);
    printf ("type HWND variable hwnd = %u\n", psh_hwnd);
    printf ("type HINSTANCE variable hInstance = %u\n", psh_hInstance);
    printf ("\n");
    
    PSH_MY_INT x = 90;
    PSH_MY_INT y = 30;
    PSH_MY_INT psh_ret;

    psh_ret = Add(x,y);
    printf ("psh_ret = %d\n", psh_ret);

    return(0);     
     
}

PSH_MY_INT Add(PSH_MY_INT psh_a, PSH_MY_INT psh_b)
{
    //code
    PSH_MY_INT psh_c;
    psh_c = psh_a + psh_b;
    return(psh_c);
}
