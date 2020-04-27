#include "unit.h"

/*************basic element of the game*****************/

unit::unit() 
{
	
}
unit::unit(int x, int y)
{
	posX = x;
	posY = y;
}
void unit::GetPos(int* x, int* y)//get item position
{
	*x = posX;
	*y = posY;
}
void unit::GetColor(int* R, int* G, int* B)// get item color
{
	*R = colorR;
	*G = colorG;
	*B = colorB;
}

void unit::SetPos(int x, int y)//assign item position
{
	posX = x;
	posY = y;
}
void unit::SetColor(int R, int G, int B) //assign item color
{
	colorR = R;
	colorG = G;
	colorB = B;
}
