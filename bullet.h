#ifndef BULLET_H_
#define BULLET_H_


#include <QImage>
#include <QRect>
#include <iostream>
class bul
{
  public:
	bul(){
		image.load("bullet.png");
		rect = image.rect();
		}

	~bul(){
		std::cout<<("bullet deleted\n");}

	void Movel(){
	rect.translate(-2, 0);//to make the bullet move left
	}

	void Mover(){
		rect.translate(2,0);}//to make the bullet move right

	void moveto(int x,int y){
		rect.moveTo(x,y);}

	QRect getRect(){return rect;}
  
	QImage & getImage(){return image;}

  private:
    int xdir;
    int ydir;
	QImage image;
    QRect rect;
};

#endif