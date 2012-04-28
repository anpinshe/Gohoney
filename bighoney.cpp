#include "bighoney.h"
#include <iostream>

using namespace std;

BIGHoney::BIGHoney()
{

  image.load("final.png");
  reset();
  rect = image.rect();

}

BIGHoney::~BIGHoney() {
  std::cout << ("BIGHoney deleted\n");
}

void BIGHoney::reset(){
	rect.moveTo(230,140);}


QRect BIGHoney::getRect()
{
  return rect;
}

QImage & BIGHoney::getImage()
{
  return image;
}

