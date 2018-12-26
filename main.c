#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

static int width, height;

void on_reshape(int width, int height);
void on_display();
void axis(int len);

int main (int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 80);
    glutInitWindowSize(600, 600);
    glutCreateWindow(argv[0] + 2);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    
    glClearColor(0, 0, 0, 1);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    
    glutReshapeFunc(on_reshape);
    glutDisplayFunc(on_display);
    
    glutMainLoop();
    return 0;
}

void on_reshape(int w, int h)
{
    width = w;
    height = h;
    glViewport(0, 0, width, height);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60, (float) width / height, 1, 10);
}

void on_display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
    
    axis(10);
    
    glutSwapBuffers();
}

void axis(int len)
{
    glDisable(GL_LIGHTING);
    glBegin(GL_LINES);
        glColor3f(1, 0, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(len, 0, 0);
        
        glColor3f(0, 1, 0);
        glVertex3f(0, 0, 0);
        glVertex3f(0, len, 0);
        
        glColor3f(0, 0, 1);
        glVertex3f(0, 0, 0);
        glVertex3f(0, 0, len);
    glEnd(); 
    glEnable(GL_LIGHTING);
}








