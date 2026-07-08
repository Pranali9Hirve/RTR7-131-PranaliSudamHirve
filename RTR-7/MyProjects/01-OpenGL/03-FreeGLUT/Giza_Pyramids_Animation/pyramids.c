#include<GL/freeglut.h>
#include<math.h>

float yPosition = 0.1f;
int main(int argc, char* argv[])
{
    // Function Declaration
    void initialize(void);
    void uninitialize(void);
    void display(void);
    void drawQuads(void);
    void drawPyramid(void);
    void drawSun(void);
    void drawTree(void);
    void drawBirds(void);
    void drawStars(void);

    // Code
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowSize(1920, 1200);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("The Pyramids of Giza: Pranali Sudam Hirve");

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

void drawQuads(void)
{
    // Quad1
    glBegin(GL_QUADS);

    if (yPosition <= 0.3f) 
    {
        glColor3f(0.0f, 0.51f, 1.0f);
    }
    else 
    {
        glColor3f(0.0f, 0.0f, 0.0f);
    }
    glVertex3f(-1.0f, 1.0f, 0.0f);

    if (yPosition <= 0.4f) 
    {
        glColor3f(0.2f, 0.6f, 1.0f);
    }
    else 
    {
        glColor3f(0.12f, 0.12f, 0.12f);
    }
    glVertex3f(-1.0f, 0.8f, 0.0f);

    if (yPosition <= 0.4f) 
    {
        glColor3f(0.2f, 0.6f, 1.0f);
    }
    else 
    {
        glColor3f(0.12f, 0.12f, 0.12f);
    }
    glVertex3f(1.0f, 0.8f, 0.0f);

    if (yPosition <= 0.3f) 
    {
        glColor3f(0.0f, 0.51f, 1.0f);
    }
    else 
    {
        glColor3f(0.0f, 0.0f, 0.0f);
    }
    glVertex3f(1.0f, 1.0f, 0.0f);
    
    glEnd();

    // Quad2
    glBegin(GL_QUADS);

    
    if (yPosition <= 0.4f) 
    {
        glColor3f(0.2f, 0.6f, 1.0f);
    }
    else 
    {
        glColor3f(0.12f, 0.12f, 0.12f);
    }
    glVertex3f(-1.0f, 0.8f, 0.0f);

    if (yPosition <= 0.5f) 
    {
        glColor3f(0.4f, 0.7f, 1.0f);
    }
    else 
    {
        glColor3f(0.2f, 0.2f, 0.2f);
    }
    glVertex3f(-1.0f, 0.4f, 0.0f);

    if (yPosition <= 0.5f) 
    {
        glColor3f(0.4f, 0.7f, 1.0f);
    }
    else 
    {
        glColor3f(0.2f, 0.2f, 0.2f);
    }
    glVertex3f(1.0f, 0.4f, 0.0f);

    if (yPosition <= 0.4f) 
    {
        glColor3f(0.2f, 0.6f, 1.0f);
    }
    else 
    {
        glColor3f(0.12f, 0.12f, 0.12f);
    }
    glVertex3f(1.0f, 0.8f, 0.0f);
    
    glEnd();

    // Quad3
    glBegin(GL_QUADS);

    if (yPosition <= 0.5f) 
    {
        glColor3f(0.4f, 0.7f, 1.0f);
    }
    else 
    {
        glColor3f(0.2f, 0.2f, 0.2f);
    }
    glVertex3f(-1.0f, 0.4f, 0.0f);

    if (yPosition <= 0.5f) 
    {
        glColor3f(0.6f, 0.8f, 1.0f);
    }
    else 
    {
        glColor3f(0.3f, 0.3f, 0.3f);
    }
    glVertex3f(-1.0f, 0.1f, 0.0f);

    if (yPosition <= 0.5f) 
    {
        glColor3f(0.6f, 0.8f, 1.0f);
    }
    else 
    {
        glColor3f(0.3f, 0.3f, 0.3f);
    }    
    glVertex3f(1.0f, 0.1f, 0.0f);

    if (yPosition <= 0.5f) 
    {
        glColor3f(0.4f, 0.7f, 1.0f);
    }
    else 
    {
        glColor3f(0.2f, 0.2f, 0.2f);
    }
    glVertex3f(1.0f, 0.4f, 0.0f);
    
    glEnd();

    // Quad4
    glBegin(GL_QUADS);

    glColor3f(0.36f, 0.22f, 0.22f);
    glVertex3f(-1.0f, 0.1f, 0.0f);

    glColor3f(0.43f, 0.25f, 0.25f);
    glVertex3f(-1.0f, 0.0f, 0.0f);

    glColor3f(0.43f, 0.25f, 0.25f);
    glVertex3f(1.0f, 0.0f, 0.0f);

    glColor3f(0.36f, 0.22f, 0.22f);
    glVertex3f(1.0f, 0.1f, 0.0f);
    
    glEnd();

    // Quad5
    glBegin(GL_QUADS);

    glColor3f(0.43f, 0.25f, 0.25f);
    glVertex3f(-1.0f, 0.0f, 0.0f);

    glColor3f(0.5f, 0.31f, 0.31f);
    glVertex3f(-1.0f, -0.4f, 0.0f);

    glColor3f(0.5f, 0.31f, 0.31f);
    glVertex3f(1.0f, -0.4f, 0.0f);

    glColor3f(0.43f, 0.25f, 0.25f);
    glVertex3f(1.0f, 0.0f, 0.0f);
    
    glEnd();

    // Quad6
    glBegin(GL_QUADS);

    glColor3f(0.5f, 0.31f, 0.31f);
    glVertex3f(-1.0f, -0.4f, 0.0f);

    glColor3f(0.54f, 0.33f, 0.33f);
    glVertex3f(-1.0f, -0.7f, 0.0f);

    glColor3f(0.54f, 0.33f, 0.33f);
    glVertex3f(1.0f, -0.7f, 0.0f);

    glColor3f(0.5f, 0.31f, 0.31f);
    glVertex3f(1.0f, -0.4f, 0.0f);
    
    glEnd();

    // Quad7
    glBegin(GL_QUADS);

    glColor3f(0.54f, 0.33f, 0.33f);
    glVertex3f(-1.0f, -0.7f, 0.0f);

    glColor3f(0.6f, 0.39f, 0.39f);
    glVertex3f(-1.0f, -1.0f, 0.0f);

    glColor3f(0.6f, 0.39f, 0.39f);
    glVertex3f(1.0f, -1.0f, 0.0f);

    glColor3f(0.54f, 0.33f, 0.33f);
    glVertex3f(1.0f, -0.7f, 0.0f);
    
    glEnd();
}

void drawSun(void)
{
    glBegin(GL_TRIANGLE_FAN);

    glColor3f(1.0f, 0.8f, 0.2f);
    glVertex3f(0.2f, 0.7f-yPosition, 0.0f);

    for (int i = 0; i <= 360; i++) {
        float theta = 2.0f * 3.1416 * i / 360;
        float x =0.2f +  0.10 * (float)cos(theta);
        float y =0.7f + 0.15 * (float)sin(theta);
        glVertex2f(x, y-yPosition);
    }
    
    glEnd();
}

void drawPyramid(void)
{
    // pyramid 1
    glBegin(GL_TRIANGLES);
    glColor3f(0.25f, 0.13f, 0.13f);
    glVertex3f(-0.9f, 0.05f, 0.0f);

    glVertex3f(-0.75f, 0.0f, 0.0f);

    glVertex3f(-0.5f, 0.5f, 0.0f);

    glEnd();

    // pyramid 1
    glBegin(GL_TRIANGLES);
    glColor3f(0.4f, 0.2f, 0.0f);
    glVertex3f(-0.75f, 0.0f, 0.0f);

    if (yPosition <= 0.5f) 
    {
        glColor3f(0.6f, 0.3f, 0.0f);
    }
    else 
    {
        glColor3f(0.45f, 0.19f, 0.16f);
    }
    glVertex3f(-0.25f, 0.0f, 0.0f);

    if (yPosition <= 0.5f) 
    {
        glColor3f(0.4f, 0.2f, 0.0f);
    }
    else 
    {
        glColor3f(0.45f, 0.19f, 0.16f);
    }
    glVertex3f(-0.5f, 0.5f, 0.0f);

    glEnd();

    // pyramid 2
    glBegin(GL_TRIANGLES);
    glColor3f(0.25f, 0.13f, 0.13f);
    glVertex3f(-0.4f, 0.3f, 0.0f);

    glVertex3f(-0.3f, 0.1f, 0.0f);

    glVertex3f(0.1f, 0.7f, 0.0f);

    glEnd();

    // pyramid 2
    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.2f, 0.0f);
    glVertex3f(-0.3f, 0.1f, 0.0f);

    glColor3f(0.4f, 0.2f, 0.0f);
    glVertex3f(-0.25f, 0.0f, 0.0f);

    if (yPosition <= 0.5f) 
    {
        glColor3f(0.6f, 0.3f, 0.0f);
    }
    else 
    {
        glColor3f(0.45f, 0.19f, 0.16f);
    }
    glVertex3f(0.5f, 0.0f, 0.0f);

    if (yPosition <= 0.5f) 
    {
        glColor3f(0.6f, 0.3f, 0.0f);
    }
    else 
    {
        glColor3f(0.45f, 0.19f, 0.16f);
    }
    glVertex3f(0.1f, 0.7f, 0.0f);

    glEnd();

    // pyramid 3
    glBegin(GL_TRIANGLES);
    glColor3f(0.25f, 0.13f, 0.13f);
    glVertex3f(0.38f, 0.2f, 0.0f);

    glVertex3f(0.44f, 0.1f, 0.0f);

    glVertex3f(0.7f, 0.5f, 0.0f);

    glEnd();

    // pyramid 3
    glBegin(GL_QUADS);
    glColor3f(0.4f, 0.2f, 0.0f);
    glVertex3f(0.44f, 0.1f, 0.0f);

    glColor3f(0.4f, 0.2f, 0.0f);
    glVertex3f(0.5f, 0.0f, 0.0f);

    glColor3f(0.4f, 0.2f, 0.0f);
    glVertex3f(1.0f, 0.0f, 0.0f);

    if (yPosition <= 0.5f) 
    {
        glColor3f(0.6f, 0.3f, 0.0f);
    }
    else 
    {
        glColor3f(0.45f, 0.19f, 0.16f);
    }
    glVertex3f(0.7f, 0.5f, 0.0f);

    glEnd();
}

