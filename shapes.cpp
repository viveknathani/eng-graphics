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
    glColor3f(1.0,1.0,0.0);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    if(forHP==true)
    {
      glBegin(GL_POLYGON);
            glVertex2i(-460,-50);  //x1, y1
            glVertex2i(-460+(shape_width*5), -50);   //x2, y1
            glVertex2i(-460+(shape_width*5), -50-(shape_height*5));  //x2, y2
            glVertex2i(-460, -50-(shape_height*5));   //x1, y2
      glEnd();
            output(-480, -60, "a"); //x1, y1 point
            output(-450+(shape_width*5), -60, "c"); //x2, y1 point
            output(-450+(shape_width*5), -70-(shape_height*5), "d"); //x3, y3 point
            output(-480, -70-(shape_height*5), "b"); //x4, y4 point
      glBegin(GL_LINES);
          glVertex2i(-480,0);
          glVertex2i(-450+(shape_width*5), 0);
      glEnd();
          output(-485, 10, "a\', b\'");
          output(-455+(shape_width*5), 10, "c\', d\'");
    }
    else
    {
      glBegin(GL_POLYGON);
            glVertex2i(-460,50);  //x1, y1
            glVertex2i(-460+(shape_width*5), 50);   //x2, y1
            glVertex2i(-460+(shape_width*5), 50+(shape_height*5));  //x2, y2
            glVertex2i(-460, 50+(shape_height*5));   //x1, y2
      glEnd();
            output(-480, 50, "b\'"); //x1, y1 point
            output(-450+(shape_width*5), 50, "c\'"); //x2, y1 point
            output(-450+(shape_width*5), 50+(shape_height*5), "d\'"); //x3, y3 point
            output(-480, 50+(shape_height*5), "a\'"); //x4, y4 point
    }


    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    // if(forHP==true)
    // {
    //   glBegin(GL_LINES);
    //       glVertex2i(-480,0);
    //       glVertex2i(-450+(shape_width*5), 0);
    //   glEnd();
    //       output(-485, 10, "a\', b\'");
    //       output(-455+(shape_width*5), 10, "c\', d\'");
    // }

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

Rectangle::Rectangle()
{
  cout<<"Enter shape width : ";
  cin>>shape_width;
  cout<<"Enter shape height : ";
  cin>>shape_height;
  cout<<"Enter plane angle value in degrees : ";
  cin>>plane_angle;
  cout<<"Enter edge angle value in degrees : ";
  cin>>edge_angle;
  char check;
  cout<<"Is the plane angle value an inclination for HP? (y/n) : ";
  cin>>check;
  if(check=='y' || check=='Y') { forHP=true; }
  else { forHP=false; }
}
