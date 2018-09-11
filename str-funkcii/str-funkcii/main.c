#include <stdio.h>

int strlen(char *);
void strcpy(char *, char *);
void strncpy(char *, char *, int n);
int strcmp(char *, char *);
int strncmp(char *, char *, int n);
void strcat(char *, char *);
void strncat(char *, char *, int n);
int strend(char *, char *);


int main()
{
	/*strlen*/

	char *string = "123456";
	printf("strlen - %d\n", strlen(string));

	/**********************************/

	/*strcpy - copy str1 in str2, strncpy*/

	char *str1 = "Copy-test";
	char str2[10];
	strcpy(str2, str1);
	printf("\nstrcpy - %s\n", str2);

	char *str3 = "Hello";
	int n = 3;
	strncpy(str2, str3, n);
	printf("\nstrncpy - %s\n", str2);

	/**********************************/

	/*strcmp - compare str1 to str2*/

	char *string1 = "a2345";
	char *string2 = "12345";
	int val = strcmp(string1, string2);
	printf("\nstrcmp - %d\n", val);

	val = strncmp(string1, string2, n);
	printf("\nstrncmp - %d\n", val);

	/*********************************/

	/*strcat - copy string 't' in the end of string 's', strncat*/

	char *t = "Hello";
	char s[15] = "Hello";
	strcat(t, s);

	printf("\nstrcat - %s\n", s);

	strncat(t, s, 3);
	printf("\nstrncat - %s\n", s);

	/**********************************/

	/*strend - proverqva dali str1 se sudurja v kraq na str2*/

	char *s1 = "abc";
	char *s2 = "1234abc";
	printf("\nstrend - %d\n", strend(s1, s2));

	/**********************************/



	system("pause");
	return 0;
}

int strlen(char *str)
{
	int i = 0;
	while (*str++ != '\0')
		i++;
	return i;
}
void strcpy(char *to, char *from)
{
	if (strlen(to) < strlen(from))
		return;
	while (*to++ = *from++)
		;
}
void strncpy(char *to, char *from, int n)
{
	int i = 0;
	if (strlen(to) < strlen(from))
		return;
	while (*to++ = *from++)
	{
		i++;
		if (i >= n)
			break;
	}
}
int strcmp(char *str1, char *str2)
{
	while(*(str1++) == *(str2++))
	{
		if (*str1 == '\0')
			return 0;
	}
	return *str1 - *str2;
}
int strncmp(char *str1, char *str2, int n)
{
	int i = 0;
	while (i < n)
	{
		if (*(str1 + i) != *(str2 + i))
			return -1;
		i++;
	}
	return 0;
}
void strcat(char *str1, char *str2)
{
	int i = 0, j = 0;
	while (str2[i] != '\0')
		i++;
	for (; str2[i] = str1[j]; i++, j++)
		;
}
void strncat(char *str1, char *str2, int n)
{
	int i = 0, j = 0;
	while (str2[i] != '\0')
		i++;
	for (; str2[i] = str1[j]; i++, j++)
		if (j >= n - 1)
			break;
}
int strend(char *str1, char *str2)
{
	int i = strlen(str2) - strlen(str1);
	int j = 0;

	while (*(str2 + i))
	{
		if (*(str1 + j) != *(str2 + i))
			return 0;
		i++;
		j++;
	}
	return 1;
}