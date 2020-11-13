#ifndef zag
#define zag
int ck(int k, int n)
{
	if (k <= 0)
		return 0;
	if ((n - k) <= 0)
		return 0;
	else
		return (fact(n)) / ((fact(k)) * fact(n - k));
}
#endif // !zag