void drawTree(void)
{
    if (yPosition <= 0.5f) 
    {
        glColor3f(0.11f, 0.3f, 0.05f);
    }
    else 
    {
        glColor3f(0.0f, 0.0f, 0.0f);
    }

    // Stem
    glLineWidth(12.0f);
    glBegin(GL_LINES);

    glVertex2f(0.5f, -0.7f);
    glVertex2f(0.5f, -1.0f);

    glEnd();

    // Branches
    glLineWidth(10.0f);
    glBegin(GL_LINES);

    glVertex2f(0.5f, -0.75f);
    glVertex2f(0.53f, -0.65f);

    glVertex2f(0.5f, -0.8f);
    glVertex2f(0.43f, -0.7f);

    glEnd();

    // Stem
    glLineWidth(12.0f);
    glBegin(GL_LINES);

    glVertex2f(0.8f, -0.7f);
    glVertex2f(0.8f, -1.0f);

    glEnd();

    // Branches
    glLineWidth(10.0f);
    glBegin(GL_LINES);

    glVertex2f(0.8f, -0.8f);
    glVertex2f(0.90f, -0.70f);

    glVertex2f(0.8f, -0.9f);
    glVertex2f(0.7f, -0.8f);

    glEnd();


    // Stem
    glLineWidth(12.0f);
    glBegin(GL_LINES);

    glVertex2f(-0.8f, -0.7f);
    glVertex2f(-0.8f, -1.0f);

    glEnd();

    // Branches
    glLineWidth(10.0f);
    glBegin(GL_LINES);

    glVertex2f(-0.8f, -0.8f);
    glVertex2f(-0.90f, -0.70f);

    glVertex2f(-0.8f, -0.9f);
    glVertex2f(-0.7f, -0.8f);

    glEnd();

}

