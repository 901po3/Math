double powSimple(double x, int n) //O(n);
{
	double result = 1;
	while (n--)
	{
		result *= x;
	}
	return result;
}

double powModified(double x, int n) //O(log n);
{
	double result = 1;
	int bit = 1;
	while (bit <= n) //while bit is smaller or equal to n;
	{//if n == 4,5,6,7 -> loop will be repeated only two times;
		if (bit & n) result *= x;
		x *= x;
		bit <<= 1;
	}
	return result;
}
