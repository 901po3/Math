#include"polynomial.h"
#include<cmath>

node *polynomial::makeNode(int degree, double coef)
{
	node *pNewNode = new node;
	pNewNode->degree = degree;
	pNewNode->coef = coef;
	pNewNode->pNext = nullptr;
	return pNewNode;
}

void polynomial::insertNode(int degree, double coef)
{
	insertNode(this->pHead, degree, coef);
}

void polynomial::insertNode(node *pHead, int degree, double coef)
{
	node *pMove, *pNewNode;
	if (coef == 0.0) return; //if coefficient is 0, we dont take it.
	pNewNode = makeNode(degree, coef);
	pMove = pHead;
	while (true)
	{
		//first, we need to find the right position to add the newNode.
		if (!pMove->pNext) //if pMove->pNext is pointing null, it means end of node;
		{
			pMove->pNext = pNewNode;
			break;
		}
		else if (pMove->pNext->degree == pNewNode->degree)
		{//if we have same exponents, sum those coefficeints together.
			pMove->pNext->coef += pNewNode->coef;
			delete pNewNode;
			break;
		}
		else if (pMove->pNext->degree < pNewNode->degree)
		{//if newNode has a bigger degree, we have to put it before it meets the smaller degree;
			pNewNode->pNext = pMove->pNext;
			pMove->pNext = pNewNode;
			break;
		}
		else
			pMove = pMove->pNext;
	}
}

node *polynomial::addPolynomial(node *a, node * b)
{
	node *pResult, *pMove;
	pResult = makeNode(0, 0); //make a head node for the result polynomial;
	pMove = pResult;
	a = a->pNext;
	b = b->pNext;
	while (a && b)//while both polynomial a and b are not ended;
	{
		if (a->degree > b->degree)
		{
			pMove->pNext = makeNode(a->degree, a->coef);
			a = a->pNext;
		}
		else if (a->degree < b->degree)
		{
			pMove->pNext = makeNode(b->degree, b->coef);
			b = b->pNext;
		}
		else
		{
			if (a->coef + b->coef) //proceed if sum of two coefficient isn't 0;
			{
				pMove->pNext = makeNode(a->degree, a->coef + b->coef);
			}
			a = a->pNext;
			b = b->pNext;
		}
		pMove = pMove->pNext;
	}
	while (a)
	{
		pMove->pNext = makeNode(a->degree, a->coef);
		a = a->pNext;
		pMove = pMove->pNext;
	}
	while (b)
	{
		pMove->pNext = makeNode(b->degree, b->coef);
		b = b->pNext;
		pMove = pMove->pNext;
	}
	return pResult;
}

node *polynomial::multiPolynomial(node *a, node *b)
{
	node *pResult, *pMove;
	pResult = makeNode(0, 0);
	a = a->pNext;
	while (a)
	{
		pMove = b->pNext;
		while (pMove)
		{
			insertNode(pResult, a->degree + pMove->degree, a->coef * b->coef);
			pMove = pMove->pNext;
		}
		a = a->pNext;
	}
	return pResult;
}

node *polynomial::diffPolynomial(node *a)
{
	node *pResult = makeNode(0, 0);
	a = a->pNext;
	while (a)
	{
		if (a->degree > 0)
			insertNode(pResult, a->degree - 1, a->coef * a->degree);
		a = a->pNext;
	}
	return pResult;
}

node *polynomial::integPolynomial(node *a)
{
	node *pResult = makeNode(0, 0);
	a = a->pNext;
	while (a)
	{
		insertNode(pResult, a->degree + 1, a->coef / (a->degree + 1));
		a = a->pNext;
	}
	return pResult;
}

double polynomial::powSimple(double baseNum, int expNum)
{//good when expNum is small;
	double result = 1;
	while (expNum--)
	{
		result *= baseNum;
	}
	return result;
}

double polynomial::powModified(double baseNum, int expNum)
{//good when expNum is huge;
	double result = 1;
	int bit = 1;
	while (bit <= expNum) //while bit is smaller or equal to n;
	{//if n == 4,5,6,7 -> loop will be repeated only two times;
		if (bit & expNum) result *= baseNum;
		baseNum *= baseNum;
		bit <<= 1;
	}
	return result;
}

double polynomial::evaluateMath(node *a, double x)
{
	double result = 0;
	while (a->pNext)
	{
		a = a->pNext;
		//can also use powSimple() and powModified(), if exponent number is integer;
		result += pow(x, a->degree) * a->coef;
	}
	return result;
}

double polynomial::evaluateMathHorner(node *a, double x)
{//((...(((CnX + Cn-1)X + Cn-2)X + Cn-3)x...)X + C0)
	double result = 0;
	int order = a->degree;
	while (a->pNext)
	{
		a = a->pNext;
		result = result * pow(x, order - a->degree) + a->coef;
		order = a->degree;
	}
	return result * pow(x, order);
}

double polynomial::combi(double a[][2], int n, int r)
{// multiply all polynomials that picked number of r from n;
	double result = 1;
	if (n <= 0 || r < 0 || n < r) return 0;
	if (n == r)
	{
		for (int i = 0; i < n; i++)
		{
			result *= a[i][0];
		}
		return result;
	}
	if (r == 0)
		return 1;
	else
		return a[n-1][0] * combi(a, n-1, r-1) + combi(a, n-1, r);
}

node *polynomial::lagrange(double a[][2], int n)
{
	int sign; //take care of sign + -
	double coef, temp;
	node *pResult;
	pResult = makeNode(NULL, NULL);
	for (int i = 0; i < n; i++)
	{
		if (!a[i][1]) continue;
		coef = a[i][1];
		for (int j = 0; j < n; j++)
		{
			if (j == i) continue;
			if (a[i][0] == a[j][0])
			{
				//if there are two different polynomials that has same coordinate, we can't get
				//lagrange polynomial
				return NULL;
			}
			coef /= a[i][0] - a[j][0];
		}
		temp = a[i][0];
		a[i][0] = 0;
		for (int j = 0; j < n; j++)
		{
			if (j % 2) sign = -1;
			else sign = 1;
			insertNode(pResult, n - j - 1, sign * coef * combi(a, n, j));
		}
		a[i][0] = temp;
	}
	return pResult;
}

void polynomial::deleteAll()
{
	node *pCur, *pPrev;
	pCur = pHead->pNext;
	pPrev = pHead;
	while (pCur != nullptr)
	{
		node *pTemp = pCur;
		pPrev->pNext = pCur->pNext;
		pCur = pPrev->pNext;
		delete pTemp;
	}
}
