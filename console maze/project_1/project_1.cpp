#include <iostream> // основная библиотека
#include <windows.h> // работа с консолью
#include <conio.h> // изменение цвета консоли
#include <time.h> // случайные числа

using namespace std;
int positions[600][2] = { 0 };

void Win()
{
    system("cls");
    system("color 2F");
    cout << "You won!" << endl << "Press any key to exit!";
}

bool check(int array[600][2], int x, int y)
{
    bool flag = true;
    for (int i = 0; i < 600; i++)
    {
        if ((array[i][0] == x) && (array[i][1] == y))
        {
            flag = false;
            break;
        }
    }
    return flag;
}

int main()
{
    SetConsoleTitle(L"Console Maze");
    int r;
    int character[10] = { 2,3,4,5,6,11,14,15,2,2 };
    srand(time(NULL));
    int c = rand() % 10;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 9);
    cout << "Welcome in Console Maze!" << endl << "Game modes:" << endl;
    SetConsoleTextAttribute(hConsole, 2);
    cout <<"1 - Easy" << endl;
    SetConsoleTextAttribute(hConsole, 6);
    cout << "2 - Normal" << endl;
    SetConsoleTextAttribute(hConsole, 4);
    cout << "3 - Hard" << endl;
    SetConsoleTextAttribute(hConsole, 5);
    cout << "4 - Endless" << endl;
    SetConsoleTextAttribute(hConsole, 9);
    cin >> r;
    system("cls");
    if (r == 2)
    {
        int my_hod[62] = { 2,2,2,3,3,3,3,3,2,2,3,3,0,0,0,0,3,3,2,3,3,3,2,2,2,2,2,2,1,1,1,2,2,3,3,3,2,2,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2 };
        int h = 0;
        SetConsoleTextAttribute(hConsole, 6);
        // 1 - стенки лабиринта
        // 0 - путь
        int mas[24][20] = { {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
                            {1,0,1,0,0,1,0,1,0,0,0,1,1,1,1,0,0,0,0,1,},
                            {1,0,1,1,0,1,0,1,0,1,0,0,0,0,1,0,1,1,0,1,},
                            {1,0,0,0,0,0,0,1,0,1,1,1,1,0,1,0,0,1,0,1,},
                            {1,1,1,1,1,1,0,1,0,1,0,0,1,0,1,1,0,1,0,1,},
                            {1,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,1,},
                            {1,0,1,1,0,1,1,1,1,1,0,0,1,0,1,1,1,1,0,1,},
                            {1,0,0,0,0,0,0,0,0,1,1,1,1,0,1,0,0,0,0,1,},
                            {1,1,1,1,1,1,0,1,1,1,0,0,0,0,1,0,1,1,1,1,},
                            {1,1,0,0,0,1,0,0,1,1,0,1,1,1,1,0,0,0,0,1,},
                            {1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,1,1,1,0,1,},
                            {1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1,},
                            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,},
                            {1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,},
                            {1,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,1,0,1,},
                            {1,0,1,1,0,1,1,0,1,0,1,1,1,0,1,0,0,0,0,1,},
                            {1,0,1,0,0,0,1,0,1,0,0,0,1,1,1,1,1,1,1,1,},
                            {1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,1,},
                            {1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,},
                            {1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,},
                            {1,0,1,0,1,0,0,0,1,0,1,1,1,1,1,1,0,1,0,1,},
                            {1,0,1,0,1,1,1,1,1,0,0,0,1,0,1,0,0,1,0,1,},
                            {1,0,1,0,0,0,0,0,1,1,1,0,0,0,1,0,1,1,0,1,},
                            {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,} };
        int q = 0;
        int s1 = 0;
        int s2 = 1;
        mas[s1][s2] = 2;
        for (int i = 0; i < 24; i++) //переключение по строкам
        {
            for (int j = 0; j < 20; j++)// переключение по столбцам
            {
                if (mas[i][j] == 1)
                {
                    // вывести два раза символ (номер которого 176 в таблице аски) в консоль
                    cout << static_cast<char>(176);
                    cout << static_cast<char>(176);
                    positions[q][0] = j * 2;
                    positions[q][1] = i * 1;
                    q++;
                }

                if (mas[i][j] == 0)
                {
                    cout << "  ";
                }

                if (mas[i][j] == 2)
                {
                    SetConsoleTextAttribute(hConsole, 4);
                    cout << static_cast<char>(character[c]);
                    cout << static_cast<char>(character[c]);
                    SetConsoleTextAttribute(hConsole, 6);
                }
                   
            }
            cout << endl;
        }
        bool flag = false;
        short x = 2;
        short y = 0;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
        int hero = character[c];
        SetConsoleTextAttribute(hConsole, 4);
        //прячем курсор
        HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO info;
        info.dwSize = 100;
        info.bVisible = FALSE;
        SetConsoleCursorInfo(consoleHandle, &info);
        if (my_hod[h] == 0)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 50,12 });
            cout << "                  ";
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 50,12 });
            cout << char(24) << char(24) << char(24) << " GO UP! " << char(24) << char(24) << char(24);
        }

        if (my_hod[h] == 1)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 50,12 });
            cout << "                  ";
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 50,12 });
            cout << char(17) << char(17) << char(17) << " GO LEFT! " << char(17) << char(17) << char(17);
        }

        if (my_hod[h] == 2)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 50,12 });
            cout << "                  ";
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 50,12 });
            cout << char(25) << char(25) << char(25) << " GO DOWN! " << char(25) << char(25) << char(25);
        }

        if (my_hod[h] == 3)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 50,12 });
            cout << "                  ";
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 50,12 });
            cout << char(26) << char(26) << char(26) << " GO RIGHT! " << char(26) << char(26) << char(26);
        }
        while (!flag)
        {
            char c = _getch();
            if ((c == 'w') && (check(positions, x, y-1)) && (y != 0)) {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << "  ";
                y -= 1;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << static_cast<char>(hero);
                cout << static_cast<char>(hero);
                h++;
            }

            if ((c == 'a') && (check(positions, x - 2, y))) {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << "  ";
                x -= 2;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << static_cast<char>(hero);
                cout << static_cast<char>(hero);
                h++;
            }

            if ((c == 's') && (check(positions, x, y+1))) {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << "  ";
                y += 1;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << static_cast<char>(hero);
                cout << static_cast<char>(hero);
                h++;
            }

            if ((c == 'd') && (check(positions,x+2,y))) {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << "  ";
                x += 2;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << static_cast<char>(hero);
                cout << static_cast<char>(hero);
                h++;
            }

            if (x == 2 && y == 24)
            {
                Win();
                break;
            }

            if (my_hod[h] == 0)
            {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 50,12 });
                cout << "                  ";
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 50,12 });
                cout << char(24) << char(24) << char(24) << " GO UP! " << char(24) << char(24) << char(24);
            }

            if (my_hod[h] == 1)
            {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 50,12 });
                cout << "                  ";
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 50,12 });
                cout << char(17) << char(17) << char(17) << " GO LEFT! " << char(17) << char(17) << char(17);
            }

            if (my_hod[h] == 2)
            {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 50,12 });
                cout << "                  ";
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 50,12 });
                cout << char(25) << char(25) << char(25) << " GO DOWN! " << char(25) << char(25) << char(25);
            }

            if (my_hod[h] == 3)
            {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 50,12 });
                cout << "                  ";
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 50,12 });
                cout << char(26) << char(26) << char(26) << " GO RIGHT! " << char(26) << char(26) << char(26);
            }
        }
    }
    if (r == 1)
    {
       int my_hod[15] = { 2,3,3,2,2,2,3,2,2,1,1,1,2,2,2 };
       int h = 0;
        SetConsoleTextAttribute(hConsole, 2);
        int mas[9][10] = { {1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
                           {1, 0, 0, 0, 1, 1, 0, 0, 0, 1 },
                           {1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
                           {1, 0, 0, 0, 1, 0, 0, 0, 0, 1 },
                           {1, 1, 1, 0, 0, 0, 1, 0, 1, 1 },
                           {1, 0, 1, 1, 0, 1, 0, 0, 0, 1 },
                           {1, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
                           {1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
                           {1, 0, 1, 1, 1, 1, 1, 1, 1, 1 } };
        int q = 0;
        int s1 = 0;
        int s2 = 1;
        mas[s1][s2] = 2;
        for (int i = 0; i < 9; i++) //переключение по строкам
        {
            for (int j = 0; j < 10; j++)// переключение по столбцам
            {
                if (mas[i][j] == 1)
                {
                    // вывести два раза символ (номер которого 176 в таблице аски) в консоль
                    cout << static_cast<char>(176);
                    cout << static_cast<char>(176);
                    positions[q][0] = j * 2;
                    positions[q][1] = i * 1;
                    q++;
                }

                if (mas[i][j] == 0)
                {
                    cout << "  ";
                }

                if (mas[i][j] == 2)
                {
                    SetConsoleTextAttribute(hConsole, 4);
                    cout << static_cast<char>(character[c]);
                    cout << static_cast<char>(character[c]);
                    SetConsoleTextAttribute(hConsole, 2);
                }

            }
            cout << endl;
        }
        bool flag = false;
        short x = 2;
        short y = 0;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
        int hero = character[c];
        SetConsoleTextAttribute(hConsole, 4);
        //прячем курсор
        HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO info;
        info.dwSize = 100;
        info.bVisible = FALSE;
        SetConsoleCursorInfo(consoleHandle, &info);
        if (my_hod[h] == 0)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 30,4 });
            cout << "                  ";
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 30,4 });
            cout << char(24) << char(24) << char(24) << " GO UP! " << char(24) << char(24) << char(24);
        }

        if (my_hod[h] == 1)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 30,4 });
            cout << "                  ";
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 30,4 });
            cout << char(17) << char(17) << char(17) << " GO LEFT! " << char(17) << char(17) << char(17);
        }

        if (my_hod[h] == 2)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 30,4 });
            cout << "                  ";
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 30,4 });
            cout << char(25) << char(25) << char(25) << " GO DOWN! " << char(25) << char(25) << char(25);
        }

        if (my_hod[h] == 3)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 30,4 });
            cout << "                  ";
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 30,4 });
            cout << char(26) << char(26) << char(26) << " GO RIGHT! " << char(26) << char(26) << char(26);
        }
        while (!flag)
        {
            char c = _getch();
            if ((c == 'w') && (check(positions, x, y - 1)) && (y != 0)) {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << "  ";
                y -= 1;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << static_cast<char>(hero);
                cout << static_cast<char>(hero);
                h++;
            }

            if ((c == 'a') && (check(positions, x - 2, y))) {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << "  ";
                x -= 2;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << static_cast<char>(hero);
                cout << static_cast<char>(hero);
                h++;
            }

            if ((c == 's') && (check(positions, x, y + 1))) {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << "  ";
                y += 1;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << static_cast<char>(hero);
                cout << static_cast<char>(hero);
                h++;
            }

            if ((c == 'd') && (check(positions, x + 2, y))) {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << "  ";
                x += 2;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << static_cast<char>(hero);
                cout << static_cast<char>(hero);
                h++;
            }

            if (x == 2 && y == 9)
            {
                Win();
                break;
            }

            if (my_hod[h] == 0)
            {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 30,4 });
                cout << "                  ";
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 30,4 });
                cout << char(24) << char(24) << char(24) << " GO UP! " << char(24) << char(24) << char(24);
            }

            if (my_hod[h] == 1)
            {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 30,4 });
                cout << "                  ";
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 30,4 });
                cout << char(17) << char(17) << char(17) << " GO LEFT! " << char(17) << char(17) << char(17);
            }

            if (my_hod[h] == 2)
            {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 30,4 });
                cout << "                  ";
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 30,4 });
                cout << char(25) << char(25) << char(25) << " GO DOWN! " << char(25) << char(25) << char(25);
            }

            if (my_hod[h] == 3)
            {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 30,4 });
                cout << "                  ";
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 30,4 });
                cout << char(26) << char(26) << char(26) << " GO RIGHT! " << char(26) << char(26) << char(26);
            }
        }
    }
    if (r == 3)
    {
        int my_hod[89] = { 2,2,2,3,3,3,3,3,2,2,3,3,0,0,0,0,3,3,2,3,3,3,2,2,2,3,3,3,0,0,1,0,0,3,3,3,2,3,3,3,3,3,3,3,3,2,2,1,1,2,2,3,3,2,2,2,2,2,1,1,2,2,2,2,1,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,2,2};
        int h = 0;
        SetConsoleTextAttribute(hConsole, 4);
        int mas[24][48] = { {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
                            {1,0,1,0,0,1,0,1,0,0,0,1,1,1,1,0,0,0,0,1,0,0,1,1,0,1,0,1,0,1,0,0,0,0,1,0,1,1,0,1,},
                            {1,0,1,1,0,1,0,1,0,1,0,0,0,0,1,0,1,1,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,0,1,0,0,1,0,1,},
                            {1,0,0,0,0,0,0,1,0,1,1,1,1,0,1,0,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,0,1,0,1,1,0,1,0,1,},
                            {1,1,1,1,1,1,0,1,0,1,0,0,1,0,1,1,0,1,0,1,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,1,},
                            {1,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,1,0,0,1,1,0,1,1,1,1,1,0,0,1,0,1,1,1,1,0,1,},
                            {1,0,1,1,0,1,1,1,1,1,0,0,1,0,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,0,0,0,0,1,},
                            {1,0,0,0,0,0,0,0,0,1,1,1,1,0,1,0,0,0,0,1,0,1,1,1,1,1,0,1,1,1,0,0,0,0,1,0,1,1,1,1,},
                            {1,1,1,1,1,1,0,1,1,1,0,0,0,0,1,0,1,1,1,1,0,1,0,1,0,1,0,0,1,1,0,1,1,1,1,0,0,0,0,1,},
                            {1,1,0,0,0,1,0,0,1,1,0,1,1,1,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,1,1,1,0,1,},
                            {1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,0,0,0,0,1,},
                            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,},
                            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,0,0,1,1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,},
                            {1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,0,1,},
                            {1,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,1,0,1,0,0,1,1,0,1,1,0,1,0,1,1,1,0,1,0,0,0,0,1,},
                            {1,0,1,1,0,1,1,0,1,0,1,1,1,0,1,0,0,0,0,1,0,0,1,0,0,0,1,0,1,0,0,0,1,1,1,1,1,1,1,1,},
                            {1,0,1,0,0,0,1,0,1,0,0,0,1,1,1,1,1,1,1,1,0,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,1,},
                            {1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,},
                            {1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,},
                            {1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,1,0,1,1,1,1,1,1,0,1,0,1,},
                            {1,0,1,0,1,0,0,0,1,0,1,1,1,1,1,0,0,1,0,1,0,0,1,0,1,1,1,1,1,0,0,0,1,0,1,0,0,1,0,1,},
                            {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,0,0,0,1,0,1,1,0,1,},
                            {1,0,1,0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
                            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,} };
        int q = 0;
        int s1 = 0;
        int s2 = 1;
        mas[s1][s2] = 2;
        for (int i = 0; i < 24; i++) //переключение по строкам
        {
            for (int j = 0; j < 48; j++)// переключение по столбцам
            {
                if (mas[i][j] == 1)
                {
                    // вывести два раза символ (номер которого 176 в таблице аски) в консоль
                    cout << static_cast<char>(176);
                    cout << static_cast<char>(176);
                    positions[q][0] = j * 2;
                    positions[q][1] = i * 1;
                    q++;
                }

                if (mas[i][j] == 0)
                {
                    cout << "  ";
                }

                if (mas[i][j] == 2)
                {
                    SetConsoleTextAttribute(hConsole, 4);
                    cout << static_cast<char>(character[c]);
                    cout << static_cast<char>(character[c]);
                    SetConsoleTextAttribute(hConsole, 4);
                }
            }
            cout << endl;
        }
        bool flag = false;
        short x = 2;
        short y = 0;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
        int hero = character[c];
        SetConsoleTextAttribute(hConsole, 4);
        //прячем курсор
        HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO info;
        info.dwSize = 100;
        info.bVisible = FALSE;
        SetConsoleCursorInfo(consoleHandle, &info);
        if (my_hod[h] == 0)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 82,12 });
            cout << "                  ";
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 82,12 });
            cout << char(24) << char(24) << char(24) << " GO UP! " << char(24) << char(24) << char(24);
        }

        if (my_hod[h] == 1)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 82,12 });
            cout << "                  ";
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 82,12 });
            cout << char(17) << char(17) << char(17) << " GO LEFT! " << char(17) << char(17) << char(17);
        }

        if (my_hod[h] == 2)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 82,12 });
            cout << "                  ";
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 82,12 });
            cout << char(25) << char(25) << char(25) << " GO DOWN! " << char(25) << char(25) << char(25);
        }

        if (my_hod[h] == 3)
        {
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 82,12 });
            cout << "                  ";
            SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 82,12 });
            cout << char(26) << char(26) << char(26) << " GO RIGHT! " << char(26) << char(26) << char(26);
        }
        while (!flag)
        {
            char c = _getch();
            if ((c == 'w') && (check(positions, x, y - 1)) && (y != 0)) {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << "  ";
                y -= 1;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << static_cast<char>(hero);
                cout << static_cast<char>(hero);
                h++;
            }

            if ((c == 'a') && (check(positions, x - 2, y))) {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << "  ";
                x -= 2;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << static_cast<char>(hero);
                cout << static_cast<char>(hero);
                h++;
            }

            if ((c == 's') && (check(positions, x, y + 1))) {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << "  ";
                y += 1;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << static_cast<char>(hero);
                cout << static_cast<char>(hero);
                h++;
            }

            if ((c == 'd') && (check(positions, x + 2, y))) {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << "  ";
                x += 2;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << static_cast<char>(hero);
                cout << static_cast<char>(hero);
                h++;
            }

            if (x == 76 && y == 24)
            {
                Win();
                break;
            }

            if (my_hod[h] == 0)
            {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 82,12 });
                cout << "                  ";
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 82,12 });
                cout << char(24) << char(24) << char(24) << " GO UP! " << char(24) << char(24) << char(24);
            }

            if (my_hod[h] == 1)
            {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 82,12 });
                cout << "                  ";
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 82,12 });
                cout << char(17) << char(17) << char(17) << " GO LEFT! " << char(17) << char(17) << char(17);
            }

            if (my_hod[h] == 2)
            {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 82,12 });
                cout << "                  ";
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 82,12 });
                cout << char(25) << char(25) << char(25) << " GO DOWN! " << char(25) << char(25) << char(25);
            }

            if (my_hod[h] == 3)
            {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 82,12 });
                cout << "                  ";
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { 82,12 });
                cout << char(26) << char(26) << char(26) << " GO RIGHT! " << char(26) << char(26) << char(26);
            }
        }
    }
    if (r == 4)
    {
        SetConsoleTextAttribute(hConsole, 5);
        int mas[24][48] = { {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,},
                            {1,0,1,0,0,1,0,1,0,0,0,1,1,1,1,0,0,0,0,1,0,0,1,1,0,1,0,1,0,1,0,0,0,0,1,0,1,1,0,1,},
                            {1,0,1,1,0,1,0,1,0,1,0,0,0,0,1,0,1,1,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,0,1,0,0,1,0,1,},
                            {1,0,0,0,0,0,0,1,0,1,1,1,1,0,1,0,0,1,0,1,0,1,1,1,1,1,0,1,0,1,0,0,1,0,1,1,0,1,0,1,},
                            {1,1,1,1,1,1,0,1,0,1,0,0,1,0,1,1,0,1,0,1,0,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,1,},
                            {1,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,1,0,0,1,1,0,1,1,1,1,1,0,0,1,0,1,1,1,1,0,1,},
                            {1,0,1,1,0,1,1,1,1,1,0,0,1,0,1,1,1,1,0,1,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,0,0,0,0,1,},
                            {1,0,0,0,0,0,0,0,0,1,1,1,1,0,1,0,0,0,0,1,0,1,1,1,1,1,0,1,1,1,0,0,0,0,1,0,1,1,1,1,},
                            {1,1,1,1,1,1,0,1,1,1,0,0,0,0,1,0,1,1,1,1,0,1,0,1,0,1,0,0,1,1,0,1,1,1,1,0,0,0,0,1,},
                            {1,1,0,0,0,1,0,0,1,1,0,1,1,1,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,1,1,1,1,0,1,},
                            {1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,1,1,1,0,1,1,1,1,1,1,1,0,1,1,1,1,1,1,0,1,0,0,0,0,1,},
                            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,},
                            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1,0,0,1,1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1,},
                            {1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,1,1,0,1,},
                            {1,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,1,0,1,0,0,1,1,0,1,1,0,1,0,1,1,1,0,1,0,0,0,0,1,},
                            {1,0,1,1,0,1,1,0,1,0,1,1,1,0,1,0,0,0,0,1,0,0,1,0,0,0,1,0,1,0,0,0,1,1,1,1,1,1,1,1,},
                            {1,0,1,0,0,0,1,0,1,0,0,0,1,1,1,1,1,1,1,1,0,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,1,},
                            {1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,},
                            {1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1,0,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,},
                            {1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,1,0,0,0,1,0,1,1,1,1,1,1,0,1,0,1,},
                            {1,0,1,0,1,0,0,0,1,0,1,1,1,1,1,0,0,1,0,1,0,0,1,0,1,1,1,1,1,0,0,0,1,0,1,0,0,1,0,1,},
                            {1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,1,1,1,0,1,1,1,1,1,1,1,0,0,0,1,0,1,1,0,1,},
                            {1,0,1,0,0,0,0,0,1,1,1,0,0,0,0,0,1,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,},
                            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,} };
        int q = 0;
        int s1 = 0;
        int s2 = 1;
        mas[s1][s2] = 2;
        for (int i = 0; i < 24; i++) //переключение по строкам
        {
            for (int j = 0; j < 48; j++)// переключение по столбцам
            {
                if (mas[i][j] == 1)
                {
                    // вывести два раза символ (номер которого 176 в таблице аски) в консоль
                    cout << static_cast<char>(176);
                    cout << static_cast<char>(176);
                    positions[q][0] = j * 2;
                    positions[q][1] = i * 1;
                    q++;
                }

                if (mas[i][j] == 0)
                {
                    cout << "  ";
                }

                if (mas[i][j] == 2)
                {
                    SetConsoleTextAttribute(hConsole, 4);
                    cout << static_cast<char>(character[c]);
                    cout << static_cast<char>(character[c]);
                    SetConsoleTextAttribute(hConsole, 5);
                }

            }
            cout << endl;
        }
        bool flag = false;
        short x = 2;
        short y = 0;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
        int hero = character[c];
        SetConsoleTextAttribute(hConsole, 4);
        //прячем курсор
        HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_CURSOR_INFO info;
        info.dwSize = 100;
        info.bVisible = FALSE;
        SetConsoleCursorInfo(consoleHandle, &info);
        while (!flag)
        {
            char c = _getch();
            if ((c == 'w') && (check(positions, x, y - 1)) && (y != 0)) {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << "  ";
                y -= 1;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << static_cast<char>(hero);
                cout << static_cast<char>(hero);
            }

            if ((c == 'a') && (check(positions, x - 2, y))) {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << "  ";
                x -= 2;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << static_cast<char>(hero);
                cout << static_cast<char>(hero);
            }

            if ((c == 's') && (check(positions, x, y + 1))) {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << "  ";
                y += 1;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << static_cast<char>(hero);
                cout << static_cast<char>(hero);
            }

            if ((c == 'd') && (check(positions, x + 2, y))) {
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << "  ";
                x += 2;
                SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), { x,y });
                cout << static_cast<char>(hero);
                cout << static_cast<char>(hero);
            }

            if (x == 76 && y == 24)
            {
                Win();
                break;
            }
        }
    }
    return 0;
}