#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct tnode {
	int count;
	char *word;
	struct tnode *left;
	struct tnode *right;
};

struct tnode *addtree(struct tnode *, char *);
int getword(char *line, char *word, int maxsize);
void treeprint(struct tnode *);
void freestruct(struct tnode *);

int main()
{
	struct tnode *root;
	char line[256];
	char word[50];
	FILE *fpR;

	if (!(fpR = fopen("D:\\test.txt", "rt")))
	{
		printf("Error opening file!");
		return 1;
	}

	root = NULL;

	while (fgets(line, 256, fpR) != NULL)
	{
		while (getword(line, word, 50))
				root = addtree(root, word);
	}
	treeprint(root);
	freestruct(root);
	free(root);

	getchar();
	return 0;
}
int getword(char *line, char *word, int maxsize)
{
	static int i;
	int j;

	while (line[i] != '\0')
	{
		if (isalpha(line[i]))
		{
			j = 0;
			while (isalpha(line[i]) && line[i] != '\0' && j < maxsize)
				word[j++] = line[i++];
			word[j] = '\0';
			return 1;
		}
		i++;
	}
	i = 0;
	return 0;
}
struct tnode *addtree(struct tnode *p, char *word)
{
	int cond;
	if (p == NULL)
	{
		p = (struct tnode *) malloc(sizeof(struct tnode));
		p->word = _strdup(word);
		if (p->word == NULL)
		{
			printf("No allocated memory");
			return NULL;
		}
		p->count = 1;
		p->left = p->right = NULL;
	}
	else if (cond = strcmp(word, p->word) == 0)
		p->count++;
	else if (cond < 0)
		p->left = addtree(p->left, word);
	else
		p->right = addtree(p->right, word);
	return p;
}
void treeprint(struct tnode *p)
{
	if (p != NULL)
	{
		treeprint(p->left);
		printf("%4d  %s\n", p->count, p->word);
		treeprint(p->right);
	}
}
void freestruct(struct tnode *p)
{
	if (p != NULL)
	{
		freestruct(p->left);
		free(p->word);
		free(p->left);
		freestruct(p->right);
		free(p->right);
	}
}