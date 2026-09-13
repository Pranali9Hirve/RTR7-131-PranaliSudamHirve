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
    glutCreateWindow("Pranali Hirve: RTR7-131-PranaliSudamHirve/RTR-7/MyProjects/01-OpenGL/03-FreeGLUT/05-DrawName/02-UsingLines");

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
    // A using GL_LINES
    glLineWidth(10.0f);
    glBegin(GL_LINES);

        // Left diagonal of A
        glColor3f(1.0f, 0.0f, 1.0f);

        glVertex3f(VALUE_FROM_PERCENT((-0.50f + psh_x_pos), psh_percent),
                   VALUE_FROM_PERCENT((0.0f + psh_y_pos), psh_percent),
                   0.0f);

        glVertex3f(VALUE_FROM_PERCENT((-0.42f + psh_x_pos), psh_percent),
                   VALUE_FROM_PERCENT((0.5f + psh_y_pos), psh_percent),
                   0.0f);


        // Right diagonal of A
        glColor3f(1.0f, 0.0f, 1.0f);

        glVertex3f(VALUE_FROM_PERCENT((-0.33f + psh_x_pos), psh_percent),
                   VALUE_FROM_PERCENT((0.5f + psh_y_pos), psh_percent),
                   0.0f);

        glVertex3f(VALUE_FROM_PERCENT((-0.23f + psh_x_pos), psh_percent),
                   VALUE_FROM_PERCENT((0.0f + psh_y_pos), psh_percent),
                   0.0f);


        // A - Crossbar
        glColor3f(1.0f, 0.0f, 1.0f);

        glVertex3f(VALUE_FROM_PERCENT((-0.42f + psh_x_pos), psh_percent),
                   VALUE_FROM_PERCENT((0.21f + psh_y_pos), psh_percent),
                   0.0f);

        glVertex3f(VALUE_FROM_PERCENT((-0.33f + psh_x_pos), psh_percent),
                   VALUE_FROM_PERCENT((0.21f + psh_y_pos), psh_percent),
                   0.0f);


        // A - Top connection
        glColor3f(1.0f, 0.0f, 1.0f);

        glVertex3f(VALUE_FROM_PERCENT((-0.42f + psh_x_pos), psh_percent),
                   VALUE_FROM_PERCENT((0.5f + psh_y_pos), psh_percent),
                   0.0f);

        glVertex3f(VALUE_FROM_PERCENT((-0.33f + psh_x_pos), psh_percent),
                   VALUE_FROM_PERCENT((0.5f + psh_y_pos), psh_percent),
                   0.0f);

    glEnd();
}

