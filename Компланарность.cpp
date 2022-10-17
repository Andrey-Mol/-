#include <iostream>
#include <string>
using namespace std;

//размер определителя смешанного произведения
const int a = 3;

//объявление определителя 
int matrix[a][a] = {};

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

//ввод данных в определитель
void opred() {
	char user_answer = ' ';
	while (user_answer != 'y')
	{
		cout << "Введите координаты векторов, образующих фигуру, для определения её объёма. Формат данных: \n \n{Ax; Ay; Az} \n{Bx; By; Bz} \n{Cx; Cy; Cz}\n \
		(Без разделительных знаков и скобок!)\n \n";
		for (int i = 0; i < a; ++i) {
			for (int j = 0; j < a; ++j) {
				cin >> matrix[i][j];
			}
		}
		cout << "\nПравильно ли введены данные?: y/n \n \n";
		for (int i = 0; i < a; ++i) {
			cout << "{ ";
			for (int j = 0; j < a; ++j) {
				cout << matrix[i][j] << " ";
			}
			cout << "}" << endl;
		}
		cout << "\n";
		cin >> user_answer;
	}
	
}

//нахождения смешанного произведения
int determinant(int matr[a][a]) {
	int det = matr[0][0] * matr[1][1] * matr[2][2] - matr[0][0] * matr[1][2] * matr[2][1]
		- matr[0][1] * matr[1][0] * matr[2][2] + matr[0][1] * matr[1][2] * matr[2][0]
		+ matr[0][2] * matr[1][0] * matr[2][1] - matr[0][2] * matr[1][1] * matr[2][0];
	return det;
}

int main() {
	//для установки русского языка в выводе:
	setlocale(LC_ALL, "Rus");
	cout << "\n";
	opred();
	cout << "\n";
	int det_main = abs(determinant(matrix));
	if (det_main == 0) {
		cout << "\n---------------------\nОни компланарны\n---------------------";
	}
	else {
		float v;
		v = det_main;
		cout << "\n---------------------\nОни не компланарны \n" << "Объём = " << v / f() <<"\n---------------------" << endl;
	}
	return 0;
}
