#include<iostream>
using namespace std;

unsigned long bits(unsigned long x, int k, int j)
{
	unsigned long zero = 0;
	return (x >> k) & ~(~zero << j);
}

unsigned long power(int b, int e)
{
	int i;
	unsigned long r = 1;
	for (i = 0; i < e; i++)
		r *= b;
	return r;
}

void printBinary(unsigned long l, int w)
{
	unsigned long i;
	i = power(2, w - 1);
	while (i > 0)
	{
		printf("%1d", l / i);
		l -= (l / i)*i;
		i /= 2;
	}
	printf(" ");
}

void sumBad()
{
	float sum = 1000.0;
	printf("\nBad summation for 1000.0 + 10000 * 0.0001");
	for (int i = 0; i < 10000; i++)
		sum += 0.0001f;
	printf("\nSum is = %f", sum);
}

void sumGroup()
{
	float sum = 1000.0;
	float group = 0.0;
	printf("\nGrouping summation for 1000.0 + 10000 * 0.0001");
	for (int i = 1; i <= 10000; i++)
		group += 0.0001f;
	sum = sum + group;
	printf("\nSum is = %f", sum);
}

int main()
{
	sumBad();
	cout << endl;
	sumGroup();
	system("pause");
	return 0;
}