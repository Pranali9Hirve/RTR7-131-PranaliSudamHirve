// Header Files
#include<windows.h> // Hi header file windows chi ahe
#include "Window.h"

// MACROS
// 4X3
#define PSH_WIN_WIDTH 800
#define PSH_WIN_HEIGHT 600

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
    psh_wndclass.hIcon = LoadIcon(psh_hInstance, MAKEINTRESOURCE(MYICON));
    psh_wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    psh_wndclass.lpszClassName = psh_szAppName;
    psh_wndclass.lpszMenuName = NULL;
    psh_wndclass.hIconSm = LoadIcon(psh_hInstance, MAKEINTRESOURCE(MYICON)); // Added newly

    // 2: Register Above psh_WNDCLASS
    RegisterClassEx(&psh_wndclass); // return value = atom (such a string which is immutable )

    // Centering
    // Farashi chi width
    int pshScreenWidth = GetSystemMetrics(SM_CXSCREEN); // SM_CXSCREEN:=> MACRO Screen chi width de , c is count
    // Farashi chi height
    int pshScreenHeight = GetSystemMetrics(SM_CYSCREEN); // SM_CYSCREEN:=> MACRO Screen chi height de

    // 3: Create the Window
    psh_hwnd = CreateWindow(
        psh_szAppName,
        TEXT("PRANALI HIRVE-RTR7-131-PranaliSudamHirve/RTR-7/MyProjects/01-OpenGL/01-FFP/01-Windows/01-Windowing/02-MessageBox"),
        WS_OVERLAPPEDWINDOW,
        pshScreenWidth/2 - PSH_WIN_WIDTH/2, // x-coordinate, screen 
        pshScreenHeight/2 - PSH_WIN_HEIGHT/2, // y-coordinate
        PSH_WIN_WIDTH, // width, rumalachi width
        PSH_WIN_HEIGHT, // height, rumalachi height
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
    TCHAR psh_str[255];
    wsprintf(psh_str, TEXT("%d"), (int)psh_msg.wParam);
   // MessageBox(hwnd, psh_str, TEXT("wParam"), MB_OK);
    MessageBox(NULL, psh_str, TEXT("wParam"), MB_OK);
    return((int)psh_msg.wParam);
}

// Declarator (Function Implementation)
LRESULT CALLBACK WndProc(HWND psh_hwnd, UINT psh_iMsg, WPARAM psh_wParam, LPARAM psh_lParam)
{
    // Code
    switch(psh_iMsg)
    {
        case WM_DESTROY:
            MessageBox(psh_hwnd, TEXT("WM_DESTROY is received "), TEXT("Message"), MB_OK);
            PostQuitMessage(131);
            break;
        case WM_CREATE:
            MessageBox(psh_hwnd, TEXT("WM_CREATE is received"), TEXT("Message"), MB_OK);
            break;
        case WM_SETFOCUS:
            break;
        case WM_KILLFOCUS:
            break;
        case WM_SIZE:
            MessageBox(psh_hwnd, TEXT("WM_SIZE is received"), TEXT("Message"), MB_OK);
            break;
        case WM_KEYDOWN:
            switch(psh_wParam)
            {
                case VK_ESCAPE:
                    MessageBox(psh_hwnd, TEXT(" WM_KEYDOWN: VK_ESCAPE is pressed"), TEXT("Message"), MB_OK);
                    break;
                default:
                    break;
            }
            break;
        case WM_CHAR:
            switch (psh_wParam)
            {
                case 'F':
                case 'f':
                    MessageBox(psh_hwnd, TEXT("WM_CHAR: F/f key is pressed"), TEXT("Message"), MB_OK);
                    break;
                
                default:
                    break;
            }
            break;
        case WM_CLOSE:
            MessageBox(psh_hwnd, TEXT("WM_CLOSE is received "), TEXT("Message"), MB_OK);
            break;
        default:
            break; 
    }
    return(DefWindowProc(psh_hwnd, psh_iMsg, psh_wParam, psh_lParam));
}
