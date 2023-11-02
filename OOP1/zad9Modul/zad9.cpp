//https://ivtipm.github.io/Programming/Glava01/index01.htm#z9
//Задача 9
//Вычисление общего сопротивления для 3х параллельно подключенных сопротивлений
//Программа Непомнящих Станислава

#include <iostream>
#include <cassert>
#include "modul9.h"

using namespace std;

int (int argc, char* argv[])
{
	assert(parallelR(3,3,3) == 1);
	assert(parallelR(2,2,3) == 0.75);
	assert(parallelR(6,6,6) == 2);

	unsigned carg = argc; //Параметр количества аргументов								

	if (carg != 3){
		cout << "R1 = "; //ввод 1 сопротивления
		cin >> r1;

		cout << "R2 = "; //ввод 2 сопротивления
		cin >> r2;

		cout << "R3 = "; //ввод 3 сопротивления
		cin >> r3;
	}
	else{
		r1 = argv[1];
		r1 = argv[2];
		r3 = argv[3];

	}

	R = parallelR(r1,r2,r3); //вычисление общего сопротивления

	cout << "R(parallel 1,2,3) = " << R << endl << endl; //вывод общего сопротивления

	return 0;
}