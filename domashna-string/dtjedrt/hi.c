#include <stdio.h>
#include <string.h>
int main()
{
	int i, j, count = 0, inWord = 0, maxMin = 0;
	char str[256], word[256], maxWord[256], minWord[256];
	
    while (printf("Enter text. For exit - Ctrl/Z: "), fgets(str, 255, stdin) != NULL)
	{
		i = 0; j = 0;
		for (i = 0; str[i]; i++)
		{
			if (inWord == 0) {
				if (str[i] != '\n' && str[i] != '\t' && str[i] != ' ') {
					inWord = 1;
					word[j] = str[i];
				//	printf("\n%s\n", word);
				}
			}
			else {
				if (str[i] != '\n' && str[i] != '\t' && str[i] != ' ')
					word[j++] = str[i];
				else {
					word[j] = '\0';
					j = 0;
					printf("The input words are: \n%s\n", word);
					count++;
					if (maxMin == 0) { 
						strcpy(maxWord, word);
						strcpy(minWord, word);
						maxMin = 1;
					}
					else {
						if (strlen(maxWord) < strlen(word))
							strcpy(maxWord, word);
						if (strlen(minWord) > strlen(word))
							strcpy(minWord, word);
					//	printf("\n\n\nThe max word is: %s \nThe min word is: %s\n", maxWord, minWord);
					}
				}
			}
        }
		   printf("\n\n\nThe max word is: %s \nThe min word is: %s\n", maxWord, minWord);
	
	}

	return 0;
}