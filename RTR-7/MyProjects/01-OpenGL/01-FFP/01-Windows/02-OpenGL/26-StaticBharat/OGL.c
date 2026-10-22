// Header Files
#include<windows.h> // Hi header file windows chi ahe
#include<stdio.h> // For file I/O
#include<stdlib.h> // for exit()
#include<math.h>

// OpenGL
#include<gl\GL.h> // SDK mazya include chya path madhe gl chya aat GL.h ahe
#include<gl\GLU.h>
#include "OGL.h"

// Link with OpenGL import library
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "GLU32.lib")

#define PI 3.14159265f

// MACROS
// 4X3
#define PSH_WIN_WIDTH 800
#define PSH_WIN_HEIGHT 600

// Global Function Declarations
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

// Global Variable declaration
HWND psh_ghwnd = NULL;
// openGL
HDC ghdc = NULL;
HGLRC ghrc = NULL; // graphics library chya render context cha handle
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
        TEXT("PRANALI HIRVE: RTR7-131-PranaliSudamHirve/RTR-7/MyProjects/01-OpenGL/01-FFP/01-Windows/02-OpenGL/26-StaticBharat"),
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
        // case WM_RBUTTONDOWN:
        //     bEscapeKeyIsPressed = TRUE;
        // break;
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
    // Function declarations
    void resize(int, int);
    void printGLInfo(void);
    void drawB(void);
    void drawH(void);
    void drawA(void);
    void drawR(void);
    void drawT(void);

    // Variable declarations
    PIXELFORMATDESCRIPTOR pfd;
    int iPixelFormatIndex;

    // Code
    memset(&pfd, 0, sizeof(PIXELFORMATDESCRIPTOR));
    pfd.nSize = sizeof(PIXELFORMATDESCRIPTOR);
    pfd.nVersion = 1; //Convensional
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cRedBits = 8;
    pfd.cBlueBits = 8;
    pfd.cAlphaBits = 8;
    pfd.cDepthBits = 32; // 2^32 => enable the depth

    ghdc = GetDC(psh_ghwnd);

    if (ghdc == NULL)
    {
        return(-1);
    }

    iPixelFormatIndex = ChoosePixelFormat(ghdc, &pfd);
    if (iPixelFormatIndex == 0)
    {
        return(-2);
    }

    if (SetPixelFormat(ghdc, iPixelFormatIndex, &pfd) == FALSE)
    {
        return(-3);
    }

    ghrc = wglCreateContext(ghdc);
    if (ghrc == NULL)
    {
        return(-4);
    }

    if (wglMakeCurrent(ghdc, ghrc) == FALSE)
    {
        return(-5);
    }

    // print opengl info
    printGLInfo();

    // Enable Depth
    glShadeModel(GL_SMOOTH); // color detana smooth thev
    glClearDepth(1.0f); // Mazya depth buffer madhlya saglya(bit chya) values 1 kr 
    glEnable(GL_DEPTH_TEST); 
    glDepthFunc(GL_LEQUAL); //LEQUAL -> less than equal to
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    // Choose screen clearing color as blue
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // blue
    resize(PSH_WIN_WIDTH, PSH_WIN_HEIGHT);

    return(0);
}

void printGLInfo(void)
{
    // Code
    fprintf(gpFile, "OpenGL Vendor: %s\n", glGetString(GL_VENDOR));
    fprintf(gpFile, "OpenGL Renderer: %s\n", glGetString(GL_RENDERER)); // Driver chi identity
    fprintf(gpFile, "OpenGL Version: %s\n", glGetString(GL_VERSION));
}

void resize(int width, int height)
{
    // Code
    if (height <= 0)
    {
        height = 1; // in future while calculating perspective we need to divide with 2
    }

    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
    glMatrixMode(GL_PROJECTION); // OpenGL function
    glLoadIdentity();

    // Perspective Projection - Js dista ts
    gluPerspective(
        45.0f, //fovy (degrees as it is angle (field of view))
        (GLfloat)width/(GLfloat)height,
        0.1f, // near to eye
        100.0f
    ); 
}

