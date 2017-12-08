#pragma once
/*
	MATRIX [i, j]
[ 00, 01, 02, 03]
[ 10, 11, 12, 13]
[ 20, 21, 22, 23]
[ 30, 31, 32, 33]
*/

#define MAX 256

struct dataNode
{
	int col, row;
	double value;	
	dataNode *pColNext, *pRowNext;
}; 


struct headNode
{
	int index;
	dataNode *pDataNext;
	headNode *pHeadNext;
};

class matrix
{
private:

public:
	matrix();
	~matrix();

	void AddMatrix(double pm1[][MAX], double pm2[][MAX],
		double result[][MAX], int n);
	void SubMatrix(double pm1[][MAX], double pm2[][MAX],
		double result[][MAX], int n);
	void MultMatrix(double pm1[][MAX], double pm2[][MAX],
		double result[][MAX], int n);
};