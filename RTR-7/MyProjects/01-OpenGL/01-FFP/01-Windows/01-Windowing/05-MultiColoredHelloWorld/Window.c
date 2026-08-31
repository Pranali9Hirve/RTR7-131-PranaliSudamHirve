// Header Files
#include<windows.h> // Hi header file windows chi ahe
#include "Window.h"

// MACROS
// 4X3
#define PSH_WIN_WIDTH 800
#define PSH_WIN_HEIGHT 600

// Global Function Declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// Global Variable Declarations
int psh_IPaintFlag = -1;

// Entry Point Function
// HINSTANCE -> HANDLE
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
    // Variable Declarations
    WNDCLASSEX wndclass;
    HWND hwnd = NULL;
    MSG msg;
    TCHAR szAppName[] = TEXT("RTR7_PSH");

    // Code
    // 1: WNDCLASSEX Structure Initialization
    wndclass.cbSize = sizeof(WNDCLASSEX); // Added newly cb-count of bytes (byte size)
    wndclass.style = CS_HREDRAW|CS_VREDRAW; // CS -> class style 
    wndclass.cbClsExtra = 0;
    wndclass.cbWndExtra = 0;
    wndclass.lpfnWndProc = WndProc;
    wndclass.hInstance = hInstance;
    wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
    wndclass.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON));
    wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndclass.lpszClassName = szAppName;
    wndclass.lpszMenuName = NULL;
    wndclass.hIconSm = LoadIcon(hInstance, MAKEINTRESOURCE(MYICON)); // Added newly

    // 2: Register Above WNDCLASS
    RegisterClassEx(&wndclass); // return value = atom (such a string which is immutable )

    // Centering
    // Farashi chi width
    int pshScreenWidth = GetSystemMetrics(SM_CXSCREEN); // SM_CXSCREEN:=> MACRO Screen chi width de , c is count
    // Farashi chi height
    int pshScreenHeight = GetSystemMetrics(SM_CYSCREEN); // SM_CYSCREEN:=> MACRO Screen chi height de

    // 3: Create the Window
    hwnd = CreateWindow(
        szAppName,
        TEXT("PRANALI HIRVE-RTR7/131-PranaliSudamHirve/RTR-7/MyProjects/01-OpenGL/01-FFP/01-Windows/01-Windowing/05-MultiColoredHelloWorld"),
        WS_OVERLAPPEDWINDOW,
        pshScreenWidth/2 - PSH_WIN_WIDTH/2, // x-coordinate, screen 
        pshScreenHeight/2 - PSH_WIN_HEIGHT/2, // y-coordinate
        PSH_WIN_WIDTH, // width, rumalachi width
        PSH_WIN_HEIGHT, // height, rumalachi height
        NULL,
        NULL,
        hInstance,
        NULL);

    // Show Window
    ShowWindow(hwnd, iCmdShow);

    // Update the window to paint its backgound
    UpdateWindow(hwnd);

    // Message Loop
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
   
    return((int)msg.wParam);
}

// Declarator (Function Implementation)
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
    // Variable Declarations
    HDC psh_hdc;
    PAINTSTRUCT psh_ps;
    RECT psh_rc;
    TCHAR psh_str[] = TEXT("Hello World!!!");

    // Code
    switch(iMsg)
    {
        case WM_DESTROY:
            PostQuitMessage(131);
            break;
        case WM_CREATE:
            break;
        case WM_SETFOCUS:
            break;
        case WM_KILLFOCUS:
            break;
        case WM_SIZE:
            break;
        case WM_KEYDOWN:
            switch(wParam)
            {
                case VK_ESCAPE:
                    break;
                default:
                    break;
            }
            break;
        case WM_CHAR:
            switch (wParam)
            {
                case 'F':
                case 'f':
                    break;
                case 'R':
                case 'r':
                    psh_IPaintFlag = 1;
                    InvalidateRect(hwnd, NULL, TRUE);
                    break;
                case 'G':
                case 'g':
                    psh_IPaintFlag = 2;
                    InvalidateRect(hwnd, NULL, TRUE);
                    break;
                case 'B':
                case 'b':
                    psh_IPaintFlag = 3;
                    InvalidateRect(hwnd, NULL, TRUE);
                    break;
                case 'C':
                case 'c':
                    psh_IPaintFlag = 4;
                    InvalidateRect(hwnd, NULL, TRUE);
                    break;
                case 'M':
                case 'm':
                    psh_IPaintFlag = 5;
                    InvalidateRect(hwnd, NULL, TRUE);
                    break;
                case 'Y':
                case 'y':
                    psh_IPaintFlag = 6;
                    InvalidateRect(hwnd, NULL, TRUE);
                    break;
                
                default:                    
                    psh_IPaintFlag = -1;
                    InvalidateRect(hwnd, NULL, TRUE);
                    break;
            }
            break;
        // case WM_LBUTTONDOWN:
        //     // Mouse cha left click
        //     GetClientRect(hwnd, &psh_rc); // mala mazya client area cha rectangle de.
        //     psh_hdc = GetDC(hwnd); // mala device chya context cha handle de
        //     SetBkColor(psh_hdc, RGB(0, 0, 0)); // set background color
        //     SetTextColor(psh_hdc, RGB(0, 255, 0));
        //     DrawText(psh_hdc, psh_str, -1, &psh_rc, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
        //     ReleaseDC(hwnd, psh_hdc);
        //     break;
        case WM_PAINT:
            // Mouse cha left click
            GetClientRect(hwnd, &psh_rc); // mala mazya client area cha rectangle de.
            psh_hdc = BeginPaint(hwnd, &psh_ps);
            SetBkColor(psh_hdc, RGB(0, 0, 0)); // set background color
            // SetTextColor(psh_hdc, RGB(0, 255, 0));
            if (psh_IPaintFlag == 1)
            {
                SetTextColor(psh_hdc, RGB(255, 0, 0));
            } 
            else if (psh_IPaintFlag == 2)
            {
                SetTextColor(psh_hdc, RGB(0, 255, 0));
            }
            else if (psh_IPaintFlag == 3)
            {
                SetTextColor(psh_hdc, RGB(0, 0, 255));
            }
            else if (psh_IPaintFlag == 4)
            {
                SetTextColor(psh_hdc, RGB(0, 255, 255));
            }
            else if (psh_IPaintFlag == 5)
            {
                SetTextColor(psh_hdc, RGB(255, 0, 255));
            }
            else if (psh_IPaintFlag == 6)
            {
                SetTextColor(psh_hdc, RGB(255, 255, 0));
            }
            else
            {
                SetTextColor(psh_hdc, RGB(255, 255, 255));
            }
            DrawText(psh_hdc, psh_str, -1, &psh_rc, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
            EndPaint(hwnd, &psh_ps);            
            break;
        case WM_CLOSE:
            break;
        default:
            break; 
    }
    return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}
