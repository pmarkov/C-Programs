#include <stdio.h>
main()
{
	float celsius, fahr;
	float lower, upper, step;
	printf("Таблица за градуси\n");
	lower = 0;
	upper = 300;
	step = 20;
	fahr = lower;
	while (fahr <= upper) {
		celsius = (5.0 / 9.0)*(fahr - 32.0);
		fahr = fahr + step;
		printf("%3.0f\t 6.1f\n", fahr, celsius);
	}
	return 0;
}