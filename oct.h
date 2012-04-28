#ifndef OCT_H
#define OCT_H

#include <QImage>
#include <QRect>

#include "mon.h"
class Oct:public Mon
{

  public:
    Oct();
    ~Oct();

  public:
    
    void autoMove();
    void move(int,int);
	bool isDestroyed();
    void setDestroyed(bool);
    void reset();

private:

	 bool destroyed;
};

#endif
