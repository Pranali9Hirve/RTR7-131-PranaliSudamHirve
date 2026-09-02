#include<GL/freeglut.h>
#include<math.h>

#define VALUE_FROM_PERCENT(complete_value, percent) ((complete_value * percent) / 100)

int psh_percent = 70;

int main(int argc, char* argv[])
{
    // Function Declaration
    void initialize(void);
    void uninitialize(void);
    void display(void);
    void psh_draw_name(float, float);
    void psh_draw_A(float, float);

    // Code
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowSize(1920, 1200);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Pranali: Pranali Sudam Hirve");

    initialize();

    glutDisplayFunc(display);

    glutMainLoop();

    // Flow should not come here
    return(0);
}

void initialize(void)
{
    // Code
    glClearColor(0.88f, 0.98f, 0.99f, 1.0f);
}

void psh_draw_A(float psh_x_pos, float psh_y_pos)
{
    // A
    glBegin(GL_QUADS);

        glColor3f(0.93f, 0.89f, 0.05f);                        
        glVertex3f(VALUE_FROM_PERCENT((-0.42f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.21f + psh_y_pos), psh_percent), 0.0f);
        glVertex3f(VALUE_FROM_PERCENT((-0.33f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.21f + psh_y_pos), psh_percent), 0.0f);
        glVertex3f(VALUE_FROM_PERCENT((-0.33f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.15f + psh_y_pos), psh_percent), 0.0f);
        glVertex3f(VALUE_FROM_PERCENT((-0.42f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.15f + psh_y_pos), psh_percent), 0.0f);

    glEnd();


    glBegin(GL_QUADS);

        glColor3f(0.9f, 0.6f, 0.05f);
        glVertex3f(VALUE_FROM_PERCENT((-0.5f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.0f + psh_y_pos), psh_percent), 0.0f);
        glVertex3f(VALUE_FROM_PERCENT((-0.42f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.5f + psh_y_pos), psh_percent), 0.0f);
        glColor3f(0.93f, 0.89f, 0.05f);                        
        glVertex3f(VALUE_FROM_PERCENT((-0.33f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.5f + psh_y_pos), psh_percent), 0.0f);
        glVertex3f(VALUE_FROM_PERCENT((-0.41f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.0f + psh_y_pos), psh_percent), 0.0f);

    glEnd();

    glBegin(GL_QUADS);

        glColor3f(0.9f, 0.6f, 0.05f);
        glVertex3f(VALUE_FROM_PERCENT((-0.42f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.5f + psh_y_pos), psh_percent), 0.0f);
        glVertex3f(VALUE_FROM_PERCENT((-0.33f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.5f + psh_y_pos), psh_percent), 0.0f);

        glColor3f(0.93f, 0.89f, 0.05f);                        
        glVertex3f(VALUE_FROM_PERCENT((-0.23f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.0f + psh_y_pos), psh_percent), 0.0f);
        glVertex3f(VALUE_FROM_PERCENT((-0.32f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.0f + psh_y_pos), psh_percent), 0.0f);

    glEnd();
}

