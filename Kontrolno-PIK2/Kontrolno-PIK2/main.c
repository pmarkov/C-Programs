#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct User{
	char name[31];
	char ID[11];
	char date[12];
	int services;
} User;

typedef struct List {
	User data;
	struct List *next;
} List;

List *addNode(List *head, User newUser) 
{
	if (head == NULL) {
		head = (List*)malloc(sizeof(List));
		head->data = newUser;
		head->next = NULL;
	}
	else
	{
		List* temp = head;
		while (temp->next != NULL) 
		{
			temp = temp->next;
		}
		temp->next = (List*)malloc(sizeof(List));
		temp->next->data = newUser;
		temp->next->next = NULL;
	}
	return head;
}

int searchClient(List* head, char ID[]) 
{
	while (head != NULL) 
	{
		if (strcmp(ID, head->data.ID) == 0)
		{
			return head->data.services;
		}
		head = head->next;
	}
	return 0;
}

void expiresIn(List* head, char Data[])
{
	FILE *fp = fopen("test", "wb+");
	int flag = 0;

	if (fp == NULL)
	{
		printf("Error opening file");
		exit(1);
	}
	int year = atoi(&Data[0]);
	int month = atoi(&Data[5]);
	int day = atoi(&Data[8]);
	while (head != NULL)
	{
		flag = 0;
		if (year > atoi(&head->data.date[0]))
		{
			flag = 1;
		} 
		else if (year == atoi(&head->data.date[0]))
		{
			if (month > atoi(&head->data.date[5]))
			{
				flag = 1;
			}
			else if (month == atoi(&head->data.date[5]))
			{
				if (day >= atoi(&head->data.date[8]))
				{
					flag = 1;
				}
			}
		}
		if (flag == 1)
		{
			printf("\n%s", head->data.name);
			printf("\n%s", head->data.ID);
			printf("\n%s", head->data.date);
			printf("\n%d", head->data.services);
			printf("\n---------------------");
			if (fwrite(&head->data, sizeof(User), 1, fp) != 1)
			{
				printf("Error writing in file");
				exit(2);
			}
		}
		head = head->next;
	}
}

List* deleteList(List *head) 
{
	while (head != NULL)
	{
		List *temp = head;
		head = head->next;
		free(temp);
	}
	return head;
}

List *deleteUser(List *head, char name[])
{
	List *curr = head;
	List *prev = head;
	while (curr != NULL) 
	{
		if (strcmp(name, curr->data.name) == 0)
		{
			prev->next = curr->next;
			free(curr);
			break;
		}
		prev = curr;
		curr = curr->next;
	}
	return head;
}

int main()
{
	List *head = NULL;

	User tempUser;
	printf("Enter name: ");
	fgets(tempUser.name, 31, stdin);
	tempUser.name[strlen(tempUser.name) - 1] = '\0';
	printf("\nEnter ID: ");
	fgets(tempUser.ID, 11, stdin);
	tempUser.ID[strlen(tempUser.ID) - 1] = '\0';
	printf("\nEnter date(YYYY.MM.DD): ");
	fgets(tempUser.date, 12, stdin);
	tempUser.date[strlen(tempUser.date) - 1] = '\0';
	printf("\nEnter services: ");
	scanf("%d", &tempUser.services);
	while (getchar() != '\n');

	head = addNode(head, tempUser);
	head = addNode(head, tempUser);
	head = addNode(head, tempUser);
	head = addNode(head, tempUser);

	char ID[11];
	printf("\nEnter ID: ");
	fgets(ID, 11, stdin);
	ID[strlen(ID) - 1] = '\0';

	int check = searchClient(head, ID);

	char date[12];
	printf("\nEnter new date(YYYY.MM.DD): ");
	fgets(date, 12, stdin);
	date[strlen(date) - 1] = '\0';

	expiresIn(head, date);

	char name[31];
	printf("\nEnter name: ");
	fgets(name, 31, stdin);
	name[strlen(name) - 1] = '\0';

	head = deleteUser(head, name);

	head = deleteList(head);

	system("pause");

	return 0;
}