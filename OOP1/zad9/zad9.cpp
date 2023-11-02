//https://ivtipm.github.io/Programming/Glava01/index01.htm#z9
//Задача 9
//Вычисление общего сопротивления для 3х параллельно подключенных сопротивлений

#include <iostream>
#include <math.h>

using namespace std;

float parallelR(float r1, float r2, float r3)
{
	float R;
	R = (r1 * r2 * r3) / (r1 * r2 + r2 * r3 + r3 * r1);
	return R;
}

float r1,r2,r3,R;

int main()
{
	while (1) {
		cout << "R1 = "; //ввод 1 сопротивления
		cin >> r1;

		cout << "R2 = "; //ввод 2 сопротивления
		cin >> r2;

		cout << "R3 = "; //ввод 3 сопротивления
		cin >> r3;

		R = parallelR(r1,r2,r3); //вычисление общего сопротивления
		//формула v
		//https://www.google.com/url?sa=i&url=https%3A%2F%2Felektroznatok.ru%2Finfo%2Felektronika%2Fsoedinenie-rezistorov&psig=AOvVaw2E3EuhNe3PTub62cMz3RLh&ust=1693615724513000&source=images&cd=vfe&opi=89978449&ved=0CA4QjRxqFwoTCPiksq-YiIEDFQAAAAAdAAAAABAD

		cout << "R(parallel 1,2,3) = " << R << endl << endl; //вывод общего сопротивления

	}

	return 0;
}