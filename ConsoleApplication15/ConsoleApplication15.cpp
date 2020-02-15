// ConsoleApplication15.cpp: главный файл проекта.

#include "stdafx.h"
#include "Field.h"
 
bool ex = true;
int c=0;
int q=0;

void threadFunction()
{
	while (ex) {
		c = getch();
	}
	
}

int main()
{
	srand(time(0));
	Console::WindowHeight = 30;
	Console::WindowWidth = 40;
	Console::BufferHeight = 30;
	Console::BufferWidth = 40;
	Console::WindowLeft = 00;
	Console::WindowTop = 00;
	Field f;

	Thread^ newThread = gcnew Thread(gcnew ThreadStart(threadFunction));
	newThread->Start();
	
	while (ex=f.getState()) {
		f.UpdateField();
		if (c == 75) { f.move(c); }
		if (c == 77) { f.move(c); }
		if (c == 102) { f.fire(); }
		c = 0;
		if (!f.met()) { q = 0 + rand() % 36; f.zapusk(q); };
	}
	Console::Clear();
	Console::Write("Вы проиграли");
	
    return 0;
}
