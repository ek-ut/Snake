#include "snakeClass.h"

snake::snake()
{

}
 bool snake::Move(int direction)
{
	 return true;
}
 void snake::ColorChange(int r, int g, int b)
 {

 }
 bool snake::Move()
 {
	 return true;
  }

 bool snake::Move(int x, int y)
 {
	 return true;
 }

 headsnake::headsnake() //making a head serpent
 {
	 
	 SetColor(255, 0, 255);
 }

 bool headsnake::Move(int direction)//moving head with direction
 {
	 int x, y;
	 GetPos(&x, &y);
	 switch (direction)
	 {
	 case UP:
		 SetPos(x , y+1);
		 break;
	 case DOWN:
		 SetPos(x , y-1);
		 break;
	 case LEFT:
		 SetPos(x-1 , y );
		 break;
	 case RIGHT:
		 SetPos(x+1, y);
		 break;

	 }
	 Direction = direction;
	 return true;
 }

 bool headsnake::Move()//moving head without direction
 {
	 Move(Direction);
	 return true;
 }

 tailsnake::tailsnake()// snake fragment creation
 {
	 
	 SetColor(0, 255, 255);
 }