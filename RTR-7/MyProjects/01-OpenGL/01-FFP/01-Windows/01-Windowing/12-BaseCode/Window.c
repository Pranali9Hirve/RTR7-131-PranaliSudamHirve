// Header Files
#include<windows.h> // Hi header file windows chi ahe
#include<stdio.h> // For file I/O
#include<stdlib.h> // for exit()
#include "Window.h"

// MACROS
// 4X3
#define PSH_WIN_WIDTH 800
#define PSH_WIN_HEIGHT 600

// Global Function Declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// Global Variable declaration
HWND psh_ghwnd = NULL;
BOOL bFullscreen = FALSE;
DWORD dwStyle;
WINDOWPLACEMENT wpPrev;
FILE *gpFile = NULL;

BOOL bActiveWindow = FALSE;
BOOL bEscapeKeyIsPressed = FALSE;

// Entry Point Function
// HINSTANCE -> HANDLE
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int iCmdShow)
{
    // Function declarations
    int initialize(void); // je pn render karaych ahe tyach rendering ethe honar ahe
    void render(void); // draw / display / render, 
    void update(void); // 
    void unInitialize(void);

    // Variable Declarations
    // Create logfile
    gpFile = fopen("Log.txt", "w");

    if (gpFile == NULL)
    {
        MessageBox(NULL, TEXT("Log file creation failed"), TEXT("ERROR"), MB_OK);
        exit(0);
    }
    else
    {
        fprintf(gpFile, "PSH: Program started successfully !!!\n");
    }

    WNDCLASSEX wndclass;
    HWND hwnd = NULL;
    MSG msg;
    TCHAR szAppName[] = TEXT("RTR7_PSH");

    // game loop
    // Variable declaration
    BOOL bDone = FALSE;

    // Code
    // 1: WNDCLASSEX Structure Initialization
    wndclass.cbSize = sizeof(WNDCLASSEX); // Added newly cb-count of bytes (byte size)
    wndclass.style = CS_HREDRAW|CS_VREDRAW|CS_OWNDC; // CS -> class style CS_HREDRAW= hexadecimal(2) and CS_VREDRAW =  hexadecimal(1)
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
    hwnd = CreateWindowEx(
        WS_EX_APPWINDOW,
        szAppName,
        TEXT("Pranali Hirve: RTR7-131-PranaliSudamHirve/RTR-7/MyProjects/01-OpenGL/01-FFP/01-Windows/01-Windowing/10-WindowStub"),
        WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN | WS_CLIPSIBLINGS | WS_VISIBLE,
        pshScreenWidth/2 - PSH_WIN_WIDTH/2, // x-coordinate, screen 
        pshScreenHeight/2 - PSH_WIN_HEIGHT/2, // y-coordinate
        PSH_WIN_WIDTH, // width, rumalachi width
        PSH_WIN_HEIGHT, // height, rumalachi height
        NULL,
        NULL,
        hInstance,
        NULL);

    
    // Set global window handle
    psh_ghwnd = hwnd;

    // Call 
    int iResult = initialize();
    if (iResult != 0)
    {
        fprintf(gpFile, "PSH: WinMain(): initialize():  function failed\n");
        DestroyWindow(hwnd); // OS send me WM_DESTROY
        hwnd = NULL;
    }
    else
    {
        fprintf(gpFile, "PSH: WinMain(): initialize():  function Succedded\n");
    }

    // Show Window
    ShowWindow(hwnd, iCmdShow);

    // Update the window to paint its backgound
    UpdateWindow(hwnd);

    SetForegroundWindow(hwnd); // window front la aanto

    SetForegroundWindow(hwnd);

    SetFocus(hwnd);


    // Game Loop
    while(bDone == FALSE)
    {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE ))
        {
            if (msg.message == WM_QUIT)
            {
                bDone = TRUE;
            }
            else
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
            if (bActiveWindow == TRUE)
            {
                if (bEscapeKeyIsPressed == TRUE)
                {
                    bDone = TRUE;
                }

                // Render
                render();
                update();
            }
        }
    }

    // unInitialize
    unInitialize();
    
    return((int)msg.wParam);
}

// Declarator (Function Implementation)
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
    // Function declarations
    void resize(int, int); // width , height
    void unInitialize(void);

    void ToggleFullscreen(void);
   
    // Code
    switch(iMsg)
    {
        case WM_DESTROY:
            PostQuitMessage(131);
            break;
        case WM_CREATE:
            memset(&wpPrev, 0, sizeof(WINDOWPLACEMENT));
            wpPrev.length = sizeof(WINDOWPLACEMENT);
            break;
        case WM_SETFOCUS:
            bActiveWindow = TRUE;
            break;
        case WM_KILLFOCUS:
            bActiveWindow = FALSE;
            break;
        case WM_SIZE:
            resize(LOWORD(lParam), HIWORD(lParam));
            break;
        case WM_KEYDOWN:
            switch(wParam)
            {
                case VK_ESCAPE:
                    bEscapeKeyIsPressed = TRUE;
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
                    if (bFullscreen == FALSE)
                    {
                        ToggleFullscreen();
                        bFullscreen = TRUE;
                    }
                    else
                    {
                        ToggleFullscreen();
                        bFullscreen = FALSE;
                    }

                    // ToggleFullscreen(); <- short code of above
                    // bFullscreen = !bFullscreen;

                    break;
                
                default:
                    break;
            }
            break;
        case WM_CLOSE:
            unInitialize();
            break;
        default:
            break; 
    }
    return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}

void ToggleFullscreen(void)
{
    // Variable declaration
    MONITORINFO mi;
    // Code
    //second setp
    if (bFullscreen == FALSE)
    {
        // Get current window style
        dwStyle = GetWindowLong(psh_ghwnd, GWL_STYLE);
        if (dwStyle & WS_OVERLAPPEDWINDOW )
        {
            memset(&mi, 0, sizeof(MONITORINFO));
            mi.cbSize = sizeof(MONITORINFO);
            if (GetWindowPlacement(psh_ghwnd, &wpPrev) && GetMonitorInfo(MonitorFromWindow(psh_ghwnd, MONITORINFOF_PRIMARY), &mi))
            {
                SetWindowLong(psh_ghwnd, GWL_STYLE, dwStyle & ~WS_OVERLAPPEDWINDOW);
                SetWindowPos(psh_ghwnd, HWND_TOP, mi.rcMonitor.left, mi.rcMonitor.top, (mi.rcMonitor.right - mi.rcMonitor.left), (mi.rcMonitor.bottom - mi.rcMonitor.top), SWP_NOZORDER |
                SWP_NOZORDER | SWP_FRAMECHANGED);
                
            }

        }
        ShowCursor(FALSE);
    }
    else
    {
        SetWindowLong(psh_ghwnd, GWL_STYLE, dwStyle | WS_OVERLAPPEDWINDOW);
        SetWindowPlacement(psh_ghwnd, &wpPrev);
        SetWindowPos(psh_ghwnd, HWND_TOP, 0 ,0 ,0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED );
        ShowCursor(TRUE);
    }
}

int initialize(void)
{
    // Code
    return(0);
}

void resize(int width, int height)
{
    // Code
}

void render()
{
    // Code
}

void update()
{
    // Code
}

void unInitialize()
{
    // Code
    // Destroy window
    if (psh_ghwnd)
    {
        DestroyWindow(psh_ghwnd);
        psh_ghwnd = NULL;
    }

    // close of file
    if (gpFile)
    {
        fprintf(gpFile, "PSH: Program terminated successfully!!!\n");
        fclose(gpFile);
        gpFile = NULL;
    }
}
