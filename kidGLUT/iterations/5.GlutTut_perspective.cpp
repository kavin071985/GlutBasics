
#include <GL/glut.h>

void init()
{
    glClearColor(0.0,0.0,0.0,1.0);
    glColor3f(1.0, 0.0, 0.0);
}

float z_position = 2.0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT); //screen color to black 
    glLoadIdentity(); //resets matrix- rotations,scale
    glTranslatef(0.0,0.0,-z_position);
    
     //draw points

    
    glBegin(GL_QUADS);          //anitclock wise is frontside
    
    glVertex3f(-1.0,1.0,0.0);   
    glVertex3f(-1.0, -1.0,0.0);
    glVertex3f(1.0, -1.0,0.0);
    glVertex3f(1.0, 1.0,0.0);
    glEnd();
    
    glutSwapBuffers(); //displays 
}

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000 / 6, timer, 0);
   if (z_position<50)
     z_position += 0.60; 
}
void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60,1,2.0,50.0);
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

