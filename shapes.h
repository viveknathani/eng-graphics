#include<GL/glut.h>

class Rectangle
{
private:
  int window_width=1366;
  int window_height=768;
  int shape_width, shape_height, plane_angle, edge_angle;
  bool forHP;
public:
  Rectangle();
  void screenSetup(int argc, char** argv);
  void drawXYLine();
  void drawRectangle();
  void output(int x, int y, const char *string);
};
