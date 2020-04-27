#include "food.h"

int randomi(int min, int max)
{
	
	return min + rand() % (max - min);
}

food::food()
{
	lifetime = randomi(30000, 60000); 
}

void food::SetPoints(int Points)
{
	points = Points;
}
void food::SetLifetime(int Lifetime)
{
	lifetime = Lifetime;
}
int food::GetPoints()
{
	return points;
}
int food::GetLifetime()
{
	return lifetime;
}
void food::moov()
{

 }



berry::berry()
{
	colorR = 255;
	colorG = 0;
	colorB = 0;
	points = 1;
}
apple::apple() 
{
	colorR = 0;
	colorG = 255;
	colorB = 0;
	points = 2;
}
banana::banana()
{
	colorR = 255;
	colorG = 255;
	colorB = 0;
	points = 3;
}
grape::grape()
{
	colorR = 0;
	colorG = 0;
	colorB = 255;
	points = 4;
}