#include<iostream>
#include "shapes.h"
#include<GL/glut.h>

using namespace std;

int main(int argc, char** argv)
{
  int x, y;
  cin>>x>>y;
  Rectangle r(x, y);
  r.screenSetup(argc, argv);
  return 0;
}
