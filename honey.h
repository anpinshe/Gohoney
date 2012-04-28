#ifndef HONEY_H
#define HONEY_H

#include <QImage>
#include <QRect>

class Honey 
{

  public:
    Honey(int,int);
    ~Honey();

  public:

    QRect getRect();
    void move(int,int);
    QImage & getImage();

  private:
  
    QImage image;
    QRect rect;

};

#endif
