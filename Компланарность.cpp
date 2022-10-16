#include <iostream>
#include <string>
using namespace std;

//размер матрицы
const int n = 3;
const int m = 3;

//объявление квадратной матрицы 3x3 и заполнение нулями:
int matrix[n][m] = {};

//создание промежуточной матрицы для вычисления всех определителей:
int temp_matrix[n][n];

//ввод данных в матрицу 3x3
void entering_coef() {
	cout << "Ax Ay Az \nBx By Bz \nCx Cy Cz\n";
	char answer = ' ';
		while (answer != 'y')
		{
			cout << "Введите координаты векторов, для определения их компланарности: \n";
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					cin >> matrix[i][j];
				}
			}
			cout << "Правильно ли введены данные?: y/n \n";
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < m; ++j) {
					cout << matrix[i][j] << " ";
				}
				cout << endl;
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

	int det_main = determinant(temp_matrix);
	cout << "Определитель:" << det_main << endl;

	if (det_main == 0) {
		cout << "Они компланарны";
	}
	else {
		cout << "Они не компланарны"<< endl;
	}
	return 0;
}