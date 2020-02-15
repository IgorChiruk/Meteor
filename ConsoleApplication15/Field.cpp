#include "stdafx.h"
#include "Field.h"


void Field::move(int i)
{
	if (i == 75) { s.downCord(); }
	if (i == 77) { s.upCord(); }
}

void Field::fire()
{
	if (!b.getState()) {
		b.setState(1);
		cordF = s.getCord() + 3;
	}
}

bool Field::met()
{
	return m.getState();
}

bool Field::getState()
{
	return s.getState();
}

void Field::zapusk(int i)
{
	if (!m.getState()) {
		m.setState(1);
		cordM = i;
	}
}
                             //Отрисовка поля
void Field::UpdateField()
{
	Console::Clear();
	
	//Обнуление поля

	for (int i = 0; i < 39; i++) {
		for (int j = 0; j < 28; j++) {
			mas[j][i] = 0;
		}
	}

	//отрисовка пули

	if (b.getState()) {
		mas[23 - b.getCord()][cordF] = 3;
		b.upCord();
	}

	//отрисовка метеорита !!!если хоть одна из координат метеорита попала на пулю и то и другой уничтожаются!!!

	if (m.getState()) {
		if (mas[m.getCord()][cordM] !=3) {
			mas[m.getCord()][cordM] = 4;
		}
		else { b.destroy(); m.destroy(); }

		if (mas[m.getCord() + 1][cordM + 1] != 3) {
			mas[m.getCord() + 1][cordM + 1] = 4;
		}
		else { b.destroy(); m.destroy(); }

		if (mas[m.getCord() + 1][cordM] != 3) {
			mas[m.getCord() + 1][cordM] = 4;
		}
		else { b.destroy(); m.destroy(); }

		if (mas[m.getCord()][cordM + 1] != 3) {
			mas[m.getCord()][cordM + 1] = 4;
		}
		else { b.destroy(); m.destroy(); }

		if (m.getState()) {m.upCord();}
	}

	//отрисовка корабля !!!если хоть одна из координат корабля попала на метеорит то игра окончена!!!
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 7; j++) {
			if(mas[i + 24][j + s.getCord()]!=4){ mas[i + 24][j + s.getCord()] = s.getmas(i, j); }
			else { s.destroy(); }
		}
	}
	for (int i = 0; i < 28; i++) {
		for (int j = 0; j < 39; j++) {
			if (mas[i][j] == 0) { Console::Write(" "); }
			else if (mas[i][j] == 1)
			{
				system("color 04");
				Console::Write("H");
			}
			else if (mas[i][j] == 2) {
				system("color 02");
				Console::Write("|");
			}
			else if (mas[i][j] == 3) {
				system("color 05");
				Console::Write("O");
			}
			else if (mas[i][j] == 4) {
				system("color 07");
				Console::Write("M");
			}

		}
		Console::WriteLine();
	}
	_sleep(70);
}

Field::Field()
{
	for (int i = 0; i < 39; i++) {
		for (int j = 0; j < 28; j++) {
			mas[j][i]=0;
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 7; j++) {
			mas[i+24][j+s.getCord()] =s.getmas(i,j) ;
		}
	}
}
