#include <stdio.h>

void qsort(int nums[], int left, int right);

int main()
{
	int i;
	int n[] = { 5, 123, 23, 32, 12, 43, 32, 0 };
	for (i = 0; i < 8; i++)
		printf("%d ", n[i]);
	printf("\n");
	qsort(n, 0, 7);
	for (i = 0; i < 8; i++)
		printf("%d ", n[i]);

	getchar();
	return 0;
}
void qsort(int nums[], int left, int right)
{
	int i, last;
	void swap(int n[], int i, int j);

	if (left >= right)
		return;
	swap(nums, left, (left + right) / 2);		//разменя първия и средния елемент на масива

	last = left;								//last е последно разменения елемент
	for (i = left + 1; i <= right; i++)			//обхождаме масива от първия елемент след лявата граница до дясната граница
		if (nums[i] < nums[left])				//ако следващият елемент е по-малък от първия, го разменяме с last
			swap(nums, ++last, i);
	swap(nums, left, last);

	qsort(nums, left, last - 1);
	qsort(nums, last + 1, right);
}
void swap(int n[], int i, int j)
{
	int temp;
	temp = n[i];
	n[i] = n[j];
	n[j] = temp;
}