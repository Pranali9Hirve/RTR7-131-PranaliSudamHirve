#include<GL/freeglut.h>
#include<math.h>

int main(int argc, char* argv[])
{
    // Function Declaration
    void initialize(void);
    void uninitialize(void);
    void display(void);
    void drawCircle(float, float);
    void Smiley1(float, float);
    void Smiley2(float, float);
    void Smiley3(float, float);
    void Smiley4(float, float);
    void Smiley5(float, float);
    void Smiley6(float, float);
    void Smiley7(float, float);
    void Smiley8(float, float);
    void Smiley9(float, float);
    void Smiley10(float, float);
    void EllipseEye(float, float);
    void HalfSmile(float, float, float);
    void TearDrop(float, float);

    // Code
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowSize(1920, 1200);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Smiley: Pranali Sudam Hirve");

    initialize();

    glutDisplayFunc(display);

    glutMainLoop();

    // Flow should not come here
    return(0);
}

void initialize(void)
{
    // Code
}


void drawCircle(float psh_x, float psh_y)
{
    glBegin(GL_TRIANGLE_FAN);

    glColor3f(1.0f, 0.8f, 0.2f);
    glVertex3f(-0.8f + psh_x, 0.7f + psh_y, 0.0f);

    for (int i = 0; i <= 360; i++) {
        float theta = 2.0f * 3.1416 * i / 360;
        float x =(-0.8f + psh_x) +  0.13 * (float)cos(theta);
        float y =(0.7f + psh_y) + 0.22 * (float)sin(theta);
        glVertex2f(x, y);
    }
    
    glEnd();
}

void EllipseEye(float psh_x, float psh_y)
{
    glBegin(GL_TRIANGLE_FAN);

    // glColor3f(1.0f, 0.0f, 0.0f);
    glColor3f(0.455f, 0.302f, 0.145f);
    glVertex3f(0.0f + psh_x, 0.0f + psh_y, 0.0f);

    for (int i = 0; i <= 360; i++) {
        float theta = 2.0f * 3.1416 * i / 360;
        float x =(0.0f + psh_x) +  0.02 * (float)cos(theta);
        float y =(0.0f + psh_y) + 0.05 * (float)sin(theta);
        glVertex2f(x, y);
    }
    
    glEnd();
}

void HalfSmile(float psh_dir, float psh_x, float psh_y)
{
    glBegin(GL_TRIANGLE_FAN);
    // glColor3f(1.0f, 0.0f, 0.0f);
    glColor3f(0.455f, 0.302f, 0.145f);
    glVertex3f(0.0f + psh_x, 0.0f + psh_y, 0.0f);

    for (int i = 0; i <= 360; i++) {
        float theta = psh_dir * 3.1416 * i / 360;
        float x =(0.0f + psh_x) +  0.05f * (float)cos(theta);
        float y =(0.0f + psh_y) + 0.05f * (float)sin(theta);
        glVertex2f(x, y);
    }
    
    glEnd();
}

void TearDrop(float psh_x, float psh_y)
{
    glBegin(GL_TRIANGLE_FAN);

    // glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f + psh_x, 0.06f + psh_y, 0.0f);

    for (int i = 0; i <= 360; i++) {
        float theta = 2.0f * 3.1416 * i / 360;
        float x =(0.0f + psh_x) +  0.015 * (float)cos(theta);
        float y =(0.0f + psh_y) + 0.03 * (float)sin(theta);
        glVertex2f(x, y);
    }
    
    glEnd();
}

