#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int main()
{
	int i, j, count = 0, inWord = 0, maxMin = 0, countwantedword = 0;
	char str[256], word[256], maxWord[256], minWord[256], wantedWord[256];
	int flag = 1;

	while (flag == 1) 
	{
		flag = 0;
		printf("Enter the word you want to count: ");
		fgets(wantedWord, 255, stdin);
		wantedWord[strlen(wantedWord) - 1] = '\0';
		for (i = 0; i < strlen(wantedWord); i++)
		{
			if (wantedWord[i] == ' ' || wantedWord[i] == '\n')
				if (wantedWord[i + 1] != ' ' && wantedWord[i + 1] != '\n')
					flag = 1;
		}
	}
	
	while (printf("Enter text. For exit - Ctrl/Z: "), fgets(str, 255, stdin) != NULL)
	{
		i = 0; j = 0;
		for (i = 0; str[i]; i++)
		{
			if (inWord == 0) 
			{
				if (str[i] != '\n' && str[i] != '\t' && str[i] != ' ') 
				{
					inWord = 1;
					word[j++] = str[i];
				}
			}
			else 
			{
				if (str[i] != '\n' && str[i] != '\t' && str[i] != ' ')
					word[j++] = str[i];
				else 
				{
					word[j] = '\0';
					if (strcmp(word, wantedWord)==0)
					{
						countwantedword++;
					}
					j = 0;
					printf("\nInput words: %s\n", word);
					count++;
					if (maxMin == 0) 
					{
						strcpy(maxWord, word);
						strcpy(minWord, word);
						maxMin = 1;
					}
					else 
					{
						if (strlen(maxWord) < strlen(word))
							strcpy(maxWord, word);
						if (strlen(minWord) > strlen(word))
							strcpy(minWord, word);
					}
				}
			}
		}
		printf("\nThe word %s is used %d time(s).", wantedWord, countwantedword);
        printf("\nThe max word is: %s \nThe min word is: %s\n", maxWord, minWord);

	}

	return 0;
}