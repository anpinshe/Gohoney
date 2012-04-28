#ifndef MON_H_
#define MON_H_


#include <QImage>
#include <QRect>

class Mon
{


  public:
	Mon(int x,int y){xdir=x;ydir=y;}
    virtual void autoMove()=0;
    virtual void move(int,int)=0;
	virtual QRect getRect(){return rect;}
  
	virtual QImage & getImage(){return image;}

  protected:
    int xdir;
    int ydir;
	QRect rect;
	QImage image;

};

#endif