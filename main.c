#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define TRUE 1
#define FALSE 0
void print_Date (void) ;
void board ( char x , char o , unsigned char* u1 , unsigned char* u2 , char* a ) ;
int checkforwin ( char* a )  ;
bool decision ( char* x , char* o , unsigned char* u1 ) ;
int main ()
{
    char a [9] = { '1' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9' } ;
    char u1 [50] , u2 [50] , symbol , re , start , dec , x , o , ga , ch , choice__ ;
    int choice , score = -1 , player = 1 , s ;
    FILE* p = fopen ( "score/score.txt" , "a+" ) ;
    fclose ( p ) ;
star_Programe:  
    system ( "cls" ) ;
    system ( "color b" ) ;
    print_Date () ;
    printf ( "\n\n\n" ) ;
    printf ( "\t\t\t\t\t\t\t ---{ T i c - T a c - T o e }--- \n\n\n" ) ;
    printf ( "\t\t\t * Start the game  ---->[1] \n\n" ) ;
    printf ( "\t\t\t * View leader board -->[2] \n" ) ;
    printf ( "\n\t\t\t * Choose an option  : " ) ; 
    scanf ( "%d" , &s ) ;  
    switch ( s ) 
     {
        case 1 :
                 
            do {
                system ( "cls" ) ;
                print_Date () ;
                printf ( "\n\n\n\t\t\t * Enter names of different players :\n\n" ) ;
                p = fopen ( "score/score.txt" , "a+" ) ;
                printf ( "\n\n\t\t\t * Enter name of player_1 -->  " ) ;
                scanf ( "%s" , u1 ) ;
                fprintf ( p , "\n%s" , u1 ) ;
                printf ( "\n\n\t\t\t * Enter name of player_2 -->  " ) ;
                scanf ( "%s" , u2 ) ;
                fprintf ( p , "\t%s" , u2 ) ;
                fclose ( p ) ;        
            } while ( !strcmp ( u1 , u2 ) ) ;          
            decision ( &x , &o , u1 ) ;
            system ( "color b" ) ;
            board ( x , o , u1 , u2 , a ) ;
            do {
                
                player = ( ( player % 2 ) ? 1:2 ) ;
                if ( player == 1 )
                    printf ( "\n\n\n\t\t * %s Type any digit from 1-9 to fill your response --> " , u1 ) ;
                else
                    printf ( "\n\n\n\t\t * %s Type any digit from 1-9 to fill your response --> " , u2 ) ;
                scanf ( "%d" , &choice ) ;
                symbol = ( ( player == 1 ) ? x:o ) ;
                if ( choice == 1 && a [0] == '1' )
                    a [0] = symbol ;
                else 
                    if ( choice == 2 && a [1] == '2' )
                        a [1] = symbol ;
                else 
                    if ( choice == 3 && a [2] == '3' )
                        a [2] = symbol ;
                else
                    if ( choice == 4 && a [3] == '4' )
                        a [3] = symbol ;
                else
                    if ( choice == 5 && a [4] == '5' )
                        a [4] = symbol ;
                else
                    if ( choice == 6 && a [5] == '6' )
                        a [5] = symbol ;
                else 
                    if ( choice == 7 && a [6] == '7' )
                        a [6] = symbol ;
                else 
                    if ( choice == 8 && a [7] == '8' )
                    a [7] = symbol ;
                else
                    if ( choice == 9 && a [8] == '9' )
                        a [8] = symbol ;
                else {
                        printf ( " Wrong Selection\n " ) ;
                        player -- ;
                }
                score = checkforwin (a) ;
                player ++ ;
                board ( x , o , u1 , u2 , a ) ;
            } while ( score == -1 ) ;
            p = fopen ( "score/score.txt" , "a+" ) ;
            if ( score == 1 )
             {
                if ( player == 2 ) 
                {
                    printf ( "\n\n\t\t\t * Player_1 %s Wins !!\n\n" , u1 ) ;
                    fprintf ( p ,"\t%s" , u1 ) ; 
                    getchar () ;
                }
                else {
                    printf ( "\n\n\t\t\t * Player_2 %s Wins !!\n\n" , u2 ) ;
                    fprintf ( p , "\t%s" , u2 ) ;
                    getchar () ;
                }
                fclose (p) ;
            }
            else {
                printf ("\n\n\t\t\t * Game Draws !!\n\n" ) ; 
                fprintf ( p ,"\t%s" , "DRAW" ) ;
                getchar () ;
            }
            break ;
        case 2:
start:        
            system("cls");
            print_Date () ;
            printf ( "\n\n\n" ) ;
            printf ( " \tLEADERBOARD\n\n " ) ;
            char c ;
            p = fopen ( "score/score.txt" , "r" ) ;
            while ( ( c = getc (p) ) != EOF )
             {
                printf ( "%c" , c ) ;
            }
            fclose (p) ;
            getchar () ;
            printf ( " \n\n\n " ) ;
	        printf ( "\t\t\t\t\t\t * Back  ---> [1]\n" ) ; 
	        printf ( "\t\t\t\t\t\t * Exit ----> [2]\n\n" ) ;
	        printf ( "\t\t\t\t\t\t * Choose an option  : " ) ;
			scanf ( " %c", &ga ) ;
			switch( ga )
				    {
						case '1':
							goto star_Programe ;
							break ;
						case '2':
							exit (1) ;
							break ;
						default:
							goto start ;
					}
				break ;
        default:
            printf ( "\n\n\t\t\t * Should have typed 1 to play the game!\n\n\t\t\t * Hope to see you back soon!\n\n" ) ;
            getchar () ;
            break ;
    }
}

void print_Date ()
{
	time_t now ;
	time ( &now ) ;
	struct tm* local = localtime ( &now ) ;
	printf ( "\n  --{ %02d / %02d / %d }-- \n ", local->tm_mday, local->tm_mon + 1, local->tm_year + 1900 ) ;
	
}
int checkforwin ( char* a ) 
{
    if ( a [0] == a [1] && a [1] == a [2] )
        return 1 ;
    else 
        if ( a [3] == a [4] && a [4] == a [5] )
            return 1 ;
    else 
        if ( a [6] == a [7] && a [7] == a [8] )
            return 1 ;
    else
        if ( a [0] == a [3] && a [3] == a [6] )
            return 1 ;
    else 
        if ( a [1] == a [4] && a [4] == a [7] )
            return 1 ;
    else 
        if ( a [2] == a [5] && a [5] == a [8] )
            return 1 ;
    else 
        if ( a [0] == a [4] && a [4] == a [8] )
            return 1 ;
    else
        if ( a [2] == a [4] && a [4] == a [6] )
            return 1 ;
    else 
        if ( a [0] != '1' && a [1] != '2' && a [2] != '3' && a [3] != '4' && a [4] != '5' && a [5] != '6' && a [6] != '7' && a [7] != '8' && a [8] != '9' ) 
            return 0 ;
    else
        return -1 ;
}
void board ( char x , char o , unsigned char* u1 , unsigned char* u2 , char* a ) 
{
    int i ;
        system ( "cls" ) ;
        print_Date () ;
        printf ( "\n\n\n" ) ;
        printf ( "\t\t * Player_1 : %s [%c] \n\n " , u1 , x  ) ;
        printf ( "\t\t * Player_2 : %s [%c] \n\n\n " , u2 , o ) ;
        printf ( "\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n" ) ;
        printf ( "\t\t\t\t\t\t\t\t\xB2             \xB2             \xB2             \xB2\n " ) ;
        printf ( "\t\t\t\t\t\t\t\t\xB2             \xB2             \xB2             \xB2\n " ) ;
        printf ( "\t\t\t\t\t\t\t\t\xB2     %c       \xB2     %c       \xB2     %c       \xB2\n ", a [0] , a [1] , a [2]  ) ;
        printf ( "\t\t\t\t\t\t\t\t\xB2             \xB2             \xB2             \xB2\n " ) ;
        printf ( "\t\t\t\t\t\t\t\t\xB2             \xB2             \xB2             \xB2\n " ) ;
        printf ( "\t\t\t\t\t\t\t\t\xB2-------------\xB2-------------\xB2-------------\xB2\n " ) ;
        printf ( "\t\t\t\t\t\t\t\t\xB2             \xB2             \xB2             \xB2\n " ) ;
        printf ( "\t\t\t\t\t\t\t\t\xB2             \xB2             \xB2             \xB2\n " ) ;
        printf ( "\t\t\t\t\t\t\t\t\xB2     %c       \xB2     %c       \xB2     %c       \xB2\n " , a [3] , a [4] , a [5] ) ;
        printf ( "\t\t\t\t\t\t\t\t\xB2             \xB2             \xB2             \xB2\n " ) ;
        printf ( "\t\t\t\t\t\t\t\t\xB2             \xB2             \xB2             \xB2\n " ) ;
        printf ( "\t\t\t\t\t\t\t\t\xB2-------------\xB2-------------\xB2-------------\xB2\n " ) ;
        printf ( "\t\t\t\t\t\t\t\t\xB2             \xB2             \xB2             \xB2\n " ) ;
        printf ( "\t\t\t\t\t\t\t\t\xB2             \xB2             \xB2             \xB2\n " ) ;
        printf ( "\t\t\t\t\t\t\t\t\xB2     %c       \xB2     %c       \xB2     %c       \xB2\n " , a [6] , a [7] , a [8] ) ;
        printf ( "\t\t\t\t\t\t\t\t\xB2             \xB2             \xB2             \xB2\n " ) ;
        printf ( "\t\t\t\t\t\t\t\t\xB2             \xB2             \xB2             \xB2\n " ) ;
        printf ( "\t\t\t\t\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2" ) ;
        
    }
bool decision ( char* x , char* o , unsigned char* u1 )
{
    char dec ;
    system ( "cls" ) ;
    system ( "color b" ) ;
    print_Date () ;
    printf ( "\n\n\n" ) ;
    do {
        printf ( "\t\t\t * Player_1 %s choose the X or O --> " , u1 ) ;
        dec = getchar () ;
        scanf ( "%c" , &dec ) ;
    } while ( dec != 'X' && dec != 'x' && dec != 'O' && dec != 'o' ) ;
    if ( dec == 'X' || dec == 'x' ) {
        *x = 'X' ;
        *o = 'O' ;
    }
    else {
        *x = 'O' ;
        *o = 'X' ;
    }
    return 1 ;
}
