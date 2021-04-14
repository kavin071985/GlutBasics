
#include <GL/glut.h>
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<string>
#include<math.h>

struct vertex
{
    GLdouble x, y, z;

};

static std::vector<vertex> normal;
static std::vector<vertex> vertices;
static int nl = 0, vx = 0;

void init()
{
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glEnable(GL_DEPTH_TEST);
}

float z_position = 2.0;
float angle = 60;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0, -5.0);
    //glScalef(25.0, 25.0, 25.0);
    glRotatef(angle, 1, 1, 1);

    glBegin(GL_TRIANGLES);          


    for (int n = 0,v = 0; n < nl;)
  {     
       if(n==0|| n == 4 )
        glColor3f(0.0, 1.0, 0.0);  
       else if (n == 2  || n == 6 )
           glColor3f(1.0, 0.0, 0.0);
       else if (n == 8 || n == 10  )
           glColor3f(0.0, 0.0, 1.0);

      glNormal3d(normal[n].x, normal[n].y, normal[n].z); n++;
      glVertex3d(vertices[v].x, vertices[v].y, vertices[v].z); v++;
      glVertex3d(vertices[v].x, vertices[v].y, vertices[v].z); v++;
      glVertex3d(vertices[v].x, vertices[v].y, vertices[v].z); v++;
      glNormal3d(normal[n].x, normal[n].y, normal[n].z); n++;
      glVertex3d(vertices[v].x, vertices[v].y, vertices[v].z); v++;
      glVertex3d(vertices[v].x, vertices[v].y, vertices[v].z); v++;
      glVertex3d(vertices[v].x, vertices[v].y, vertices[v].z); v++;
  }
    glEnd();


    glutSwapBuffers(); //displays 
}

void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, timer, 0);
     
    if (angle < 350)
        angle += 0.60;
}
void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, 1, 2.0, 50.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv)
{   
    std::string line, facet, norm;
    GLdouble x = 0, y = 0, z = 0;
    std::ifstream ifs("cube.stl");
    if (ifs.is_open())
        std::cout << "File is Opened" << std::endl;

    while (!ifs.eof())
    {
        getline(ifs, line);

        if (line.find("vertex") != std::string::npos)
        {
            std::istringstream is(line);
            is >> norm >> x >> y >> z;
            vertices.push_back({ x,y,z });

            ++vx;
        }
    }

    for (int i = 0; i < vertices.size(); )
    {
        GLdouble a[3] = { vertices[i + 1].x - vertices[i].x ,vertices[i + 1].y - vertices[i].y,vertices[i + 1].z - vertices[i].z };

        GLdouble b[3] = { vertices[i + 2].x - vertices[i].x ,vertices[i + 2].y - vertices[i].y,vertices[i + 2].z - vertices[i].z };

        GLdouble v[3] = { a[1] * b[2] - a[2] * b[1], -(a[0] * b[2] - a[2] * b[0]), a[0] * b[1] - a[1] * b[0] };

        GLdouble length = sqrt(v[0] * v[0] + v[1] * v[1] + v[2] * v[2]);
        for (int j = 0; j < 3; j++)
        {
            v[j] = v[j] / length;
        }
        
        normal.push_back({v[0], v[1], v[2]});
		nl++;
        i = i + 3;
		
	}

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); 

    glutInitWindowPosition(600, 100);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Window 1");

    glutDisplayFunc(display);
    init();
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();
    return 0;             
}

