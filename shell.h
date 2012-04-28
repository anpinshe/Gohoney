#ifndef SHELL_H
#define SHELL_H

#include <QImage>
#include <QRect>
#include <iostream>
class Shell
{

  public:
    Shell();
	~Shell();

  public:

	  void move(int x,int y);
	  QRect getRect();
  
	  QImage & getImage();
  private:
  
    QImage image;
    QRect rect;

};

#endif
