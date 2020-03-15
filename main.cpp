#include<iostream>
#include "shapes.h"
#include<GL/glut.h>

using namespace std;

int main(int argc, char** argv)
{
  Rectangle r;
  r.screenSetup(argc, argv);
  return 0;
}
