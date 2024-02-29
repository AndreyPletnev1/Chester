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
            printf("\n�� ����������� � ���������� ����� - ����� 6");
            break;
        case 7:
            printf("\n�� ����������� � ���������� ����� - ����� 7");
            break;
        case 8:
            printf("\n�� ����������� � ���������� ����� - ����� 8");
            break;
        case 9:
            printf("\n�� ����������� � ���������� ����� - ����� 9");
            break;
        case 10:
            printf("\n�� ����������� � ���������� ����� - ����� 10");
            break;
        case 11:
            printf("\n�� ����������� � ���������� ����� - ����� �����");
            break;
        case 12:
            printf("\n�� ����������� � ���������� ����� - ����� ����");
            break;
        case 13:
            printf("\n�� ����������� � ���������� ����� - ����� ������");
            break;
        case 14:
            printf("\n�� ����������� � ���������� ����� - ����� ���");
            break;
        }
        break;
    case 2:
        switch (turnC)
        {
        case 6:
            printf("\n�� ����������� � ���������� ����� - ���� 6");
            break;
        case 7:
            printf("\n�� ����������� � ���������� ����� - ���� 7");
            break;
        case 8:
            printf("\n�� ����������� � ���������� ����� - ���� 8");
            break;
        case 9:
            printf("\n�� ����������� � ���������� ����� - ���� 9");
            break;
        case 10:
            printf("\n�� ����������� � ���������� ����� - ���� 10");
            break;
        case 11:
            printf("\n�� ����������� � ���������� ����� - ���� �����");
            break;
        case 12:
            printf("\n�� ����������� � ���������� ����� - ���� ����");
            break;
        case 13:
            printf("\n�� ����������� � ���������� ����� - ���� ������");
            break;
        case 14:
            printf("\n�� ����������� � ���������� ����� - ���� ���");
            break;
        }
        break;
    case 3:
        switch (turnC)
        {
        case 6:
            printf("\n�� ����������� � ���������� ����� - ������ 6");
            break;
        case 7:
            printf("\n�� ����������� � ���������� ����� - ������ 7");
            break;
        case 8:
            printf("\n�� ����������� � ���������� ����� - ������ 8");
            break;
        case 9:
            printf("\n�� ����������� � ���������� ����� - ������ 9");
            break;
        case 10:
            printf("\n�� ����������� � ���������� ����� - ������ 10");
            break;
        case 11:
            printf("\n�� ����������� � ���������� ����� - ������ �����");
            break;
        case 12:
            printf("\n�� ����������� � ���������� ����� - ������ ����");
            break;
        case 13:
            printf("\n�� ����������� � ���������� ����� - ������ ������");
            break;
        case 14:
            printf("\n�� ����������� � ���������� ����� - ������ ���");
            break;
        }
        break;
    case 4:
        switch (turnC)
        {
        case 6:
            printf("\n�� ����������� � ���������� ����� - ���� 6");
            break;
        case 7:
            printf("\n�� ����������� � ���������� ����� - ���� 7");
            break;
        case 8:
            printf("\n�� ����������� � ���������� ����� - ���� 8");
            break;
        case 9:
            printf("\n�� ����������� � ���������� ����� - ���� 9");
            break;
        case 10:
            printf("\n�� ����������� � ���������� ����� - ���� 10");
            break;
        case 11:
            printf("\n�� ����������� � ���������� ����� - ���� �����");
            break;
        case 12:
            printf("\n�� ����������� � ���������� ����� - ���� ����");
            break;
        case 13:
            printf("\n�� ����������� � ���������� ����� - ���� ������");
            break;
        case 14:
            printf("\n�� ����������� � ���������� ����� - ���� ���");
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
            return 1; // ����� ���� � ����������
        }
    }
    return 0; // ����� ��� � ����������
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

    printf("\n���������� ������� ���� ��� � ���������� (������� Enter)");

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
        printf("\n���� ����� � ����� �����: \n");
        PrintCardHand(HandPlayer);
        printf("\n");
        PrintCardHand(HandBot);

        int turnM, turnC;

        if (PlayerTurn == 0) {
            printf("\n\n��� ���! �������� ����� (������� �� 1 �� 4 - �����, ����, ������, ����) \n� ����� (�� 6 �� 10 ��� 11 - �����, 12-����, 13- ������, 14 - ���): ");
            do
            {
                scanf_s("%i %i", &turnM, &turnC);
				if (turnM < 1 || turnM > 4 || turnC < 1 || turnC>14);
                printf("�� ����� ������������ ��������!\n");
            } while (turnM < 1 || turnM > 4 || turnC < 1 || turnC>14);

            IdentCard(turnM, turnC);

            int choice[2] = { turnM, turnC };

            bool isCorrectChoice = MyTurn(choice, HandBot);

            if (isCorrectChoice) {
                printf("\n�� ������� ����� � ����������! �� ��������� �� ����.");

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
                printf("\n��������� �� ����� ����� �����. �������� ������.");
                DistOfCard(Card, HandPlayer, 1);
                DellCard(Card);
                PlayerTurn = 1;
            }

        }
        else {
            printf("\n\n����� ��� ���������!");

            int botChoice = rand() % 4;

            if (HandPlayer[botChoice][0] > 0 && HandPlayer[botChoice][1] > 0) 
            {
                printf("\n��������� ���������� � ��� ����� - ");
                IdentCard(HandPlayer[botChoice][0], HandPlayer[botChoice][1]);

                int playerChoice[2] = { HandPlayer[botChoice][0], HandPlayer[botChoice][1] };

                bool isCorrectChoice = MyTurn(playerChoice, HandBot);

                if (isCorrectChoice) {
                    printf("\n ��������� ������ ���� �����! �� �������� �� ����.");

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
                    printf("\n�� �� ������ ����� �����. ��������� ����� ����� �� ������.");
                    DistOfCard(Card, HandBot, 1);
                    DellCard(Card);
                }
            }
            else {
                printf("\n��������� ����� ����� �� ������.");
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