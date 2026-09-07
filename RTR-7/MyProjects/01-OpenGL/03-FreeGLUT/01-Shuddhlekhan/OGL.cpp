# include <GL/freeglut.h>
bool bIsFullScreen = false;
int main(int argc, char* argv[])
{
    // Function Declaration
    void initialize(void);
    void unInitialize(void);
    void resize(int, int);
    void display(void);
    void keyboard(unsigned char, int, int);
    void mouse(int, int, int, int);

    // Code
    glutInit(&argc, argv); // WinMain is hidden in glutInit, wndClassEx ch initialization, registerClassEx he glutInit madhe ahe
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA); // GLUT_DOUBLE -> PFD_DOUBLEBUFFER 
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(100, 100); // x and y
    glutCreateWindow("My First RTR7 Program: Pranali Sudam Hirve"); // TEXT

    initialize();

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard); // WM_KEYDOWN
    glutMouseFunc(mouse);
    glutCloseFunc(unInitialize);

    glutMainLoop(); // Game loop

    // Flow should not come here
    return(0);
}

void initialize(void)
{
    // Code
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void resize(int width, int height)
{
    // Code
    if (height <= 0)
        height = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
}

void display(void)
{
    // Code
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glBegin(GL_TRIANGLES);
        glColor3f(1.0f, 0.0f, 0.0f);
        glVertex3f(0.0f, 1.0f, 0.0f);
        glColor3f(0.0f, 1.0f, 0.0f);
        glVertex3f(-1.0f, -1.0f, 0.0f);
        glColor3f(0.0f, 0.0f, 1.0f);
        glVertex3f(1.0f, -1.0f, -1.0f);
    glEnd();
    glutSwapBuffers(); // internally calling SwapBuffers(ghdc);
}

void keyboard(unsigned char key, int x, int y)
{
    // Code
    switch (key)
    {
        case 27: // VK_ESCAPE
            glutLeaveMainLoop();
            break;
        case 'F':
        case 'f':
            if (bIsFullScreen == false)
            {
                glutFullScreen();
                bIsFullScreen = true;
            }
            else
            {
                glutLeaveFullScreen();
                bIsFullScreen = false;
            }
            break;
        default:
            break;
    }
}

void mouse(int button, int state, int x, int y)
{
    // Code
    switch (button)
    {
        case GLUT_RIGHT_BUTTON:
            glutLeaveMainLoop();
            break;
        default:
            break;
    }
}

void unInitialize(void)
{
    // Code
}