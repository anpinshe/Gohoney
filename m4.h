#ifndef M4_H
#define M4_H

#include <QImage>
#include <QRect>

#include "mon.h"
class M4:public Mon
{

  public:
    M4(int,int,int,int);
    ~M4();

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
