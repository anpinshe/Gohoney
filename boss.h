#ifndef BOSS_H
#define BOSS_H

#include <QImage>
#include <QRect>

#include "mon.h"
class Boss:public Mon
{

  public:
    Boss(int,int,int,int);//set bee's initial position 
    ~Boss();

  public:
    
    void autoMove();
    void move(int,int);
	bool isDestroyed();
    void setDestroyed(bool);

private:

	 bool destroyed;
};

#endif
