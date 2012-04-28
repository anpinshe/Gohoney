#ifndef ME_H
#define ME_H

#include <QImage>
#include <QRect>

class Me
{

  public:
    Me();
    ~Me();

  public:
    void resetState();
	void jumpup();
	void jumpdown();
    void moveLeft(int);
    void moveRight(int);
    void moveBottom(int);
    void moveTop(int);
	void moveto(int,int);
    QRect getRect();
    QImage & getImage();

  private:
	  int xdir;
	  int ydir;
    QImage image;
    QRect rect;

};

#endif
