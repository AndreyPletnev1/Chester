#include <iostream>
#include <conio.h>

void Clear()
{
    system("cls");
}

void  Continue()
{
    char ch;
    while ((ch = getchar()) != '\n');
}

void Menu()
{
    char ch;
    printf("\n\n\n                                                 Сундучок\n\n");
    printf("                                      Чтобы начать игру нажмите Enter\n");
    while ((ch = getchar()) != '\n');
}

// Функция вывода колоды карт
void PrintCard(int Card[36][2])
{
    for (int i = 0; i < 36; i++)
    {
        printf("%i %i\n", Card[i][0],Card[i][1]);
    }
}

void PrintCardHand(int HandPlayer[36][2])
{
    for (int i = 0; i < 36; i++)
    {
        if ((HandPlayer[i][0] > 0) && (HandPlayer[i][1] > 0))
            printf("%i %i\n", HandPlayer[i][0], HandPlayer[i][1]);
    }
}

// Функция для генерации карт
void GenerationCard(int Card[36][2])
{
        // Массив мастей и значений карт
        int Suits[4] = { 1, 2, 3, 4 }; // Черви, Пики, Крести, Буби
        int Numbers[9] = { 6, 7, 8, 9, 10, 11, 12, 13, 14 };//11 - валет, 12-Дама, 13- Король, 14 - Туз.
        int k = 0;
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 9; j++)
                {
                    Card[k][0] = Suits[i];
                    Card[k][1] = Numbers[j];
                    k++;
                }
}

void RandCard(int Card[36][2])
{
    for (int i = 0; i < 36; i++)
    {
        int random = rand() % 36;
        int temp0=Card[i][0];
        int temp1=Card[i][1];
        Card[i][0] = Card[random][0];
        Card[i][1] = Card[random][1];
        Card[random][0] = temp0;
        Card[random][1] = temp1;
    }
}

void DellCard(int Card[36][2])
{
   int n = 36;
    for (int i = 1; i < n; i++) 
    {
        // Сохраняем первый элемент 
        Card[i - 1][0] = Card[i][0];
        Card[i - 1][1] = Card[i][1];
        // Записываем сохраненный элемент в конец строки
    }
        Card[n-1][0] = 0;
        Card[n-1][1] = 0;
}

void DistOfCard(int Card[36][2], int HandPlayer[36][2], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 36; j++)
        {
            if ((HandPlayer[j][0] <= 0) && (HandPlayer[j][1] <= 0))
            {
                HandPlayer[j][0] = Card[i][0];
                HandPlayer[j][1] = Card[i][1];
                break;
            }
        }
    }

}




/*
int main()
{
    system("chcp 1251");
    srand(time(NULL));
    int Card[36][2];
    int HandPlayer[4][2];
    int HandBot[4][2];
    Clear();
    Menu();
    Clear();
    GenerationCard(Card);
    PrintCard(Card);
    Continue();
    Clear();
    RandCard(Card);
    PrintCard(Card);
    Continue();
    DistOfCard(Card, HandPlayer, 4);
    PrintCardHand(HandPlayer);
    DellCard(Card);
    DellCard(Card);
    DellCard(Card);
    DellCard(Card);
    Continue();
    DistOfCard(Card, HandBot, 4);
    PrintCardHand(HandBot);
    DellCard(Card);
    DellCard(Card);
    DellCard(Card);
    DellCard(Card);
    Continue();
    PrintCard(Card);
    Continue();
    return 0;
}
*/