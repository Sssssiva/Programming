#pragma once
int  fact(int x)
{
	if (x == 1)
		return 1;
	if (x < 0)
		return 0;
	else
		return fact(x - 1) * x;

}
