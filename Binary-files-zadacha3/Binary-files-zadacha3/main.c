#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Schedule {
	char busNumber[20];
	double departureHour;
	char startingCity[20];
	char destinationCity[20];
	int place;
	double ticketPrice;
	int freePlaces;
	int busyPlaces[30];
};

void makeFile(char *fname);
void readFile(char *fname);
void tickets(char *busNumber, int wantedPlace);

int main()
{
	char fileName[] = "schedule.dat";
	char busNumber[20];
	int wantedPlace;

//	makeFile(fileName);
	readFile(fileName);

	printf("\nEnter bus number: ");
	fgets(busNumber, 20, stdin);
	busNumber[strlen(busNumber) - 1] = '\0';

	printf("Enter wanted place: ");
	scanf("%d", &wantedPlace);

	tickets(busNumber, wantedPlace);


	system("pause");
	return 0;
}

void makeFile(char *fname)
{
	FILE *fp;
	struct Schedule busline;
	int count;

	if ((fp = fopen(fname, "wb")) == NULL)
	{
		exit(1);
	}

	printf("How many bus lines?\n");
	scanf("%d", &count);

	for (int i = 0; i < count; i++)
	{
		printf("\nEnter bus number: ");
		scanf("%s", busline.busNumber);

		printf("\nEnter departure hour: ");
		scanf("%lf", &busline.departureHour);

		printf("\nEnter starting city: ");
		scanf("%s", busline.startingCity);

		printf("\nEnter destination city: ");
		scanf("%s", busline.destinationCity);

		printf("\nEnter wanted place: ");
		scanf("%d", &busline.place);

		printf("\nEnter ticket price: ");
		scanf("%lf", &busline.ticketPrice);

		printf("\nEnter free places: ");
		scanf("%d", &busline.freePlaces);
		while (getchar() != '\n');

		for (int i = 0; i < 30; i++)
		{
			busline.busyPlaces[i] = 0;
		}
		if (fwrite(&busline, sizeof(struct Schedule), 1, fp) != 1)
		{
			printf("Error writing in file");
			exit(2);
		}
	}

	fclose(fp);
}
void readFile(char *fname)
{
	FILE *fp;
	struct Schedule busLines;

	if ((fp = fopen(fname, "rb")) == NULL)
	{
		printf("Error opening file for reading");
		exit(3);
	}

	int i = 1;
	while (fread(&busLines, sizeof(struct Schedule), 1, fp))
	{
		printf("Bus %d number: %s\n", i,  busLines.busNumber);
		printf("Departure hour: %.2lf\n", busLines.departureHour);
		printf("Starting city: %s\n", busLines.startingCity);
		printf("Destination city: %s\n", busLines.destinationCity);
		printf("Wanted place: %d\n", busLines.place);
		printf("Ticket price: %.2lf\n", busLines.ticketPrice);
		printf("Free places: %d\n\n\n", busLines.freePlaces);
		i++;
	}
	fclose(fp);
}

void tickets(char *busNumber, int wantedPlace)
{
	FILE *fp;
	struct Schedule busline;
	int count = 0;

	if ((fp = fopen("schedule.dat", "rb+")) == NULL)
	{
		printf("Error opening file");
		exit(3);
	}

	while (fread(&busline, sizeof(struct Schedule), 1, fp))
	{
		if (!strcmp(busNumber, busline.busNumber))
		{
			if (busline.freePlaces == 0)
			{
				printf("No free places are left\n");
				fclose(fp);
				return;
			}
			else
			{
				if (wantedPlace <= 30)
				{
					if (!busline.busyPlaces[wantedPlace - 1])
					{
						printf("The place costs %.2lf\n", busline.ticketPrice);
						busline.freePlaces--;
						busline.place = wantedPlace;
						busline.busyPlaces[wantedPlace - 1] = 1;
						fseek(fp, sizeof(struct Schedule) * count, SEEK_SET);
						fwrite(&busline, sizeof(struct Schedule), 1, fp);
						fclose(fp);
						return;
					}
					else
					{
						printf("This place is already taken\nThe places that are free are: ");
						for (int i = 0; i < 30; i++)
						{
							if (!busline.busyPlaces[i])
								printf("%d ", i+1);
						}
						printf("\n");
						return;
					}
				}
				
			}
		}
		count++;
	}
	printf("This number cannot be found\n");
	fclose(fp);
	return;
}