#pragma once

//Representation of Polynomail
#define MAX_TERM	256

struct polynomialNode
{
	double coef; //number of coefficient;
	int degree;
	polynomialNode *pNext;
};
typedef polynomialNode node;

/*
ex)
8x^4 + 6x^2 + 5x^2 -3x 1
[coef	:	8,	6,	5,	-3,	1,	0]
[degree	:	4,	2,	2,	 1, 0,	0]
(if coef && degree are 0, it means end of polynomial)
*/

class polynomial
{
private:
	node *pHead;
public:
	polynomial() : pHead(makeNode(0, 0)) {}
	~polynomial() { deleteAll(); delete pHead; }

	node *getHead() { return pHead; }

	node *makeNode(int degree, double coef);
	
	void insertNode(int degree, double coef);
	void insertNode(node *pHead, int degree, double coef);

	node *addPolynomial(node *a, node * b);//add two polynomials into one;
	node *multiPolynomial(node *a, node *b);//multiply two polynomials into one;
	node *diffPolynomial(node *a); //differentate polynomial;
	node *integPolynomial(node *a); //integration polynomial;

	double powSimple(double baseNum, int expNum); //x^n; O(n);
	double powModified(double baseNum, int expNum); //x^n; O(log n);

	//insert number into variable x and solve the polynomial;
	double evaluateMath(node *a, double x); //O(n ^ 2);
	double evaluateMathHorner(node *a, double x); // O(n) Horner's law;

	void deleteAll();
};