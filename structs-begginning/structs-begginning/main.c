#include <stdio.h>

struct point makepoint(int x, int y);
int ptinrect(struct point p, struct rect r);

struct point
{
	int x;
	int y;
};

struct rect
{
	struct point pt1;
	struct point pt2;
};

int main()
{
	struct rect screen;
	struct point middle;
	
	screen.pt1 = makepoint(0, 0);
	screen.pt2 = makepoint(100, 100);
	middle = makepoint((screen.pt1.x + screen.pt2.x) / 2,
		(screen.pt1.y + screen.pt2.y) / 2);

	printf("pt1.x = %d, pt1.y = %d, pt2.x = %d, pt2.y = %d", screen.pt1.x, screen.pt1.y, screen.pt2.x, screen.pt2.y);
	printf("\nmiddle = %d", middle);

	getchar();
	return 0;
}
struct point makepoint(int x, int y)
{
	struct point temp;

	temp.x = x;
	temp.y = y;
	return temp;
}
int ptinrect(struct point p, struct rect r)
{
	return p.x >= r.pt1.x && p.x < r.pt2.x && p.y >= r.pt1.y && p.y < r.pt2.y;
}