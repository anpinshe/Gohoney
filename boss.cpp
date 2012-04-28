#include "boss.h"
#include <iostream>

using namespace std;

Boss::Boss(int x,int y,int a,int b):Mon(a,b)
{

  image.load("bee.png");
  destroyed = FALSE;
  rect = image.rect();
  rect.translate(x,y);

}

Boss::~Boss() {
  std::cout << ("monster deleted\n");
}


void Boss::autoMove()
{
  rect.translate(0, ydir);

  if (rect.top() <= 118) {
    ydir = 1;
  }

  if (rect.bottom() >= 233) {
    ydir = -1;
  }
}

void Boss::move(int x,int y)
{
  rect.moveTo(150,231);
}

bool Boss::isDestroyed()
{
  return destroyed;
}

void Boss::setDestroyed(bool destr)
{
  destroyed = destr;
}