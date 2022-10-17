#include <iostream>
#include <string>
using namespace std;


//размер матрицы
const int n = 3;

//объявление квадратной матрицы 3x3 и заполнение нулями:
int matrix[n][n] = {};

//создание промежуточной матрицы для вычисления всех определителей:
int temp_matrix[n][n];

//выбор фигуры
int f() {
	cout << "Выберите необходимую фигуру: Тетраэдр - t  Параллелепипед - p \n";
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

//ввод данных в матрицу 3x3
void entering_coef() {
	char answer = ' ';
	while (answer != 'y')
	{
		cout << "Введите координаты векторов, образующих фигуру, для определения её объёма. Формат данных: \n \n{Ax; Ay; Az} \n{Bx; By; Bz} \n{Cx; Cy; Cz}\n \
		(Без разделительных знаков и скобок!)\n";
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> matrix[i][j];
			}
		}
		cout << "Правильно ли введены данные?: y/n \n";
		for (int i = 0; i < n; ++i) {
			cout << "{ ";
			for (int j = 0; j < n; ++j) {
				cout << matrix[i][j] << " ";
			}
			cout << "}" << endl;
		}
		cin >> answer;

	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			temp_matrix[i][j] = matrix[i][j];
		}
	}
}

//нахождения определителя матрицы 3x3
int determinant(int matr[n][n]) {
	int det = matr[0][0] * matr[1][1] * matr[2][2] - matr[0][0] * matr[1][2] * matr[2][1]
		- matr[0][1] * matr[1][0] * matr[2][2] + matr[0][1] * matr[1][2] * matr[2][0]
		+ matr[0][2] * matr[1][0] * matr[2][1] - matr[0][2] * matr[1][1] * matr[2][0];
	return det;
}


int main() {
	//для установки русского языка в выводе:
	setlocale(LC_ALL, "Russian");
	entering_coef();
	cout << "---------------------------------------------" << endl;

	int det_main = abs(determinant(temp_matrix));
	if (det_main == 0) {
		cout << "Они компланарны";
	}
	else {
		float v;
		v = det_main;
		cout << "Они не компланарны \n" << "Объём = " << v / f() << endl;
	}
	return 0;
}
