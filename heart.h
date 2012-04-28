#ifndef HEART_H
#define HEART_H

#include <QImage>
#include <QRect>

class Heart
{

  public:
    Heart(int,int);
    ~Heart();

  public:
    QRect getRect();
    void move(int,int);
    QImage & getImage();

  private:
  
    QImage image;
    QRect rect;

};

#endif