void render() // disply
{
    // Code
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0.0f, -0.05f, -2.0f);

    glPushMatrix();
    drawB();
    glPopMatrix();

    glPushMatrix();
    drawH();
    glPopMatrix();

    glPushMatrix();
    drawA();
    glPopMatrix();

    glPushMatrix();
    drawR();
    glPopMatrix();
   
    glPushMatrix();
    glTranslatef(0.48f, 0.0f, 0.0f);
    drawA();
    glPopMatrix();

    glPushMatrix();
    drawT();
    glPopMatrix();
    
    // Do double buffering
    SwapBuffers(ghdc);
}

void drawB(void)
{
    // first top  
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.41f, 0.13f);
        glVertex3f(-0.7f, 0.2f, 0.0f);
        glVertex3f(-0.51f, 0.2f, 0.0f);
        glColor3f(1.0f, 0.59f, 0.40f);
        glVertex3f(-0.49f, 0.16f, 0.0f);
        glVertex3f(-0.7f, 0.16f, 0.0f);
    glEnd();
 
    // second left part
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.59f, 0.40f);
        glVertex3f(-0.7f, 0.16f, 0.0f);
        glVertex3f(-0.63f, 0.16f, 0.0f);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-0.63f, 0.07f, 0.0f);
        glVertex3f(-0.7f, 0.07f, 0.0f);
    glEnd();
 
    // second right side upper
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.59f, 0.40f);
        glVertex3f(-0.49f, 0.16f, 0.0f);
        glVertex3f(-0.56f, 0.16f, 0.0f);
        glColor3f(1.0f, 0.77f, 0.66f);
        glVertex3f(-0.55f, 0.12f, 0.0f);
        glVertex3f(-0.48f, 0.12f, 0.0f);
    glEnd();
 
    // second right side lower
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.77f, 0.66f);
        glVertex3f(-0.48f, 0.12f, 0.0f);
        glVertex3f(-0.55f, 0.12f, 0.0f);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-0.56f, 0.07f, 0.0f);
        glVertex3f(-0.49f, 0.07f, 0.0f);
    glEnd();
 
    // Third (middle section) 
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-0.7f, 0.07f, 0.0f);
        glVertex3f(-0.49f, 0.07f, 0.0f);
        glVertex3f(-0.49f, 0.03f, 0.0f);
        glVertex3f(-0.7f, 0.03f, 0.0f);
    glEnd();
 
    // Fourth (second last)
    // left side
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-0.7f, 0.03f, 0.0f);
        glVertex3f(-0.63f, 0.03f, 0.0f);
        glColor3f(0.32f, 0.60f, 0.46f);
        glVertex3f(-0.63f, -0.06f, 0.0f);
        glVertex3f(-0.7f, -0.06f, 0.0f);
    glEnd();
 
    // right side upper
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-0.49f, 0.03f, 0.0f);
        glVertex3f(-0.56f, 0.03f, 0.0f);
        glColor3f(0.70f, 0.82f, 0.76f);
        glVertex3f(-0.55f, -0.01f, 0.0f);
        glVertex3f(-0.48f, -0.01f, 0.0f);
    glEnd();
 
    // right side lower
    glBegin(GL_POLYGON);
        glColor3f(0.70f, 0.82f, 0.76f);
        glVertex3f(-0.48f, -0.01f, 0.0f);
        glVertex3f(-0.55f, -0.01f, 0.0f);
        glColor3f(0.32f, 0.60f, 0.46f);
        glVertex3f(-0.56f, -0.06f, 0.0f);
        glVertex3f(-0.49f, -0.06f, 0.0f);
    glEnd();
 
    // last bottom bar
    glBegin(GL_POLYGON);
        glColor3f(0.32f, 0.60f, 0.46f);
        glVertex3f(-0.7f, -0.06f, 0.0f);
        glVertex3f(-0.49f, -0.06f, 0.0f);
        glColor3f(0.02f, 0.42f, 0.0f);
        glVertex3f(-0.50f, -0.1f, 0.0f);
        glVertex3f(-0.7f, -0.1f, 0.0f);
    glEnd();
}

