#pragma once
#include "unit.h"
#include <cstdlib>
int randomi(int min, int max);
class food : public unit // элемент еда, созданный на базовом элементе
{
public:
	food();
	void SetPoints(int Points); //назначить количество очков которое будит начисляться при поедании
	void SetLifetime(int Lifetime);// назначить время жизни элемента
	int GetPoints();// получить количество очком ззапоедание
	int GetLifetime();// получить время жизни обекта
	virtual void moov();
protected:
	int points = 0;
	int lifetime = 0;
};

//**************************** разновидность еды в игре*************************//
class berry : public food
{
public:
	berry();
};

class apple : public food
{
public:
	apple();
};

class banana : public food
{
public:
	banana();
};

class grape : public food
{
public:
	grape();
};
////////////////////////////////////////////////////////////////////////////

