/*
  Project : Engineering Graphics
  Author: Vivek Nathani
  Year: 2020
*/


#include<iostream>
#include<fstream>
#include<chrono>
#include "shapes.h"
#include<GL/glut.h>
#include<string.h>
#include<sstream>
#include<math.h>

#define pi 3.142857

void Rectangle::screenSetup(int argc, char** argv)
{
  using namespace std::chrono;

  glutInit(&argc, argv);

  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

  glutInitWindowSize(window_width, window_height);

  glutCreateWindow("Rectangle");

  glClearColor(0.08235294117, 0.08235294117, 0.08235294117, 1.0); //background colour

  glColor3f(0.0, 0.41176470588, 0.18823529411); //default drawing colour

  glMatrixMode(GL_PROJECTION);

  glLoadIdentity();

  gluOrtho2D(-780, 780, -420, 420);

  auto start1=high_resolution_clock::now();
  drawXYLine();
  auto stop1=high_resolution_clock::now();

  auto start2=high_resolution_clock::now();
  stage1();
  auto stop2=high_resolution_clock::now();

  auto start3=high_resolution_clock::now();
  stage2();
  auto stop3=high_resolution_clock::now();

  auto start4=high_resolution_clock::now();
  stage3();
  auto stop4=high_resolution_clock::now();


  //calculating time
  auto duration1=duration_cast<microseconds>(stop1-start1);
  auto duration2=duration_cast<microseconds>(stop2-start2);
  auto duration3=duration_cast<microseconds>(stop3-start3);
  auto duration4=duration_cast<microseconds>(stop4-start4);
  auto duration5=duration_cast<microseconds>(stop4-start1);

  std::fstream file;
  file.open("log.txt", std::ios::out);
  std::streambuf* stream_buffer_cout = std::cout.rdbuf();
  std::streambuf* stream_buffer_cin = std::cin.rdbuf();
  std::streambuf* stream_buffer_file = file.rdbuf();
  std::cout.rdbuf(stream_buffer_file);

  //logging things coz it is fun
  std::cout<<"Initialised screen in "<<duration1.count()<<" microseconds."<<std::endl;
  std::cout<<"Completed Stage 1 in "<<duration2.count()<<" microseconds."<<std::endl;
  std::cout<<"Completed Stage 2 in "<<duration3.count()<<" microseconds."<<std::endl;
  std::cout<<"Completed Stage 3 in "<<duration4.count()<<" microseconds."<<std::endl;
  std::cout<<"Elapsed time : "<<duration5.count()<<" microseconds."<<std::endl;

  std::cout.rdbuf(stream_buffer_cout);
  file.close();
  glutMainLoop();
}

void Rectangle::drawXYLine()
{
  //glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_LINES);
  //line segment
    glVertex2f(-500, 0);
    glVertex2f(500, 0);
  //left arrow head
    glVertex2f(-500, 0);
    glVertex2f(-490, 5);
    glVertex2f(-500, 0);
    glVertex2f(-490, -5);
  //right arrow head
    glVertex2f(500, 0);
    glVertex2f(490, 5);
    glVertex2f(500, 0);
    glVertex2f(490, -5);
  glEnd();

  //title
  output(625, 350, "GraphicSheet", 6);
  output(595, 320, "by Vivek Nathani", 6);

  //xy notation
  output(-500, -40, "X", 0);
  output(480, -40, "Y", 0);
  glFlush();
}

Rectangle::Rectangle()
{
  char plane_check, edge_check;
  std::cout<<"HEY THERE!"<<std::endl;
  std::cout<<"This is a C++ project to demonstrate projection of planes."<<std::endl;
  std::cout<<"You may check out the log file in the root directory of this project after generation of your output."<<std::endl;
  std::cout<<"Press ENTER to continue..."<<std::endl;
  std::cin.ignore();
  std::cout<<"Enter shape width : ";
  std::cin>>shape_width;
  std::cout<<"Enter shape height : ";
  std::cin>>shape_height;
  std::cout<<"Enter plane angle value in degrees : ";
  std::cin>>plane_angle;
  std::cout<<"Enter edge angle value in degrees : ";
  std::cin>>edge_angle;
  std::cout<<"Is the plane angle value an inclination for HP? (y||n) : ";
  std::cin>>plane_check;
  if(plane_check=='y' || plane_check=='Y') { forHP=true; }
  else { forHP=false; }
  std::cout<<"Is the edge angle value an inclination for HP? (y||n) : ";
  std::cin>>edge_check;
  if(edge_check=='y' || edge_check=='Y') { eforHP=true; }
  else { eforHP=false; }
}

