// TICTACTOE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>  
#include <conio.h>
using namespace std;
int Graph(int map[40][40], int z);
int Log(int map[40][40]);
int main()
{// 0 bosluk, 1 |, 2 =, 3 O, 4 X,5 *(cursor)
    int GAME;
    char Y;
    for(GAME=0;GAME==0;)// restart 
    {
        Y = 'n';
        int i, j, map[40][40], game, cursorx = 9, cursory = 3, ymem , xmem , z = 1, locyX[10];
        int locxX[10], locyO[10], locxO[10], o = 0, x = 0, b = 40,l=0;
        unsigned char yon;
        // j line, i column

        for (i = 0; i < 5; i++)// loc degerlerine goruntunun disinda olacak sekilde deger ataniyor
        {
            locyX[i] = b--;
            locxX[i] = b--;
        }
        for (i = 0; i < 5; i++)
        {
            locyO[i] = b--;
            locxO[i] = b--;
        }

        cout << "TICTACTOE\n";// giris ekrani
        cout << "Use arrow keys to move the cursor\n";
        cout << "Press space key to place symbols\n";
        cout << "Press \"G\" to start";// g tusu yalan kullaniciyi space veya ok tuslarina basmaktan alikoymak icin
        for (GAME = 0; GAME == 0;)
        {
            Y = _getch();
            if (Y == 'G' || Y == 'g')
            {
                system("cls");
                break;
            }
        }
        for (game = 1; game < 10;)// goruntunun tekrar gelmesini saglayan for komutu
        {
            if (l == 0)
            {


                for (j = 0; j < 8; j++)// map arrayinin tictactoe zemini olusturacak sekilde kodlanmasi
                {
                    for (i = 0; i < 19; i++)
                    {
                        if (i == 5 && j != 5 && j != 2)
                        {
                            map[j][i] = 1;

                        }
                        else if (i == 6 && j != 2 && j != 5)
                        {
                            map[j][i] = 1;

                        }
                        else if (i == 12 && j != 2 && j != 5)
                        {
                            map[j][i] = 1;

                        }

                        else if (i == 13 && j != 2 && j != 5)
                        {
                            map[j][i] = 1;

                        }

                        else if (j == 2 || j == 5)
                        {
                            map[j][i] = 2;

                        }
                        else
                        {
                            map[j][i] = 0;
                        }

                    }

                }
            }
            if (l == 0)
            {
                map[cursory][cursorx] = 5;
                Graph(map, z);
                l++;
            }
            for (j = 0; j < 8; j++)// map arrayinin tictactoe zemini olusturacak sekilde kodlanmasi
            {
                for (i = 0; i < 19; i++)
                {
                    if (i == 5 && j != 5 && j != 2)
                    {
                        map[j][i] = 1;

                    }
                    else if (i == 6 && j != 2 && j != 5)
                    {
                        map[j][i] = 1;

                    }
                    else if (i == 12 && j != 2 && j != 5)
                    {
                        map[j][i] = 1;

                    }

                    else if (i == 13 && j != 2 && j != 5)
                    {
                        map[j][i] = 1;

                    }

                    else if (j == 2 || j == 5)
                    {
                        map[j][i] = 2;

                    }
                    else
                    {
                        map[j][i] = 0;
                    }

                }

            }
            yon = _getch();//imleci hareket ettiren tuslarin girdisinin alinmasi neyahutda isareti koymak icin space e basilirsa algilamak icin
            system("cls");
            if (yon == 0 || yon == 0xE0)// ok tuslarina basilirsa olucaklar
            {
                ymem = cursory;
                xmem = cursorx;
                yon = _getch();
                switch (yon)
                {
                case 72:
                    cursory -= 3;//down
                    break;
                case 80:

                    cursory += 3;//up
                    break;
                case 75:
                    cursorx -= 7;//left
                    break;
                case 77:
                    cursorx += 7;//right
                    break;

                }
            }
            else if (yon == ' ')// space tusuna basilirsa olucaklar
            {
                z++;// x ve o arasinda gecisi sagliyor

                if (z % 2 == 0)
                {
                    map[cursory + 1][cursorx] = 4;
                    locyX[x] = cursory + 1;
                    locxX[x] = cursorx;
                    if (x != 0)
                    {
                        for (i = 0; i < 5; i++)
                        {
                            if ((locyX[x] == locyX[x - 1] && locxX[o] == locxX[x - 1]) || (locxX[x] == locxO[i] && locyX[x] == locyO[i]))
                            {
                                x--;
                                game--;
                                z--;
                            }
                        }
                    }
                    x++;
                    game++;
                }
                else
                {
                    map[cursory + 1][cursorx] = 3;
                    locyO[o] = cursory + 1;
                    locxO[o] = cursorx;
                    if (o != 0)
                    {
                        for (i = 0; i < 5; i++)
                        {
                            if ((locyO[o] == locyO[o - 1] && locxO[o] == locxO[o - 1]) || (locxO[o] == locxX[i] && locyO[o] == locyX[i]))
                            {
                                o--;
                                game--;
                                z--;
                            }
                        }
                    }
                    o++;
                    game++;
                }
            }
            if (cursory > 6 || cursory < 0)
            {
                cursory = ymem;
            }
            if (cursorx > 16 || cursorx < 2)
            {
                cursorx = xmem;
            }
            map[cursory][cursorx] = 5;
            for (i = 0; i < 5; i++)
            {
                map[locyX[i]][locxX[i]] = 4;
            }
            for (i = 0; i < 4; i++)
            {
                map[locyO[i]][locxO[i]] = 3;
            }


            Graph(map, z);
            GAME = Log(map);
            if (GAME == 2)
            {
                game = 11;
            }
        }
        if (game == 10)
        {
            GAME == 2;
            system("cls");
            cout << "Game Over:DRAW";

        }
        Sleep(2500);
        system("cls");
        cout << "Press \"Y\" and enter to restart";
        cin >> Y;
        if (Y == 'y' || Y == 'Y')
        {
            system("cls");
            GAME = 0;
        }
    }
return 0 ;
}
int Graph(int map[40][40], int z)
{
    int j, i ;
    for (j = 0; j < 8; j++)
    {
        for (i = 0; i < 19; i++)
        {
            
                    if (map[j][i] == 0)
                    {
                        cout << " ";
                    }
                    else if (map[j][i] == 1)
                    {
                        cout << "|";
                 
                    }
                    else if (map[j][i] == 2)
                    {
                        cout << "=";
                      
                    }
                    else if (map[j][i] == 3)
                    {
                        cout << "O";
                    }
                    else if (map[j][i] == 4)
                    {
                        cout << "X";
                    }
                    else if (map[j][i] == 5)
                    {
                        cout << "*";
                    }
 
        }
        cout << endl;
    }
    if (z % 2 == 0)// tur hangi oyuncudaysa yaziyor
    {
        cout << "Player O's turn";
    }
    else
    {
        cout << "Player X's turn";
    }
    return 0;
}
int Log(int map[40][40] )
{int j, i;
    for(j=1;j<8;j+=3)
        {   if((map[j][2] == map[j][9] && map[j][2] == map[j][16])  &&(map[j][2] == 3 || map[j][2] == 4))
            {   if(map[j][2]==3)
                 {
                    system("cls");
                    cout << "Game over: O wins";
                    return 2;
                }
                if (map[j][2] == 4)
                {
                    system("cls");
                    cout << "Game over: X wins";
                    return 2;
                }
            
            }


        }
    for (i = 2; i < 17; i += 7)
    {
        if ((map[1][i] == map[4][i] && map[1][i] == map[7][i]) && (map[1][i] == 3 || map[1][i] == 4))
        {
            if (map[1][i] == 3)
            {
                system("cls");
                cout << "Game over: O wins";
                return 2;
            }
            if (map[1][i] == 4)
            {
                system("cls");
                cout << "Game over: X wins";
                return 2;
            }

        }

    }
    if ((map[1][2] == map[4][9] && map[1][2] == map[7][16]) && (map[1][2] == 3 || map[1][2] == 4))
    {
        if (map[1][2] == 3)
        {
            system("cls");
            cout << "Game over: O wins";
                return 2;
        }
        if (map[1][2] == 4)
        {
            system("cls");
            cout << "Game over: X wins";
                return 2;
        }
    }
    if ((map[1][16] == map[4][9] && map[1][16] == map[7][2]) && (map[1][16] == 3 || map[1][16] == 4))
    {
        if (map[1][16] == 3)
        {
            system("cls");
            cout << "Game over: O wins";
                return 2;
        }
        if (map[1][16] == 4)
        {
            system("cls");
            cout << "Game over: X wins";
                return 2;
        }
    }
    return 0;
}

