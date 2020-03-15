#include<GL/glut.h>

class Rectangle
{
private:
  int window_width=1366;
  int window_height=768;
  float shape_width, shape_height, plane_angle, edge_angle;
  bool forHP, eforHP;
public:
  Rectangle();
  void screenSetup(int argc, char** argv);
  void drawXYLine();
  void drawRectangle();
  void stage2();
  float* findInterSection(float points1[], float points2[], float slope1, float slope2);
  void stage3();
  void drawArc(float center_x, float center_y, float arc_angle, float arc_radius);
  void output(int x, int y, const char *string);
};
