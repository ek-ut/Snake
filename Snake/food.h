#pragma once
#include "unit.h"
#include <cstdlib>
int randomi(int min, int max);
class food : public unit // ������� ���, ��������� �� ������� ��������
{
public:
	food();
	void SetPoints(int Points); //��������� ���������� ����� ������� ����� ����������� ��� ��������
	void SetLifetime(int Lifetime);// ��������� ����� ����� ��������
	int GetPoints();// �������� ���������� ����� �����������
	int GetLifetime();// �������� ����� ����� ������
	virtual void moov();
protected:
	int points = 0;
	int lifetime = 0;
};

//**************************** ������������� ��� � ����*************************//
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

