#include <stdio.h>
#include <Windows.h>
int main()
{
	int a[100], *pa, k, n, max, min, indMax, indMin;
	SetConsoleOutputCP(1251);
	do {
		printf("Въведете броя на елементите: ");
		k = scanf("%d", &n);
		while (getchar() != '\n');
	} while (k != 1 || n < 1 || n>100);

	pa = a;
	for (int i = 0; i < 100; i++) {
		printf("Въведете елемента a[%d]: ", i);
		k = scanf("%d", pa);
		while (getchar() != '\n');
	}while (k != 1);

	pa = a;
	printf("Съдържание на масива:");
	for (int i = 0; i < n; i++)
		printf("\na[%d]=%d", i, *pa);
	pa = a+1;
	max = min = *pa;
	indMax = indMin = 0;
	for (int i = 1; i < n; pa++, i++)
	{
		if (*pa > max) {
			max = *pa;
			indMax = i;
		}
		if (*pa < min) {
			min = *pa;
			indMin = i;
		}
	}
	printf("\nmax=%d\tmin=%d\nindMax=%d\tindMin=%d", max, min, indMax, indMin);
	getchar();

	return 0;
}