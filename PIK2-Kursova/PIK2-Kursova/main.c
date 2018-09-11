#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

char fileName[30];

int main()
{
	FILE *fp = fileOpen();
	
	StorageList *root = NULL;
	root = createList(root, fp);
	
	if (root == NULL) {
		printf("The file is empty\n");
	}
	
	char ID[14];
	int quit = 0;

	printMenu();
	while (!quit) {
		int choice = 0, k;
		do {
			printf("\nEnter your choice(7 for menu): ");
			k = scanf("%d", &choice);
			while (getchar() != '\n');
		} while (k != 1);
		system("cls");
		switch (choice) {
			case 1:
				root = addNewProduct(root, fp);
				break;
			case 2:
				printf("Enter product ID: ");
				fgets(ID, 14, stdin);
				ID[strlen(ID) - 1] = '\0';
				root = changeProductQuantity(root, &fp, ID);
				break;
			case 3:
				expiredProducts(root);
				break;
			case 4:
				printf("Enter product ID: ");
				fgets(ID, 14, stdin);
				ID[strlen(ID) - 1] = '\0';
				showProduct(root, ID);
				break;
			case 5:
				printStorage(root);
				break;
			case 6:
				quit = 1;
				break;
			case 7:
				printMenu();
				break;
		}

	}

	root = freeList(root);
	fclose(fp);

	return 0;
}

FILE* fileOpen()
{
	FILE *fp;

	printf("Enter the storage file you want to open: ");
	fgets(fileName, 29, stdin);
	fileName[strlen(fileName) - 1] = '\0';

	if ((fp = fopen(fileName, "ab+")) == NULL) {
		printf("Cannot open %s.\n", fileName);
		system("pause");
		exit(1);
	}
	return fp;
}

StorageList* createList(StorageList *root, FILE *fp)
{
	rewind(fp);
	
	StorageInfo properties;

	while (!feof(fp)) {
		if (fread(&properties, sizeof(StorageInfo), 1, fp) != 1) {
			break;
		}
		root = addNode(root, properties);
	}
	return root;
}

StorageList *addNode(StorageList* root, StorageInfo properties)
{
	if (root == NULL) {
		root = createNode(properties);
	}
	else {
		StorageList *temp = root;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = createNode(properties);
	}
	return root;
}

StorageList* createNode(StorageInfo properties)
{
	StorageList *newNode = (StorageList*)malloc(sizeof(StorageList));
	if (newNode == NULL) {
		printf("Error allocating memory");
	}
	else {
		newNode->storageInfo = properties;
		newNode->next = NULL;
	}
	return newNode;
}

StorageList* addNewProduct(StorageList *root, FILE *fp)
{
	StorageInfo productInfo = newProductInfo();

	if (fwrite(&productInfo, sizeof(StorageInfo), 1, fp) != 1) {
		printf("Error writing the data in file");
	}
	else {
		root = addNode(root, productInfo);
	}
	return root;
}

StorageInfo newProductInfo()
{
	StorageInfo newInfo;
	int k;

	printf("Enter product ID(12 symbols): ");
	fgets(newInfo.ID, 14, stdin);
	newInfo.ID[strlen(newInfo.ID) - 1] = '\0';


	printf("\nEnter product name: ");
	fgets(newInfo.productName, 49, stdin);
	newInfo.productName[strlen(newInfo.productName) - 1] = '\0';

	do {
		printf("\nEnter the price: ");
		k = scanf("%lf", &newInfo.price);
		while (getchar() != '\n');
	} while (k != 1);

	do {
		printf("\nEnter quantity of the product: ");
		k = scanf("%d", &newInfo.quantity);
		while (getchar() != '\n');
	} while (k != 1 && newInfo.quantity <= 0);

	int flag = 1;
	char currDate[14];
	while (flag) {
		flag = 0;
		printf("\nEnter the current date: ");
		fgets(currDate, 13, stdin);
		currDate[strlen(currDate) - 1] = '\0';
		for (unsigned int i = 0; i < strlen(currDate); i++) {
			if (i == 2 || i == 5) {
				if (currDate[i] != '.') {
					flag = 1;
					printf("Invalid input\n");
					break;
				}
			}
			else {
				if (currDate[i] < '0' || currDate[i] > '9') {
					printf("Invalid date input\n");
					flag = 1;
					break;
				}
			}
		}
	}
	strcpy(newInfo.date, currDate);

	return newInfo;
}

