#include <iostream>
#include <string>
using namespace std;

//размер определителя смешанного произведения
const int a = 3;

//объявление определителя 
int opred_vect[a][a] = {};

//выбор фигуры
int f() {
	cout << "Выберите необходимую фигуру: Тетраэдр - t  Параллелепипед - p \n\n";
	float fig = 0;
	char k;
	while (fig == 0) {
		cin >> k;
		if (k == 't') {
			fig = 6;
		}
		else if ((k == 'p')) {
			fig = 1;
		}
		else {
			cout << "Повторите попытку \n";
		}
	}
	return fig;
}

//ввод координат в определитель
void opred() {
	char user_answer = ' ';
	while (user_answer != 'y')
	{
		cout << "Введите координаты векторов, образующих фигуру, для определения её объёма. Формат данных: \n \n{Ax; Ay; Az} \n{Bx; By; Bz} \n{Cx; Cy; Cz}\n \
		(Без разделительных знаков и скобок!)\n \n";
		for (int i = 0; i < a; ++i) {
			for (int j = 0; j < a; ++j) {
				cin >> opred_vect[i][j];
			}
		}
		cout << "\nКорректно ли получены данные?: y/n \n \n";
		for (int i = 0; i < a; ++i) {
			cout << "{ ";
			for (int j = 0; j < a; ++j) {
				cout << opred_vect[i][j] << " ";
			}
			cout << "}" << endl;
		}
		cout << "\n";
		cin >> user_answer;
	}
	
}

//нахождения смешанного произведения
int smesh_proizv(int opred[a][a]) {
	int det = opred[0][0] * opred[1][1] * opred[2][2] - opred[0][0] * opred[1][2] * opred[2][1]
		- opred[0][1] * opred[1][0] * opred[2][2] + opred[0][1] * opred[1][2] * opred[2][0]
		+ opred[0][2] * opred[1][0] * opred[2][1] - opred[0][2] * opred[1][1] * opred[2][0];
	return det;
}

int main() {
	//для установки русского языка в выводе:
	setlocale(LC_ALL, "Rus");
	//работа основного алгоритма
	cout << "\n";
	opred();
	cout << "\n";
	int det_main = abs(smesh_proizv(opred_vect));
	if (det_main == 0) {
		cout << "\n---------------------\nВекторы компланарны\n---------------------";
	}
	else {
		float v;
		v = det_main;
		int figura;
		figura = f();
		cout << "\n---------------------\nВекторы не компланарны \n" << endl;
		if (figura == 1) {
			cout  << "Объём параллелепипеда = " << v / figura << "\n---------------------" << endl;
		}
		else {
			cout << "Объём тетраэдра = " << v / figura << "\n---------------------" << endl;
		}
	}
	return 0;
}
