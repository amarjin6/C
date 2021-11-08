#include <stdio.h>
#include <string.h>
#define n 80 // length path to the file
#define k 100 // quantity strings
#define m 255 // length strings in file
#define file_b "b.txt"
#define file_a "a.txt"
#include <locale.h>

void revstr(char* str1)
{
	int i, len, temp;
	len = strlen(str1);
	if (str1[len-1] == '\n')
	{
		len -= 1;
	}
	for (i = 0; i < len / 2; i++)
	{
		temp = str1[i];
		str1[i] = str1[len - i - 1];
		str1[len - i - 1] = temp;
	}
}

int main()
{
	//setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	printf("Enter file name: \n");
	char s[n] = "";
	char s2[n] = "";
	gets(s);
	int x = 0;
	FILE* a, * b;
	printf("\n0 - exit, 1 - add component, 2 - remove all, 3 - show all, 4 - rewrite reverse, 5 - show reversed: \n");
	scanf_s("%d", &x);
	getchar();
	while (x != 0)
	{
		if (x == 1)
		{
			a = fopen(s, "a+");
			char s1[n] = "";
			gets(s1);
			fflush(a);
			fseek(a, 0, SEEK_END);
			long pos = ftell(a);
			if (pos > 0)
			{
				fputs("\n", a);
			}
			fprintf(a, "%s", s1);
			fclose(a);
		}

		if (x == 2)
		{
			a = fopen(s, "w");
			fclose(a);
		}

		if (x == 3)
		{
			printf("\nFILE content:\n");
			a = fopen(s, "a+");
			char r[m] = "";
			while (!feof(a))
			{
				fgets(r, n, a);
				printf("%s", r);
			}
			if (r[0] == '\0')
			{
				printf("File is EMPTY!\n");
			}
			fclose(a);
		}

		if (x == 4)
		{
			char str[k][m];
			int i = 0;
			a = fopen(s, "a+");
			while (!feof(a))
			{
				fgets(str[i], n, a);
				i++;
			}
			fclose(a);
			printf("Enter file name: \n");
			gets(s2);
			b = fopen(s2, "w");
			for (int j = i-1; j >= 0; j--)
			{
				//revstr(str[j]);
				fprintf(b, "%s", str[j]);
			}
			fclose(b);
		}

		if (x == 5)
		{
			printf("\nFILE content:\n");
			b = fopen(s2, "a+");
			char r[m] = "";
			if (b == NULL)
			{
				printf("\nError\n");
				return 0;
			}
			while (!feof(b))
			{
				fgets(r, n, b);
				printf("%s", r);
			}
			if (r[0] == '\0')
			{
				printf("File is EMPTY!\n");
			}
			fclose(b);
		}

		printf("\n0 - exit, 1 - add component, 2 - remove all, 3 - show all, 4 - rewrite reverse, 5 - show reversed: \n");
		scanf_s("%d", &x);
		getchar();
	}
	return 0;
}