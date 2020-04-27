#pragma once
class unit // basic element of the game
{
public:
	unit();
	unit(int x, int y);
	void GetPos(int* x, int* y); //	get item position
	void SetPos(int x, int y);// assign item position
	void GetColor(int* R, int* G, int* B); //get item color
	void SetColor(int R, int G, int B); // assign item color

protected:
	int posX = 0;
	int posY = 0;
	int colorR = 0;
	int colorG = 0;
	int colorB = 0;

};

