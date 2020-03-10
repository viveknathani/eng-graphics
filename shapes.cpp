#include<iostream>
#include "shapes.h"
#include<GL/glut.h>
#include<string.h>
#include<math.h>
#define pi 3.142857

using namespace std;

void Rectangle::screenSetup(int argc, char** argv)
{
  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  glutInitWindowSize(window_width, window_height);

  glutCreateWindow("Rectangle");

  glClearColor(0.0, 0.0, 0.0, 1.0);

  glColor3f(0.0, 1.0, 0.0);

  glMatrixMode(GL_PROJECTION);

  glLoadIdentity();

  gluOrtho2D(-780, 780, -420, 420);

  drawXYLine();

  drawRectangle();

	glutMainLoop();
}

void Rectangle::drawXYLine()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_LINES);
  //line segment
    glVertex2i(-500, 0);
    glVertex2i(500, 0);
  //left arrow head
    glVertex2i(-500, 0);
    glVertex2i(-490, 5);
    glVertex2i(-500, 0);
    glVertex2i(-490, -5);
  //right arrow head
    glVertex2i(500, 0);
    glVertex2i(490, 5);
    glVertex2i(500, 0);
    glVertex2i(490, -5);
  glEnd();
  output(-500, -40, "X");
  output(480, -40, "Y");
  glFlush();
}

void Rectangle::drawRectangle()
{
    glColor3f(0.0,1.0,0.0);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glBegin(GL_POLYGON);
        glVertex2i(-480,10);  //x1, y1
        glVertex2i(-480+(shape_width*5), 10);   //x2, y1
        glVertex2i(-480+(shape_width*5), 10+(shape_height*5));  //x2, y2
        glVertex2i(-480, 10+(shape_height*5));   //x1, y2
    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glFlush();
}

void Rectangle::output(int x, int y, const char *string)
{
  glRasterPos2f(x,y);

  int len=(int)strlen(string);

  for (int i = 0; i<len; i++)
  {
  	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
  }
}

Rectangle::Rectangle(int x, int y)
{
  shape_width=x;
  shape_height=y;
}
