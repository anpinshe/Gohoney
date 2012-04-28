#ifndef M3_H
#define M3_H

#include <QImage>
#include <QRect>

#include "mon.h"
class M3:public Mon
{

  public:
    M3(int,int,int,int);
    ~M3();

  public:
    
    void autoMove();
    void move(int,int);
	bool isDestroyed();
    void setDestroyed(bool);
    void setdir(int x,int y);
private:

	 bool destroyed;
};

#endif
