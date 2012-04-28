#include "m2.h"
#include <iostream>

using namespace std;

M2::M2(int x,int y,int a,int b):Mon(a,b)
{

  image.load("mon2.png");
  destroyed = FALSE;
  rect = image.rect();
  rect.translate(x,y);

}

M2::~M2() {
  std::cout << ("monster deleted\n");
}


void M2::autoMove()
{
  rect.translate(xdir, ydir);

  if (rect.left() <= 0) {
    xdir = 1;
  }

  if (rect.right() >= 298) {
    xdir = -1;
  }
}

void M2::move(int x,int y)
{
  rect.moveTo(x,y);
}


bool M2::isDestroyed()
{
  return destroyed;
}

void M2::setDestroyed(bool destr)
{
  destroyed = destr;
}