#include <stdio.h>
#include <stdlib.h>

typedef struct Stock {
	int intNum;
	float floatNum;
	char text[34];
}stock;

typedef struct List {
	stock data;
	struct List *next;
}list;

list *c()
{
	FILE *fp;
	char fileName[30];

	printf("Enter file name: ");
	fgets(fileName, 30, stdin);

	if ((fp = fopen(fileName, "rb")) == NULL) {
		exit(1);
	}
	
	list *head = NULL;
	stock newStock;
	while (1) {
		if (fread(&newStock, sizeof(stock), 1, fp) != 1) {
			break;
		}
		if (head == NULL) {
			head = (list*)malloc(sizeof(list));
			head->data = newStock;
			head->next = NULL;
		}
		else {
			list *temp = (list*)malloc(sizeof(list));
			temp->data = newStock;
			temp->next = head;
			head = temp;
		}
	}
	return head;
}

void sec26(list *head, FILE *fp)
{
	while (head != NULL) {
		if (fprintf(fp, "%d\n", head->data.intNum) < 0) {
			printf("Error while writing in file 1");
		}
		if (fprintf(fp, "%f\n", head->data.floatNum) < 0) {
			printf("Error while writing in file 2");
		}
		if (fprintf(fp, "%s\n", head->data.text) < 0) {
			printf("Error while writing in file 3");
		}
		head = head->next;
	}
}

int trd26(list *head)
{
	int count = 0;

	while (head != NULL) {
		char ch = head->data.text[0];
		if (ch >= '0' && ch <= '9') {
			count++;
		}
		head = head->next;
	}
	return count;
}

int main()
{
	list *head = NULL;

	head = c();
	FILE *fp;
	if ((fp = fopen("C:\kap.txt", "wb")) == NULL) {
		exit(1);
	}

	sec26(head, fp);
	int node_count = trd26(head);

	return 0;
}