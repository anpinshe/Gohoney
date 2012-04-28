#include "me.h"
#include <iostream>

Me::Me()
{
  xdir=0;ydir=-1;
  image.load("bear.png");

  rect = image.rect();
  resetState();
}

Me::~Me()
{
 std::cout << ("Bear deleted\n");
}

void Me::moveto(int x,int y){
	rect.moveTo(x,y);}

void Me::moveLeft(int left)
{
  if (rect.left() >= 1)
    rect.moveTo(left, rect.top());
}

void Me::moveRight(int right)
{
  if (rect.right() <= 298)
    rect.moveTo(right, rect.top());
}

void Me::moveBottom(int bottom)
{
  if (rect.bottom() <= 398)
  rect.moveTo(rect.left(),bottom);
}

void Me::moveTop(int top)
{
  if (rect.top() >= 2)
  rect.moveTo(rect.left(),top);
}

void Me::jumpup()
{
	rect.translate(0, -2);
}

void Me::jumpdown()
{
	rect.translate(0,2);
}

void Me::resetState()
{
  rect.moveTo(220, 354);
}

QRect Me::getRect()
{
  return rect;
}

QImage & Me::getImage()
{
  return image;
}
