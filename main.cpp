#include "game.h"
#include <QDesktopWidget>
#include <QApplication>
#include <QPalette>

void center(QWidget &widget)
{
  int x, y;
  int screenWidth;
  int screenHeight;

  int WIDTH = 300;
  int HEIGHT = 400;//set the size of the window
  
  //set the color of background to be white
  
  QDesktopWidget *desktop = QApplication::desktop();

  screenWidth = desktop->width();
  screenHeight = desktop->height();
 
  x = (screenWidth - WIDTH)/2;
  y = (screenHeight - HEIGHT)/2 ;

  widget.setGeometry(x, y, WIDTH, HEIGHT);//to make the window appear in the middle of the screen
  widget.setFixedSize(WIDTH, HEIGHT);
}


int main(int argc, char *argv[])
{
  QApplication app(argc, argv);  
    
  Game window;//create a window for the game
  
  window.setWindowTitle("Game");//set the window's name to be "Game"
  window.show();
  center(window);

  return app.exec();
}