StorageList* changeProductQuantity(StorageList *root, FILE** fp, char *productID)
{
	int addition;
	int choice, k;
	do {
		printf("1 - for addition\n2 - for substraction\nEnter here: ");
		k = scanf("%d", &choice);
		while (getchar() != '\n');
	} while (k != 1 && (choice != 1 || choice != 2));
	if (choice == 1) {
		do {
			printf("Enter the quantity you want to add: ");
			k = scanf("%d", &addition);
			while (getchar() != '\n');
		} while (k != 1);
	}
	else {
		do {
			printf("Enter the quantity you want to substract: ");
			k = scanf("%d", &addition);
			while (getchar() != '\n');
		} while (k != 1);
		addition *= (-1);
	}
	StorageList *temp = root;
	while (temp != NULL) {
		if (strcmp(temp->storageInfo.ID, productID) == 0) {
			int tempQuantity = temp->storageInfo.quantity + addition;
			if (tempQuantity < 0) {
				printf("There is only %d of this product.\n", temp->storageInfo.quantity);
				return root;
			}
			else if (tempQuantity == 0) {
				printf("There is no more left of this product and it will be removed.\n");
				root = removeNode(root, temp);
			}
			else {
				temp->storageInfo.quantity = tempQuantity;
			}
			FILE *tempFptr = fopen("temp_file.bin", "ab+");
			temp = root;

			while (temp != NULL) {
				fwrite(&temp->storageInfo, sizeof(StorageInfo), 1, tempFptr);
				temp = temp->next;
			}
			fclose(*fp);
			fclose(tempFptr);
			if (remove(fileName) != 0) {
				printf("Error deleting file\n");
			}
			if (rename("temp_file.bin", fileName) != 0) {
				printf("Error renaming file\n");
			}
			(*fp) = fopen(fileName, "ab+");
			return root;
		}
		temp = temp->next;
	}

	printf("There is no product with that ID.\n");

	return root;
}

StorageList *removeNode(StorageList *root, StorageList* node)
{
	if (node == root) {
		root = root->next;
		free(node);
	}
	else {
		StorageList *temp = root;
		while (temp->next != node) {
			temp = temp->next;
		}
		temp->next = node->next;
		free(node);
	}
	return root;
}

void expiredProducts(StorageList *root)
{
	if (root == NULL) {
		printf("The list is empty.\n");
		return;
	}
	char currDate[14];
	int flag = 1;

	while (flag) {
		flag = 0;
		printf("Enter the current date: ");
		fgets(currDate, 13, stdin);
		currDate[strlen(currDate) - 1] = '\0';
		for (unsigned int i = 0; i < strlen(currDate); i++) {
			if (i == 2 || i == 5) {
				if (currDate[i] != '.') {
					flag = 1;
					printf("Invalid input\n");
					break;
				}
			}
			else {
				if (currDate[i] < '0' || currDate[i] > '9') {
					printf("Invalid date input\n");
					flag = 1;
					break;
				}
			}
		}
	}
	int day = atoi(currDate);
	int month = atoi(&currDate[3]);
	int year = atoi(&currDate[6]);

	printf("-------------------------------\n");
	while (root != NULL) {
		int prDay = atoi(root->storageInfo.date);
		int prMonth = atoi(&root->storageInfo.date[3]);
		int prYear = atoi(&root->storageInfo.date[6]);

		if (prYear < year) {
			showProduct(root, root->storageInfo.ID);
		}
		else if (prYear == year) {
			if (prMonth < month) {
				showProduct(root, root->storageInfo.ID);
			}
			else if (prMonth == month) {
				if (prDay < day) {
					showProduct(root, root->storageInfo.ID);
				}
			}
		}
		root = root->next;
	}

}

void showProduct(StorageList *root, char *productID)
{
	if (root == NULL) {
		printf("The storage is empty.\n");
	}
	else {
		while (root != NULL) {
			if (strcmp(root->storageInfo.ID, productID) == 0) {
				printf("Product ID : %s\n", root->storageInfo.ID);
				printf("Product name: %s\n", root->storageInfo.productName);
				printf("Price: %.2lf.\n", root->storageInfo.price);
				printf("Product quantity: %d\n", root->storageInfo.quantity);
				printf("Date of manufacture: %s\n", root->storageInfo.date);
				printf("-------------------------------\n");
				return;
			}
			root = root->next;
		}
		printf("There is no product with %s ID.\n", productID);
	}
}

void printStorage(StorageList *root)
{
	if (root == NULL) {
		printf("This storage is empty.\n");
		return;
	}
	while (root != NULL) {
		printf("Product ID: %s\n", root->storageInfo.ID);
		printf("Product name: %s\n", root->storageInfo.productName);
		printf("Price: %.2lf.\n", root->storageInfo.price);
		printf("Product quantity: %d\n", root->storageInfo.quantity);
		printf("Date of manufacture: %s\n", root->storageInfo.date);
		printf("-------------------------------\n");
		root = root->next;
	}
	printf("\n");
}

void printMenu()
{
	printf("Choose:\n1 - Enter new product in the storage.\n2 - Change quantity of product.\n");
	printf("3 - Show products with expired date.\n4 - Show product info.\n5 - Show storage content.\n");
	printf("6 - To exit the program.\n7 - To show options.");
}
StorageList* freeList(StorageList* root)
{
	StorageList* temp;
	while (root != NULL) {
		temp = root;
		root = root->next;
		free(temp);
	}
	return root;
}