void Rectangle::stage1()
{
    using namespace std;
    stringstream ss;
    ss<<shape_width;
    string s;
    ss>>s;
    int n=s.length();
    char shape_w[n+1];
    strcpy(shape_w, s.c_str());
    stringstream ss_2;
    ss_2<<shape_height;
    ss_2>>s;
    n=s.length();
    char shape_h[n+1];
    strcpy(shape_h, s.c_str());

    glColor3f(0.07058823529, 0.36078431372, 0.94117647058);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    if(forHP==true)
    {
      glBegin(GL_POLYGON);
            glVertex2f(-460,-50);
            glVertex2f(-460+(shape_width*5), -50);
            glVertex2f(-460+(shape_width*5), -50-(shape_height*5));
            glVertex2f(-460, -50-(shape_height*5));
      glEnd();
            output(-480, -60, "a", 6);
            output(-450+(shape_width*5), -60, "d", 6);
            output(-450+(shape_width*5), -70-(shape_height*5), "c", 6);
            output(-480, -70-(shape_height*5), "b", 6);
            output(-490, (-60-70-(shape_height*5))/2, shape_h, 6);
            output((-480-450+(shape_width*5))/2,-80-(shape_height*5),shape_w, 6);
      glBegin(GL_LINES);
          glVertex2f(-480,0);
          glVertex2f(-450+(shape_width*5), 0);
      glEnd();
          output(-485, 10, "a\', b\'", 6);
          output(-455+(shape_width*5), 10, "d\', e\'", 6);
    }
    else
    {
      glBegin(GL_POLYGON);
            glVertex2f(-460,50);
            glVertex2f(-460+(shape_width*5), 50);
            glVertex2f(-460+(shape_width*5), 50+(shape_height*5));
            glVertex2f(-460, 50+(shape_height*5));
      glEnd();
            output(-480, 50, "b\'", 6);
            output(-450+(shape_width*5), 50, "c\'", 6);
            output(-450+(shape_width*5), 50+(shape_height*5), "d\'", 6);
            output(-480, 50+(shape_height*5), "a\'", 6);
            output(-490, (50+50+(shape_height*5))/2, shape_h, 6);
            output((-480-450+(shape_width*5))/2, 60+(shape_height*5),shape_w, 6);
      glBegin(GL_LINES);
          glVertex2f(-480,0);
          glVertex2f(-450+(shape_width*5), 0);
      glEnd();
          output(-485, 10, "a, b", 6);
          output(-455+(shape_width*5), 10, "c, d", 6);
    }

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glFlush();
}

