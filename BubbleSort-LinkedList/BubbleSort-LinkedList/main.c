#include <stdio.h>
#include <stdlib.h>

typedef struct List {
	int data;
	struct List *next;
} List;

List *head = NULL;

void add_node(int data);
void print_list(List *root);
List *sort_list();
void swap_nodes(List *node1, List *node2);

int main() 
{
	int arr[10] = { 5, 89, -1, 15, 0, 8, 23, 51, 17, 8 };

	for (int i = 0; i < 10; i++) {
		add_node(arr[i]);
	}
	print_list(head);

	List *sorted = sort_list();
	print_list(sorted);

	system("pause");
	return 0;
}

void add_node(int data)
{
	if (head == NULL) {
		head = (List*)malloc(sizeof(List));
		head->data = data;
		head->next = NULL;
	}
	else {
		List *temp = (List*)malloc(sizeof(List));
		temp->data = data;
		temp->next = head;
		head = temp;
	}
}

void print_list(List *root)
{
	List *temp = root;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

List *sort_list()
{
	if (head == NULL) {
		return NULL;
	}

	List *temp = head;
	
	List *new_list = (List*)malloc(sizeof(List));
	new_list->data = temp->data;
	new_list->next = NULL;

	temp = temp->next;
	while (temp != NULL) {
		List *new_list_temp = (List*)malloc(sizeof(List));
		new_list_temp->data = temp->data;
		new_list_temp->next = new_list;
		new_list = new_list_temp;
		temp = temp->next;
	}

	int isSwapped = 1;
	
	while (isSwapped) {
		isSwapped = 0;
		List *iterator = new_list;
		while (iterator->next != NULL) {
			if (iterator->data > iterator->next->data) {
				swap_nodes(iterator, iterator->next);
				isSwapped = 1;
			}
			iterator = iterator->next;
		}
	}

	return new_list;
}

void swap_nodes(List *node1, List *node2)
{
	int temp_data = node1->data;
	node1->data = node2->data;
	node2->data = temp_data;
}