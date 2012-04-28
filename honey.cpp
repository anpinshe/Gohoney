#include "honey.h"
#include <iostream>

using namespace std;

Honey::Honey(int x,int y)
{

  image.load("honey.png");

  rect = image.rect();
  rect.translate(x,y);

}

Honey::~Honey() {
  std::cout << ("Honey deleted\n");
}

void Honey::move(int x, int y){
  rect.moveTo(x,y);//relocate the honey
}

QRect Honey::getRect()
{
  return rect;
}

QImage & Honey::getImage()
{
  return image;
}