void psh_draw_name(float psh_x_pos, float psh_y_pos)
{
     glLineWidth(10.0f);
    // P using GL_LINES

    glBegin(GL_LINES);

        // P - Left vertical stroke
        glColor3f(1.0f, 0.0f, 1.0f);

        glVertex3f(VALUE_FROM_PERCENT((-1.0f + psh_x_pos), psh_percent),
                   VALUE_FROM_PERCENT((0.5f + psh_y_pos), psh_percent),
                   0.0f);

        glVertex3f(VALUE_FROM_PERCENT((-1.0f + psh_x_pos), psh_percent),
                   VALUE_FROM_PERCENT((0.0f + psh_y_pos), psh_percent),
                   0.0f);


        // P - Top horizontal stroke
        glColor3f(1.0f, 0.0f, 1.0f);

        glVertex3f(VALUE_FROM_PERCENT((-1.0f + psh_x_pos), psh_percent),
                   VALUE_FROM_PERCENT((0.5f + psh_y_pos), psh_percent),
                   0.0f);

        glVertex3f(VALUE_FROM_PERCENT((-0.8f + psh_x_pos), psh_percent),
                   VALUE_FROM_PERCENT((0.5f + psh_y_pos), psh_percent),
                   0.0f);


        // P - Right upper vertical stroke
        glColor3f(1.0f, 0.0f, 1.0f);

        glVertex3f(VALUE_FROM_PERCENT((-0.8f + psh_x_pos), psh_percent),
                   VALUE_FROM_PERCENT((0.5f + psh_y_pos), psh_percent),
                   0.0f);

        glVertex3f(VALUE_FROM_PERCENT((-0.8f + psh_x_pos), psh_percent),
                   VALUE_FROM_PERCENT((0.25f + psh_y_pos), psh_percent),
                   0.0f);


        // P - Middle horizontal stroke
        glColor3f(1.0f, 0.0f, 1.0f);

        glVertex3f(VALUE_FROM_PERCENT((-1.0f + psh_x_pos), psh_percent),
                   VALUE_FROM_PERCENT((0.25f + psh_y_pos), psh_percent),
                   0.0f);

        glVertex3f(VALUE_FROM_PERCENT((-0.8f + psh_x_pos), psh_percent),
                   VALUE_FROM_PERCENT((0.25f + psh_y_pos), psh_percent),
                   0.0f);

    glEnd();


   
    // R using GL_LINES

    glBegin(GL_LINES);

        // R - Left vertical stroke
        glColor3f(1.0f, 0.0f, 1.0f);

        glVertex3f(VALUE_FROM_PERCENT((-0.75f + psh_x_pos), psh_percent),
                   VALUE_FROM_PERCENT((0.5f + psh_y_pos), psh_percent),
                   0.0f);

        glVertex3f(VALUE_FROM_PERCENT((-0.75f + psh_x_pos), psh_percent),
                   VALUE_FROM_PERCENT((0.0f + psh_y_pos), psh_percent),
                   0.0f);


        // R - Top horizontal stroke
        glColor3f(1.0f, 0.0f, 1.0f);

        glVertex3f(VALUE_FROM_PERCENT((-0.75f + psh_x_pos), psh_percent),
                   VALUE_FROM_PERCENT((0.5f + psh_y_pos), psh_percent),
                   0.0f);

        glVertex3f(VALUE_FROM_PERCENT((-0.55f + psh_x_pos), psh_percent),
                   VALUE_FROM_PERCENT((0.5f + psh_y_pos), psh_percent),
                   0.0f);


        // R - Upper-right vertical stroke
        glColor3f(1.0f, 0.0f, 1.0f);

        glVertex3f(VALUE_FROM_PERCENT((-0.55f + psh_x_pos), psh_percent),
                   VALUE_FROM_PERCENT((0.5f + psh_y_pos), psh_percent),
                   0.0f);

        glVertex3f(VALUE_FROM_PERCENT((-0.55f + psh_x_pos), psh_percent),
                   VALUE_FROM_PERCENT((0.32f + psh_y_pos), psh_percent),
                   0.0f);


        // R - Middle horizontal stroke
        glColor3f(1.0f, 0.0f, 1.0f);

        glVertex3f(VALUE_FROM_PERCENT((-0.75f + psh_x_pos), psh_percent),
                   VALUE_FROM_PERCENT((0.32f + psh_y_pos), psh_percent),
                   0.0f);

        glVertex3f(VALUE_FROM_PERCENT((-0.55f + psh_x_pos), psh_percent),
                   VALUE_FROM_PERCENT((0.32f + psh_y_pos), psh_percent),
                   0.0f);


        // R - Diagonal leg
        glColor3f(1.0f, 0.0f, 1.0f);

        glVertex3f(VALUE_FROM_PERCENT((-0.67f + psh_x_pos), psh_percent),
                   VALUE_FROM_PERCENT((0.3f + psh_y_pos), psh_percent),
                   0.0f);

        glVertex3f(VALUE_FROM_PERCENT((-0.58f + psh_x_pos), psh_percent),
                   VALUE_FROM_PERCENT((0.0f + psh_y_pos), psh_percent),
                   0.0f);

    glEnd();


    // A

    psh_draw_A(psh_x_pos, psh_y_pos);

    
    // N using GL_LINES
    glBegin(GL_LINES);

        // N - Left vertical stroke
        glColor3f(1.0f, 0.0f, 1.0f);

        glVertex3f(VALUE_FROM_PERCENT((-0.2f + psh_x_pos), psh_percent),
                   VALUE_FROM_PERCENT((0.0f + psh_y_pos), psh_percent),
                   0.0f);

        glVertex3f(VALUE_FROM_PERCENT((-0.2f + psh_x_pos), psh_percent),
                   VALUE_FROM_PERCENT((0.5f + psh_y_pos), psh_percent),
                   0.0f);


        // N - Diagonal stroke
        glColor3f(1.0f, 0.0f, 1.0f);

        glVertex3f(VALUE_FROM_PERCENT((-0.2f + psh_x_pos), psh_percent),
                   VALUE_FROM_PERCENT((0.5f + psh_y_pos), psh_percent),
                   0.0f);

        glVertex3f(VALUE_FROM_PERCENT((0.05f + psh_x_pos), psh_percent),
                   VALUE_FROM_PERCENT((0.0f + psh_y_pos), psh_percent),
                   0.0f);


        // N - Right vertical stroke
        glColor3f(1.0f, 0.0f, 1.0f);

        glVertex3f(VALUE_FROM_PERCENT((0.05f + psh_x_pos), psh_percent),
                   VALUE_FROM_PERCENT((0.0f + psh_y_pos), psh_percent),
                   0.0f);

        glVertex3f(VALUE_FROM_PERCENT((0.05f + psh_x_pos), psh_percent),
                   VALUE_FROM_PERCENT((0.5f + psh_y_pos), psh_percent),
                   0.0f);

    glEnd();


    // A

    psh_draw_A(psh_x_pos + 0.58f, psh_y_pos);
   
    
    // L using GL_LINES

    glBegin(GL_LINES);

        // L - Vertical stroke
        glColor3f(1.0f, 0.0f, 1.0f);

        glVertex3f(VALUE_FROM_PERCENT((0.4f + psh_x_pos), psh_percent),
                   VALUE_FROM_PERCENT((0.5f + psh_y_pos), psh_percent),
                   0.0f);

        glVertex3f(VALUE_FROM_PERCENT((0.4f + psh_x_pos), psh_percent),
                   VALUE_FROM_PERCENT((0.0f + psh_y_pos), psh_percent),
                   0.0f);


        // L - Bottom horizontal stroke
        glColor3f(1.0f, 0.0f, 1.0f);

        glVertex3f(VALUE_FROM_PERCENT((0.4f + psh_x_pos), psh_percent),
                   VALUE_FROM_PERCENT((0.0f + psh_y_pos), psh_percent),
                   0.0f);

        glVertex3f(VALUE_FROM_PERCENT((0.6f + psh_x_pos), psh_percent),
                   VALUE_FROM_PERCENT((0.0f + psh_y_pos), psh_percent),
                   0.0f);

    glEnd();

    // I using GL_LINES

    glBegin(GL_LINES);

        // I - Vertical stroke
        glColor3f(1.0f, 0.0f, 1.0f);

        glVertex3f(VALUE_FROM_PERCENT((0.65f + psh_x_pos), psh_percent),
                   VALUE_FROM_PERCENT((0.0f + psh_y_pos), psh_percent),
                   0.0f);

        glVertex3f(VALUE_FROM_PERCENT((0.65f + psh_x_pos), psh_percent),
                   VALUE_FROM_PERCENT((0.5f + psh_y_pos), psh_percent),
                   0.0f);

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
