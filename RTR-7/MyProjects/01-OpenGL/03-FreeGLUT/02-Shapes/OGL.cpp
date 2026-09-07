#include <GL/freeglut.h>
#include <math.h>

bool pshBIsFullScreen = true;
int main(int argc, char* argv[])
{
    // Function Declaration
    void initialize(void);
    void unInitialize(void);
    void resize(int, int);
    
    void display(void);
    void keyboard(unsigned char, int, int);
    void mouse(int, int, int, int);
    void drawTriangle(void);
    void drawQuads(void);
    void drawCircle(void);
    void drawLine(void);

    // Code
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowSize(1920, 1200);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Pranali Hirve: RTR7-131-PranaliSudamHirve/RTR-7/MyProjects/01-OpenGL/03-FreeGLUT/02-Shapes");

    initialize();

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutCloseFunc(unInitialize);

    glutMainLoop();

    // Flow should not come here
    return(0);
}

void initialize(void)
{
    // Code
    glClearColor(1.8f, 1.0f, 1.0f, 1.0f);
}

void resize(int pshWidth, int pshHeight)
{
    // Code
    if (pshHeight <= 0)
        pshHeight = 1;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, (GLsizei)pshWidth, (GLsizei)pshHeight);
}

void drawTriangle(void)
{
    // Code
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Triangle 1
    glBegin(GL_TRIANGLES);
    glColor3f(0.7f, 0.3f, 0.2f);
    glVertex2f(-1.0f, 0.3f);

    glColor3f(0.6f, 0.4f, 0.3f);
    glVertex2f(-0.8f, 0.7f);

    glColor3f(0.7f, 0.3f, 0.2f);
    glVertex2f(-0.6f, 0.3f);

    glEnd();

}

void drawQuads(void)
{

    // quad 1
    glBegin(GL_QUADS);
    glColor3f(0.5f, 0.2f, 0.2f);
    glVertex2f(-0.2f, -0.1f);

    glColor3f(0.5f, 0.2f, 0.2f);
    glVertex2f(-0.4f, -0.3f);

    glColor3f(0.7f, 0.4f, 0.3f);
    glVertex2f(-1.0f, -0.3f);

    glColor3f(0.7f, 0.4f, 0.3f);
    glVertex2f(-0.8f, -0.1f);

    glEnd();

    // quad 2
    glBegin(GL_QUADS);
    glColor3f(0.7f, 0.7f, 1.0f);
    glVertex2f(0.0f, -0.3f);

    glColor3f(0.7f, 0.7f, 1.0f);
    glVertex2f(0.0f, -0.7f);

    glColor3f(0.7f, 0.7f, 0.2f);
    glVertex2f(0.4f, -0.7f);

    glColor3f(0.7f, 0.7f, 0.2f);
    glVertex2f(0.4f, -0.3f);

    glEnd();
}

void drawCircle(void)
{
    glBegin(GL_TRIANGLE_FAN);

    glColor3f(1.0f, 0.8f, 0.2f);
    glVertex2f(0.2f, 0.8f);

    for (int i = 0; i <= 150; i++) {
        float theta = 2.0f * 3.14 * i / 150;
        float x =0.2f +  0.1 * (float)cos(theta);
        float y =0.8f + 0.15 * (float)sin(theta);
        glVertex2f(x, y);
    }
    
    glEnd();
}

void drawLine(void)
{
    glLineWidth(12.0f);
    glBegin(GL_LINES);

        glVertex2f(0.5f, 0.3f);
        glVertex2f(0.5f, 0.7f);

    glEnd();
}

void keyboard(unsigned char key, int x, int y)
{
    // Code
    switch (key)
    {
        case 27:
            glutLeaveMainLoop();
            break;
        case 'F':
        case 'f':
            if (pshBIsFullScreen == false)
            {
                glutFullScreen();
                pshBIsFullScreen = true;
            }
            else
            {
                glutLeaveFullScreen();
                pshBIsFullScreen = false;
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

void display(void)
{
    // Code
    glClear(GL_COLOR_BUFFER_BIT);

    drawTriangle();
    drawQuads();
    drawCircle();
    drawLine();
    glutSwapBuffers();
}

void unInitialize(void)
{
    // Code
}