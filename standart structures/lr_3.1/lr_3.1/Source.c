#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
//#include <locale.h> // для русского языка
#include <string.h>
#include <stdlib.h> // для malloc
#define n 61
#define a 97
#define A 65
#define z 122
#define Z 90

int sort_letter(char* str)
{
	int k = 0;
	for (int i = 0; i < (int)strlen(str) - 1; i++)
	{
		if (str[i] < str[i + 1])
		{
			k++;
		}
	}

	return k;
}

int compare(char* str1, char* str2)
{
	int len = 0;
	if (strlen(str1) >= strlen(str2))
	{
		len = strlen(str2);
	}

	if (strlen(str2) > strlen(str1))
	{
		len = strlen(str1);
	}

	for (int i = 0; i < len; i++)
	{
		if (str1[i] != str2[i])
		{
			return 1;
		}
	}

	return 0;
}

void change_letter(char* str)
{
	if ((strlen(str)) % 2 > 0)
	{
		for (int i = 0; i < (int)strlen(str); i++)
		{
			if (str[i] == 'b')
				str[i] = 'B';

			if (str[i] == 'c')
				str[i] = 'C';

			if (str[i] == 'd')
				str[i] = 'D';

			if (str[i] == 'f')
				str[i] = 'F';

			if (str[i] == 'g')
				str[i] = 'G';

			if (str[i] == 'h')
				str[i] = 'H';

			if (str[i] == 'j')
				str[i] = 'J';

			if (str[i] == 'k')
				str[i] = 'K';

			if (str[i] == 'l')
				str[i] = 'L';

			if (str[i] == 'm')
				str[i] = 'M';

			if (str[i] == 'n')
				str[i] = 'N';

			if (str[i] == 'p')
				str[i] = 'P';

			if (str[i] == 'q')
				str[i] = 'Q';

			if (str[i] == 'r')
				str[i] = 'R';

			if (str[i] == 's')
				str[i] = 'S';

			if (str[i] == 't')
				str[i] = 'T';

			if (str[i] == 'v')
				str[i] = 'V';

			if (str[i] == 'w')
				str[i] = 'W';

			if (str[i] == 'x')
				str[i] = 'X';

			if (str[i] == 'y')
				str[i] = 'Y';

			if (str[i] == 'z')
				str[i] = 'Z';
		}

		printf("%s\n", str);
	}

	else
	{
		printf("%s\n", str);
	}

}

int check_str(char* str)
{
	for (int i = strlen(str) - 1; i >= 0; i--)
	{
		if ((str[i] < a || str[i] > z) && (str[i] < A || str[i] > Z) && (str[i] != '\n'))
		{
			return 1;
		}
	}

	if (strlen(str) == 0)
	{
		return -1;
	}

	return 0;
}

int main()
{
	char* str;  // строка на n элементов
	str = (char*)malloc(sizeof(char) * n);
	char words[n][n] = { '\0' };
	printf("Enter string (max - %d elements):\n", n - 1);
	fgets(str, n, stdin); // без вылета gets

	int i = 0, j = 0;
	while (i < (int)(strlen(str) - 1))
	{
		while (str[i] == ' ')
		{
			i++;
		}

		int start = i;

		while (str[i] != ' ' && i < (int)(strlen(str) - 1))
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

		int check = check_str(words[j]);
		if (check == 0)
		{
			j++;
		}

		if (check == 1)
		{
			int l = 0;
			for (int k = start; k < end; k++)
			{
				words[j][l] = '\0';
				l++;
			}
		}

	}

	int k = 0;
	printf("\nYour words:\n");
	for (int i = 0; i < j; i++)
	{
		if (words[i] != '\0')
		{
			printf("%s\n", words[i]);
			k++;
		}

	}

	if (k == 0)
	{
		printf("You haven't got any words!\n");
		return 0;
	}

	if (k > 0)
	{
		printf("\nFirst task:\n");
		int kol[n] = { -1 };
		int j1 = 0;
		for (int i = 0; i < j + 1; i++)
		{
			if (compare(words[i], words[j - 1]) == 1)
			{
				int k1 = sort_letter(words[i]);
				kol[j1] = k1;
				j1++;
			}
		}

		int min = kol[0];
		for (int i = 0; i < j1; i++)
		{
			if (kol[i] < min)
			{
				min = kol[i];
			}
		}

		for (int i = 0; i < j1; i++)
		{
			if (kol[i] == min && (compare(words[i], words[j - 1]) == 1))
			{
				printf("%s\n", words[i]);
			}
		}

		printf("\nSecond task:\n");
		for (int i = 0; i < j; i++)
		{
			if (compare(words[i], words[j - 1]) == 1)
			{
				str = words[i];
				change_letter(str);
			}
		}
	}

	return 0;
}