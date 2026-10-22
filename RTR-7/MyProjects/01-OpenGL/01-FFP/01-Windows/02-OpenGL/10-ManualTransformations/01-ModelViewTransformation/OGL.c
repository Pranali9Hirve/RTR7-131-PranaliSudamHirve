// Header Files
#include<windows.h> // Hi header file windows chi ahe
#include<stdio.h> // For file I/O
#include<stdlib.h> // for exit()

#define _USE_MATH_DEFINES 1
#include<MATH.h> // for sin and cos

// OpenGL
#include<gl\GL.h> // SDK mazya include chya path madhe gl chya aat GL.h ahe
#include<gl\GLU.h>
#include "OGL.h"

// Link with OpenGL import library
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "GLU32.lib")

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

GLfloat pshAngleCube = 0.0f;

// Transformation matrices
GLfloat modelViewMatrix[16];
GLfloat identityMatrix[16];
GLfloat translationMatrix[16];
GLfloat scaleMatrix[16];
GLfloat rotationMatrix_X[16];
GLfloat rotationMatrix_Y[16];
GLfloat rotationMatrix_Z[16];


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
        TEXT("PRANALI HIRVE: RTR7-131-PranaliSudamHirve/RTR-7/MyProjects/01-OpenGL/01-FFP/01-Windows/02-OpenGL/10-ManualTransformations/01-ModelViewTransformation"),
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
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); //bepth buffer clear kr with 1.0f
    // Pyramid
    // glMatrixMode(GL_MODELVIEW);
    // glLoadIdentity();
    // glTranslatef(0.0f, 0.0f, -6.0f); // Matrix madhe value aaly ani triangle dislay

    // Cube:  front red, right green, back blue, left cyan, top magenta , bottom yellow
    glMatrixMode(GL_MODELVIEW); // Optional

    //glLoadIdentity(); // Compulsory
    identityMatrix[0] = 1.0f;
    identityMatrix[1]= 0.0f;
    identityMatrix[2]= 0.0f;
    identityMatrix[3]= 0.0f;
    identityMatrix[4]= 0.0f;
    identityMatrix[5]= 1.0f;
    identityMatrix[6]= 0.0f;
    identityMatrix[7]= 0.0f;
    identityMatrix[8]= 0.0f;
    identityMatrix[9]= 0.0f;
    identityMatrix[10]= 1.0f;
    identityMatrix[11]= 0.0f;
    identityMatrix[12]= 0.0f;
    identityMatrix[13]= 0.0f;
    identityMatrix[14]= 0.0f;
    identityMatrix[15]= 1.0f;

    glLoadMatrixf(identityMatrix);

    // translation Matrix
    // glTranslatef(1.5f, 0.0f, -6.0f);
    translationMatrix[0] = 1.0f;
    translationMatrix[1]= 0.0f;
    translationMatrix[2]= 0.0f;
    translationMatrix[3]= 0.0f;
    translationMatrix[4]= 0.0f;
    translationMatrix[5]= 1.0f;
    translationMatrix[6]= 0.0f;
    translationMatrix[7]= 0.0f;
    translationMatrix[8]= 0.0f;
    translationMatrix[9]= 0.0f;
    translationMatrix[10]= 1.0f;
    translationMatrix[11]= 0.0f;
    translationMatrix[12]= 0.0f;
    translationMatrix[13]= 0.0f;
    translationMatrix[14]= -6.0f;
    translationMatrix[15]= 1.0f;

    glMultMatrixf(translationMatrix);

    // Scale Matruix
    scaleMatrix[0] = 0.75f;
    scaleMatrix[1]= 0.0f;
    scaleMatrix[2]= 0.0f;
    scaleMatrix[3]= 0.0f;
    scaleMatrix[4]= 0.0f;
    scaleMatrix[5]= 0.75f;
    scaleMatrix[6]= 0.0f;
    scaleMatrix[7]= 0.0f;
    scaleMatrix[8]= 0.0f;
    scaleMatrix[9]= 0.0f;
    scaleMatrix[10]= 0.75f;
    scaleMatrix[11]= 0.0f;
    scaleMatrix[12]= 0.0f;
    scaleMatrix[13]= 0.0f;
    scaleMatrix[14]= 0.0f;
    scaleMatrix[15]= 1.0f;

    glMultMatrixf(scaleMatrix);

    //Converted angle in degree to angle in radions
    float angle = pshAngleCube * (M_PI/180.0f);
    // Rotation Matrix
    rotationMatrix_X[0] = 1.0f;
    rotationMatrix_X[1]= 0.0f;
    rotationMatrix_X[2]= 0.0f;
    rotationMatrix_X[3]= 0.0f;
    rotationMatrix_X[4]= 0.0f;
    rotationMatrix_X[5]= cos(angle);
    rotationMatrix_X[6]= sin(angle);
    rotationMatrix_X[7]= 0.0f;
    rotationMatrix_X[8]= 0.0f;
    rotationMatrix_X[9]= -sin(angle);
    rotationMatrix_X[10]= cos(angle);
    rotationMatrix_X[11]= 0.0f;
    rotationMatrix_X[12]= 0.0f;
    rotationMatrix_X[13]= 0.0f;
    rotationMatrix_X[14]= 0.0f;
    rotationMatrix_X[15]= 1.0f;


    // Rotation Matrix
    rotationMatrix_Y[0] = cos(angle);
    rotationMatrix_Y[1]= 0.0f;
    rotationMatrix_Y[2]= -sin(angle);
    rotationMatrix_Y[3]= 0.0f;
    rotationMatrix_Y[4]= 0.0f;
    rotationMatrix_Y[5]= 1.0f;
    rotationMatrix_Y[6]= 0.0f;
    rotationMatrix_Y[7]= 0.0f;
    rotationMatrix_Y[8]= sin(angle);
    rotationMatrix_Y[9]= 0.0f;
    rotationMatrix_Y[10]= cos(angle);
    rotationMatrix_Y[11]= 0.0f;
    rotationMatrix_Y[12]= 0.0f;
    rotationMatrix_Y[13]= 0.0f;
    rotationMatrix_Y[14]= 0.0f;
    rotationMatrix_Y[15]= 1.0f;

    // Rotation Matrix Z
    rotationMatrix_Z[0] =cos(angle);
    rotationMatrix_Z[1]= sin(angle);
    rotationMatrix_Z[2]= 0.0f;
    rotationMatrix_Z[3]= 0.0f;
    rotationMatrix_Z[4]= -sin(angle);
    rotationMatrix_Z[5]= cos(angle);
    rotationMatrix_Z[6]= 0.0f;
    rotationMatrix_Z[7]= 0.0f;
    rotationMatrix_Z[8]= 0.0f;
    rotationMatrix_Z[9]= 0.0f;
    rotationMatrix_Z[10]= 1.0f;
    rotationMatrix_Z[11]= 0.0f;
    rotationMatrix_Z[12]= 0.0f;
    rotationMatrix_Z[13]= 0.0f;
    rotationMatrix_Z[14]= 0.0f;
    rotationMatrix_Z[15]= 1.0f;

    glMultMatrixf(rotationMatrix_X);
    glMultMatrixf(rotationMatrix_Y);
    glMultMatrixf(rotationMatrix_Z);
    // Now this matrix is 

    // glScalef(0.75f, 0.75f, 0.75f); // cube la saglya bajune 0.25f ne small kr
    // glRotatef(pshAngleCube, 1.0f, 0.0f, 0.0f);
    // glRotatef(pshAngleCube, 0.0f, 1.0f, 0.0f);
    // glRotatef(pshAngleCube, 0.0f, 0.0f, 1.0f);

    glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(1.0f, 1.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);

        // Right
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(1.0f,  1.0f, -1.0f);
        glVertex3f(1.0f,  1.0f,  1.0f);
        glVertex3f(1.0f, -1.0f,  1.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);

        // B
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(1.0f,  1.0f, -1.0f);
        glVertex3f(-1.0f,  1.0f, -1.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);

        // Left
        glColor3f(0.0f, 1.0f, 1.0f);
        glVertex3f(-1.0f,  1.0f,  1.0f);
        glVertex3f(-1.0f,  1.0f, -1.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);

        // top	
        glColor3f(1.0f, 0.0f, 1.0f);			 
        glVertex3f(1.0f,  1.0f, -1.0f);	
        glVertex3f(-1.0f,  1.0f, -1.0f);	
        glVertex3f(-1.0f,  1.0f,  1.0f);
        glVertex3f(1.0f,  1.0f,  1.0f);
						 
	    // bottom	
        glColor3f(1.0f, 1.0f, 0.0f);        
        glVertex3f(1.0f, -1.0f,  1.0f);
        glVertex3f(-1.0f, -1.0f,  1.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);

    glEnd();

    // Do double buffering
    SwapBuffers(ghdc);
}

void update()
{
    // Code

    pshAngleCube = pshAngleCube + 0.2f;
    if (pshAngleCube >= 360.0f)
    {
        pshAngleCube = 0.0f;
    }
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
