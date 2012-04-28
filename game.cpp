#include "game.h"
#include <QPainter>
#include <QApplication>
#include <QString>

Game::Game(QWidget *parent)
    : QWidget(parent)//set all the qualities before the game starts
{
  p=0;
  r=0;
  s=0;
  t=0;//to set each level in level 2
  x = 0;
  score=0;
  life=3;
  numbull=0;
  numm1=2;
  numm2=2;
  numm3=2;
  numm4=2;
  over=0;
  gameOver = FALSE;
  gameWon = FALSE;
  paused = FALSE;
  gameStarted = FALSE;
  shell=false;
  level1=true;
  level2=false;
  level3=false;
  top =TRUE;
  jumpup=false;
  jumpdown=false;
  help=false;
  left=true;
  leftb=false;
  ml=false;
  right=true;
  rightb=false;
  mr=false;
  up=false;
  down=false;
  for(int k=0;k<100;k++)
  bull[k]=false;
  for(int k=0;k<5;k++)
	  bbull[k]=false;
  bullm=false;
  me = new Me();
  for (int a=0;a<100;a++){
	  b1[a] = new bul();}
  for (int a=0;a<5;a++)
	  bb[a] =new bul();
  bm = new bul();
  sh =new Shell();
  oct = new Oct();
  honey = new Honey(rand()%230+35,31);//place the target at a random place
  big = new BIGHoney();
  heart = new Heart(rand()%230+35,62);
  bee = new Boss(150,130,0,1);
  for (int i=0;i<2;i++){
  m1[i]= new M1(rand()%230+35,i*250+35,1,0);
  m2[i]= new M2(rand()%230+35,i*80+112,-1,0);
  m3[i]= new M3(40*i,146*i+160,1,-1);
  m4[i]= new M4(260-40*i,140*i+95,-1,-1);
}//create the monsters
  
}

Game::~Game() {
 delete me;
 delete honey;
 delete heart;
 delete bee;
 for (int a=0;a<100;a++){
	  delete b1[a];}
  for (int a=0;a<5;a++)
	  delete bb[a];
  delete bm;
  delete sh;
  delete oct;
  delete big;
 for (int i=0;i<2;i++){
 delete m1[i];
 delete m2[i];
 delete m3[i];
 delete m4[i];
 }
}//After quit the game

