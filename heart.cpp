#include "heart.h"
#include <iostream>

using namespace std;

Heart::Heart(int x,int y)
{

  image.load("heart.png");

  rect = image.rect();
  rect.translate(x,y);

}

Heart::~Heart() {
  std::cout << ("Heart deleted\n");
}

void Heart::move(int x, int y){
  rect.moveTo(x,y);//relocate the heart
}

QRect Heart::getRect()
{
  return rect;
}

QImage & Heart::getImage()
{
  return image;
}

