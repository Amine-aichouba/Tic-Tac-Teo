#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define BOARD_SIZE 9
#define MAX_NAME_LENGTH 50

void print_date(void);
void print_board(const char* a, char x, char o, const char* u1, const char* u2);
int check_for_win(const char* a);
void get_player_symbols(char* x, char* o, const char* u1);
void print_leaderboard(void);
void update_leaderboard(const char* winner, const char* u1, const char* u2);
void clear_screen(void);
void get_player_names(char* u1, char* u2);
void display_menu(void);
void play_game(void);

int main() {
    int menu_choice;

    while (1) {
        clear_screen();
        print_date();
        display_menu();

        printf("\n\t\t\t * Choose an option  : ");
        scanf("%d", &menu_choice);

        switch (menu_choice) {
            case 1:
                play_game();
                break;
            case 2:
                print_leaderboard();
                break;
            default:
                printf("\n\n\t\t\t * Invalid option. Please choose 1 or 2.\n\n");
                break;
        }

        char exit_choice;
        printf("\n\n\n\t\t\t\t\t\t * Back  ---> [1]\n");
        printf("\t\t\t\t\t\t * Exit ----> [2]\n\n");
        printf("\t\t\t\t\t\t * Choose an option  : ");
        scanf(" %c", &exit_choice);
        if (exit_choice == '2') {
            exit(0);
        }
    }

    return 0;
}

void display_menu() {
    printf("\n\n\n");
    printf("\t\t\t\t\t\t\t ---{ T i c - T a c - T o e }--- \n\n\n");
    printf("\t\t\t * Start the game  ---->[1] \n\n");
    printf("\t\t\t * View leaderboard -->[2] \n");
}

void play_game() {
    char board[BOARD_SIZE] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char u1[MAX_NAME_LENGTH], u2[MAX_NAME_LENGTH];
    char x, o;
    int choice, score = -1, player = 1;

    get_player_names(u1, u2);
    get_player_symbols(&x, &o, u1);
    print_board(board, x, o, u1, u2);

    while (score == -1) {
        player = (player % 2) ? 1 : 2;
        printf("\n\n\n\t\t * %s Type any digit from 1-9 to fill your response --> ", (player == 1) ? u1 : u2);
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 9 && board[choice - 1] == (choice + '0')) {
            board[choice - 1] = (player == 1) ? x : o;
        } else {
            printf(" Wrong Selection\n ");
            player--;
        }

        score = check_for_win(board);
        player++;
        print_board(board, x, o, u1, u2);
    }

    if (score == 1) {
        if (player == 2) {
            printf("\n\n\t\t\t * Player_1 %s Wins !!\n\n", u1);
            update_leaderboard(u1, u1, u2);
        } else {
            printf("\n\n\t\t\t * Player_2 %s Wins !!\n\n", u2);
            update_leaderboard(u2, u1, u2);
        }
    } else {
        printf("\n\n\t\t\t * Game Draws !!\n\n");
        update_leaderboard("DRAW", u1, u2);
    }
}

void print_date() {
    time_t now;
    time(&now);
    struct tm* local = localtime(&now);
    printf("\n  --{ %02d / %02d / %d }-- \n ", local->tm_mday, local->tm_mon + 1, local->tm_year + 1900);
}

int check_for_win(const char* a) {
    int win_patterns[8][3] = {
        { 0 , 1 , 2 } , // Top row
        { 3 , 4 , 5 } , // Middle row
        { 6 , 7 , 8 } , // Bottom row
        { 0 , 3 , 6 } , // Left column
        { 1 , 4 , 7 } , // Middle column
        { 2 , 5 , 8 } , // Right column
        { 0 , 4 , 8 } , // Left diagonal
        { 2 , 4 , 6 }  // Right diagonal
    };

    for (int i = 0; i < 8; i++) {
        if (a[win_patterns[i][0]] == a[win_patterns[i][1]] && a[win_patterns[i][1]] == a[win_patterns[i][2]]) {
            return 1; // Win
        }
    }

    // Check for draw
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (a[i] >= '1' && a[i] <= '9') {
            return -1; // Continue the game
        }
    }

    return 0; // Draw
}

