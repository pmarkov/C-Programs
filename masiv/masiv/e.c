#include <stdio.h>
#include <Windows.h>
int main()
{
	int a[100], n, k, max, min, indMax, indMin;
	SetConsoleOutputCP(1251);
	do {
		printf("Въведете броя на елементите за обработка: ");
		k = scanf("%d", &n);
		while (getchar() != '\n');
	} while (k != 1 || n < 1 || n > 100);
	for (int i = 0; i<n; i++)
		do
		{
			printf("Въведете елемента a[%d]= ", i);
			k = scanf("%d", &a[i]);
			while (getchar() != '\n');
		} while (k != 1);
		printf("Съдържание на масива: ");
		for (int i = 0; i < n; i++)
			printf("\na[%d]=%d", i, a[i]);

		max = min = a[0];
		indMax = indMin = 0;
		for (int i = 1; i < n; i++) {
			if (a[i] > max) {
				max = a[i];
				indMax = i;
			}
			if (a[i] < min) {
				min = a[i];
				indMin = i;
			}
		}

		printf("\nmax=%d\tmin=%d\tindMax=%d\tindMin=%d", max, min, indMax, indMin);
		getchar();

		return 0;
}