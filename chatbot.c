#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

void intro();
void feel();
void botfeel();
void play();
int game2();
char matrix[3][3];                          
char check(void);
void init_matrix(void);
void get_player_move(void);
void get_computer_move(void);
void disp_matrix(void);

int main(){
    printf("Booting Up...........\n\n");
    intro();
    feel();
    botfeel();
    play();
    return 0;
}
void intro(){
    printf("hi i am ur assistant zoro\n");
}
void feel(){
    printf("how are u feeling today\n");
    char s[] = "sad";
    char h[] = "happy";
    char ptr[10];
    scanf("%s", ptr );
    int res = strcmp(s,ptr);
    if(res==0){
        printf("its ok u are doing your best\n\n");
    }
    else{
        printf("i am gald to hear that\n\n");
    }
    
}
void botfeel(){
    char input[60];
    printf("Ask how the Bot feels\n");
    while(1){
        gets(input);
        if(strcmp(input,"how are u")==0){
            srand(time(NULL));
            int r;
            char *ans[] = {"i am fine","i was sad but i feel happy talking to u","i am happy,lets have fun",
                           "owo","i am feeling low","not bad","fantastic","different day same exsistence","oh,just usual"};
            r = rand()%9;
            printf("%s\n\n",ans[r]);
            break;
        }
    }
}
void play(){
    printf("Thankyou to care about my feelings,i am delighted\n\n");
    printf("What would u like to do\n\n");
    char a[] = "task";
    char input[15];
    scanf("%s",input);
    int i = strcmp(a,input);
    if(i==0){
        char ask[60];
        printf("what do u wanna play or talk about\n\n");
        while(1){
            gets(ask);
            if(strcmp(ask,"guess the number")==0){
                int number, guess, nguesses=1;
                srand(time(0));
                number = rand()%100 + 1;

                do{
                    printf("Guess the number between 1 to 100\n");
                    scanf("%d", &guess);
                    if(guess>number){
                        printf("Lower number please!\n");
                    }
                    else if(guess<number){
                        printf("Higher number please!\n");
                    }
                    else{
                        printf("You guessed it in %d attempts\n", nguesses);
                    }
                    nguesses++;
                } while(guess!=number);
            break;
            }
            if(strcmp(ask,"swg")==0){
                char you , comp ;
                srand(time(0));
                int number = rand()%100+1;
                if(number<33){
                    comp='s';
                }
                else if(number>33 && number<66){
                    comp='w';
                }
                else{
                    comp='g';
                }

                printf("Enter 's' for snake , 'w' for water , 'g' for gun\n\n");
                scanf("%c",&you);
                int result = game2(you,comp);
                if(result==0){
                    printf("Game Draw!\n\n");
                }
                else if(result==1){
                    printf("You Win!\n\n");
                }
                else{
                    printf("You Lose!\n\n");
                }

                printf("You chose %c and computer chose %c" ,you,comp);
            break;
            }
            if(strcmp(ask,"tic tac")==0){
                char done;
                printf("This is the game of Tic Tac Toe.\n");
                printf("You will be playing  against the computer.\n");
                done = ' ';
                init_matrix();
                do{
                disp_matrix();
                get_player_move();
                done = check();                                                               
                if(done!= ' ') break;                                                       
                get_computer_move();
                done = check();                                    
                } while(done== ' ');
                if(done=='X') printf("You won!\n");
                else printf("I won!!!!\n");
                disp_matrix();
            break;
            }
        
            if(strcmp(ask,"cricket")==0){
                int ran;
                char *reply[] = {"wow i love cricket\n","same pinch\n","i get so excited while watching it\n","i love the rivarly players have during the match\n"};
                ran = rand()%4;
                printf("%s\n\n",reply[ran]);
            break;
            }
            if(strcmp(ask,"tell me more about cricket")==0){
                printf("cricket is a game played between 2 teams each consisting  of 11 players, there are different formats\n;");
            break;
            }
            if(strcmp(ask,"football")==0){
                int gg;
                char *soccer[] = {"i love football\n","lets goal!!!!\n","i get so excited when palyers start dribbling\n","i love the rivarly players have , especially between ronaldo nad messi\n"};
                gg = rand()%4;
                printf("%s\n\n",soccer[gg]);            
            break;
            }
        }
    }
}
int game2( you ,comp){
    if(you==comp){
        return 0;
    }

    if(you=='s' && comp=='g'){
        return -1;
    }
    else if(you=='g' && comp=='s'){
        return 1;
    }

    if(you=='s' && comp=='w'){
        return 1;
    }
    else if(you=='w' && comp=='s'){
        return -1;
    }

    if(you=='g' && comp=='w'){
        return -1;
    }
    else if(you=='w' && comp=='g'){
        return 1;
    }

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
exit(0);
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
for(i=0; i<3; i++)                                                    /* check rows */
if(matrix[i][0]==matrix[i][1] &&
matrix[i][0]==matrix[i][2]) return matrix[i][0];
for(i=0; i<3; i++)                                                   /* check columns */
if(matrix[0][i]==matrix[1][i] && matrix[0][i]==matrix[2][i])
    return matrix[0][i];
/* test diagonals */
if(matrix[0][0]==matrix[1][1] &&
matrix[1][1]==matrix[2][2])
return matrix[0][0];
if(matrix[0][2]==matrix[1][1] &&
matrix[1][1]==matrix[2][0])
return matrix[0][2];
return ' ';
}