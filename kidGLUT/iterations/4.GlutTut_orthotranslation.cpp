
#include <GL/glut.h>

void init()
{
    glClearColor(0.0,0.0,0.0,1.0);
    glColor3f(1.0, 0.0, 0.0);
}

float x_position = -10.0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT); //screen color to black 
    glLoadIdentity(); //resets matrix- rotations,scale
    glTranslatef(x_position,0.0,0.0);
    
     //draw points

    glPointSize(10.0);
    glBegin(GL_QUADS);          //anitclock wise is fronside
    glColor3f(1.0, 0.0, 0.0);   //smooth shading
    glVertex2f(-1.0,1.0);   
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(-1.0, -1.0);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(1, -1.0);
    glColor3f(0.5, 0.5, 1.0);
    glVertex2f(1, 1.0);
    glEnd();
    
    glutSwapBuffers(); //displays 
}

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer, 0);
   if (x_position<8)
     x_position += 0.15; 
}
void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10,10,-10,10);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); //front displayed buffer, hidden back buffer

    glutInitWindowPosition(600,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("Window 1");
   
    glutDisplayFunc(display);
    init();
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer,0);
    glutMainLoop();
    return 0;             /* ANSI C requires main to return int. */
}