void Rectangle::stage2()
{
  using namespace std;

  stringstream ss_3;
  ss_3<<plane_angle;
  string s;
  ss_3>>s;
  int n=s.length();
  char plane_a[n+1];
  strcpy(plane_a, s.c_str());
  glColor3f(0.07058823529, 0.36078431372, 0.94117647058);
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  if(forHP==true)
  {
    glBegin(GL_LINES);
    //line segment
      glVertex2f(-380+(shape_width*5), 0);
      glVertex2f(-380+(shape_width*5)+(shape_width*5*cos(plane_angle*pi/180)), shape_width*5*sin(plane_angle*pi/180));
    glEnd();
      drawArc(-380+(shape_width*5), 0, plane_angle, 50);
      output(-325+(shape_width*5), 10, plane_a, 6);
      drawArc(-300+(shape_width*5), 30, 360, 2.5);
          output(-380+(shape_width*5), -20, "a\', b\'", 6);
          output(-380+(shape_width*5)+(shape_width*5*cos(plane_angle*pi/180)), shape_width*5*sin(plane_angle*pi/180), "d\', c\'", 6);

    glBegin(GL_POLYGON);
          glVertex2f(-380+(shape_width*5),-50);
          glVertex2f(-380+(shape_width*5)+(shape_width*5*cos(plane_angle*pi/180)), -50);
          glVertex2f(-380+(shape_width*5)+(shape_width*5*cos(plane_angle*pi/180)), -50-(shape_height*5));
          glVertex2f(-380+(shape_width*5), -50-(shape_height*5));
    glEnd();
          output(-400+(shape_width*5), -60, "a", 6);
          output(-370+(shape_width*5)+(shape_width*5*cos(plane_angle*pi/180)), -60, "d", 6);
          output(-370+(shape_width*5)+(shape_width*5*cos(plane_angle*pi/180)), -70-(shape_height*5), "c", 6);
          output(-400+(shape_width*5), -70-(shape_height*5), "b", 6);
  }
  else
  {
    glBegin(GL_LINES);
    //line segment
      glVertex2f(-380+(shape_width*5),0);
      glVertex2f(-380+(shape_width*5)+(shape_width*5*cos(plane_angle*pi/180)), shape_width*5*sin(-plane_angle*pi/180));
    glEnd();
      drawArc(-380+(shape_width*5), 0, -plane_angle, 50);
      output(-325+(shape_width*5), -30, plane_a, 6);
      drawArc(-300+(shape_width*5), -10, 360, 2.5);
          output(-380+(shape_width*5), 10, "a\', b\'", 6);
          output(-380+(shape_width*5)+(shape_width*5*cos(plane_angle*pi/180)), shape_width*5*sin(-plane_angle*pi/180), "d\', c\'", 6);

    glBegin(GL_POLYGON);
          glVertex2f(-380+(shape_width*5),50);
          glVertex2f(-380+(shape_width*5)+(shape_width*5*cos(plane_angle*pi/180)), 50);
          glVertex2f(-380+(shape_width*5)+(shape_width*5*cos(plane_angle*pi/180)), 50+(shape_height*5));
          glVertex2f(-380+(shape_width*5), 50+(shape_height*5));
    glEnd();
          output(-400+(shape_width*5), 50, "b", 6);
          output(-370+(shape_width*5)+(shape_width*5*cos(plane_angle*pi/180)), 50, "c", 6);
          output(-370+(shape_width*5)+(shape_width*5*cos(plane_angle*pi/180)), 60+(shape_height*5), "d", 6);
          output(-400+(shape_width*5), 60+(shape_height*5), "a", 6);
  }

  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glFlush();
}

