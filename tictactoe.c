#include <stdio.h>


char box[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

void creating_board();
void marking_board(int, char);
int check_for_win();
void creating_board()
{


    printf("\n\n\tTic Tac Toe\n\n");

    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", box[1], box[2], box[3]);

    printf("_____|_____|______\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", box[4], box[5], box[6]);

    printf("_____|_____|______\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", box[7], box[8], box[9]);

    printf("     |     |     \n\n");
}


void marking_board( int choice, char mark)
{
    if (choice == 1 && box[1] == '1')
        box[1] = mark;

    else if (choice == 2 && box[2] == '2')
        box[2] = mark;

    else if (choice == 3 && box[3] == '3')
        box[3] = mark;

    else if (choice == 4 && box[4] == '4')
        box[4] = mark;

    else if (choice == 5 && box[5] == '5')
        box[5] = mark;

    else if (choice == 6 && box[6] == '6')
        box[6] = mark;

    else if (choice == 7 && box[7] == '7')
        box[7] = mark;

    else if (choice == 8 && box[8] == '8')
        box[8] = mark;

    else if (choice == 9 && box[9] == '9')
        box[9] = mark;

    else
    {
        printf("Invalid move ");


    }
}
int check_for_win() {
    if (box[1] == box[2] && box[2] == box[3])
        return 1;

    else if (box[4] == box[5] && box[5] == box[6])                // horizontal match
        return 1;

    else if (box[7] == box[8] && box[8] == box[9])
        return 1;



    else if (box[1] == box[4] && box[4] == box[7])
        return 1;

    else if (box[2] == box[5] && box[5] == box[8])                  // vertical match
        return 1;

    else if (box[3] == box[6] && box[6] == box[9])
        return 1;



    else if (box[1] == box[5] && box[5] == box[9])
        return 1;
                                                                        // diagonal match
    else if (box[3] == box[5] && box[5] == box[7])
        return 1;



    else if (box[1] != '1' && box[2] != '2' && box[3] != '3' &&box[4] != '4' && box[5] != '5'
                && box[6] != '6' && box[7]!= '7' && box[8] != '8' && box[9] != '9')                 // no match

        return 0;
    else
        return -1;

}

char matrix[3][3]; /* the tic tac toe matrix */

char check(void);

void init_matrix(void);

void get_player_move(void);

void get_computer_move(void);

void disp_matrix(void);

int main()
{
    int player = 1, i, choice, num;
     printf("Enter mode\n");
     printf(" 1 == single player\n 2 == two player ");
     printf("\nMode = ");
     scanf("%d", &num);

       if (num == 1){
        char done;

        printf("This is the game of Tic Tac Toe.\n");

        printf("You will be playing against the computer.\n");

        done = ' ';

        init_matrix();

        do {

        disp_matrix();

        get_player_move();

        done = check(); /* see if winner */

        if(done!= ' ') break; /* winner!*/

        get_computer_move();

        done = check(); /* see if winner */

        } while(done== ' ');

        if(done=='X') printf("You won!\n");

        else printf("I won!!!!\n");

        disp_matrix(); /* show final positions */

      }
      else if(num == 2){
     char mark;
     do
     {
         creating_board();
         player = (player % 2) ? 1 : 2;

         printf("Player %d, enter a number:  ", player);
         scanf("%d", &choice);

         mark = (player == 1) ? 'X' : 'O';

         marking_board(choice, mark);
         i = check_for_win();

         player++;
     }
     while (i ==  - 1);

     creating_board();

     if (i == 1)
         printf("Player %d you have won the game :-) ", --player);
     else
         printf("Game draw");
       }

    return 0;
}
/* Initialize the matrix. */

void init_matrix(void)

{

int i, j;

for(i=0; i<3; i++)

for(j=0; j<3; j++) matrix[i][j] = ' ';

}

/* Get a player's move. */

void get_player_move(void)

{

int x, y;

printf("Enter X,Y coordinates for your move: ");

scanf("%d%*c%d", &x, &y);

x--; y--;

if(matrix[x][y]!= ' '){

printf("Invalid move, try again.\n");

get_player_move();

}

else matrix[x][y] = 'X';

}

/* Get a move from the computer. */

void get_computer_move(void)

{

int i, j;

for(i=0; i<3; i++){

for(j=0; j<3; j++)

if(matrix[i][j]==' ') break;

if(matrix[i][j]==' ') break;

}

if(i*j==9) {

printf("draw\n");



}

else

matrix[i][j] = 'O';

}

/* Display the matrix on the screen. */

void disp_matrix(void)

{

int t;

for(t=0; t<3; t++) {

printf(" %c | %c | %c ",matrix[t][0],

matrix[t][1], matrix [t][2]);

if(t!=2) printf("\n---|---|---\n");

}

printf("\n");

}

/* See if there is a winner. */

char check(void)

{

int i;

for(i=0; i<3; i++) /* check rows */

if(matrix[i][0]==matrix[i][1] &&

matrix[i][0]==matrix[i][2]) return matrix[i][0];

for(i=0; i<3; i++) /* check columns */

if(matrix[0][i]==matrix[1][i] &&

matrix[0][i]==matrix[2][i]) return matrix[0][i];

/* test diagonals */

if(matrix[0][0]==matrix[1][1] &&

matrix[1][1]==matrix[2][2])

return matrix[0][0];

if(matrix[0][2]==matrix[1][1] &&

matrix[1][1]==matrix[2][0])

return matrix[0][2];

return ' ';

}
