//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//#include <stdlib.h>
#include <locale.h>
#include <math.h>

//#define _CRT_SECURE_NO_WARNINGS
struct node {
    int koeff;
    int power;
    struct node* next;
};

typedef struct node* list;

void createList(list* phead, char* name);
void enterListElems(list* phead);
int addToHead(list* phead, int koeff, int power);
int checkIfExist(list* phead, int power);
void printList(list* phead, char* name);
void Equality(list* P, list* Q);
void Meaning(list* P, list* Q);
void Add(list* P, list* Q, list* R);

int main(void)
{
    list P;
    list Q;
    list R;

    setlocale(LC_ALL, "RUSSIAN");

    createList(&P, "P");
    enterListElems(&P);
    createList(&Q, "Q");
    enterListElems(&Q);
    printList(&P, "P");
    printList(&Q, "Q");
    Equality(&P, &Q, &R);
    Meaning(&P, &Q);
    Add(&P, &Q, &R);
    //system("pause");
    return 0;
}

void createList(list* phead, char* name) //создание списка
{
    *phead = NULL;
    printf("\nСоздание %s:\n", name);
}

int checkIfExist(list* phead, int power, int koeff) // проверка на одинаковую степень в одном и том же списке
{
    list p = *phead;
    while (p != NULL)
    {
        if (p->power == power)
        {
            p->koeff += koeff;
            return 1;
        }
        p = p->next;
    }
    return 0;
}

int addToHead(list* phead, int koeff, int power)
{
    list p;
    if (checkIfExist(phead, power, koeff))
    {
        printf("Такая степень уже есть %d\n", power);
        return 0;
    }
    p = malloc(sizeof(*p));
    p->koeff = koeff;
    p->power = power;
    p->next = *phead;
    *phead = p;
    printf("Добавлено: %dx^%d\n", p->koeff, p->power);
    return 1;
}

void enterListElems(list* phead) // ввод элементов списка
{
    int i_koeff = 1, i_power = 1;
    while (i_power != 0)
    {
        printf("\nВвод\n");
        printf("Kоэффициент: ");
        scanf_s("%d", &i_koeff);
        printf("Cтепень: ");
        scanf_s("%d", &i_power);
        if (i_power == 0)
        {
            addToHead(phead, i_koeff, i_power);
            return;
        }

        addToHead(phead, i_koeff, i_power);
    }
}

void printList(list* phead, char* name) // вывод списка в консоль
{
    list p;
    printf("\n");
    printf("%s(x) = ", name);
    for (p = *phead; p != NULL; p = p->next)
    {
        if (p->next != NULL)
        {
            printf("%dx^%d + ", p->koeff, p->power);
        }
        else
        {
            printf("%dx^%d. ", p->koeff, p->power);
        }
    }
}

void Equality(list* P, list* Q) // проверка на равенство
{
    list p;
    list q;
    int flag = 1;
    int i = 0;
    int j = 0;
    int i1 = 0;
    int j1 = 0;
    printf("\n");
    for (p = *P; p != NULL; p = p->next)
    {
        i1++;
    }
    for (q = *Q; q != NULL; q = q->next)
    {
        j1++;
    }
    if ((i1 == j1) && (i1 > 1))
    {
        for (p = *P; p != NULL; p = p->next)
        {
            j = 0;
            for (q = *Q; q != NULL; q = q->next)
            {
                if (i == j)
                {
                    if (p->koeff != q->koeff)
                    {
                        if (p->power != q->power)
                        {
                            flag = 0;
                            break;
                        }
                    }
                }

                j++;
            }

            i++;
        }
    }
    if (i1 != j1)
    {
        flag = 0;
    }
    if ((i1 == j1) && (i1 == 1))
    {
        for (p = *P; p != NULL; p = p->next)
        {
            j = 0;
            for (q = *Q; q != NULL; q = q->next)
            {
                if (i == j)
                {
                    if (p->koeff != q->koeff)
                    {
                        flag = 0;
                        break;

                    }
                }

                j++;
            }

            i++;
        }
    }

    if (flag == 1)
    {
        printf("Многочлен P равен многочлену Q!");
    }

    if (flag == 0)
    {
        printf("Многочлен P не равен многочлену Q!");
    }
}

void Meaning(list* P, list* Q) // вычисление значение многочлена в точке
{

    printf("\nЗначение какого многочлена хотите вычислить? (1 -- P, 2 -- Q)");
    int ch = 0;
    printf("\n");
    scanf_s("%d", &ch);
    list pq = NULL;
    if (ch == 1)
    {
        pq = *P;
    }
    if (ch == 2)
    {
        pq = *Q;
    }
    printf("Укажите целочисленную точку X:");
    int x = 0;
    scanf_s("%d", &x);
    int sum = 0;
    for (; pq != NULL; pq = pq->next)
    {
        sum += (int)(pq->koeff * pow(x, pq->power));
    }
    printf("\nСумма равна = %d", sum);
}

void Add(list* P, list* Q, list* R) // сумма введенных многочленов
{
    list p = NULL;
    list q = NULL;
    list tmp = NULL;
    list res = NULL;
    int i = 0;
    int mas[256] = { 0 };
    for (p = *P; p != NULL; p = p->next)
    {
        int koeff = p->koeff;
        int power = p->power;
        tmp = malloc(sizeof(*tmp));
        tmp->koeff = koeff;
        tmp->power = power;
        for (q = *Q; q != NULL; q = q->next)
        {
            if (p->power == q->power)
            {
                tmp->koeff = p->koeff + q->koeff;
            }
        }
        mas[i] = tmp->power;
        tmp->next = *R;
        *R = tmp;
        i++;
    }
    int ii = i;
    for (q = *Q; q != NULL; q = q->next)
    {
        int flag = 0;
        for (int i1 = 0; i1 < i; i1++)
        {
            if (mas[i1] == q->power)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            int koeff = q->koeff;
            int power = q->power;
            tmp = malloc(sizeof(*tmp));
            tmp->koeff = koeff;
            tmp->power = power;
            tmp->next = *R;
            *R = tmp;
            ii++;
        }

    }
    printf("\nСумма многочленов P + Q равна:");
    printf("\nR(x) = ");
    res = *R;
    for (int j = 0; j < ii; j++)
    {
        printf("%dx^%d + ", res->koeff, res->power);
        res = res->next;
    }
    printf("0.");
    return 0;
}