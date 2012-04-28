#include "m1.h"
#include <iostream>

using namespace std;

M1::M1(int x,int y,int a,int b):Mon(a,b)
{
  image.load("m1.png");
  destroyed = FALSE;
  rect = image.rect();
  rect.translate(x,y);

}

M1::~M1() {
  std::cout << ("monster deleted\n");
}


void M1::autoMove()
{
  rect.translate(xdir, ydir); 

  if (rect.left() <= 0) {
    xdir = 1;//If touch the left side of the window go back
  }

  if (rect.right()>=298) {
    xdir = -1;
  }
}

void M1::move(int x,int y){
    rect.moveTo(x,y);//relocate the monster at (x,y)
}


bool M1::isDestroyed()
{
  return destroyed;
}

void M1::setDestroyed(bool destr)
{
  destroyed = destr;
}