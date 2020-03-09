#include<GL/glut.h>

class Rectangle
{
private:
  int window_width=1366;
  int window_height=768;
public:
  void screenSetup(int argc, char** argv);
  static void show();
  static void drawXYLine();
  static void drawRectangle();
  static void output(int x, int y, const char *string);
};
