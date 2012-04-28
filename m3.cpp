#include "m3.h"
#include <iostream>

using namespace std;

M3::M3(int x,int y,int a,int b):Mon(a,b)
{

  image.load("crab.png");
  destroyed = FALSE;
  rect = image.rect();
  rect.translate(x,y);

}

M3::~M3() {
  std::cout << ("monster deleted\n");
}


void M3::autoMove()
{
  rect.translate(xdir, ydir);

  if ((rect.bottom() >= 316&&rect.bottom()<=317)||(rect.bottom() >= 176&&rect.bottom()<=177)) {
    ydir = -1;
  }

  if (rect.right()>=300) {
    xdir = -1;
  }
  if ((rect.top()<=248&&rect.top()>=247)||(rect.top()<=108&&rect.top()>=107)){
	  ydir=1;}
  if (rect.left()<=0)
	  xdir=1;
}

void M3::move(int x,int y)
{
  rect.moveTo(x,y);
}


void M3::setdir(int x, int y){
	xdir=x;
	ydir=y;
}

bool M3::isDestroyed()
{
  return destroyed;
}

void M3::setDestroyed(bool destr)
{
  destroyed = destr;
}