void print_board(const char* a, char x, char o, const char* u1, const char* u2) {
    clear_screen();
    print_date();
    printf("\n\n\n");
    printf("\t\t * Player_1 : %s [%c] \n\n ", u1, x);
    printf("\t\t * Player_2 : %s [%c] \n\n\n ", u2, o);
    printf("\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
    printf("\t\t\t\t\t\t\t\t\xB2             \xB2             \xB2             \xB2\n");
    printf("\t\t\t\t\t\t\t\t\xB2             \xB2             \xB2             \xB2\n");
    printf("\t\t\t\t\t\t\t\t\xB2     %c       \xB2     %c       \xB2     %c       \xB2\n", a[0], a[1], a[2]);
    printf("\t\t\t\t\t\t\t\t\xB2             \xB2             \xB2             \xB2\n");
    printf("\t\t\t\t\t\t\t\t\xB2             \xB2             \xB2             \xB2\n");
    printf("\t\t\t\t\t\t\t\t\xB2-------------\xB2-------------\xB2-------------\xB2\n");
    printf("\t\t\t\t\t\t\t\t\xB2             \xB2             \xB2             \xB2\n");
    printf("\t\t\t\t\t\t\t\t\xB2             \xB2             \xB2             \xB2\n");
    printf("\t\t\t\t\t\t\t\t\xB2     %c       \xB2     %c       \xB2     %c       \xB2\n", a[3], a[4], a[5]);
    printf("\t\t\t\t\t\t\t\t\xB2             \xB2             \xB2             \xB2\n");
    printf("\t\t\t\t\t\t\t\t\xB2-------------\xB2-------------\xB2-------------\xB2\n");
    printf("\t\t\t\t\t\t\t\t\xB2             \xB2             \xB2             \xB2\n");
    printf("\t\t\t\t\t\t\t\t\xB2             \xB2             \xB2             \xB2\n");
    printf("\t\t\t\t\t\t\t\t\xB2     %c       \xB2     %c       \xB2     %c       \xB2\n", a[6], a[7], a[8]);
    printf("\t\t\t\t\t\t\t\t\xB2             \xB2             \xB2             \xB2\n");
    printf("\t\t\t\t\t\t\t\t\xB2             \xB2             \xB2             \xB2\n");
    printf("\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n\n");
}

void clear_screen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void get_player_symbols(char* x, char* o, const char* u1) {
    printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   * [Player_1] %s Choose X or O : ", u1);
    getchar();
    scanf("%c", x);
    *o = (*x == 'X' || *x == 'x') ? 'O' : 'X';
}

void get_player_names(char* u1, char* u2) {
    printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   * [Player_1] Name : ");
    scanf("%s", u1);
    printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t   * [Player_2] Name : ");
    scanf("%s", u2);
}

void update_leaderboard(const char* winner, const char* u1, const char* u2) {
    FILE* fp;
    fp = fopen("leaderboard.txt", "a");

    if (fp == NULL) {
        printf("\n\n\t\t\t\t\t\t\t\t * Error Opening File !!\n\n");
        exit(1);
    }

    if (strcmp(winner, "DRAW") == 0) {
        fprintf(fp, "\n\t\t\t\t\t\t\t\t\t\t\t * [DRAW] Game - %s vs %s\n", u1, u2);
    } else {
        fprintf(fp, "\n\t\t\t\t\t\t\t\t * [WINNER] %s defeated %s\n", winner, (strcmp(winner, u1) == 0) ? u2 : u1);
    }

    fclose(fp);
}

void print_leaderboard() {
    FILE* fp;
    char ch;

    fp = fopen("leaderboard.txt", "r");

    if (fp == NULL) {
        printf("\n\n\t\t\t\t\t\t\t\t * No Record Found !!\n\n");
        return;
    }

    printf("\n\n\n\n\t\t\t\t\t\t\t\t * Leaderboard *\n\n\n");

    while ((ch = fgetc(fp)) != EOF) {
        printf("%c", ch);
    }

    fclose(fp);
}
