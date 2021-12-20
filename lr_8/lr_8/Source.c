#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define State 5
#define n 100

/*
char c1[] = "ctUnknown";
char c2[] = "ctLetter";
char c3[] = "ctOperator_1";
char c4[] = "ctOperator_2";
char c5[] = "ctSymbol";
*/

int IsFinalState[State+1] = { 0, 0, 0, 0, 1, 1 };

int Transitions[State+1][State] = {
								  {0, 0, 0, 0, 0},
								  {0, 2, 0, 0, 0},
								  {0, 0, 3, 0, 0},
								  {0, 0, 0, 4, 0},
								  {0, 0, 0, 0, 5},
								  {0, 0, 0, 4, 5}
};

int GetCharType(char c)
{
	if (c >= 65 && c <= 90)
	{
		return 1;
	}

	else if (c == ':')
	{
		return 2;
	}

	else if (c == '\\')
	{
		return 3;
	}

	else if (c != '*' && c != '|' && c != '\\' && c != ':' && c != '"' && c != '<' && c != '>' && c != '?' && c != '/')
	{
		return 4;
	}

	else
	{
		return 0;
	}
}

int GetCharType_1(char c)
{

	if (c == ':')
	{
		return 2;
	}

	else if (c == '\\')
	{
		return 3;
	}

	else if (c != '*' && c != '|' && c != '\\' && c != ':' && c != '"' && c != '<' && c != '>' && c != '?' && c != '/')
	{
		return 4;
	}

	else
	{
		return 0;
	}
}

int GetCharType_2(char c)
{

	if (c == ':')
	{
		return 2;
	}

	else if (c == '\\')
	{
		return 3;
	}

	else if (c != '*' && c != '|' && c != '\\' && c != ':' && c != '"' && c != '<' && c != '>' && c != '?' && c != '/' && c != 32)
	{
		return 4;
	}

	else
	{
		return 0;
	}
}

int checkString(char s[], int x)
{
	int state = 1;

	for (int i = 0; i < strlen(s); i++)
	{
		int k = GetCharType(s[i]);

		if (i >= 2)
		{
			if (x == 1)
			{
				k = GetCharType_1(s[i]);
			}

			if (x == 2)
			{
				k = GetCharType_2(s[i]);
			}
		}
		state = Transitions[state][k];
	}

	return IsFinalState[state];
}

int main()
{
	int x = 0;
	char str[n];
	char words[n][n] = { '\0' };
	printf("\n1 - task 1, 2 - task 2, 3 - exit\n");
	scanf_s("%d", &x);
	getchar();
	while (x != 3)
	{
		if (x == 1)
		{
			printf("\nEnter path:\n");
			fgets(str, n, stdin); // без вылета gets

			int k = checkString(str,1);

			if (k == 1)
			{
				printf("\nCorrect!\n");
			}

			else
			{
				printf("\nError!\n");
			}

			for (int j = 0; j < strlen(str); j++)
			{
				str[j] = '\0';
			}
		}

		if (x == 2)
		{
			printf("\nEnter pathes:\n");
			fgets(str, n, stdin); // без вылета gets

			int i = 0, j = 0;

			while (i < (int)(strlen(str) - 1))
			{
				while (str[i] == ',')
				{
					i++;
				}

				int start = i;

				while (str[i] != ',' && i < (int)(strlen(str) - 1))
				{
					i++;
				}

				int end = i;
				int l = 0;

				for (int k = start; k < end; k++)
				{
					words[j][l] = str[k];
					l++;
				}

				j++;
			}

			int k = 0;
			int kk = 0;
			printf("\nYour pathes:\n");
			for (int i = 0; i < j; i++)
			{
				if (words[i] != '\0')
				{
					k = checkString(words[i],2);
					printf("%s - ", words[i]);

					if (k == 1)
					{
						printf("Correct!\n");
						kk++;
					}

					else
					{
						printf("Error!\n");
					}
				}
			}
			printf("\nKOl: %d\n",kk);
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < strlen(words[i]); j++)
				{
					words[i][j] = '\0';
				}
			}

			for (int j = 0; j < strlen(str); j++)
			{
				str[j] = '\0';
			}

		}

		printf("\n1 - task 1, 2 - task 2, 3 - exit\n");
		scanf_s("%d", &x);
		getchar();
	}

	return 0;
}