void Game::paintEvent(QPaintEvent *event)
{
  QPainter painter(this);

  if (gameOver) {
    QFont font("Courier", 15, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.width("Game Over");
	painter.setPen(QPen(QColor(Qt::black)));
    painter.setFont(font);
    int h = height();
    int w = width();
	QPalette palette;
	palette.setBrush(this->backgroundRole(), QBrush(QImage("lose.png")));
	this->setPalette(palette);
    painter.translate(QPoint(w/2, h/2));
    painter.drawText(-textWidth/2-45,20, "Final Score:");
    painter.drawText(80, 20, QString::number(score));
    painter.drawText(-textWidth/2-55,40, "Press 's' to restart");
  }//Things displayed after gameover
  else if(gameWon){
	  QFont font("Courier", 15, QFont::DemiBold);
    QFontMetrics fm(font);
    int textWidth = fm.width("Game Over");
	painter.setPen(QPen(QColor(Qt::black)));//make the word's color black
    painter.setFont(font);
    int h = height();
    int w = width();
	QPalette palette;
	palette.setBrush(this->backgroundRole(), QBrush(QImage("vic.png")));
	this->setPalette(palette);
    painter.translate(QPoint(w/2, h/2));
    painter.drawText(-textWidth/2-45,20, "Final Score:");
    painter.drawText(80, 20, QString::number(score));
	painter.drawText(-textWidth/2-55,40, "Press 's' to restart");}//Things displayed after you win

  else if (top){
	QPalette palette;
	palette.setBrush(this->backgroundRole(), QBrush(QImage("top.png")));
	this->setPalette(palette);
   }  //Things displayed when you first open the game
  else if (help){
	  QPalette palette;
	palette.setBrush(this->backgroundRole(), QBrush(QImage("help.png")));
	this->setPalette(palette);
  }
  else {
	 QFont font("Courier", 15, QFont::DemiBold);
	 painter.setPen(QPen(QColor(Qt::white)));
    QFontMetrics fm(font);
    int textWidth = fm.width("Score:");
    painter.setFont(font);
    int h = height();
    int w = width();
	
    painter.translate(QPoint(textWidth/2, 20));
    painter.drawText(-textWidth/2, 0, "Score:");
    painter.drawText(textWidth-20, 0, QString::number(score));
    painter.translate(QPoint(w/2, 0));
    painter.drawText(0, 0, "Lives:");
    painter.drawText(80, 0, QString::number(life));
    painter.translate(QPoint(-w/2-textWidth/2,-20));//Scores and lives displayed at the top;
	
    painter.drawImage(me->getRect(), 
        me->getImage());
	for(int k=0;k<numbull+1;k++){
	if(bull[k])//if you fire a bullet, make it appear
		painter.drawImage(b1[k]->getRect(),b1[k]->getImage());}
	
	if(level1){//Things displayed in level 1
	if(bullm)
			painter.drawImage(bm->getRect(),bm->getImage());
	if(shell)
		painter.drawImage(sh->getRect(),sh->getImage());
	QPalette palette;
	palette.setBrush(this->backgroundRole(), QBrush(QImage("b1.png")));//set background
	this->setPalette(palette);
    painter.drawImage(honey->getRect(),honey->getImage());
	
    for (int i=0; i<numm1;i++)
		if(!m1[i]->isDestroyed())//if the monster is not killed,destroy it
			painter.drawImage(m1[i]->getRect(),m1[i]->getImage());
	for (int i=0; i<numm2;i++)
		if(!m2[i]->isDestroyed())
			painter.drawImage(m2[i]->getRect(),m2[i]->getImage());}

	if(level2){//displayed in level 2
	QPalette palette;
	palette.setBrush(this->backgroundRole(), QBrush(QImage("b2.png")));
	this->setPalette(palette);
	for (int i=0; i<numm3;i++)
		if(!m3[i]->isDestroyed())
			painter.drawImage(m3[i]->getRect(),m3[i]->getImage());
	for (int i=0; i<numm4;i++)
		if(!m4[i]->isDestroyed())
			painter.drawImage(m4[i]->getRect(),m4[i]->getImage());
	painter.drawImage(oct->getRect(),oct->getImage());
	painter.drawImage(heart->getRect(),heart->getImage());
	}
	if(level3){
		QPalette palette;
		palette.setBrush(this->backgroundRole(), QBrush(QImage("b3.png")));
		this->setPalette(palette);
		if(!bee->isDestroyed())
		painter.drawImage(bee->getRect(),bee->getImage());
		for(int k=0;k<5;k++){
		if(bbull[k])
		painter.drawImage(bb[k]->getRect(),bb[k]->getImage());}
		painter.drawImage(big->getRect(),big->getImage());
	}
  }//The normal display format of your game
}

void Game::timerEvent(QTimerEvent *event)
{
	if(level1){//in process of level 1
  for(int i=0;i<numm1;i++)
	  if(!m1[i]->isDestroyed())//if the monster is not killed, continue to move 
		m1[i]->autoMove();
  for(int i=0;i<numm2;i++)
	  if(!m2[i]->isDestroyed())
		  m2[i]->autoMove();
  if(bullm){
	  if(ml){
		bm->Movel();//if you you appears to the monster's left, the monster's bullet will go left 
		}
	  if(mr){
		 bm->Mover();//right
		}
  }}
	if(level2){
		for(int i=0;i<numm3;i++)
			if(!m3[i]->isDestroyed())
				m3[i]->autoMove();
		for(int i=0;i<numm4;i++)
			if(!m4[i]->isDestroyed())
				m4[i]->autoMove();
		oct->autoMove();//octopus starts to move
		if(jumpup){
	  me->jumpup();}//you can jump in level 2
  if(jumpdown){
	  me->jumpdown();}
	}
	if(level3){
		bee->autoMove();
		for(int i=0;i<5;i++)
		if(bbull[i])
			bb[i]->Movel();//bee's bullet will always move left
		for(int k=0;k<numbull;k++){
			if(bull[k]){
				b1[k]->Mover();}}//your bullet will always move right withoout determining the direction first
	}
  if(!level3){
  for(int k=0;k<numbull;k++){
  if(bull[k]){
	  if(leftb){
		b1[k]->Movel();
		}
	  if(rightb){
		 b1[k]->Mover();
		}
  }}}//if you press left and then fire the bullet, the bullet will go left; vice versa
  checkCollision();
  repaint();
}//what should something do during the game



void Game::keyPressEvent(QKeyEvent *event)//set the commands for severl keys
{
    switch (event->key()) {
    case Qt::Key_Left:
       { 
		   if(left){
         int x = me->getRect().x();
        for (int i=1; i<=5; i++)
			me->moveLeft(x--);
		   if(bull[numbull-1]==false || numbull==0){
		  rightb=false;
		  leftb=true;}

		   }//make the bear go left
       }
		break;
    case Qt::Key_Right:
        { 
		  if(right){
          int x = me->getRect().x();
          for (int i=1; i<=5; i++)
			  me->moveRight(x++);
		  if(bull[numbull-1]==false || numbull==0){
			  leftb=false;
			  rightb=true;}
		  }
        }//go right,set bullet go right or the shell to appear by your right;
		break;
	case Qt::Key_Space:
		{
			if(!level3){
			if(leftb){
				b1[numbull]->moveto(me->getRect().left()-22,me->getRect().bottom()-22);
				}
			if(rightb){
				b1[numbull]->moveto(me->getRect().right()+1,me->getRect().bottom()-22);}//if it is not level 3, you can determine the direction of your bullet
			bull[numbull]=true;
			numbull++;}
			else{
				b1[numbull]->moveto(me->getRect().right()+1,me->getRect().bottom()-22);//you can only fire you bullet to the right in level3
				bull[numbull]=true;
				numbull++;}
		}
		break;
    case Qt::Key_Up://you can go up only when there is a ladder
        {
			if(up){
          int x= me->getRect().y();
          for (int i=1;i<=5;i++)
			  me->moveTop(x--);}
        }

        break;
    case Qt::Key_Down://same as above
        {
			if(down){
          int x= me->getRect().y();
          for (int i=1;i<=5;i++)
			  me->moveBottom(x++);}
        }
        break;
    case Qt::Key_P:
        { 
          pauseGame();
        }
        break;
	case Qt::Key_X:
		{
			if(level1){
			if(!shell){
			if(leftb){//if you press left before, your shield will appear at your left
				sh->move(me->getRect().left()-22,me->getRect().bottom()-22);
				}
			if(rightb){//vice versa
				sh->move(me->getRect().right()-15,me->getRect().bottom()-22);}
			shell=true;}
			else//if the shell has already appeared, press x again to take it back;
				shell=false;}
		}
		break;
	case Qt::Key_H:
		{
			if(!help){
			help=true;
			pauseGame();}
			else
			{
				help=false;
				pauseGame();
			}
		}
		break;
	case Qt::Key_Z:
		{
			jumpup=true;//you can only jump in level 2
		}
		break;
    case Qt::Key_S:
        {
          startGame();//start the game by press s, reset level1
        }
        break;
    case Qt::Key_Escape:
        {
          qApp->exit();
        }
        break;
    default:
        QWidget::keyPressEvent(event);

    }
}

void Game::startGame()
{ 
	if(!gameStarted){
    me->resetState();
    honey->move(rand()%230+35,30);//reselect a location for the honey
	big->reset();
  int k=0;
  for (int i=0;i<2;i++){
  m1[k]->move(rand()%230+35,i*250+35);
  m2[k]->move(rand()%230+35,i*80+112);//relocate the monsters
  k++;}
  oct->reset();
    life=3;
    score=0;
	numm1=2;//all the monsters are alive
	numm2=2;
	numm3=2;
	numm4=2;
	over=0;
	p=0;
	r=0;
	s=0;
	t=0;
	x = 0;
	shell=false;
    top = FALSE;
    gameOver = FALSE; 
    gameWon = FALSE; 
	bullm=false;
    numbull=0;
	mr=false;
	ml=false;
	leftb=false;
	rightb=false;
	level1=true;//begin with level 1
	level2=false;
	level3=false;
	jumpup=false;
	jumpdown=false;

	for (int i=0; i<numm1; i++) 
      m1[i]->setDestroyed(FALSE);
	for (int i=0; i<numm2; i++) 
		m2[i]->setDestroyed(FALSE);
    timerId = startTimer(10);  
	gameStarted = TRUE;}
}

void Game::pauseGame()
{
  if (paused) {
    timerId = startTimer(10);
    paused = FALSE;
  } else {
    paused = TRUE;
    killTimer(timerId); //pause the game by stop the timmimg
   }
}

void Game::stopGame()
{
  killTimer(timerId);        
  gameStarted = FALSE;//if game stopped, game is not started
}


void Game::checkCollision()
{
	
      int meLeft = me->getRect().left();  
      int meHeight = me->getRect().height(); 
      int meWidth = me->getRect().width();
      int meTop = me->getRect().top();  
	  int meBottom = me->getRect().bottom();

	if(level1){
    for (int i=0;i<numm1;i++)
    if((me->getRect()).intersects(m1[i]->getRect())){
		   shell=false;
		   bullm=false;
           me->resetState();
		   for(int i=0;i<numbull;i++)
		   bull[i]=false;
		   jumpup=false;
		   jumpdown=false;
		   left=true;
		   leftb=false;
		   right=true;
		   rightb=false;
		   up=false;
		   down=false;
           life--;//reset when you lose a life when touch a monster
	}
	for (int i=0;i<numm2;i++)
      if((me->getRect()).intersects(m2[i]->getRect())){
		   shell=false;
		   bullm=false;
           me->resetState();
		   jumpup=false;
		   jumpdown=false;
           life--;
		   for(int i=0;i<numbull;i++)
		   bull[i]=false;
		   jumpup=false;
		   jumpdown=false;
		   left=true;
		   leftb=false;
		   right=true;
		   rightb=false;
		   up=false;
		   down=false;
	  }  
  //What will happen when the bear touches one of the monsters
	  if(!bullm){
	  if(meBottom<=319&&meBottom>=239){
		  if(!m1[1]->isDestroyed()){
		  if(meLeft>m1[1]->getRect().left()){
			  bm->moveto(m1[1]->getRect().right()+1,m1[1]->getRect().bottom()-15);
			  ml=false;
			  mr=true;//if you appear to the right of the monster, the monster's bullet will be fired right
			  }
		  else{
			  bm->moveto(m1[1]->getRect().left()+1,m1[1]->getRect().bottom()-15);
			  mr=false;
			  ml=true;}
		  bullm=true;

		  }}
	  if(meBottom<=237&&meBottom>=158){//set different monsters to react in different levels
		  if(!m2[1]->isDestroyed()){
		  if(meLeft>m2[1]->getRect().right()){
			  bm->moveto(m2[1]->getRect().right()+1,m2[1]->getRect().bottom()-15);
			  ml=false;
			  mr=true;}
		  else{
			  bm->moveto(m2[1]->getRect().left()+1,m2[1]->getRect().bottom()-15);
			  mr=false;
			  ml=true;
		  }
		  bullm=true;}}
	  if(meBottom<=155&&meBottom>=74){
		  if(!m2[0]->isDestroyed()){
		  if(meLeft>m2[0]->getRect().right()){
			  bm->moveto(m2[0]->getRect().right()+1,m2[0]->getRect().bottom()-15);
			  ml=false;
			  mr=true;}
		  else{
			  bm->moveto(m2[0]->getRect().left()+1,m2[0]->getRect().bottom()-15);
			  mr=false;
			  ml=true;
		  }
		  bullm=true;}}
	  if(meBottom<=71&&meBottom>=30){
		  if(!m1[0]->isDestroyed()){
		  if(meLeft>m1[0]->getRect().right()){
			  bm->moveto(m1[0]->getRect().right()+1,m1[0]->getRect().bottom()-15);
			  ml=false;
			  mr=true;}
		  else{
			  bm->moveto(m1[0]->getRect().left()+1,m1[0]->getRect().bottom()-15);
			  mr=false;
			  ml=true;
		  }
		  bullm=true;}}
	  }


  if(me->getRect().left()>=15&&me->getRect().left()<=30){//set all the conditions when you can go up or go down, when you can move left or right
	  up=true;
	  down=true;
	  if(me->getRect().bottom()<319)
		  up=false;
	  if(me->getRect().bottom()<318||me->getRect().bottom()>399)
		  down=false;
	  if(me->getRect().bottom()>=320&&me->getRect().bottom()<=396){
		  left=false;
		  right=false;
	  }
	  else{
		  left=true;
		  right=true;}
  }
  else if(me->getRect().left()>=197&&me->getRect().left()<=216){
	  up=true;
	  down=true;
	  if(me->getRect().bottom()<237||me->getRect().bottom()>320)
		  up=false;
	  if(me->getRect().bottom()<234||me->getRect().bottom()>317)
		  down=false;
	  if(me->getRect().bottom()<=317&&me->getRect().bottom()>=238){
		  left=false;
		  right=false;
	  }
	  else{
		  left=true;
		  right=true;}
  }
  else if(me->getRect().left()>=71&&me->getRect().left()<=83){
	  up=true;
	  down=true;
	  if(me->getRect().bottom()>=156&&me->getRect().bottom()<=230){
		  left=false;
		  right=false;}
	  else{
		  left=true;
		  right=true;}
	  if(me->getRect().bottom()<155||me->getRect().bottom()>238)
		  up=false;
	  if(me->getRect().bottom()<154||me->getRect().bottom()>235)
		  down=false;
  }
  else if(me->getRect().left()>=243&&me->getRect().left()<=257){
	  up=true;
	  down=true;
	  if(me->getRect().bottom()<71||me->getRect().bottom()>156)
		  up=false;
	  if(me->getRect().bottom()<70||me->getRect().bottom()>153)
		  down=false;
	  if(me->getRect().bottom()<=153&&me->getRect().bottom()>=72){
		  left=false;
		  right=false;
	  }
	  else{
		  left=true;
		  right=true;}
  }
  else{
	  up=false;
	  down=false;
	  left=true;
	  right=true;
  }

      if((me->getRect()).intersects(honey->getRect())){//if you have reached the honey at the top, reset all the setting of level 2, go to level2
           score+=50;
		   me->moveto(40,354);
		   numm3=2;
		   numm4=2;
		   for (int i=0; i<numm3; i++) 
		   m3[i]->setDestroyed(FALSE);
	       for (int i=0;i<numm4;i++)
		   m4[i]->setDestroyed(FALSE);
		   oct->reset();
		   heart->move(rand()%230+35,62);
		   for(int i=0;i<2;i++){
			m3[i]->move(40*i,146*i+160);
			m4[i]->move(240-40*i,140*i+95);
			m3[i]->setdir(1,-1);
			m4[i]->setdir(-1,-1);
		   }
		    
		    jumpup=false;
			jumpdown=false;
			left=true;
			leftb=false;
			right=true;
			rightb=false;
			up=false;
			down=false;
			shell=false;
		   bullm=false;
		   level1=false;
		   level2=true;
		   level3=false;
		   for(int k=0;k<100;k++)
			bull[k]=false;
		   numbull=0;
        } 
	  for(int p=0;p<numbull;p++){//if a bullet you fired touches a monster, it disappears
		  if(b1[p]->getRect().left()<=0||b1[p]->getRect().right()>=300)
			  bull[p]=false;
		  for (int y=0;y<numm1;y++)
			  if(!m1[y]->isDestroyed()){
				if(b1[p]->getRect().intersects(m1[y]->getRect())&&bull[p]==true){
				  m1[y]->setDestroyed(true);
				  bullm=false;
				  numm1--;
				  score+=10;}}
		  for (int y=0;y<numm2;y++)
			  if(!m2[y]->isDestroyed()){
			  if(b1[p]->getRect().intersects(m2[y]->getRect())&&bull[p]==true){
				  m2[y]->setDestroyed(true);
				  bullm=false;
				  numm2--;
				  score+=10;}}
	  }
	  
	  if(bm->getRect().left()<=0||bm->getRect().right()>=300||bm->getRect().intersects(sh->getRect()))//if the monster's bullet touches the shell, it will disappear
		  bullm=false;
	  if(bm->getRect().intersects(me->getRect())){
		  if(bullm){
		  me->resetState();
		  bullm=false;
		  shell=false;
		  for(int i=0;i<numbull;i++)
		  bull[i]=false;
		   jumpup=false;
		   jumpdown=false;
           life--;
		   jumpup=false;
		   jumpdown=false;
		   left=true;
		   leftb=false;
		   right=true;
		   rightb=false;
		   up=false;
		   down=false;}
	  }
}
	   if(level2){
		  for (int i=0;i<numm3;i++)
		   if((me->getRect()).intersects(m3[i]->getRect())){//reset when touched by  monster
			   me->moveto(40,354);
			   for(int i=0;i<numbull;i++)
			   bull[i]=false;
		   jumpup=false;
		   jumpdown=false;
		   oct->reset();
		   left=true;
		   leftb=false;
		   right=true;
		   rightb=false;
		   up=false;
		   down=false;
           life--;
	}
		   for(int i=0;i<numm4;i++)
		   if((me->getRect()).intersects(m4[i]->getRect())){
			   me->moveto(40,354);
			   for(int i=0;i<numbull;i++)
			   bull[i]=false;
		   jumpup=false;
		   jumpdown=false;
		   oct->reset();
		   left=true;
		   leftb=false;
		   right=true;
		   rightb=false;
		   up=false;
		   down=false;
           life--;
	}
		   if(me->getRect().intersects(oct->getRect())){
		   me->moveto(40,354);
		   for(int i=0;i<numbull;i++)
			   bull[i]=false;
		   jumpup=false;
		   oct->reset();
		   jumpdown=false;
		   left=true;
		   leftb=false;
		   right=true;
		   rightb=false;
		   up=false;
		   down=false;
           life--;
			}

		   for(int q=0;q<numbull;q++){//a monster is killed when you shoot it
		  if(b1[q]->getRect().left()<=0||b1[q]->getRect().right()>=300)
			  bull[q]=false;
		  for (int y=0;y<numm3;y++)
			  if(!m3[y]->isDestroyed()){
				if(b1[q]->getRect().intersects(m3[y]->getRect())&&bull[q]==true){
				  m3[y]->setDestroyed(true);
				  bull[q]=false;
				  numm3--;
				  score+=10;}}
		  for (int y=0;y<numm4;y++)
			  if(!m4[y]->isDestroyed()){
				if(b1[q]->getRect().intersects(m4[y]->getRect())&&bull[q]==true){
				  m4[y]->setDestroyed(true);
				  bull[q]=false;
				  numm4--;
				  score+=10;}}
			  if(b1[q]->getRect().intersects(oct->getRect())&&bull[q]==true){
				  bull[q]=false;
				  score+=10;
				  oct->reset();}
		   }
		   if(me->getRect().intersects(heart->getRect())){//if you reached the heart, get one bonus life and go to level 3
			   life++;
			   jumpup=false;
			jumpdown=false;
			left=true;
			leftb=false;
			right=true;
			rightb=false;
			up=false;
			bee->move(150,130);
			down=false;
			shell=false;
		   bullm=false;
		   
		   me->resetState();
		   bee->setDestroyed(false);
		   big->reset();
		   for(int i=0;i<5;i++)
			   bbull[i]=false;
		   for(int k=0;k<100;k++)
			bull[k]=false;
		   numbull=0;
		   level1=false;
		   level2=false;
		   level3=true;
		   }
		   if (jumpup){//set all conditions that what height the bear may jump and make sure it stay on one level
			   if(meBottom<=400&&meBottom>=330){
				   p=0;
				   r=0;
				   s=0;
				   t=0;
			   }
			   if(meTop==262||meTop==263){
				   if(p==0){
				   jumpup=false;
				   jumpdown=true;
				   p=1;
				   r=0;
				   s=0;
				   t=0;
				   }
				   else
					   jumpup=true;
				   }
			   
			   if(meTop==196||meTop==197){
				   if(r==0){
				   jumpup=false;
				   jumpdown=true;
				   p=0;
				   r=1;
				   s=0;
				   t=0;
				   }
				   else
					   jumpup=true;
			   }
			   if(meTop==115||meTop==116){
				   if(s==0){
				   jumpup=false;
				   jumpdown=true;
				   p=0;
				   r=0;
				   s=1;
				   t=0;
				   }
				   else
					   jumpup=true;
			   }
			   if(meTop==56||meTop==57){
				   if(t==0){
				   jumpup=false;
				   jumpdown=true;
				   p=0;
				   r=0;
				   s=0;
				   t=1;
				   }
				   else
					   jumpup=true;
			   }
			   if(meTop==30){
				   jumpup=false;
				   jumpdown=true;
			   }
		   }

  if (jumpdown){//stop it falling when it reach a height
	   if(meBottom==312||meBottom==313||meBottom==168||meBottom==167)
		{	
		jumpdown=false;
	    }
	   if(meBottom==248||meBottom==249||meBottom==107||meBottom==108)
		{
			jumpdown=false;
		}
	  if(meBottom==400||meBottom==399)
		  jumpdown=false;
	  }

	  }
	  if(level3){
		  
		  if(!bee->isDestroyed()){//set the condition that you can only go up when climbing the ladder
			  if(meLeft>=16&&meLeft<=35){
			  if(meBottom>=107&&meBottom<=401)
				  up=true;
			  else
				  up=false;
			  if(meBottom>=100&&meBottom<=399)
				  down=true;
			  else
				  down=false;
			  if(meBottom>=106&&meBottom<=396){left=false;right=false;}
			  else{left=true;right=true;}
		  }
		  if(meTop<=223&&meTop>212){//you reached some height, the big bee will shoot at you with some bullet
			  if(!bbull[0]){
				  bb[0]->moveto(181,223);
				  bbull[0]=true;}
		  }
		  if(meTop<=212&&meTop>190){
			  if(!bbull[1]){
				  bb[1]->moveto(181,202);
				  bbull[1]=true;}
		  }
		  if(meTop<=190&&meTop>169){
			  if(!bbull[2]){
				  bb[2]->moveto(181,181);
				  bbull[2]=true;}
		  }
		  if(meTop<=169&&meTop>148){
			  if(!bbull[3]){
				  bb[3]->moveto(181,159);
				  bbull[3]=true;}
		  }
		  if(meTop<=148&&meTop>130){
			  if(!bbull[4]){
				  bb[4]->moveto(181,140);
				  bbull[4]=true;}
		  }}
		  else{//if the bee is killed, you can go to the higher level and get the honey
			  if(meLeft>=16&&meLeft<=35){
			  if(meBottom>=107&&meBottom<=401)
				  up=true;
			  else
				  up=false;
			  if(meBottom>=104&&meBottom<=232)
				  down=true;
			  else
				  down=false;
			  if(meBottom>=106&&meBottom<=229){left=false;right=false;}
			  else{left=true;right=true;}
			  }
		  }
		  for(int i=0;i<5;i++){//if you touches one of the bee's bullet, you lose one life.
			  if(bb[i]->getRect().left()<=0)
				  bbull[i]=false;
			  if(bb[i]->getRect().intersects(me->getRect()))
				  if(bbull[i]){
					  me->resetState();
					  life--;
					  up=false;
					  down=false;
					  left=true;
					  right=true;
					  for(int a=0;a<numbull;a++)
					  bull[a]=false;
				  bbull[i]=false;
				  
				  }
		  }
		  for(int i=0;i<numbull;i++){//if you hit the bee 30 times. The bee is killed
			  if(!bee->isDestroyed()){
				if(b1[i]->getRect().intersects(bee->getRect())&&bull[i]==true){
				  bull[i]=false;
				  score+=10;
				  over++;
				  if(over>=30){
				  bee->setDestroyed(true);
				  score+=100;
				  for(int i=0;i<5;i++)
					  bbull[i]=false;}
				}}
			  }
		  if(me->getRect().intersects(big->getRect())){
			  stopGame();
			  gameWon=true;//if you get the big honey, You Won!!
		  }

	  }
if (life==0){
           stopGame();//when life=0,gameover 
		   gameOver=true;}
}
        
