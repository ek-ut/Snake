#include "GameForm.h"

std::vector<food*> Foods;
std::vector<snake*> Snake;
int TimeNewFood = 0;
int d = 0;
int Points = 0;
int gameForma;
GLdouble xStart, yStart;

bool Menu = true;
bool Over = false;


void reshape(int w, int h) // scene making
{
	Createhead();
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, COLUMNS, 0, ROWS, -1, 1);
	glMatrixMode(GL_MODELVIEW);
}

void render() //scene redrawing
{
	if (!Menu)
	{
		if (!Over)
		{

			CreateMap();
			AddFood();
			RefreshFoods();
			RefreshSnake();
			GameOver();
			PrintPoints(Points);
			glutSwapBuffers();
		}
	}
	else
	{
		MenuForm();

		glutSwapBuffers();
	}
}

void timer(int t)//timer yes scene updates
{

	int Spid = TimerT - (Snake.size() - 1) * 10;
	glutPostRedisplay();
	glutTimerFunc(Spid, timer, 0);

}

void keyboard_Special(int key, int lParam, int wPram) // processing system buttons
{

	//d = 0;
	switch (key)
	{
	case GLUT_KEY_UP:
		d = UP;
		break;
	case GLUT_KEY_DOWN:
		d = DOWN;
		break;
	case GLUT_KEY_LEFT:
		d = LEFT;
		break;
	case GLUT_KEY_RIGHT:
		d = RIGHT;
		break;
	case GLUT_KEY_INSERT:
		Over = false;
		break;

	}

}

void keyboard_Normal(unsigned char key, int lParam, int wPram) // handling standard buttons
{
	d = 0;
	switch (key)
	{

	case 13: // ENTER
		Over = false;
		break;

	case 27: // Esc
		if (Menu || Over)
		{
			glutDestroyWindow(gameForma);
		}
		break;

	}

}




void MenuForm() // start menu creation
{
	glClearColor(0, 0, 0, 250);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnd();


	glColor3ub(255, 0, 0);

	xStart = COLUMNS / 2 - 4;
	yStart = ROWS / 2 + 7;
	glRectd(xStart, yStart, xStart + 8, yStart - 2);
	glRectd(xStart, yStart - 4, xStart + 8, yStart - 6);

	const  char* c = "START GAME";
	const unsigned char* a = reinterpret_cast<const unsigned char*>(c);
	glColor3ub(0, 255, 255);
	glRasterPos2f(xStart + 1.6, yStart - 1.25f);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, a);

	c = "Exit";
	a = reinterpret_cast<const unsigned char*>(c);
	glColor3ub(0, 255, 255);
	glRasterPos2f(xStart + 3.5, yStart - 5.25f);
	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, a);



}

void MouseFunc(int button, int state, int x, int y) //start menu processing
{

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		int y1 = 900 - y;
		if (((xStart + 1) * COLUMNS < x && (xStart + 10) * COLUMNS > x) &&
			(yStart * ROWS > y1 && (yStart - 2)* ROWS < y1))
		{
			Menu = false;
		}

		if (((xStart + 1) * COLUMNS < x && (xStart + 10) * COLUMNS > x) &&
			((yStart - 4) * ROWS > y1 && (yStart - 6)* ROWS < y1))
		{
			glutDestroyWindow(gameForma);
		}

	}

}

void CreateMap() // creating marginsand map borders.
{
	glClearColor(0, 0, 0, 250);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	/**********линии на карте**************/
	/*glColor3ub(255, 255, 255);
	glLineWidth(1);
	glBegin(GL_LINES);

	for (int x = 0; x < COLUMNS; x++)
	{
		for (int y = 0; y < ROWS; y++)
		{
			glVertex2i(x, y);
			glVertex2i(x, y + 1);
			glVertex2i(x, y);
			glVertex2i(x + 1, y);
		}
	}
	glEnd();*/
	/****************клнец линий**********************/

	//**************отрисовка граних карты*************/
	glColor3ub(255, 0, 0);

	for (GLdouble x = 0; x < COLUMNS; x++)
	{
		for (GLdouble y = 0; y < ROWS; y++)
		{
			if (x == 0 || x == (GLdouble)(COLUMNS - 1) || y == 0 || y == (GLdouble)(ROWS - 1))
			{
				glRectd(x, y, x + 1, y + 1);
			}
		}
	}
	/****************клнец границ**********************/
}

bool CheckCollision()//collision check
{
	bool Collision = false;
	int xHead, yHead, xCurrent, yCurrent;
	snake* hSnake;
	hSnake = Snake.at(0);
	hSnake->GetPos(&xHead, &yHead);
	int sizeSnake = Snake.size() - 1;
	if (xHead == 1 || xHead == COLUMNS - 1 || yHead == 1 || yHead == ROWS - 1)
	{
		Collision = true;
	}
	else
	{
		for (int i = sizeSnake; i > 1; i--)
		{
			hSnake = Snake.at(i);
			hSnake->GetPos(&xCurrent, &yCurrent);
			if (xHead == xCurrent && yHead == yCurrent)
			{
				Collision = true;
			}
		}
	}
	return Collision;

}

void PrintPoints(int paramPoints)// display current result
{


	std::string str = "POINTS  " + to_string(paramPoints);
	const  char* c = str.data();
	const unsigned char* a = reinterpret_cast<const unsigned char*>(c);

	glColor3ub(0, 255, 0);
	glRasterPos2f(COLUMNS / 2 - 3, ROWS - 1);

	glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, a);
}

