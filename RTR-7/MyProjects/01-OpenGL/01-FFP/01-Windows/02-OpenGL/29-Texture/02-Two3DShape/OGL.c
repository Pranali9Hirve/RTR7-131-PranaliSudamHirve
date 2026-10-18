// Header Files
#include<windows.h> // Hi header file windows chi ahe
#include<stdio.h> // For file I/O
#include<stdlib.h> // for exit()

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
HDC psh_ghdc = NULL;
HGLRC psh_ghrc = NULL; // graphics library chya render context cha handle
BOOL psh_bFullscreen = FALSE;
DWORD psh_dwStyle;
WINDOWPLACEMENT psh_wpPrev;
FILE *psh_gpFile = NULL;

BOOL psh_bActiveWindow = FALSE;
BOOL psh_bEscapeKeyIsPressed = FALSE;

GLfloat pshAnglePyramid = 0.0f;
GLfloat pshAngleCube = 0.0f;

GLint psh_texture_stone = 0; 
GLint psh_texture_kundali = 0;

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
    psh_gpFile = fopen("Log.txt", "w");

    if (psh_gpFile == NULL)
    {
        MessageBox(NULL, TEXT("Log file creation failed"), TEXT("ERROR"), MB_OK);
        exit(0);
    }
    else
    {
        fprintf(psh_gpFile, "PSH: Program started successfully !!!\n");
    }

    WNDCLASSEX wndclass;
    HWND hwnd = NULL;
    MSG msg;
    TCHAR szAppName[] = TEXT("RTR7_PSH");

    // game loop
    // Variable declaration
    BOOL psh_bDone = FALSE;

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
        TEXT("PRANALI HIRVE: RTR7-131-PranaliSudamHirve/RTR-7/MyProjects/01-OpenGL/01-FFP/01-Windows/02-OpenGL/29-Texture/02-Two3DShape"),
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
        fprintf(psh_gpFile, "PSH: WinMain(): initialize():  function failed\n");
        DestroyWindow(hwnd); // OS send me WM_DESTROY
        hwnd = NULL;
    }
    else
    {
        fprintf(psh_gpFile, "PSH: WinMain(): initialize():  function Succedded\n");
    }

    // Show Window
    ShowWindow(hwnd, iCmdShow);

    // Update the window to paint its backgound
    UpdateWindow(hwnd);

    SetForegroundWindow(hwnd); // window front la aanto

    SetForegroundWindow(hwnd);

    SetFocus(hwnd);


    // Game Loop
    while(psh_bDone == FALSE)
    {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE ))
        {
            if (msg.message == WM_QUIT)
            {
                psh_bDone = TRUE;
            }
            else
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
        }
        else
        {
            if (psh_bActiveWindow == TRUE)
            {
                if (psh_bEscapeKeyIsPressed == TRUE)
                {
                    psh_bDone = TRUE;
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
            memset(&psh_wpPrev, 0, sizeof(WINDOWPLACEMENT));
            psh_wpPrev.length = sizeof(WINDOWPLACEMENT);
            break;
        case WM_SETFOCUS:
            psh_bActiveWindow = TRUE;
            break;
        case WM_KILLFOCUS:
            psh_bActiveWindow = FALSE;
            break;
        case WM_SIZE:
            resize(LOWORD(lParam), HIWORD(lParam));
            break;
        case WM_KEYDOWN:
            switch(wParam)
            {
                case VK_ESCAPE:
                    psh_bEscapeKeyIsPressed = TRUE;
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
                    if (psh_bFullscreen == FALSE)
                    {
                        ToggleFullscreen();
                        psh_bFullscreen = TRUE;
                    }
                    else
                    {
                        ToggleFullscreen();
                        psh_bFullscreen = FALSE;
                    }

                    // ToggleFullscreen(); <- short code of above
                    // psh_bFullscreen = !psh_bFullscreen;

                    break;
                
                default:
                    break;
            }
            break;
        // case WM_RBUTTONDOWN:
        //     psh_bEscapeKeyIsPressed = TRUE;
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
    if (psh_bFullscreen == FALSE)
    {
        // Get current window style
        psh_dwStyle = GetWindowLong(psh_ghwnd, GWL_STYLE);
        if (psh_dwStyle & WS_OVERLAPPEDWINDOW )
        {
            memset(&mi, 0, sizeof(MONITORINFO));
            mi.cbSize = sizeof(MONITORINFO);
            if (GetWindowPlacement(psh_ghwnd, &psh_wpPrev) && GetMonitorInfo(MonitorFromWindow(psh_ghwnd, MONITORINFOF_PRIMARY), &mi))
            {
                SetWindowLong(psh_ghwnd, GWL_STYLE, psh_dwStyle & ~WS_OVERLAPPEDWINDOW);
                SetWindowPos(psh_ghwnd, HWND_TOP, mi.rcMonitor.left, mi.rcMonitor.top, (mi.rcMonitor.right - mi.rcMonitor.left), (mi.rcMonitor.bottom - mi.rcMonitor.top), SWP_NOZORDER |
                SWP_NOZORDER | SWP_FRAMECHANGED);
                
            }

        }
        ShowCursor(FALSE);
    }
    else
    {
        SetWindowLong(psh_ghwnd, GWL_STYLE, psh_dwStyle | WS_OVERLAPPEDWINDOW);
        SetWindowPlacement(psh_ghwnd, &psh_wpPrev);
        SetWindowPos(psh_ghwnd, HWND_TOP, 0 ,0 ,0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOOWNERZORDER | SWP_NOZORDER | SWP_FRAMECHANGED );
        ShowCursor(TRUE);
    }
}

int initialize(void)
{
    // Function declarations
    void resize(int, int);
    void printGLInfo(void);
    BOOL loadGLTexture(GLuint* , TCHAR[]);
    

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

    psh_ghdc = GetDC(psh_ghwnd);

    if (psh_ghdc == NULL)
    {
        return(-1);
    }

    iPixelFormatIndex = ChoosePixelFormat(psh_ghdc, &pfd);
    if (iPixelFormatIndex == 0)
    {
        return(-2);
    }

    if (SetPixelFormat(psh_ghdc, iPixelFormatIndex, &pfd) == FALSE)
    {
        return(-3);
    }

    psh_ghrc = wglCreateContext(psh_ghdc);
    if (psh_ghrc == NULL)
    {
        return(-4);
    }

    if (wglMakeCurrent(psh_ghdc, psh_ghrc) == FALSE)
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

    // Load textures
    BOOL bResult = FALSE;
    bResult = loadGLTexture(&psh_texture_stone, MAKEINTRESOURCE(IDBITMAP_STONE));
    if (bResult == FALSE)
    {
        fprintf(psh_gpFile, "failed to load psh_texture_stone !!!\n");
        return -6;

    }

    // BOOL bResult = FALSE;
    bResult = loadGLTexture(&psh_texture_kundali, MAKEINTRESOURCE(IDBITMAP_KUNDALI));
    if (bResult == FALSE)
    {
        fprintf(psh_gpFile, "failed to load psh_texture_kundali !!!\n");
        return -6;

    }

    // Enable texturing
    glEnable(GL_TEXTURE_2D);

    resize(PSH_WIN_WIDTH, PSH_WIN_HEIGHT);

    return(0);
}

void printGLInfo(void)
{
    // Code
    fprintf(psh_gpFile, "OpenGL Vendor: %s\n", glGetString(GL_VENDOR));
    fprintf(psh_gpFile, "OpenGL Renderer: %s\n", glGetString(GL_RENDERER)); // Driver chi identity
    fprintf(psh_gpFile, "OpenGL Version: %s\n", glGetString(GL_VERSION));
}

BOOL loadGLTexture(GLuint* tx, TCHAR imageResourceId[])
{
    //Variable declarations
    HBITMAP hBitMap = NULL;
    BITMAP bmp;

    // code
    hBitMap = (HBITMAP)LoadImage(GetModuleHandle(NULL), imageResourceId, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION);
    if (hBitMap == NULL)
    {
        fprintf(psh_gpFile, "failed to load psh_texture_kundali !!!\n");
    }

    GetObject(hBitMap, sizeof(BITMAP), &bmp);

    // 
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);

    // 
    glGenTextures(1, tx);

    glBindTexture(GL_TEXTURE_2D, *tx);

    // give parameters
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);

    gluBuild2DMipmaps(GL_TEXTURE_2D, 3, bmp.bmWidth, bmp.bmHeight, GL_BGR_EXT, GL_UNSIGNED_BYTE, bmp.bmBits);
    glBindTexture(GL_TEXTURE_2D, 0);

    DeleteObject(hBitMap);

    return TRUE;
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
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(-1.5f, 0.0f, -6.0f); // Matrix madhe value aaly ani triangle disla
    glRotatef(pshAnglePyramid, 0.0f, 1.0f, 0.0f);

    glBindTexture(GL_TEXTURE_2D, psh_texture_stone);

    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_TRIANGLES);
        // Front face
        glTexCoord2f(0.5f, 1.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f); // LB
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(1.0f, -1.0f, 1.0f); // RB

        // right face
        glTexCoord2f(0.5f, 1.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);

        // back face
        glTexCoord2f(0.5f, 1.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);

        // left face
        glTexCoord2f(0.5f, 1.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);
    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);
    

    // Cube:  front red, right green, back blue, left cyan, top magenta , bottom yellow
    glMatrixMode(GL_MODELVIEW); // Optional
    glLoadIdentity(); // Compulsory
    glTranslatef(1.5f, 0.0f, -6.0f);
    glScalef(0.75f, 0.75f, 0.75f); // cube la saglya bajune 0.25f ne small kr
    glRotatef(pshAngleCube, 1.0f, 0.0f, 0.0f);
    glRotatef(pshAngleCube, 0.0f, 1.0f, 0.0f);
    glRotatef(pshAngleCube, 0.0f, 0.0f, 1.0f);

    glBindTexture(GL_TEXTURE_2D, psh_texture_kundali);

    glBegin(GL_QUADS);
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(1.0f, 1.0f, 1.0f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-1.0f, 1.0f, 1.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(1.0f, -1.0f, 1.0f);

        // Right
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(1.0f,  1.0f, -1.0f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(1.0f,  1.0f,  1.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(1.0f, -1.0f,  1.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);

        // BACK
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(1.0f,  1.0f, -1.0f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-1.0f,  1.0f, -1.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);

        // Left
        glTexCoord2f(1.0f, 1.0f);
        glVertex3f(-1.0f,  1.0f,  1.0f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-1.0f,  1.0f, -1.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, 1.0f);

        // top	
        glTexCoord2f(1.0f, 1.0f);			 
        glVertex3f(1.0f,  1.0f, -1.0f);
        glTexCoord2f(0.0f, 1.0f);	
        glVertex3f(-1.0f,  1.0f, -1.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-1.0f,  1.0f,  1.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(1.0f,  1.0f,  1.0f);
						 
	    // bottom
        glTexCoord2f(1.0f, 1.0f);	        
        glVertex3f(1.0f, -1.0f,  1.0f);
        glTexCoord2f(0.0f, 1.0f);
        glVertex3f(-1.0f, -1.0f,  1.0f);
        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, -1.0f);
        glTexCoord2f(1.0f, 0.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);

    glEnd();
    glBindTexture(GL_TEXTURE_2D, 0);

    // Do double buffering
    SwapBuffers(psh_ghdc);
}

void update()
{
    // Code
    pshAnglePyramid = pshAnglePyramid + 0.1f;
    if (pshAnglePyramid >= 360.0f)
    {
        pshAnglePyramid = 0.0f;
    }

    pshAngleCube = pshAngleCube + 0.1f;
    if (pshAngleCube >= 360.0f)
    {
        pshAngleCube = 0.0f;
    }
}

void unInitialize()
{


    // Code
    // if exiting in fullcreen first restore then proceed
    if (psh_bFullscreen == TRUE)
    {
        ToggleFullscreen();
        psh_bFullscreen = FALSE;
    }

    if (psh_texture_kundali)
    {
        glDeleteTextures(1, &psh_texture_kundali);
            psh_texture_kundali = 0;

    }

    if (psh_texture_stone)
    {
        glDeleteTextures(1, &psh_texture_stone);
            psh_texture_stone = 0;

    }
    // Destroy window
    // First check the current context and if it is then un make it

    if (wglGetCurrentContext() == psh_ghrc)
    {
        wglMakeCurrent(NULL, NULL);
    }

    // Now destroy the rendering context
    if (psh_ghrc)
    {
        wglDeleteContext(psh_ghrc);
        psh_ghrc = NULL;
    }

    // release the device context
    if (psh_ghdc)
    {
        ReleaseDC(psh_ghwnd, psh_ghdc);
        psh_ghdc = NULL;
    }

    if (psh_ghwnd)
    {
        DestroyWindow(psh_ghwnd);
        psh_ghwnd = NULL;
    }

    // close of file
    if (psh_gpFile)
    {
        fprintf(psh_gpFile, "PSH: Program terminated successfully!!!\n");
        fclose(psh_gpFile);
        psh_gpFile = NULL;
    }
}