void Smiley1(float psh_x, float psh_y)
{
    drawCircle(psh_x, psh_y);
    EllipseEye(0.35f, 0.15f);

    // glColor3f(1.f, 0.0f, 0.0f);   
    glColor3f(0.455f, 0.302f, 0.145f); 
    glLineWidth(5.0f);
    glBegin(GL_LINES);
        glVertex3f(0.42f, 0.15f, 0.0f);
        glVertex3f(0.47f, 0.18f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(0.42f, 0.15f, 0.0f);
        glVertex3f(0.47f, 0.12f, 0.0f);
    glEnd();

    HalfSmile(-1.0f, 0.4f, 0.0f);
}

void Smiley2(float psh_x, float psh_y)
{
    drawCircle(psh_x, psh_y);
    EllipseEye(-0.85f, 0.75f);
    EllipseEye(-0.75f, 0.75f);
    HalfSmile(-1.0f, -0.8f, 0.61f);
}

void Smiley3(float psh_x, float psh_y)
{
    drawCircle(psh_x, psh_y);
    EllipseEye(-0.55f, 0.75f);
    EllipseEye(-0.45f, 0.75f);
    HalfSmile(1.0f, -0.5f, 0.58f);
}

void Smiley4(float psh_x, float psh_y)
{
    drawCircle(psh_x, psh_y);
    EllipseEye(-0.25f, 0.75f);
    EllipseEye(-0.15f, 0.75f);

    // glColor3f(1.0f, 0.0f, 0.0f); 
    glColor3f(0.455f, 0.302f, 0.145f);   
    glLineWidth(4.0f);
    glBegin(GL_LINES);
        glVertex3f(-0.25f, 0.6f, 0.0f);
        glVertex3f(-0.15f, 0.6f, 0.0f);
    glEnd();
}

void Smiley5(float psh_x, float psh_y)
{
    drawCircle(psh_x, psh_y);
    EllipseEye(0.05f, 0.75f);
    EllipseEye(0.15f, 0.75f);

    // glColor3f(1.0f, 0.0f, 0.0f);   
    glColor3f(0.455f, 0.302f, 0.145f); 
    glLineWidth(4.0f);
    glBegin(GL_LINES);
        glVertex3f(0.06f, 0.55f, 0.0f);
        glVertex3f(0.15f, 0.6f, 0.0f);
    glEnd();

}

void Smiley6(float psh_x, float psh_y)
{
    drawCircle(psh_x, psh_y);
    EllipseEye(0.35f, 0.75f);
    EllipseEye(0.45f, 0.75f);
    glColor3f(0.2f, 0.678f, 1.0f);    
    TearDrop(0.35f, 0.636f);
    HalfSmile(1.0f, 0.4f, 0.56f);
}

void Smiley7(float psh_x, float psh_y)
{
    drawCircle(psh_x, psh_y);
    EllipseEye(-0.85f, 0.15f);
    EllipseEye(-0.75f, 0.15f);
}

void Smiley8(float psh_x, float psh_y)
{
    drawCircle(psh_x, psh_y);
    EllipseEye(-0.55f, 0.15f);
    EllipseEye(-0.45f, 0.15f);

    glBegin(GL_TRIANGLE_FAN);

    glColor3f(0.455f, 0.302f, 0.145f); 
    glVertex3f(-0.5f, -0.0f, 0.0f);

    for (int i = 0; i <= 360; i++) {
        float theta = 2.0f * 3.1416 * i / 360;
        float x =(-0.5f) +  0.03 * (float)cos(theta);
        float y =(-0.0f) + 0.05 * (float)sin(theta);
        glVertex2f(x, y);
    }
    
    glEnd();
}

void Smiley9(float psh_x, float psh_y)
{
    drawCircle(psh_x, psh_y);

    EllipseEye(-0.25f, 0.15f);
    EllipseEye(-0.15f, 0.15f);
    HalfSmile(1.0f, -0.2f, -0.02f);

    glColor3f(0.2f, 0.678f, 1.0f);    
    glLineWidth(15.0f);
    glBegin(GL_LINES);
        glVertex3f(-0.25f, 0.1f, 0.0f);
        glVertex3f(-0.25f, -0.09f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(-0.15f, 0.1f, 0.0f);
        glVertex3f(-0.15f, -0.09f, 0.0f);
    glEnd();
}

void Smiley10(float psh_x, float psh_y)
{
    drawCircle(psh_x, psh_y);
    // glColor3f(1.f, 0.0f, 0.0f);   
    glColor3f(0.455f, 0.302f, 0.145f); 
    glLineWidth(5.0f);
    glBegin(GL_LINES);
        glVertex3f(0.08f, 0.15f, 0.0f);
        glVertex3f(0.03f, 0.18f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(0.08f, 0.15f, 0.0f);
        glVertex3f(0.03f, 0.12f, 0.0f);
    glEnd();

    glBegin(GL_LINES);
        glVertex3f(0.12f, 0.15f, 0.0f);
        glVertex3f(0.17f, 0.18f, 0.0f);
    glEnd();
    glBegin(GL_LINES);
        glVertex3f(0.12f, 0.15f, 0.0f);
        glVertex3f(0.17f, 0.12f, 0.0f);
    glEnd();

    HalfSmile(-1.0f, 0.1f, 0.0f);
}

void display(void)
{
    // Code
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    Smiley1(1.2f, -0.6f);
    Smiley2(0.0f, 0.0f);
    Smiley3(0.3f, 0.0f);
    Smiley4(0.6f, 0.0f);
    Smiley5(0.9f, 0.0f);
    Smiley6(1.2f, 0.0f);
    Smiley7(0.0f, -0.6f);
    Smiley8(0.3f, -0.6f);
    Smiley9(0.6f, -0.6f);
    Smiley10(0.9f, -0.6f);
    glutSwapBuffers();
}