#include <GenCard.h>
#include <iostream>
#include <conio.h>
void IdentCard(int turnM, int turnC)
{
    switch (turnM)
    {
    case 1:
        switch (turnC)
        {
        case 6:
            printf("\nВы спрашиваете у противника карту - Черви 6");
            break;
        case 7:
            printf("\nВы спрашиваете у противника карту - Черви 7");
            break;
        case 8:
            printf("\nВы спрашиваете у противника карту - Черви 8");
            break;
        case 9:
            printf("\nВы спрашиваете у противника карту - Черви 9");
            break;
        case 10:
            printf("\nВы спрашиваете у противника карту - Черви 10");
            break;
        case 11:
            printf("\nВы спрашиваете у противника карту - Черви Валет");
            break;
        case 12:
            printf("\nВы спрашиваете у противника карту - Черви Дама");
            break;
        case 13:
            printf("\nВы спрашиваете у противника карту - Черви Король");
            break;
        case 14:
            printf("\nВы спрашиваете у противника карту - Черви Туз");
            break;
        }
        break;
    case 2:
        switch (turnC)
        {
        case 6:
            printf("\nВы спрашиваете у противника карту - Пики 6");
            break;
        case 7:
            printf("\nВы спрашиваете у противника карту - Пики 7");
            break;
        case 8:
            printf("\nВы спрашиваете у противника карту - Пики 8");
            break;
        case 9:
            printf("\nВы спрашиваете у противника карту - Пики 9");
            break;
        case 10:
            printf("\nВы спрашиваете у противника карту - Пики 10");
            break;
        case 11:
            printf("\nВы спрашиваете у противника карту - Пики Валет");
            break;
        case 12:
            printf("\nВы спрашиваете у противника карту - Пики Дама");
            break;
        case 13:
            printf("\nВы спрашиваете у противника карту - Пики Король");
            break;
        case 14:
            printf("\nВы спрашиваете у противника карту - Пики Туз");
            break;
        }
        break;
    case 3:
        switch (turnC)
        {
        case 6:
            printf("\nВы спрашиваете у противника карту - Крести 6");
            break;
        case 7:
            printf("\nВы спрашиваете у противника карту - Крести 7");
            break;
        case 8:
            printf("\nВы спрашиваете у противника карту - Крести 8");
            break;
        case 9:
            printf("\nВы спрашиваете у противника карту - Крести 9");
            break;
        case 10:
            printf("\nВы спрашиваете у противника карту - Крести 10");
            break;
        case 11:
            printf("\nВы спрашиваете у противника карту - Крести Валет");
            break;
        case 12:
            printf("\nВы спрашиваете у противника карту - Крести Дама");
            break;
        case 13:
            printf("\nВы спрашиваете у противника карту - Крести Король");
            break;
        case 14:
            printf("\nВы спрашиваете у противника карту - Крести Туз");
            break;
        }
        break;
    case 4:
        switch (turnC)
        {
        case 6:
            printf("\nВы спрашиваете у противника карту - Буби 6");
            break;
        case 7:
            printf("\nВы спрашиваете у противника карту - Буби 7");
            break;
        case 8:
            printf("\nВы спрашиваете у противника карту - Буби 8");
            break;
        case 9:
            printf("\nВы спрашиваете у противника карту - Буби 9");
            break;
        case 10:
            printf("\nВы спрашиваете у противника карту - Буби 10");
            break;
        case 11:
            printf("\nВы спрашиваете у противника карту - Буби Валет");
            break;
        case 12:
            printf("\nВы спрашиваете у противника карту - Буби Дама");
            break;
        case 13:
            printf("\nВы спрашиваете у противника карту - Буби Король");
            break;
        case 14:
            printf("\nВы спрашиваете у противника карту - Буби Туз");
            break;
        }
        break;
    }
}
bool RandPlayer()
{
    srand(time(NULL));
	int player = rand() % 2;
    if (player == 1)
		return true;
	else
		return false;
}

int CountCards(int HandPlayer[36][2])
{
    int n = 0;
    for (int i = 0; i < 36; i++)
    {
        if ((HandPlayer[i][0] > 0) && (HandPlayer[i][1] > 0))
            n++;
        else
            break;
    }
    return n;
}
int MyTurn(int choice[2], int HandBot[4][2]) {
    for (int i = 0; i < 36; i++) {
        if ((choice[0] == HandBot[i][0]) && (choice[1] == HandBot[i][1])) {
            HandBot[i][0] = 0;
            HandBot[i][1] = 0;
            return 1; // Карта есть у противника
        }
    }
    return 0; // Карты нет у противника
}



