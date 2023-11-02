//ИВТ-22 Непомнящих Станислав
//Little change


#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <math.h>
#include <string>
#include <vector>

using namespace std;

///Заполнение массива array случайными числами от Down_board до Up_board
void FillArrayRand(vector<double>& array, float Up_board, float Down_board)
{
	unsigned n = array.size();
	int Mrange = Up_board - Down_board; 				//Диапазон рандома	
	for(unsigned i = 0; i < n; i ++)
	{
		//(float)rand()/RAND_MAX выдает значение от 0 до 1
		//*Mrange превращает значение в число из диапазона
		//+Down_board задаёт нач. значение
		array[i] = ((float)rand()/RAND_MAX*Mrange+Down_board);
	}
}

///Вычисляет сумму по условиям задачи 136з
double zad136z(const vector<double>& array)
{
	int negative = 1, factorial = 1;					//Соблюдены знакопеременность и оптимальный факториал
	float result = -1*array[0];
	for(unsigned i = 1; i < array.size(); i ++)
	{
		factorial = factorial * (i+1);
		result=result+(negative*array[i]/factorial);
		negative = -negative;
	}
	return result;
}

///Вывод массива array в файл file_name
void WriteArrayF(const vector<double>& array, const string &file_name)
{
	ofstream file(file_name, ios::binary);
    if (!file.is_open())								//Проверка открытия файла
	{
		throw runtime_error("File opening error") ;

	}
	else
	{
    	for (unsigned long int i = 0; i < array.size(); i++)
        {
            file << array[i] << endl;
        }
        file.close();
	}
};

///Ищет размер файла file_name в виде числа строк
int FileSize(const string &file_name)
{
	string empty_line;									//Пустая строка для подсчёта
	unsigned result = 0;
	ifstream file(file_name);

	if (!file.is_open())								//Проверка открытия файла
	{
		throw runtime_error("File opening error");
	}

	while (getline(file, empty_line))
	{
		result++;
	}

	if (result == 0)									//Проверка открытия файла
	{
		throw invalid_argument("File is empty");
	}

	file.close();
	return (result);
};

///Загрузка массива array размера n из файла file_name
void GetArrayF(vector<double>& array, unsigned size, const string &file_name)
{
    ifstream file(file_name, ios::binary);
    if (!file.is_open())								//Проверка открытия файла
    {
        throw runtime_error("File opening error");
    }
    else
    {
        file.read(reinterpret_cast<char*>(&size), sizeof(size));
        array.resize(size);
        file.read(reinterpret_cast<char*>(array.data()), sizeof(double) * size);
        file.close();
    }
<<<<<<< HEAD
}





// FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
// FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
// FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
// FFFFFFFF
// FFFFFFFF
// FFFFFFFF
// FFFFFFFF
// FFFFFFFFFFFFFFFFFFFFF
// FFFFFFFFFFFFFFFFFFF
// FFFFFFFFFFFFFFFFF
// FFFFFFFF
// FFFFFFFF
// FFFFFFFF
// FFFFFFFF
// FFFFFFFF
// FFFFFFFF
// FFFFFFFF
// FFFFFFFF
// FFFFFFFF
// FFFFFFFF
=======
}
>>>>>>> dev1
