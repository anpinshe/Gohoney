#include <QImage>
#include <QRect>
#include <iostream>
#include "shell.h"



    Shell::Shell(){
		image.load("usc.png");
		rect = image.rect();}

	Shell::~Shell(){std::cout<<"shell deleted\n";}

	 void Shell::move(int x,int y){rect.moveTo(x,y);}

	 QRect Shell::getRect(){return rect;}
  
	 QImage & Shell::getImage(){return image;}