void drawH(void)
{
    // first upper left side
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.41f, 0.13f);
        glVertex3f(-0.46f, 0.2f, 0.0f);
        glVertex3f(-0.39f, 0.2f, 0.0f);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-0.39f, 0.07f, 0.0f);
        glVertex3f(-0.46f, 0.07f, 0.0f);
    glEnd();
 
    // first upper right side
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.41f, 0.13f);
        glVertex3f(-0.31f, 0.2f, 0.0f);
        glVertex3f(-0.24f, 0.2f, 0.0f);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-0.24f, 0.07f, 0.0f);
        glVertex3f(-0.31f, 0.07f, 0.0f);
    glEnd();
 
    // middle part
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-0.46f, 0.07f, 0.0f);
        glVertex3f(-0.24f, 0.07f, 0.0f);
        glVertex3f(-0.24f, 0.03f, 0.0f);
        glVertex3f(-0.46f, 0.03f, 0.0f);
    glEnd();
 
    // third left side
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-0.46f, 0.03f, 0.0f);
        glVertex3f(-0.39f, 0.03f, 0.0f);
        glColor3f(0.02f, 0.42f, 0.22f);
        glVertex3f(-0.39f, -0.1f, 0.0f);
        glVertex3f(-0.46f, -0.1f, 0.0f);
    glEnd();
 
    // third right side
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-0.31f, 0.03f, 0.0f);
        glVertex3f(-0.24f, 0.03f, 0.0f);
        glColor3f(0.02f, 0.42f, 0.22f);
        glVertex3f(-0.24f, -0.1f, 0.0f);
        glVertex3f(-0.31f, -0.1f, 0.0f);
    glEnd();
}
 
void drawA(void)
{
    // forst top bar
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.41f, 0.13f);
        glVertex3f(-0.18f, 0.2f, 0.0f);
        glVertex3f(-0.04f, 0.2f, 0.0f);
        glColor3f(1.0f, 0.59f, 0.40f);
        glVertex3f(-0.03f, 0.16f, 0.0f);
        glVertex3f(-0.19f, 0.16f, 0.0f);
    glEnd();
 
    // second left side
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.59f, 0.40f);
        glVertex3f(-0.19f, 0.16f, 0.0f);
        glVertex3f(-0.13f, 0.16f, 0.0f);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-0.15f, 0.07f, 0.0f);
        glVertex3f(-0.22f, 0.07f, 0.0f);
    glEnd();
 
    // second right side
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.59f, 0.40f);
        glVertex3f(-0.09f, 0.16f, 0.0f);
        glVertex3f(-0.03f, 0.16f, 0.0f);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(0.0f, 0.07f, 0.0f);
        glVertex3f(-0.07f, 0.07f, 0.0f);
    glEnd();
 
    // middle part
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-0.22f, 0.07f, 0.0f);
        glVertex3f(0.0f, 0.07f, 0.0f);
        glVertex3f(0.0f, 0.03f, 0.0f);
        glVertex3f(-0.22f, 0.03f, 0.0f);
    glEnd();

    // middle part
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-0.15f, 0.03f, 0.0f);
        glVertex3f(-0.07f, 0.03f, 0.0f);
        glColor3f(0.85f, 0.91f, 0.88f);
        glVertex3f(-0.07f, 0.01f, 0.0f);
        glVertex3f(-0.15f, 0.01f, 0.0f);
    glEnd();
 
    // bottom left side
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-0.22f, 0.03f, 0.0f);
        glVertex3f(-0.15f, 0.03f, 0.0f);
        glColor3f(0.02f, 0.42f, 0.22f);
        glVertex3f(-0.15f, -0.1f, 0.0f);
        glVertex3f(-0.22f, -0.1f, 0.0f);
    glEnd();
 
    // bottom right side
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-0.07f, 0.03f, 0.0f);
        glVertex3f(0.0f, 0.03f, 0.0f);
        glColor3f(0.02f, 0.42f, 0.22f);
        glVertex3f(0.0f, -0.1f, 0.0f);
        glVertex3f(-0.07f, -0.1f, 0.0f);
    glEnd();

}
 
