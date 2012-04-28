#ifndef GAME_H
#define GAME_H

#include "mon.h"
#include "m1.h"
#include "me.h"
#include "m2.h"
#include "bullet.h"
#include "heart.h"
#include "honey.h"
#include "m3.h"
#include "m4.h"
#include "shell.h"
#include "oct.h"
#include "boss.h"
#include "bighoney.h"
#include <QWidget>
#include <QKeyEvent>

class Game : public QWidget
{
  Q_OBJECT

  public:
    Game(QWidget *parent = 0);
    ~Game();

  protected:
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
    void keyPressEvent(QKeyEvent *event);

    void startGame();
    void pauseGame();
    void stopGame();
    void checkCollision();

  private:
    int x;
    int timerId;
	int numbull;
	int numm1;//number of monster1
	int numm2;
	int numm3;
	int numm4;
	int over;//how many times you have hit the boss
	int p,r,s,t;
    Me *me;
    M1 *m1[2];//create two monster 1
    M2 *m2[2];
	M3 *m3[2];
	M4 *m4[2];
	Shell *sh;
	Oct *oct;
    Honey *honey;
	Heart *heart;
	Boss *bee;
	BIGHoney *big;
	bul *b1[100]; //your bullets
	bul *bm;
	bul *bb[5];//bee's bullets
    bool gameOver;
    bool gameWon;
    bool gameStarted;
    bool paused;
    bool top;//whether the first time to open the game
	bool left;
	bool leftb;
	bool right;
	bool rightb;
	bool ml;
	bool mr;
	bool up;
	bool down;
	bool jumpup;
	bool jumpdown;
	bool bull[100];//whether the bullet should appear, hurt or not(bullet you fired)
	bool bullm;
	bool bbull[5];
	bool level1;//to check if it is level 1
	bool level2;
	bool level3;
	bool help;
	bool shell;
    int score;
    int life;

};

#endif