void GameOver()// stop the game and display the keyboard menu
{
	if (CheckCollision())
	{

		const  char* c = "GAME OVER";
		const unsigned char* a = reinterpret_cast<const unsigned char*>(c);
		glColor3ub(255, 0, 0);
		glRasterPos2f(COLUMNS / 2 - 3, ROWS / 2 + 1);
		glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, a);

		c = "to start a new game, press ENTER";
		a = reinterpret_cast<const unsigned char*>(c);
		glRasterPos2f(COLUMNS / 2 - 6, ROWS / 2 - 1);
		glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, a);

		c = "Exit, press Esc";
		a = reinterpret_cast<const unsigned char*>(c);
		glRasterPos2f(COLUMNS / 2 - 3, ROWS / 2 - 3);
		glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, a);

		std::string str = "YOUR RESULT:   " + to_string(Points);
		c = str.data();
		a = reinterpret_cast<const unsigned char*>(c);
		glColor3ub(0, 255, 0);
		glRasterPos2f(COLUMNS / 2 - 4, ROWS / 2 + 5);
		glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, a);

		Over = true;

		TimeNewFood = 0;
		d = 0;

		Points = 0;
		Foods.clear();
		Createhead();

	}
}



void Createhead()//making snake head
{

	Snake.clear();
	snake* hs = new headsnake();
	hs->SetPos(randomi(1, COLUMNS - 1), randomi(1, ROWS - 1));
	Snake.push_back(hs);
}

void Createtail()//creating one snake segment
{
	snake* ts = new tailsnake();
	snake* Last = Snake.at(Snake.size() - 1);
	int x, y;
	Last->GetPos(&x, &y);
	ts->SetPos(x, y);
	Snake.push_back(ts);
}

void RefreshSnake()//redrawing the snake in a new position
{
	int x, y, r, g, b;
	snake* hs;
	snake* hsPrev;
	int sizeSnake = Snake.size() -1;
	for (int i = sizeSnake ; i > 0; i--)
	{
		hs = Snake.at(i);
		hsPrev = Snake.at(i-1);
		hsPrev->GetPos(&x, &y);
		hs->SetPos(x, y);
		hs->GetColor(&r, &g, &b);
		glColor3ub(r, g, b);
		glRecti(x, y, x + 1, y + 1);
	}
	hs = Snake.at(0);
	hs->Move(d);
	hs->GetPos(&x, &y);
	hs->GetColor(&r, &g, &b);
	glColor3ub(r, g, b);
	glRecti(x, y, x + 1, y + 1);
	Eat();

}

void ChengeColor(int r, int g, int b) //snake color changes
{
	snake* hs;
	int sizeSnake = Snake.size() - 1;
	for (int i = sizeSnake; i > 0; i--)
	{
		hs = Snake.at(i);
		hs->SetColor(r, g, b);
	}
}




bool AddFood() //adding food to the list
{
	if (Foods.empty())
	{
		TimeNewFood = 0;
	}
	if ((Foods.size() > 5) || TimeNewFood > 0)
	{
		return false;
	}
	int TypeFood = randomi(BERRY, GRAPE + 1);
	food* Food;
	switch (TypeFood)
	{
	case BERRY:
		Food = new berry();
		break;
	case APPLE:
		Food = new apple();
		break;
	case BANANA:
		Food = new banana();
		break;
	case GRAPE:
		Food = new grape();
		break;

	default:
		return false;
		break;
	}
	Food->SetPos(randomi(1, COLUMNS - 1), randomi(1, ROWS - 1));
	TimeNewFood = randomi(5000, 20000);
	Foods.push_back(Food);
	return true;

}

void RefreshFoods()// food redrawing
{
	int x, y, r, g, b;
	int TimeL;
	int sizeFoods = Foods.size();
	food* Food;
	for (int i = 0; i < sizeFoods; i++)
	{
		Food = Foods.at(i);
		Food->GetPos(&x, &y);
		Food->GetColor(&r, &g, &b);
		TimeL = Food->GetLifetime() - TimerT;
		Food->SetLifetime(TimeL);
		if (TimeL <= 0)
		{
			DelFood(i);
			i--;
			sizeFoods--;
		}
		else
		{
			glColor3ub(r, g, b);
			glRecti(x, y, x + 1, y + 1);
		}

	}

	TimeNewFood = TimeNewFood - TimerT;
}

void Eat()// check can either sit food and eat it
{
	int xHead, yHead, xFood, yFood;
	int r, g, b;
	snake* hs;
	food* Food;
	hs = Snake.at(0);
	hs->GetPos(&xHead, &yHead);
	int sizeFoods = Foods.size();
	for (int i = 0; i < sizeFoods; i++)
	{
		Food = Foods.at(i);
		Food->GetPos(&xFood, &yFood);
		if (xHead == xFood && yHead == yFood) // if the head coincides with the food, then its snake sedans
		{
			Food->GetColor(&r, &g, &b);
			Points = Points + Food->GetPoints();
			DelFood(i);
			i--;
			sizeFoods--;
			Createtail();
			ChengeColor(r, g, b);
		}
	}
}

void DelFood(int Indeks)// removing food by index in array
{
	Foods.erase(Foods.begin() + Indeks);
}



GameForm::GameForm(int argc, char* argv[]) // run OpenGL form
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH); //Init Display
	glutInitWindowPosition(100, 50);//screen position
	glutInitWindowSize(1000, 900);  // Set the window size
	gameForma =	glutCreateWindow("Snake"); //creating a window with the name
	glutDisplayFunc(render);// connection scene update
	glutReshapeFunc(reshape);//connection scene creation
	glutTimerFunc(TimerT, timer, 1);// connection start timer
	glutSpecialFunc(keyboard_Special); // connection keyboard tracking
	glutKeyboardFunc(keyboard_Normal); //connection keyboard tracking
	glutMouseFunc(MouseFunc); //mouse tracking connection
	glutMainLoop(); // show window
}

GameForm::~GameForm()
{
	glutDestroyWindow(gameForma);
}



