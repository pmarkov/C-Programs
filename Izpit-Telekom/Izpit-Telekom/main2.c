#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef struct {
	int num;
	char name[28];
} inf;
int main()
{
	char m[] = "153rfut2345t", *p = m + 3;
	int x, y;
	const char *ar[] = { "x72w3e78", "f6e3q634r", "r5w651q24t" };
	inf st[] = { {20, "w9rr12"}, {3, "g4w28t"}, {18, "t3rer72"}, {7, "d32yt92"} };
	x = 0x14; y = 0xEC; x <<= 2; y >>= 2; printf("1:%x %x\n", x, y);
	x = 0x57; y = 9; printf("2:%x %x %x %x %x\n", x | y, x&y, x^y, x, y);
	x = 0xE1; y = 9; printf("3:%x %x %x %x\n", x, y&(~y), y | (~y), y);
	printf("4: %c %c %s\n", *(m + 1), *m + 2, m + 1);
	printf("5: %c %s\n", p[1], p + 2);
	printf("6: %s %s\n", *(ar + 2), *ar + 1);
	printf("7: %c %c\n", **(ar + 1), *(*ar + 2));
	printf("8: %d %s\n", st[3].num, st[1].name + 1);
	printf("9: %d %s\n", (st + 2)->num, st->name + 1);
	printf("10: %c %c %c\n", *(st->name), *((st + 1)->name), *(st->name + 1));
	return 0;

}