void drawBirds(void)
{
    glColor3f(0.0f, 0.0f, 0.0f);

    glLineWidth(2.0f);

    // Bird 1
    glBegin(GL_LINE_STRIP);
    glVertex2f(0.45f, 0.78f);
    glVertex2f(0.50f, 0.82f);
    glVertex2f(0.55f, 0.78f);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(0.55f, 0.78f);
    glVertex2f(0.60f, 0.82f);
    glVertex2f(0.65f, 0.78f);
    glEnd();

    // Bird 2
    glBegin(GL_LINE_STRIP);
    glVertex2f(0.60f, 0.65f);
    glVertex2f(0.64f, 0.69f);
    glVertex2f(0.68f, 0.65f);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(0.68f, 0.65f);
    glVertex2f(0.72f, 0.69f);
    glVertex2f(0.76f, 0.65f);
    glEnd();

    // Bird 3
    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.65f, 0.67f);
    glVertex2f(-0.6f, 0.7f);
    glVertex2f(-0.55f, 0.67f);
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(-0.55f, 0.67f);
    glVertex2f(-0.5f, 0.7f);
    glVertex2f(-0.45f, 0.67f);
    glEnd();
}

void drawStars(void)
{
    glPointSize(3.0f);
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_POINTS);

    glVertex2f(0.8f, 0.6f);
   
    glVertex2f(-0.7f, 0.8f);

    glVertex2f(-0.5f, 0.6f);

    glVertex2f(-0.9f, 0.7f);
    glVertex2f(-0.6f, 0.8f);
    glVertex2f(0.3f, 0.8f);
    glVertex2f(0.9f, 0.9f);
    glVertex2f(0.7f, 0.7f);
    glVertex2f(-0.2f, 0.7f);
    glVertex2f(-0.7f, 0.5f);

    glEnd();

    glPointSize(1.5f);
    glColor3f(1.0f, 1.0f, 1.0f);

    glBegin(GL_POINTS);

    glVertex2f(0.9f, 0.3f);
   
    glVertex2f(0.4f, 0.4f);

    glVertex2f(-0.2f, 0.5f);

    glVertex2f(-0.9f, 0.2f);
    

    glEnd();
}

void display(void)
{
    // Code
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    if (yPosition <= 0.5f)
    {
        yPosition = yPosition + 0.00002f;
    }
    drawQuads();
    drawSun();
    drawPyramid();
    drawTree();
    if (yPosition < 0.5f)
    {
        drawBirds();
    }
    else
    {
        drawStars();
    }
    glutSwapBuffers();
    glutPostRedisplay();
}