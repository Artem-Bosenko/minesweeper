#include "Field.h"

using namespace sf;

Field::Field()
{
	n = 8;
	bomb = 0;
	FieldLogic = new int* [n];
	for (int i = 0; i < n; i++)
		FieldLogic[i] = new int[n];
	FieldView = new int* [n];
	for (int i = 0; i < n; i++)
		FieldView[i] = new int[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			FieldView[i][j] = 10;
			if (bomb != ((pow(n, 2)) / 4)) {
				if (rand() % 5 == 0)
				{
					FieldLogic[i][j] = 9;
					bomb++;
				}
				else continue;
			}
			else FieldLogic[i][j] = 0;
		}
	std::cout << bomb;
}
Field::Field(int a)
{
	n = a;
	bomb = 0;
	FieldLogic = new int* [n];
	for (int i = 0; i < n; i++)
		FieldLogic[i] = new int[n];
	FieldView = new int* [n];
	for (int i = 0; i < n; i++)
		FieldView[i] = new int[n];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			FieldView[i][j] = 10;
			if (bomb != ((pow(n, 2)) / 4)) {
				if (rand() % 5 == 0)
				{
					FieldLogic[i][j] = 9;
					bomb++;
				}
				else continue;
			}
			else FieldLogic[i][j] = 0;
		}
	std::cout << bomb << std::endl;
}
void Field::calc_mine()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			int count = 0;
			if (FieldLogic[i][j] == 9) continue;
			// крайние точки
			if (i == 0 && j == 0)
			{
				if (FieldLogic[0][1] == 9) count++;
				if (FieldLogic[1][0] == 9) count++;
				if (FieldLogic[1][1] == 9) count++;
			}
			if (i == 0 && j == n - 1)
			{
				if (FieldLogic[0][n - 2] == 9) count++;
				if (FieldLogic[1][n - 1] == 9) count++;
				if (FieldLogic[1][n - 2] == 9) count++;
			}
			if (i == n - 1 && j == 0)
			{
				if (FieldLogic[n - 2][0] == 9) count++;
				if (FieldLogic[n - 1][1] == 9) count++;
				if (FieldLogic[n - 2][1] == 9) count++;
			}
			if (i == n - 1 && j == n - 1)
			{
				if (FieldLogic[n - 1][n - 2] == 9) count++;
				if (FieldLogic[n - 2][n - 1] == 9) count++;
				if (FieldLogic[n - 2][n - 2] == 9) count++;
			}

			//линии
			if (i == 0 && j != 0 && j != n - 1)
			{
				if (FieldLogic[i][j + 1] == 9) count++;
				if (FieldLogic[i][j - 1] == 9) count++;
				if (FieldLogic[i + 1][j] == 9) count++;
				if (FieldLogic[i + 1][j - 1] == 9) count++;
				if (FieldLogic[i + 1][j + 1] == 9) count++;
			}
			if (j == 0 && i != 0 && i != n - 1)
			{
				if (FieldLogic[i + 1][j] == 9) count++;
				if (FieldLogic[i - 1][j] == 9) count++;
				if (FieldLogic[i][j + 1] == 9) count++;
				if (FieldLogic[i - 1][j + 1] == 9) count++;
				if (FieldLogic[i + 1][j + 1] == 9) count++;
			}
			if (i == n - 1 && j != n - 1 && j != 0)
			{
				if (FieldLogic[i][j + 1] == 9) count++;
				if (FieldLogic[i][j - 1] == 9) count++;
				if (FieldLogic[i - 1][j] == 9) count++;
				if (FieldLogic[i - 1][j - 1] == 9) count++;
				if (FieldLogic[i - 1][j + 1] == 9) count++;
			}
			if (j == n - 1 && i != 0 && i != n - 1)
			{
				if (FieldLogic[i + 1][j] == 9) count++;
				if (FieldLogic[i - 1][j] == 9) count++;
				if (FieldLogic[i][j - 1] == 9) count++;
				if (FieldLogic[i - 1][j - 1] == 9) count++;
				if (FieldLogic[i + 1][j - 1] == 9) count++;
			}
			// центр
			else if (i != 0 && j != 0 && i != n - 1 && j != n - 1)
			{
				if (FieldLogic[i + 1][j] == 9) count++;
				if (FieldLogic[i - 1][j] == 9) count++;
				if (FieldLogic[i][j + 1] == 9) count++;
				if (FieldLogic[i][j - 1] == 9) count++;
				if (FieldLogic[i - 1][j + 1] == 9) count++;
				if (FieldLogic[i + 1][j + 1] == 9) count++;
				if (FieldLogic[i - 1][j - 1] == 9) count++;
				if (FieldLogic[i + 1][j - 1] == 9) count++;
			}
			FieldLogic[i][j] = count;
		}
}
Field::~Field()
{
	for (int i = 0; i < n; i++)
		delete[] FieldLogic[i];
	delete[] FieldLogic;
	for (int i = 0; i < n; i++)
		delete[] FieldView[i];
	delete[] FieldView;

}