#pragma once

typedef struct StorageInfo {
	char ID[14];
	char productName[50];
	double price;
	int quantity;
	char date[14];
} StorageInfo;

typedef struct StorageList {
	StorageInfo storageInfo;
	struct StorageList *next;
} StorageList;

StorageList* createList(StorageList *root, FILE *fp);
StorageList* addNode(StorageList *root, StorageInfo properties);
StorageList* removeNode(StorageList *root, StorageList* node);
StorageList* createNode(StorageInfo properties);
StorageList* changeProductQuantity(StorageList *root, FILE** fp, char *productID);
StorageList* addNewProduct(StorageList *root, FILE *fp);
StorageInfo newProductInfo();
FILE* fileOpen();
void showProduct(StorageList *root, char *productID);
void expiredProducts(StorageList *root);
void printStorage(StorageList *root);
void printMenu();
StorageList* freeList(StorageList* root);