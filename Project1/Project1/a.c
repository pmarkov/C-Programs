//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main()
{
	SetConsoleOutputCP(1251);
	int a, b, c;
	double x, x1, x2, re, im, d;
	//SetConsoleOutputCP(1251);
	system("chcp 1251>nul");
	printf("��������� a=");
	scanf("%d", &a);
	printf("��������� b=");
	scanf("%d", &b);
	printf("��������� c=");
	scanf("%d", &c);
	if (a == 0 && b == 0)
		printf("�������� ���������\n");
	else
	{
		if (a == 0)
		{
			x = -c / (double)b;
			printf("������� ��������� x=%f\n", x);
        }
		else
		{
			if (c == 0)
			{
				x1 = -c / (double)b;
				x2 = 0;
				printf("��� ������ x1=%f, x2=%f\n", x1, x2);
			}
			else
			{
				re = -b / (double)(2 * a);
				d = pow(b, 2) - 4 * a*c;
				im = sqrt(abs(d)) / (2 * a);
				if (d > 0)
				{
					x1 = re + im;
					x2 = re - im;
					printf("��� ������ x1=%f, x2=%f\n", x1, x2);
				}
				else if (d < 0)
					printf("(%d,%d), (%d,%d)-���������� ������\n", re, im, re, -im);
				else
				{
					x1 = re;
					x2 = x1;
					printf("��� ����� ������ x1=x2\n");
				}
			}
		}
	}
	return 0;

}