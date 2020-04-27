#pragma once
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <GL/glut.h>
#include <iostream>
#include "food.h"
#include "snakeClass.h"

#include<string>  
//#include <list>
#include<vector>

using namespace std;


#define COLUMNS 30
#define ROWS 30 
#define TimerT 300

void reshape(int w, int h);//scene making
void render();// scene redrawing
void timer(int t); // timer yes scene updates
void keyboard_Normal(unsigned char key, int lParam, int wPram); // handling standard buttons
void keyboard_Special(int key, int lParam, int wPram); //processing system buttons

void MenuForm(); //start menu creation
void MouseFunc(int button, int state, int x, int y);// start menu processing
void CreateMap();// creating marginsand map borders.
bool CheckCollision();//collision check
void PrintPoints(int paramPoints);// display current result
void GameOver(); // stop the game and display the keyboard menu

void Createhead(); //making snake head
void Createtail(); //creating one snake segment
void RefreshSnake();//redrawing the snake in a new position
void ChengeColor(int r, int g, int b);//snake color changes

bool AddFood();//adding food to the list
void RefreshFoods();//food redrawing 
void Eat(); // check can either sit food and eat it
void DelFood(int Indeks);// removing food by index in array










enum FoodsEnum
{
	BERRY = 0,
	APPLE,
	BANANA,
	GRAPE
};





class GameForm
{
public:
	GameForm(int argc, char* argv[]);
	~ GameForm();
	
};