void FillHand(int Card[36][2], int HandBot[36][2])
{
    int MyHandCount = CountCards(HandBot);
    
    while (MyHandCount < 4)
    {

        DistOfCard(Card, HandBot, 1);
        DellCard(Card);
        MyHandCount++;
    }
}

void Game(int Card[36][2], int HandPlayer[4][2], int HandBot[4][2]) {
    bool IsGame = true;

    RandCard(Card);

    printf("\nПроисходит раздача карт вам и противнику (нажмите Enter)");

    Continue();

    Clear();

    DistOfCard(Card, HandPlayer, 4);

    for (int i = 0; i < 4; i++)
        DellCard(Card);

    DistOfCard(Card, HandBot, 4);

    for (int i = 0; i < 4; i++)
        DellCard(Card);

    int PlayerTurn = RandPlayer() ? 0 : 1;

    while (IsGame) {
        printf("\nВаши карты и карты врага: \n");
        PrintCardHand(HandPlayer);
        printf("\n");
        PrintCardHand(HandBot);

        int turnM, turnC;

        if (PlayerTurn == 0) {
            printf("\n\nВаш ход! Выберите масть (введите от 1 до 4 - Черви, Пики, Крести, Буби) \nи карту (от 6 до 10 или 11 - валет, 12-Дама, 13- Король, 14 - Туз): ");
            do
            {
                scanf_s("%i %i", &turnM, &turnC);
				if (turnM < 1 || turnM > 4 || turnC < 1 || turnC>14);
                printf("Вы ввели неккоректное значение!\n");
            } while (turnM < 1 || turnM > 4 || turnC < 1 || turnC>14);

            IdentCard(turnM, turnC);

            int choice[2] = { turnM, turnC };

            bool isCorrectChoice = MyTurn(choice, HandBot);

            if (isCorrectChoice) {
                printf("\nВы угадали карту у противника! Вы забираете ее себе.");

                for (int i = 0; i < 36; i++) {
                    if ((choice[0] == HandBot[i][0]) && (choice[1] == HandBot[i][1])) {
                        HandBot[i][0] = 0;
                        HandBot[i][1] = 0;
                        break;
                    }
                }
                for (int i = 0; i < 36; i++) {
                    if ((HandPlayer[i][0] <= 0) && (HandPlayer[i][1] <= 0)) {
                        HandPlayer[i][0] = choice[0];
                        HandPlayer[i][1] = choice[1];
                        break;
                    }
                }
            }
            else {
                printf("\nПротивник не имеет такой карты. Выберите другую.");
                DistOfCard(Card, HandPlayer, 1);
                DellCard(Card);
                PlayerTurn = 1;
            }

        }
        else {
            printf("\n\nХодит ваш противник!");

            int botChoice = rand() % 4;

            if (HandPlayer[botChoice][0] > 0 && HandPlayer[botChoice][1] > 0) 
            {
                printf("\nПротивник спрашивает у вас карту - ");
                IdentCard(HandPlayer[botChoice][0], HandPlayer[botChoice][1]);

                int playerChoice[2] = { HandPlayer[botChoice][0], HandPlayer[botChoice][1] };

                bool isCorrectChoice = MyTurn(playerChoice, HandBot);

                if (isCorrectChoice) {
                    printf("\n Противник угадал вашу карту! Он забирает ее себе.");

                    HandPlayer[botChoice][0] = 0;
                    HandPlayer[botChoice][1] = 0;

                    for (int i = 0; i < 4; i++) {
                        if ((HandBot[i][0] <= 0) && (HandBot[i][1] <= 0)) {
                            HandBot[i][0] = playerChoice[0];
                            HandBot[i][1] = playerChoice[1];
                            break;
                        }
                    }
                }
                else {
                    printf("\nВы не имеете такой карты. Противник берет карту из колоды.");
                    DistOfCard(Card, HandBot, 1);
                    DellCard(Card);
                }
            }
            else {
                printf("\nПротивник берет карту из колоды.");
                DistOfCard(Card, HandBot, 1);
                DellCard(Card);
            PlayerTurn = 0;
            }

        }
    }
}



int main()
{
    system("chcp 1251");
    srand(time(NULL));
    int Card[36][2];
    int HandPlayer[36][2];
    int HandBot[36][2];
    
    Clear();
    Menu();
    Clear();
    GenerationCard(Card);
    RandCard(Card);
    Game(Card, HandPlayer, HandBot);

    return 0;
}