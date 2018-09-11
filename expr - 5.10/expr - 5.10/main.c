#include <stdio.h>
#include <stdlib.h>

/*Изчислява израз, подаден от командия ред по метода на
обратния полски калкулатор. Всеки оператор или операнд се приема за отделен аргумент.
Пр.: expr 2 3 4 + * изчислява 2*(3+4) */

int main(int argc, char *argv[])
{
	int num[10];
	int i = 0, n , c;
	int result;

	for (int j = 1; --argc > 0; j++)
	{
		c = *argv[j];

		if (c >= '0' && c <= '9')
		{
			n = atoi(argv[j]);
			num[i++] = n;
		}
		if (c == '+')
		{
			i--;
			result = num[i] + num[i - 1];
			num[i - 1] = result;
		}
		if (c == '*')
		{
			i--;
			result = num[i] * num[i - 1];
			num[i - 1] = result;
		}
		if (c == '-')
		{
			if ((c = *++argv[j]) < '9' && c > '0')
			{
				*--argv[j];
				n = atoi(argv[j]);
				num[i++] = n;
			}
			else
			{
				i--;
				result = num[i - 1] - num[i];
				num[i - 1] = result;
			}
		}
		if(c == '/')
		{
			i--;
			result = num[i] / num[i - 1];
			num[i - 1] = result;
		}
	}
	printf("Result is: %d", result);

	getchar();
	return 0;
}