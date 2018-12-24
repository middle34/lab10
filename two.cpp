#include <iostream> 
#include <conio.h>
#include <stdlib.h> 
#include <time.h> 
using namespace::std;
const int n = 1;
const int m = 5;
int N;

void funcPrint(double **a) {
	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}

void mult(double **a, double **b, int s)
{
	double **d = new double *[s];
	for (int i = 0; i < s; i++)
	{
		d[i] = new double[s];
		for (int j = 0; j < s; j++)
		{
			d[i][j] = 0;
			for (int k = 0; k < s; k++)
				d[i][j] += a[i][k] * b[k][j];
		}
	}
	cout << "Произведение матриц";
	cout << endl;
	funcPrint((double**)d);
	for (int i = 0; i < s; i++) 
		delete[]d[i];
	delete[]d;

}



int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	std::cout << "Введите размер квадратных матриц :";
	std::cin >> N;

	double **A = new double *[N];
	double **B = new double *[N];
	double **C = new double *[N];

	for (int i = 0; i < N; i++) {
		A[i] = new double[N];
		B[i] = new double[N];
		C[i] = new double[N];
	}
	cout << endl;
	cout << "Матрица А" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			A[i][j] = rand() % m + n;
		}
	}
	funcPrint((double**)A);
	cout << endl;
	cout << "Матрица B" << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			B[i][j] = rand() % m + n;
		}
	}
	funcPrint((double**)B);
	cout << endl;

	mult((double **)A, (double**)B, (int) N);

	for (int i = 0; i < N; i++) {
		delete[]A[i];
		delete[]B[i];
		delete[]C[i];
	}
	delete[]A;
	delete[]B;
	delete[]C;
	return 0;
}

