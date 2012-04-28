#include "oct.h"
#include <iostream>

using namespace std;

Oct::Oct():Mon(-1,0)
{
  image.load("oct.png");
  destroyed = FALSE;
  reset();
  rect = image.rect();

}

Oct::~Oct() {
  std::cout << ("monster deleted\n");
}

void Oct::reset(){
	xdir=-1;
	ydir=0;
	rect.moveTo(250,354);}

void Oct::autoMove()
{
  rect.translate(xdir, ydir); 

  if (rect.left() <= 0) {
	if(rect.bottom()==312||rect.bottom()==313||rect.bottom()==165||rect.bottom()==166){
		xdir=1;
		ydir=0;}
	else if(rect.y()==354||rect.y()==355||rect.bottom()==248||rect.bottom()==249){
		xdir=0;
		ydir=-1;}
  }

  if (rect.right()>=300) {
	  if(rect.bottom()==312||rect.bottom()==313||rect.bottom()==165||rect.bottom()==166){
	  ydir=-1;
	  xdir = 0;}
	  else if(rect.y()==354||rect.y()==355||rect.bottom()==248||rect.bottom()==249){
		  ydir=0;
		  xdir=-1;}
  }
}

void Oct::move(int x,int y){
    rect.moveTo(x,y);//relocate the monster at (x,y)
}

bool Oct::isDestroyed()
{
  return destroyed;
}

void Oct::setDestroyed(bool destr)
{
  destroyed = destr;
}