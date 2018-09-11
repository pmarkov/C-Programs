#include <stdio.h>
#include <stdlib.h>
int main()
{
	system("chcp 1251");
	int a, b, c;
	double x, x1, x2, re, d, im;
	printf("Въвеждаме a=");
	scanf("%d", &a);
	printf("Въвеждаме b=");
	scanf("%d", &b);
	printf("Въвеждаме c=");
	scanf("%d", &c);
	if (a == 0 && b == 0)
		printf("Изродено уравнение\n");
	else
	{
		if (a == 0)
		{
			a = -c / (double)b;
			printf("Линейно уравнение x=%f\n", x);
			scanf("%f", x);
		}
		else
		{
			if (c == 0)
			{
				x1 = -c / (double)b;
				x2 = 0;
				printf("Два корена x1=%f, x2=%f\n", x1, x2);
			}
			else
			{
				re = -b / (double)(2 * a);
				d = pow(b, 2) - 4 * a*c;
				im = sqrt(abs(d)) / (2 * a);
				if (d>0)
				{
					x1 = re + im;
					x2 = re - im;
					printf("Два корена x1=%f, x2=%f\n", x1, x2);
				}
				else if (d<0)
					printf("(%d,%d),(%d,%d)-Комплексни корени\n", re, im, re, -im);
				else
				{
					x1 = re;
					x2 = x1;
					printf("Два равни корена x1=x2\n");
				}
			}
		}
	}
	return 0;
}