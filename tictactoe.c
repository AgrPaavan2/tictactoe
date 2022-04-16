#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global Variables
char player1Symbol, player2Symbol;
char a[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char player1[50], player2[50];

// Function Prototyping
void board();
void rules();
int checkforwin();
int decision();
void printresult(int* score, int* player);

// Main Function
int main() {
    int player = 1;
    int choice, score = -1;
    char symbol, again;

    rules();

read:
    printf("\nEnter name of player 1: ");
    scanf("%s", player1);
    printf("Enter name of player 2: ");
    scanf("%s", player2);
    if (!strcmp(player1, player2)) {
        printf("\nEnter different names");
        goto read;
    } else {
        decision();
    }

    board();

    do {
        player = (player % 2) ? 1 : 2;

        if (player == 1)
            printf("%s type any digit from 1-9 to fill your response:- ", player1);
        else
            printf("%s type any digit from 1-9 to fill your response:- ", player2);

        scanf("%d", &choice);

        symbol = (player == 1) ? player1Symbol : player2Symbol;

        if (choice == 1 && a[0] == '1')
            a[0] = symbol;
        else if (choice == 2 && a[1] == '2')
            a[1] = symbol;
        else if (choice == 3 && a[2] == '3')
            a[2] = symbol;
        else if (choice == 4 && a[3] == '4')
            a[3] = symbol;
        else if (choice == 5 && a[4] == '5')
            a[4] = symbol;
        else if (choice == 6 && a[5] == '6')
            a[5] = symbol;
        else if (choice == 7 && a[6] == '7')
            a[6] = symbol;
        else if (choice == 8 && a[7] == '8')
            a[7] = symbol;
        else if (choice == 9 && a[8] == '9')
            a[8] = symbol;
        else {
            printf("Wrong Selection\n");
            player--;
        }

        score = checkforwin();
        player++;
        board();
    } while (score == -1);

    printresult(&score, &player);
}

void rules() {
    char link;
    printf("\tTic-Tac-Toe\n\n");
    printf("Welcome to the most played 2D game and a sort of fun using X and O\n\n");
    printf("Rules:-");
    printf("\n1:Each player will be entering the number to put respective X or O in the desired position");
    printf("\n2:Player who gets a combination of 3 same characters either diagonal or horizontally or \n  vertically will be declared as the winner");
    printf("\n\nEnjoy the game! Be a Winner!\n\n");
    printf("For more clarifications press Y else type any other character:- ");
    scanf("%c", &link);
    if (link == 'y' || link == 'Y') {
        system("start http://www.wikihow.com/Play-Tic-Tac-Toe");
    }
}

void board() {
    int i;
    system("cls");

    printf("\tTic-Tac-Toe\n\n");
    printf("%s:- (%c)\n%s:- (%c)\n\n\n", player1, player1Symbol, player2, player2Symbol);

    printf("       |       |    \n");
    printf("   %c   |   %c   |   %c\n", a[0], a[1], a[2]);
    printf("       |       |    \n");
    printf("-------|-------|-------\n");
    printf("       |       |    \n");
    printf("   %c   |   %c   |   %c\n", a[3], a[4], a[5]);
    printf("       |       |    \n");
    printf("-------|-------|-------\n");
    printf("       |       |    \n");
    printf("   %c   |   %c   |   %c\n", a[6], a[7], a[8]);
    printf("       |       |    \n");
}

int decision() {
    char dec;
deci:
    printf("\n\nPlayer 1 %s choose X or O: ", player1);
    dec = getchar();
    scanf("%c", &dec);

    if (dec == 'X' || dec == 'x') {
        player1Symbol = 'X';
        player2Symbol = 'O';
    } else if (dec == 'O' || dec == 'o') {
        player1Symbol = 'O';
        player2Symbol = 'X';
    } else {
        printf("Please enter either X or O");
        goto deci;
    }
}

int checkforwin() {
    if (a[0] == a[1] && a[1] == a[2])
        return 1;
    else if (a[3] == a[4] && a[4] == a[5])
        return 1;
    else if (a[6] == a[7] && a[7] == a[8])
        return 1;
    else if (a[0] == a[3] && a[3] == a[6])
        return 1;
    else if (a[1] == a[4] && a[4] == a[7])
        return 1;
    else if (a[2] == a[5] && a[5] == a[8])
        return 1;
    else if (a[0] == a[4] && a[4] == a[8])
        return 1;
    else if (a[2] == a[4] && a[4] == a[6])
        return 1;
    else if (a[0] != '1' && a[1] != '2' && a[2] != '3' && a[3] != '4' && a[4] != '5' && a[5] != '6' && a[6] != '7' && a[7] != '8' && a[8] != '9')
        return 0;
    else
        return -1;
}

void printresult(int* score, int* player) {
    if (*score == 1) {
        if (*player == 2)
            printf("\n\nPlayer1 %s Wins!\n\n", player1);
        else
            printf("\n\nPlayer2 %s Wins!\n\n", player2);
    } else
        printf("\n\nGame Draws!\n\n");
}
