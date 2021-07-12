#include <stdio.h>
#include <stdbool.h>
#include <math.h>

float f(float x)
{
	return x * x - 3;
}

bool check_signal(float a, float b)
{
	if (f(a) < 0 && f(b) < 0)
	{
		return true;
	}
	else if (f(a) > 0 && f(b) > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

float bisection_method(float a, float b, float tol, int nmax)
{
	if ((a < b) && (f(a) * f(b) < 0))
	{
		float c;
		int n = 1;

		while (n <= nmax || (b-a) >= tol)
		{
			c = (a + b) / 2;
			if ((((b - a) / 2) < tol))
			{
				return c;
			}
			else
			{
				if (check_signal(a, c))
				{
					a = c;
				}
				else
				{
					b = c;
				}
			}

			n += 1;
		}
	}

	return 0;
}

int main(void)
{
	float a, b, tole, value;
	int nmax;

	printf("Enter the interval: a b\n");
	scanf("%f %f", &a, &b);
	printf("Enter the tolerance: tol\n");
	scanf("%f", &tole);
	printf("Enter the n max: n max\n");
	scanf("%d", &nmax);

	value = bisection_method(a, b, tole, nmax);
	printf("C value is %f\n", value);

	return 0;
}