void psh_draw_name(float psh_x_pos, float psh_y_pos)
{
    // P
    glBegin(GL_QUADS);

        glColor3f(0.9f, 0.6f, 0.05f);
        glVertex3f(VALUE_FROM_PERCENT((-1.0f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.5f + psh_y_pos), psh_percent), 0.0f);
        glVertex3f(VALUE_FROM_PERCENT((-0.8f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.5f + psh_y_pos), psh_percent), 0.0f);
        glColor3f(0.93f, 0.89f, 0.05f);
        glVertex3f(VALUE_FROM_PERCENT((-0.8f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.42f + psh_y_pos), psh_percent), 0.0f);
        glVertex3f(VALUE_FROM_PERCENT((-1.0f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.42f + psh_y_pos), psh_percent), 0.0f);

    glEnd();

    glBegin(GL_QUADS);

        glColor3f(0.9f, 0.6f, 0.05f);
        glVertex3f(VALUE_FROM_PERCENT((-0.85f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.5f + psh_y_pos), psh_percent), 0.0f);
        glVertex3f(VALUE_FROM_PERCENT((-0.8f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.5f + psh_y_pos), psh_percent), 0.0f);
        glColor3f(0.93f, 0.89f, 0.05f);
        glVertex3f(VALUE_FROM_PERCENT((-0.8f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.25f + psh_y_pos), psh_percent), 0.0f);
        glVertex3f(VALUE_FROM_PERCENT((-0.85f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.25f + psh_y_pos), psh_percent), 0.0f);

    glEnd();

    glBegin(GL_QUADS);

        glColor3f(0.9f, 0.6f, 0.05f);
        glVertex3f(VALUE_FROM_PERCENT((-1.0f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.18f + psh_y_pos), psh_percent), 0.0f);
        glVertex3f(VALUE_FROM_PERCENT((-0.8f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.18f + psh_y_pos), psh_percent), 0.0f);
        glColor3f(0.93f, 0.89f, 0.05f);
        glVertex3f(VALUE_FROM_PERCENT((-0.8f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.25f + psh_y_pos), psh_percent), 0.0f);
        glVertex3f(VALUE_FROM_PERCENT((-1.0f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.25f + psh_y_pos), psh_percent), 0.0f);


    glEnd();

    glBegin(GL_QUADS);

        glColor3f(0.93f, 0.89f, 0.05f);
        glVertex3f(VALUE_FROM_PERCENT((-0.95f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.5f + psh_y_pos), psh_percent), 0.0f);
        glVertex3f(VALUE_FROM_PERCENT((-0.95f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.0f + psh_y_pos), psh_percent), 0.0f);
        glColor3f(0.9f, 0.6f, 0.05f);
        glVertex3f(VALUE_FROM_PERCENT((-1.0f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.0f + psh_y_pos), psh_percent), 0.0f);
        glVertex3f(VALUE_FROM_PERCENT((-1.0f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.5f + psh_y_pos), psh_percent), 0.0f);
    
    glEnd();


    // R
    glBegin(GL_QUADS);
    
        glColor3f(0.9f, 0.6f, 0.05f);
        glVertex3f(VALUE_FROM_PERCENT((-0.75f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.5f + psh_y_pos), psh_percent), 0.0f);
        glVertex3f(VALUE_FROM_PERCENT((-0.55f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.5f + psh_y_pos), psh_percent), 0.0f);
        glColor3f(0.93f, 0.89f, 0.05f);        
        glVertex3f(VALUE_FROM_PERCENT((-0.55f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.42f + psh_y_pos), psh_percent), 0.0f);
        glVertex3f(VALUE_FROM_PERCENT((-0.75f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.42f + psh_y_pos), psh_percent), 0.0f);

    glEnd();

    glBegin(GL_QUADS);

        glColor3f(0.9f, 0.6f, 0.05f);
        glVertex3f(VALUE_FROM_PERCENT((-0.61f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.5f + psh_y_pos), psh_percent), 0.0f);
        glVertex3f(VALUE_FROM_PERCENT((-0.55f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.5f + psh_y_pos), psh_percent), 0.0f);
        glColor3f(0.93f, 0.89f, 0.05f);        
        glVertex3f(VALUE_FROM_PERCENT((-0.55f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.25f + psh_y_pos), psh_percent), 0.0f);
        glVertex3f(VALUE_FROM_PERCENT((-0.61f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.25f + psh_y_pos), psh_percent), 0.0f);

    glEnd();

    glBegin(GL_QUADS);

        glColor3f(0.93f, 0.89f, 0.05f);                
        glVertex3f(VALUE_FROM_PERCENT((-0.67f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.28f + psh_y_pos), psh_percent), 0.0f);
        glVertex3f(VALUE_FROM_PERCENT((-0.58f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.0f + psh_y_pos), psh_percent), 0.0f);
        glVertex3f(VALUE_FROM_PERCENT((-0.63f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.0f + psh_y_pos), psh_percent), 0.0f);
        glVertex3f(VALUE_FROM_PERCENT((-0.71f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.24f + psh_y_pos), psh_percent), 0.0f);
    
    glEnd();

    glBegin(GL_QUADS);

        glColor3f(0.9f, 0.6f, 0.05f);    
        glVertex3f(VALUE_FROM_PERCENT((-0.75f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.32f + psh_y_pos), psh_percent), 0.0f);
        glVertex3f(VALUE_FROM_PERCENT((-0.55f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.32f + psh_y_pos), psh_percent), 0.0f);
        glColor3f(0.93f, 0.89f, 0.05f);    
        glVertex3f(VALUE_FROM_PERCENT((-0.55f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.23f + psh_y_pos), psh_percent), 0.0f);
        glVertex3f(VALUE_FROM_PERCENT((-0.75f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.23f + psh_y_pos), psh_percent), 0.0f);

    glEnd();


    glBegin(GL_QUADS);
        glColor3f(0.93f, 0.89f, 0.05f);
        glVertex3f(VALUE_FROM_PERCENT((-0.7f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.5f + psh_y_pos), psh_percent), 0.0f);
        glVertex3f(VALUE_FROM_PERCENT((-0.7f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.0f + psh_y_pos), psh_percent), 0.0f);
        glColor3f(0.9f, 0.6f, 0.05f);                
        glVertex3f(VALUE_FROM_PERCENT((-0.75f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.0f + psh_y_pos), psh_percent), 0.0f);
        glVertex3f(VALUE_FROM_PERCENT((-0.75f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.5f + psh_y_pos), psh_percent), 0.0f);
    
    glEnd();


    // A

    psh_draw_A(psh_x_pos, psh_y_pos);

    
    // N

    glBegin(GL_QUADS);

        glColor3f(0.9f, 0.6f, 0.05f);
        glVertex3f(VALUE_FROM_PERCENT((-0.2f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.5f + psh_y_pos), psh_percent), 0.0f);
        glVertex3f(VALUE_FROM_PERCENT((-0.13f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.5f + psh_y_pos), psh_percent), 0.0f);
        glColor3f(0.93f, 0.89f, 0.05f);                        
        glVertex3f(VALUE_FROM_PERCENT((0.05f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.0f + psh_y_pos), psh_percent), 0.0f);
        glVertex3f(VALUE_FROM_PERCENT((-0.02f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.0f + psh_y_pos), psh_percent), 0.0f);

    glEnd();

    glBegin(GL_QUADS);

        glColor3f(0.9f, 0.6f, 0.05f);
        glVertex3f(VALUE_FROM_PERCENT((-0.2f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.0f + psh_y_pos), psh_percent), 0.0f);
        glVertex3f(VALUE_FROM_PERCENT((-0.2f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.5f + psh_y_pos), psh_percent), 0.0f);
        glColor3f(0.93f, 0.89f, 0.05f);                        
        glVertex3f(VALUE_FROM_PERCENT((-0.13f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.5f + psh_y_pos), psh_percent), 0.0f);
        glVertex3f(VALUE_FROM_PERCENT((-0.13f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.0f + psh_y_pos), psh_percent), 0.0f);

    glEnd();

    glBegin(GL_QUADS);

        glColor3f(0.9f, 0.6f, 0.05f);
        glVertex3f(VALUE_FROM_PERCENT((-0.02f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.0f + psh_y_pos), psh_percent), 0.0f);
        glVertex3f(VALUE_FROM_PERCENT((-0.02f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.5f + psh_y_pos), psh_percent), 0.0f);
        glColor3f(0.93f, 0.89f, 0.05f);                        
        glVertex3f(VALUE_FROM_PERCENT((0.05f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.5f + psh_y_pos), psh_percent), 0.0f);
        glVertex3f(VALUE_FROM_PERCENT((0.05f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.0f + psh_y_pos), psh_percent), 0.0f);

    glEnd();

    // A

    psh_draw_A(psh_x_pos + 0.58f, psh_y_pos);
   
    // L
    glBegin(GL_QUADS);

        glColor3f(0.9f, 0.6f, 0.05f);
        glVertex3f(VALUE_FROM_PERCENT((0.4f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.0f + psh_y_pos), psh_percent), 0.0f);
        glVertex3f(VALUE_FROM_PERCENT((0.4f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.5f + psh_y_pos), psh_percent), 0.0f);
        glColor3f(0.93f, 0.89f, 0.05f);                                
        glVertex3f(VALUE_FROM_PERCENT((0.47f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.5f + psh_y_pos), psh_percent), 0.0f);
        glVertex3f(VALUE_FROM_PERCENT((0.47f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.0f + psh_y_pos), psh_percent), 0.0f);

    glEnd();

    glBegin(GL_QUADS);

        glColor3f(0.93f, 0.89f, 0.05f);                                
        glVertex3f(VALUE_FROM_PERCENT((0.47f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.0f + psh_y_pos), psh_percent), 0.0f);
        glVertex3f(VALUE_FROM_PERCENT((0.47f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.12f + psh_y_pos), psh_percent), 0.0f);
        glVertex3f(VALUE_FROM_PERCENT((0.6f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.12f + psh_y_pos), psh_percent), 0.0f);
        glVertex3f(VALUE_FROM_PERCENT((0.6f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.0f + psh_y_pos), psh_percent), 0.0f);

    glEnd();


    // I
    glBegin(GL_QUADS);

        glColor3f(0.9f, 0.6f, 0.05f);
        glVertex3f(VALUE_FROM_PERCENT((0.65f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.0f + psh_y_pos), psh_percent), 0.0f);
        glVertex3f(VALUE_FROM_PERCENT((0.65f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.5f + psh_y_pos), psh_percent), 0.0f);
        glColor3f(0.93f, 0.89f, 0.05f);                                
        glVertex3f(VALUE_FROM_PERCENT((0.72f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.5f + psh_y_pos), psh_percent), 0.0f);
        glVertex3f(VALUE_FROM_PERCENT((0.72f + psh_x_pos), psh_percent), VALUE_FROM_PERCENT((0.0f + psh_y_pos), psh_percent), 0.0f);

    glEnd();
    
}

void display(void)
{
    // Code
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    psh_draw_name(0.0f, 0.0f);

    glutSwapBuffers();
}