#include<GL/glut.h>

class Rectangle
{
private:
  int window_width=1366;
  int window_height=768;
  int shape_width, shape_height;
public:
  Rectangle(int x, int y);
  void screenSetup(int argc, char** argv);
  void drawXYLine();
  void drawRectangle();
  void output(int x, int y, const char *string);
};
