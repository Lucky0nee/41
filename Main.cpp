#include <iostream>
#include <vector>
#include <time.h>
#include <random>

using namespace std;

void coutArr(int* Arr[], int M, int N) {
	for (int i = 0; i < M; i++) {
		cout << "\n";
		for (int j = 0; j < N; j++)
			cout << Arr[i][j] << " ";
	}
}

void moveArray(int* Arr[], int M, int N, int K, bool Напрямок) {
	for (int again = 0; again < K + (Напрямок == false ? (K != 1 ? K - 1 : K + 2) : 0); again++) {
		for (int i = 0; i < M; i++) {
			if (i == 0)
				Arr[M] = Arr[M - M];
			Arr[i] = Arr[i + 1];
		}
	}
}

int main() {
	system("chcp 1251>nul");
	srand(time(NULL));

	cout << "Введiть кiлькiсть рядків: "; int M; cin >> M;
	cout << "Введiть кiлькiсть стовпців: "; int N; cin >> N;
	cout << "Введiть кiлькiсть зсувiв: "; int K = 0; cin >> K;
	cout << "Введiть напрямок (1 - вгору; 0 - вниз): "; bool Напрямок = 1; cin >> Напрямок;

	int** Arr = new int* [M];
	for (int i = 0; i < M; i++) Arr[i] = new int[N];

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			Arr[i][j] = rand() % 9;

	cout << "Масив: \t\t   ";			 coutArr(Arr, M, N);
	moveArray(Arr, M, N, K, Напрямок);
	cout << "\nЗсунутий масив: \t\t   "; coutArr(Arr, M, N);

	return 0;
}

/*
Задайте матрицю розміру M × N (M рядків, N стовпців).
Заповніть її випадковими значеннями.
Створіть функцію, що виконує циклічний зсув рядків такої матриці на задану кількість разів у вказаному напрямку
(вгору або вниз).
*/