void Rectangle::stage3()
{
  glColor3f(1.0,1.0,0.0);
  glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  if(eforHP==false)
  {
    //b
    float points1[]={-380+(shape_width*5),-50-(shape_height*5)};
    float points2[]={-380+(shape_width*5), -50-(shape_height*5)-350};
    float slope1=tan((-edge_angle)*pi/180);
    float slope2=tan((90-edge_angle)*pi/180);
    float *interesction_a;
    float *interesction_b;
    float *interesction_c;
    float *interesction_d;
    interesction_b=findInterSection(points1, points2, slope1, slope2);
    float b1=*(interesction_b);
    float b2=*(interesction_b+1);
    output(b1-15, b2, "b1", 5);
    //a
    points1[0]=-380+(shape_width*5);
    points1[1]=-50;
    interesction_a=findInterSection(points1, points2, slope1, slope2);
    float a1=*(interesction_a);
    float a2=*(interesction_a+1);
    output(a1-15, a2, "a1", 5);
    //pushing c and d ahead
    float pushlength=shape_width*5*sin(plane_angle*pi/180);
    //d
    points1[0]=-380+(shape_width*5)+(shape_width*5*cos(plane_angle*pi/180));
    points1[1]=-50-(shape_height*5);
    interesction_d=findInterSection(points1, points2, slope1, slope2);
    *(interesction_d)+=pushlength*cos(edge_angle*pi/180);
    *(interesction_d+1)+=pushlength*sin(-edge_angle*pi/180);
    float d1=*(interesction_d);
    float d2=*(interesction_d+1);
    output(d1+10, d2, "d1", 5);
    //c
    points1[0]=-380+(shape_width*5)+(shape_width*5*cos(plane_angle*pi/180));
    points1[1]=-50;
    interesction_c=findInterSection(points1, points2, slope1, slope2);
    *(interesction_c)+=pushlength*cos(edge_angle*pi/180);
    *(interesction_c+1)+=pushlength*sin(-edge_angle*pi/180);
    float c1=*(interesction_c);
    float c2=*(interesction_c+1);
    output(c1+10, c2, "c1", 5);

  	glBegin(GL_POLYGON);
    glVertex2f(a1, a2);
    glVertex2f(b1, b2);
    glVertex2f(d1, d2);
    glVertex2f(c1, c2);
  	glEnd();
  }
  else
  {
    float points1[]={-380+(shape_width*5),50+(shape_height*5)};
    float points2[]={-380+(shape_width*5), 50+(shape_height*5)-350};
    float slope1=tan((edge_angle)*pi/180);
    float slope2=tan((90-edge_angle)*pi/180);
    float *interesction_a;
    float *interesction_b;
    float *interesction_c;
    float *interesction_d;
    interesction_b=findInterSection(points1, points2, slope1, slope2);
    float b1=*(interesction_b);
    float b2=*(interesction_b+1);
    output(b1-15, b2, "b1", 5);
    //a
    points1[0]=-380+(shape_width*5);
    points1[1]=+50;
    interesction_a=findInterSection(points1, points2, slope1, slope2);
    float a1=*(interesction_a);
    float a2=*(interesction_a+1);
    output(a1-15, a2, "a1", 5);
    //pushing c and d ahead
    float pushlength=shape_width*5*sin(plane_angle*pi/180);
    //d
    points1[0]=-380+(shape_width*5)+(shape_width*5*cos(plane_angle*pi/180));
    points1[1]=50+(shape_height*5);
    interesction_d=findInterSection(points1, points2, slope1, slope2);
    *(interesction_d)+=pushlength*cos(edge_angle*pi/180);
    *(interesction_d+1)+=pushlength*sin(edge_angle*pi/180);
    float d1=*(interesction_d);
    float d2=*(interesction_d+1);
    output(d1+10, d2, "d1", 5);
    //c
    points1[0]=-380+(shape_width*5)+(shape_width*5*cos(plane_angle*pi/180));
    points1[1]=50;
    interesction_c=findInterSection(points1, points2, slope1, slope2);
    *(interesction_c)+=pushlength*cos(edge_angle*pi/180);
    *(interesction_c+1)+=pushlength*sin(edge_angle*pi/180);
    float c1=*(interesction_c);
    float c2=*(interesction_c+1);
    output(c1+10, c2, "c1", 5);

  	glBegin(GL_POLYGON);
    glVertex2f(a1, a2);
    glVertex2f(b1, b2);
    glVertex2f(d1, d2);
    glVertex2f(c1, c2);
  	glEnd();
  }
  glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
  glFlush();
}

void Rectangle::output(int x, int y, const char *string, int font_id)
{
  glRasterPos2f(x, y);

  int len=(int)strlen(string);

  for (int i = 0; i<len; i++)
  {
    switch(font_id)
    {
      case 0: glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
              break;

      case 1: glutBitmapCharacter(GLUT_BITMAP_8_BY_13, string[i]);
              break;

      case 2: glutBitmapCharacter(GLUT_BITMAP_9_BY_15, string[i]);
              break;

      case 3: glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, string[i]);
              break;

      case 4: glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10, string[i]);
              break;

      case 5: glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, string[i]);
              break;

      case 6: glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, string[i]);
              break;

      default: std::cout<<"Log : Couldn't find a match for the font."<<std::endl;
    }
  }
}

void Rectangle::drawArc(float center_x, float center_y, float arc_angle, float arc_radius)
{
  glBegin(GL_POINTS);
  float x, y, i;

    if(arc_angle>0)
    {
      for (i=0; i<(arc_angle*pi/180); i+=0.001)
      {
          x = center_x+(arc_radius*cos(i));
          y = center_y+(arc_radius*sin(i));
          glVertex2f(x, y);
      }
    }
    else
    {
      for (i=0; i>(arc_angle*pi/180); i-=0.001)
      {
          x = center_x+(arc_radius*cos(i));
          y = center_y+(arc_radius*sin(i));
          glVertex2f(x, y);

      }
    }
  glEnd();
}

float* Rectangle::findInterSection(float points1[], float points2[], float slope1, float slope2)
{
  float a1=slope1, a2=slope2;
  float b1=-1, b2=-1;
  float k1=(slope1*points1[0])-points1[1];
  float k2=(slope2*points2[0])-points2[1];
  float D, Dx, Dy;
  D=(a1*b2)-(a2*b1);
  Dx=(k1*b2)-(k2*b1);
  Dy=(a1*k2)-(a2*k1);
  static float points3[2];
  points3[0]=Dx/D;
  points3[1]=Dy/D;
  return points3;
}
