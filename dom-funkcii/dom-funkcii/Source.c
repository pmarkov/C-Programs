#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include "Header.h"


int main()
{
	char str[256], max[256], min[256], wantedWordArr[256];
	int flag = 1;
	
	while (flag == 1)
	{
		flag = 0;
		printf("Enter the word you want to count: ");
		readFile(wantedWordArr);
		wantedWordArr[strlen(wantedWordArr)-1] = '\0';
		for (int i = 0; i < strlen(wantedWordArr); i++)
		{
			if (wantedWordArr[i] == ' ' || wantedWordArr[i] == '\n')
				if (wantedWordArr[i + 1] != ' ' && wantedWordArr[i + 1] != '\n')
					flag = 1;
		}
	}

	while (printf("\nInput line. For exit(Ctrl/Z): "), readFile(str) != NULL)
	{		
		printf("\nCount= %d", maxMin(min, max, str));
		printf("\nMax: %s", max);
		printf("\nMin: %s", min);
		printf("\nCount of wanted word: %d\n", wantedWord(str, wantedWordArr));
	}

	return 0;
}

char *readFile(char *str)
{
	return fgets(str, 255, stdin);
}

int maxMin(char *min, char *max, char *str)
{
	int count = 0;
	int i = 0, j = 0, inWord = 0, minMax = 0;
	char word[256];
	for (; i < strlen(str); i++) 
	{
		j = 0;
		inWord = 0;
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && i < strlen(str))
		{
			word[j++] = str[i++];
			inWord = 1;
		}
		word[j] = '\0';

		if (inWord == 1)
		{
			count++;
			if (minMax == 0) {
				strcpy(min, word);
				strcpy(max, word);
				minMax = 1;
			}
			else
			{
				if (strlen(min) > strlen(word)) 
					strcpy(min, word);
				if (strlen(max) < strlen(word)) 
					strcpy(max, word);
			}
		}
	}
	
	return count;
}

int wantedWord(char *str, char *wantedWordArr)
{
	int count = 0;
	int i = 0, j = 0, inWord = 0;
	char word[256];
	for (; i < strlen(str); i++)
	{
		j = 0;
		inWord = 0;
		while (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && i < strlen(str))
		{
			word[j++] = str[i++];
			inWord = 1;
		}
		word[j] = '\0';
		if (inWord == 1) 
		{
			if (strcmp(word, wantedWordArr)==0)
				count++;
		}
	}
	return count;
}

