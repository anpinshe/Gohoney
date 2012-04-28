#include "m4.h"
#include <iostream>

using namespace std;

M4::M4(int x,int y,int a,int b):Mon(a,b)
{

  image.load("lob.png");
  destroyed = FALSE;
  rect = image.rect();
  rect.translate(x,y);

}

M4::~M4() {
  std::cout << ("monster deleted\n");
}


void M4::autoMove()
{
  rect.translate(xdir, ydir);

  if ((rect.bottom() >= 106&&rect.bottom()<=107)||(rect.bottom() >= 246&&rect.bottom()<=247)) {
    ydir = -1;
  }

  if (rect.right()>=300) {
    xdir = -1;
  }
  if ((rect.top()<=180&&rect.top()>=179)||(rect.top()<=48&&rect.top()>=47)){
	  ydir=1;}
  if (rect.left()<=0)
	  xdir=1;
}

void M4::move(int x,int y)
{
  rect.moveTo(x,y);
}

void M4::setdir(int x, int y){
	xdir=x;
	ydir=y;
}

bool M4::isDestroyed()
{
  return destroyed;
}

void M4::setDestroyed(bool destr)
{
  destroyed = destr;
}