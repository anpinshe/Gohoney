#ifndef BIGHONEY_H
#define BIGHONEY_H

#include <QImage>
#include <QRect>

class BIGHoney 
{

  public:
    BIGHoney();
    ~BIGHoney();

  public:

    QRect getRect();
    void reset();
    QImage & getImage();

  private:
  
    QImage image;
    QRect rect;

};

#endif
