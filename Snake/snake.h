#pragma once
#include "unit.h"

enum snakeEnum
{
	UP = 0,
	DOWN,
	RIGHT,
	LEFT
	
};
class snake : public unit
{
public:
	snake();
	virtual bool Move();
	virtual bool Move(int direction);
	virtual bool Move(int x, int y);
	virtual void ColorChange(int r, int g, int b);
	

};

class headsnake : public snake
{
public:
	headsnake();
	bool Move(int direction);
	bool Move();
	

private:

	int Direction = 0;

};

class tailsnake : public snake
{
public:
	tailsnake();
	
};