void drawR(void)
{
    // first top bar
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.41f, 0.13f);
        glVertex3f(0.02f, 0.2f, 0.0f);
        glVertex3f(0.21f, 0.2f, 0.0f);
        glColor3f(1.0f, 0.59f, 0.40f);
        glVertex3f(0.23f, 0.16f, 0.0f);
        glVertex3f(0.02f, 0.16f, 0.0f);
    glEnd();
 
    // second left side
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.59f, 0.40f);
        glVertex3f(0.02f, 0.16f, 0.0f);
        glVertex3f(0.09f, 0.16f, 0.0f);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(0.09f, 0.07f, 0.0f);
        glVertex3f(0.02f, 0.07f, 0.0f);
    glEnd();
 
    // second right side upper
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.59f, 0.40f);
        glVertex3f(0.23f, 0.16f, 0.0f);
        glVertex3f(0.16f, 0.16f, 0.0f);
        glColor3f(1.0f, 0.77f, 0.66f);
        glVertex3f(0.18f, 0.12f, 0.0f);
        glVertex3f(0.24f, 0.12f, 0.0f);
    glEnd();
 
    // second right side lower
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.77f, 0.66f);
        glVertex3f(0.24f, 0.12f, 0.0f);
        glVertex3f(0.18f, 0.12f, 0.0f);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(0.16f, 0.07f, 0.0f);
        glVertex3f(0.24f, 0.07f, 0.0f);
    glEnd();
 
    // middle
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(0.02f, 0.07f, 0.0f);
        glVertex3f(0.24f, 0.07f, 0.0f);
        glVertex3f(0.20f, 0.03f, 0.0f);
        glVertex3f(0.02f, 0.03f, 0.0f);
    glEnd();
 
    // bottom left side
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(0.02f, 0.03f, 0.0f);
        glVertex3f(0.09f, 0.03f, 0.0f);
        glColor3f(0.02f, 0.42f, 0.22f);
        glVertex3f(0.09f, -0.1f, 0.0f);
        glVertex3f(0.02f, -0.1f, 0.0f);
    glEnd();
 
    // bottom right side
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(0.14f, 0.03f, 0.0f);
        glVertex3f(0.20f, 0.03f, 0.0f);
        glColor3f(0.02f, 0.42f, 0.22f);
        glVertex3f(0.24f, -0.1f, 0.0f);
        glVertex3f(0.18f, -0.1f, 0.0f);
    glEnd();
}
 
void drawT(void)
{
    // saffron - top bar
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.41f, 0.13f);
        glVertex3f(0.5f, 0.2f, 0.0f);
        glVertex3f(0.7f, 0.2f, 0.0f);
        glColor3f(1.0f, 0.59f, 0.40f);
        glVertex3f(0.7f, 0.16f, 0.0f);
        glVertex3f(0.5f, 0.16f, 0.0f);
    glEnd();
 
    // saffron - side
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 0.59f, 0.40f);
        glVertex3f(0.566f, 0.16f, 0.0f);
        glVertex3f(0.634f, 0.16f, 0.0f);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(0.634f, 0.07f, 0.0f);
        glVertex3f(0.566f, 0.07f, 0.0f);
    glEnd();
 
    // white - middle
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(0.566f, 0.07f, 0.0f);
        glVertex3f(0.634f, 0.07f, 0.0f);
        glVertex3f(0.634f, 0.03f, 0.0f);
        glVertex3f(0.566f, 0.03f, 0.0f);
    glEnd();
 
    // green - side
    glBegin(GL_POLYGON);
        glColor3f(1.0f, 1.0f, 1.0f);
        glVertex3f(0.566f, 0.03f, 0.0f);
        glVertex3f(0.634f, 0.03f, 0.0f);
        glColor3f(0.02f, 0.42f, 0.22f);
        glVertex3f(0.634f, -0.1f, 0.0f);
        glVertex3f(0.566f, -0.1f, 0.0f);
    glEnd();
}

void update()
{
    // Code
}

void unInitialize()
{
    // Code
    // if exiting in fullcreen first restore then proceed
    if (bFullscreen == TRUE)
    {
        ToggleFullscreen();
        bFullscreen = FALSE;
    }

    // Destroy window
    // First check the current context and if it is then un make it

    if (wglGetCurrentContext() == ghrc)
    {
        wglMakeCurrent(NULL, NULL);
    }

    // Now destroy the rendering context
    if (ghrc)
    {
        wglDeleteContext(ghrc);
        ghrc = NULL;
    }

    // release the device context
    if (ghdc)
    {
        ReleaseDC(psh_ghwnd, ghdc);
        ghdc = NULL;
    }

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
