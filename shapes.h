/*
  Project : Engineering Graphics
  Author: Vivek Nathani
  Year: 2020
*/

#ifndef SHAPES_H
#define SHAPES_H

class Rectangle
{
private:
  int window_width=1366;
  int window_height=768;

  //parameters specific for EG problems
  float shape_width, shape_height, plane_angle, edge_angle;

  //for HP is true if the given plane angle has an inclination with HP
  //efor HP is true if the given edge angle has an inclination with HP
  bool forHP, eforHP;

public:
  //constructor to initialise the problem specific parameters
  Rectangle();

  //function that sets up the environment for openGL to draw our content
  void screenSetup(int argc, char** argv);

  //fundamental function
  void drawXYLine();

  //key functions
  void stage1();
  void stage2();
  void stage3();

  //utility functions used by key functions
  float* findInterSection(float points1[], float points2[], float slope1, float slope2);
  void drawArc(float center_x, float center_y, float arc_angle, float arc_radius);
  void output(int x, int y, const char *string, int font_id=0);
};

#endif
