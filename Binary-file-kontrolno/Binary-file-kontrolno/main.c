#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Client {
	int number;
	char name[20];
	char address[20];
	double income;
};

void createFile(char *fileName, int count);
void readFile(FILE *fp, struct Client clientInfo);

int main(int argc, char *argv[])
{
	if (argc < 4)
	{
		printf("Not enough arguments");
		exit(1);
	}

	FILE *fpR;
	struct Client clientInfo;
	int clientNumber = atoi(argv[1]);
	int articleNo = atoi(argv[2]);
	double price = atof(argv[3]);

/*	int n;
	printf("How many clients?");
	scanf("%d", &n);

	createFile("clients.dat", n); */
	
	if ((fpR = fopen("clients.dat", "rb+")) == NULL)
	{
		printf("The file couldn't be found");
		exit(1);
	}

	int i = 0;

	while (fread(&clientInfo, sizeof(struct Client), 1, fpR))
	{
		if (clientInfo.number == clientNumber)
		{
			if (5000 - clientInfo.income < 0);
			{
				price -= price * 10 / 100;
			}
			if(clientInfo.income > 1000 && clientInfo.income <= 5000)
			{
				price -= price * 5 / 100;
			}

			clientInfo.income += price;
			fseek(fpR, sizeof(struct Client) * i, SEEK_SET);
			fwrite(&clientInfo, sizeof(struct Client), 1, fpR);
			printf("\nThe new price is: %.2lf\n\n", price);
			break;
		}
		i++;
	}

	rewind(fpR);

	readFile(fpR, clientInfo);

	fclose(fpR);
	
	system("pause");
	return 0;
}
void createFile(char *fileName, int count)
{
	FILE *fp;
	struct Client client;

	if ((fp = fopen(fileName, "wb")) == NULL)
	{
		printf("Error creating file");
		exit(1);
	}

	for (int i = 0; i < count; i++)
	{
		printf("\nEnter client number: ");
		scanf("%d", &client.number);
		printf("\nEnter client name: ");
		scanf("%s", client.name);
		printf("\nEnter client address: ");
		scanf("%s", client.address);
		printf("\nEnter the income: ");
		scanf("%lf", &client.income);
		fwrite(&client, sizeof(struct Client), 1, fp);
	}
	fclose(fp);
}
void readFile(FILE *fp, struct Client clientInfo)
{
	while (fread(&clientInfo, sizeof(struct Client), 1, fp))
	{
		printf("Client number: %d\n", clientInfo.number);
		printf("Client name: %s\n", clientInfo.name);
		printf("Client address: %s\n", clientInfo.address);
		printf("Income: %.2lf\n\n\n", clientInfo.income);
	}
}