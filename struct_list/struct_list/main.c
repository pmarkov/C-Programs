#include <stdio.h>
#include <stdlib.h>

struct List *list_create();
void list_add(struct List *list, int num);
void list_free(struct List *list);

struct List {
int *array;
size_t count;
size_t lenght;
};

int main()
{

	struct List *list = list_create();
	if (!list)
	{
		printf("Error creating list!");
		exit(1);
	}
	int i;

	for (i = 0; i < 40; i++)
	{
		list_add(list, i);
	}
	for (i = 0; i < 40; i++)
	{
		printf("%d ", list->array[i]);
	}
	
	list_free(list);
	getchar();
	return 0;
}

struct List *list_create()
{
	struct List *list = malloc(sizeof(struct List));
	if (!list)
		return NULL;

	list->array = malloc(sizeof(int) * 16);
	if (!list->array)
	{
		free(list);
		return NULL;
	}
	list->count = 0;
	list->lenght = 16;

	return list;
}
void list_add(struct List *list, int num)
{
	if (list->count == list->lenght)
	{
		int *resized = realloc(list->array, list->lenght * 2 * sizeof(int));
		if (!resized)
			return;
		list->array = resized;
		list->lenght *= 2;
	}
	list->array[list->count++] = num;
}
void list_free(struct List *list)
{
	free(list->array);
	free(list);
}