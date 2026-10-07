// Header Files
#include<windows.h>

// Global Function Declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// Entry Point Function
// HINSTANCE -> HANDLE
int WINAPI WinMain(HINSTANCE psh_hInstance, HINSTANCE psh_hPrevInstance, LPSTR psh_lpszCmdLine, int psh_iCmdShow)
{
    // Variable Declarations
    WNDCLASSEX psh_wndclass;
    HWND psh_hwnd = NULL;
    MSG psh_msg;
    TCHAR psh_szAppName[] = TEXT("RTR7_PSH");

    // Code
    // 1: WNDCLASSEX Structure Initialization
    psh_wndclass.cbSize = sizeof(WNDCLASSEX); // Added newly cb-count of bytes (byte size)
    psh_wndclass.style = CS_HREDRAW|CS_VREDRAW; // CS -> class style 
    psh_wndclass.cbClsExtra = 0;
    psh_wndclass.cbWndExtra = 0;
    psh_wndclass.lpfnWndProc = WndProc;
    psh_wndclass.hInstance = psh_hInstance;
    psh_wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    psh_wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    psh_wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    psh_wndclass.lpszClassName = psh_szAppName;
    psh_wndclass.lpszMenuName = NULL;
    psh_wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION); // Added newly

    // 2: Register Above WNDCLASS
    RegisterClassEx(&psh_wndclass); // return value = atom (such a string which is immutable )

    // 3: Create the Window
    psh_hwnd = CreateWindow(
        psh_szAppName,
        TEXT("My First RTR7 Program: RTR7-131-PranaliSudamHirve/RTR-7/MyProjects/01-OpenGL/01-FFP/01-Windows/01-Windowing/01-Window"),
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        NULL,
        NULL,
        psh_hInstance,
        NULL);

    // Show Window
    ShowWindow(psh_hwnd, psh_iCmdShow);

    // Update the window to paint its backgound
    UpdateWindow(psh_hwnd);

    // Message Loop
    while (GetMessage(&psh_msg, NULL, 0, 0))
    {
        TranslateMessage(&psh_msg);
        DispatchMessage(&psh_msg);
    }

    return((int)psh_msg.wParam);
}

// Declarator (Function Implementation)
LRESULT CALLBACK WndProc(HWND psh_hwnd, UINT psh_iMsg, WPARAM psh_wParam, LPARAM psh_lParam)
{
    // Code
    switch(psh_iMsg)
    {
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            break; 
    }
    return(DefWindowProc(psh_hwnd, psh_iMsg, psh_wParam, psh_lParam));
}
