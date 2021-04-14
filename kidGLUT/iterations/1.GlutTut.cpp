
#include <GL/glut.h>

void init()
{
    glClearColor(1.0,1.0,0.0,1.0);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT); //screen color to black 
    glLoadIdentity();               //resets matrix- rotations,scale
     //draw points
    glPointSize(10.0);
    glBegin(GL_POINTS);

    glVertex2f(5, 5);
    glVertex2f(-5, -5);
    glEnd();

    glFlush(); //displays 
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
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(200,100);
    glutInitWindowSize(500,500);
    glutCreateWindow("Window 1");
   
    glutDisplayFunc(display);
    //init();
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;             /* ANSI C requires main to return int. */
}

