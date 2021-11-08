#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define _CRT_SECURE_NO_WARNINGS
#define n 3 // timetables count
#define k 20 // desination length
#define t 7 // HH:MM time format

struct node {
	int num; // race number
	char str[k]; // destination
	char t_b[t]; // start
	char t_e[t]; // end

} timetable;

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

int main()
{
	printf("Bus station information");
	struct node timetable[n];
	int q = 0;
	int i = 0;
	int w = 0;
	printf("\n0-Exit, 1-Add, 2-Remove, 3-Print, 4-Seek routes\n");
	scanf_s("%d", &q);
	while (q != 0)
	{
		getchar();
		if (q == 1)
		{
			//enter elements
			i = w;
			if (i < n)
			{
				printf("\n%d route:\n", i + 1);
				printf("Race number:\n");
				scanf_s("%d", &timetable[i].num);
				getchar();
				printf("Destination:\n");
				fgets(timetable[i].str, k, stdin);
				printf("Departure time (HH:MM)\n");
				fgets(timetable[i].t_b, t, stdin);
				printf("Arrival time (HH:MM)\n");
				fgets(timetable[i].t_e, t, stdin);
				i++;
			}
			w = i;
			if (w == n)
			{
				printf("\nStruct is full!");
			}

		}

		if (q == 2)
		{
			printf("\nEnter struct Num:\n");
			int z = 0;
			scanf_s("%d", &z);
			if (z < w)
			{
				for (int j = z; j < n; j++)
				{
					timetable[j].num = timetable[j + 1].num;
					for (int x = 0; x < k; x++)
					{
						timetable[j].str[x] = timetable[j + 1].str[x];
					}

					for (int x = 0; x < t; x++)
					{
						timetable[j].t_b[x] = timetable[j + 1].t_b[x];
					}

					for (int x = 0; x < t; x++)
					{
						timetable[j].t_e[x] = timetable[j + 1].t_e[x];
					}
				}
				w--;
			}

			else
			{
				printf("\nError!\n");
			}
			
		}

		if (q == 3)
		{
			int f = 0;
			for (int j = 0; j < w; j++)
			{
				printf("Race number:\n");
				printf("%d\n", timetable[j].num);
				printf("Destination:\n");
				printf("%s\n", timetable[j].str);
				printf("Departure time (HH:MM)\n");
				printf("%s\n", timetable[j].t_b);
				printf("Arrival time (HH:MM)\n");
				printf("%s\n", timetable[j].t_e);
				f++;
			}

			if (f == 0)
			{
				printf("\nThere are no routes!\n");
			}
		}

		if (q == 4)
		{
			//user destination
			char str[k];
			char time[t];
			printf("\nEnter destination where you want to go:\n");
			fgets(str, k, stdin);
			printf("Enter time (HH:MM)\n");
			fgets(time, t, stdin);

			//main loop
			int f = 0;
			printf("\nYou can use this races:\n");
			for (int i = 0; i < w; i++)
			{
				if (compare(timetable[i].str, str) == 0)
				{
					int hu = 0, mu = 0, he = 0, me = 0;
					char str1[3];
					strncpy(str1, time, 2);
					hu = atoi(str1);
					strncpy(str1, time + 3, 2);
					mu = atoi(str1);
					strncpy(str1, timetable[i].t_e, 2);
					he = atoi(str1);
					strncpy(str1, timetable[i].t_e + 3, 2);
					me = atoi(str1);
					if (he == hu)
					{
						if (me <= mu)
						{
							printf("Race number:\n");
							printf("%d\n", timetable[i].num);
							printf("Destination:\n");
							printf("%s\n", timetable[i].str);
							printf("Departure time (HH:MM)\n");
							printf("%s\n", timetable[i].t_b);
							printf("Arrival time (HH:MM)\n");
							printf("%s\n", timetable[i].t_e);
							f++;
						}
					}
					if (he < hu)
					{
						printf("Race number:\n");
						printf("%d\n", timetable[i].num);
						printf("Destination:\n");
						printf("%s\n", timetable[i].str);
						printf("Departure time (HH:MM)\n");
						printf("%s\n", timetable[i].t_b);
						printf("Arrival time (HH:MM)\n");
						printf("%s\n", timetable[i].t_e);
						f++;
					}
				}
			}
			if (f > 0)
			{
				printf("You can choose from %d races\n", f);
			}
			if (f == 0)
			{
				printf("Sorry, we can't effort you any races!\n");
			}
		}
		printf("\n0-Exit, 1-Add, 2-Remove, 3-Print, 4-Seek routes\n");
		scanf_s("%d", &q);
	}
}
