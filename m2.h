#ifndef M2_H
#define M2_H

#include <QImage>
#include <QRect>

#include "mon.h"

class M2: public Mon
{

  public:
    M2(int,int,int,int);
    ~M2();

  public:
    void move(int,int);
    void autoMove();
	bool isDestroyed();
    void setDestroyed(bool);

  private:

	bool destroyed;

};

#endif
