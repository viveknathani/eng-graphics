#include<GL/glut.h>

class Rectangle
{
private:
  int width=1366;
  int height=768;
public:
  void screenSetup(int argc, char** argv);
  static void show();
  static void drawXYLine();
  static void output(int x, int y, const char *string);
};
