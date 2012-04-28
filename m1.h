#ifndef M1_H
#define M1_H

#include <QImage>
#include <QRect>

#include "mon.h"
class M1:public Mon
{

  public:
    M1(int,int,int,int);
    ~M1();

  public:
    
    void autoMove();
    void move(int,int);
	bool isDestroyed();
    void setDestroyed(bool);

private:
	 bool destroyed;
};

#endif
