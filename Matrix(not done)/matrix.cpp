#include "matrix.h"

matrix::matrix()
{

}

matrix::~matrix()
{

}

void matrix::AddMatrix(double pm1[][MAX], double pm2[][MAX],
	double result[][MAX], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			result[i][j] = pm1[i][j] + pm2[i][j];
		}
	}
}

void matrix::SubMatrix(double pm1[][MAX], double pm2[][MAX],
	double result[][MAX], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			result[i][j] = pm1[i][j] - pm2[i][j];
		}
	}
}

void matrix::MultMatrix(double pm1[][MAX], double pm2[][MAX],
	double result[][MAX], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			result[i][j] = pm1[i][j] * pm2[i][j];
		}
	}
}
