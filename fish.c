#include <stdio.h>
#include <stdlib.h>

struct Grid
{
    int x;
    int y;
    char data;
    struct Grid * up;
    struct Grid * down;
    struct Grid * left;
    struct Grid * right;
    struct Grid * upLeft;
    struct Grid * upRight;
    struct Grid * downLeft;
    struct Grid * downRight;
}
;
typedef struct Grid grid;

struct Board 
{
    grid**coords;
}
;
struct player
{
    char symbol;
    int score;
    int x;
    int y;
}
;
struct AI
{
    char symbol;
    int score;
    int x;
    int y;
}
;




void printBoard(struct Board board)
{
    for (int i=0;i<6;i++) 
       {
        for (int j=0;j<6;j++) 
          {
            printf("%c",board.coords[i][j].data);
            printf(" ");
            if(j==5)
            {
                 printf("\n");
            }
        }
       }
}

void setBoard(struct Board board)
{
int row=6;
int column=6;

for(int i=0;i<6;i++) 
{
    for (int j=0;j<6;j++) 
    {
        if(i!=0)
        {
        board.coords[i][j].up=&board.coords[i-1][j];
        }
        else
        {
        board.coords[i][j].up=NULL;
        }

        if(i!=5)
        {
        board.coords[i][j].down=&board.coords[i+1][j];
        }
        else
        {
        board.coords[i][j].down=NULL;
        }

        if(j!=0)
        {
            board.coords[i][j].left=&board.coords[i][j-1];
        }
        else
        {
            board.coords[i][j].left=NULL;
        }

        if(j!=5)
        {
            board.coords[i][j].right=&board.coords[i][j+1];
        }
        else
        
            board.coords[i][j].left=NULL;
        }


    }
}

void setData(struct Board board)
{
    int row=6;
    int column=6;

    for(int i=0;i<6;i++) 
 {
    for (int j=0;j<6;j++) 
    {
        board.coords[i][j].data ='3';
    }
 }


    for(int i=0;i<6;i++) 
 {
    for (int j=0;j<6;j++) 
    {
      if(i==0||i==5||j==0||j==5)
      {
          board.coords[i][j].data ='1';
      }

      if(i==1||i==4)
      {    
          if(j>0&&j<5)
          board.coords[i][j].data ='2'; 
      }

      if(j==1||j==4)
      {    
          if(i>0&&i<5)
          {
          board.coords[i][j].data ='2'; 
          }
      }
    }
  } 
}

void AImove (struct Board board,struct AI AI) 
{
int randMove=(rand()%8)+1; 
switch(randMove)
{
case 1:
board.coords[AI.x][AI.y].data ='.';
AI.x=AI.x-1;
AI.y=AI.y-1;
AI.score=AI.score+board.coords[AI.x][AI.y].data;
AI.score-='0';
board.coords[AI.x][AI.y].data ='A';
break;

case 2:
board.coords[AI.x][AI.y].data ='.';
AI.x=AI.x-1;
AI.score=AI.score+board.coords[AI.x][AI.y].data;
AI.score-='0';
board.coords[AI.x][AI.y].data ='A';
break;

case 3:
board.coords[AI.x][AI.y].data ='.';
AI.x=AI.x-1;
AI.y=AI.y+1;
AI.score=AI.score+board.coords[AI.x][AI.y].data;
AI.score-='0';
board.coords[AI.x][AI.y].data ='A';
break;

case 4:
board.coords[AI.x][AI.y].data ='.';
AI.y=AI.y-1;
AI.score=AI.score+board.coords[AI.x][AI.y].data;
AI.score-='0';
board.coords[AI.x][AI.y].data ='A';
break;

case 5:
board.coords[AI.x][AI.y].data ='.';
AI.y=AI.y+1;
AI.score=AI.score+board.coords[AI.x][AI.y].data;
AI.score-='0';
board.coords[AI.x][AI.y].data ='A';
break;

case 6:
board.coords[AI.x][AI.y].data ='.';
AI.x=AI.x+1;
AI.y=AI.y-1;
AI.score=AI.score+board.coords[AI.x][AI.y].data;
AI.score-='0';
board.coords[AI.x][AI.y].data ='A';
break;

case 7:
board.coords[AI.x][AI.y].data ='.';
AI.x=AI.x+1;
AI.score=AI.score+board.coords[AI.x][AI.y].data;
AI.score-='0';
board.coords[AI.x][AI.y].data ='A';
break;

case 8:
board.coords[AI.x][AI.y].data ='.';
AI.x=AI.x+1;
AI.y=AI.y+1;
AI.score=AI.score+board.coords[AI.x][AI.y].data;
AI.score-='0';
board.coords[AI.x][AI.y].data ='A';
break;
}
}

void start (struct Board board, struct player Player, struct AI AI)
{

while(1)
{
int choice;
int steps;
printf("Which direction do you want to move? (Type 1 to move top left, 2 to move up, 3 to move top right\n, 4 to move left, 5 to move right, 6 to move bottom left, 7 to move down, 8 to move bottom right)\n");
scanf("%i",&choice);
int canMove=1;
switch(choice)
{
case 1:

printf("How many steps?\n");
scanf("%i", &steps);
board.coords[Player.x][Player.y].data ='.';
Player.x=Player.x-steps;
Player.y=Player.y-steps;
Player.score=Player.score+board.coords[Player.x][Player.y].data;
Player.score-='0';
board.coords[Player.x][Player.y].data ='P';
printBoard(board);
printf("Player Score %i, AI Score %i\n", Player.score, AI.score);



break;

case 2:
printf("How many steps?\n");
scanf("%i", &steps);
board.coords[Player.x][Player.y].data ='.';
Player.x=Player.x-steps;
Player.score=Player.score+board.coords[Player.x][Player.y].data;
Player.score-='0';
board.coords[Player.x][Player.y].data ='P';
printBoard(board);
printf("Player Score %i \n",Player.score);
break;

case 3:
printf("How many steps?\n");
scanf("%i", &steps);
board.coords[Player.x][Player.y].data ='.';
Player.x=Player.x-steps;
Player.y=Player.y+steps;
Player.score=Player.score+board.coords[Player.x][Player.y].data;
Player.score-='0';
board.coords[Player.x][Player.y].data ='P';

printBoard(board);
printf("Player Score %i\n",Player.score);
break;

case 4:
printf("How many steps?\n");
scanf("%i", &steps);
board.coords[Player.x][Player.y].data ='.';
Player.y=Player.y-steps;
Player.score=Player.score+board.coords[Player.x][Player.y].data;
Player.score-='0';
board.coords[Player.x][Player.y].data ='P';
printBoard(board);
printf("Player Score %i \n",Player.score);
break;

case 5:
printf("How many steps?\n");
scanf("%i", &steps);
board.coords[Player.x][Player.y].data ='.';
Player.y=Player.y+steps;
Player.score=Player.score+board.coords[Player.x][Player.y].data;
Player.score-='0';
board.coords[Player.x][Player.y].data ='P';

printBoard(board);
printf("Player Score %i \n",Player.score);
break;

case 6:
printf("How many steps?\n");
scanf("%i", &steps);
board.coords[Player.x][Player.y].data ='.';
Player.x=Player.x+steps;
Player.y=Player.y-steps;
Player.score=Player.score+board.coords[Player.x][Player.y].data;
Player.score-='0';
board.coords[Player.x][Player.y].data ='P';

printBoard(board);
printf("Player Score %i \n",Player.score);
break;

case 7:
printf("How many steps?\n");
scanf("%i", &steps);
board.coords[Player.x][Player.y].data ='.';
Player.x=Player.x+steps;
Player.score=Player.score+board.coords[Player.x][Player.y].data;
Player.score-='0';
board.coords[Player.x][Player.y].data ='P';

printBoard(board);
printf("Player Score %i \n",Player.score);
break;

case 8:
printf("How many steps?\n");
scanf("%i", &steps);
board.coords[Player.x][Player.y].data ='.';
Player.x=Player.x+steps;
Player.y=Player.y+steps;
Player.score=Player.score+board.coords[Player.x][Player.y].data;
Player.score-='0';
board.coords[Player.x][Player.y].data ='P';

printBoard(board);
printf("Player Score %i \n",Player.score);
break;

  }
 }
}


int main()
{
struct Board board;
int row=6;
int column=6;
board.coords = (grid**)malloc(sizeof(grid*)*6);
    for (int i = 0; i < row; i++) 
    {
        board.coords[i] = (grid*)malloc(sizeof(grid)*column);
    }

setBoard(board);
setData(board);


for (int i=0;i<6;i++) 
{
        for (int j=0;j<6;j++) 
        {
            printf("%c",board.coords[i][j].data);
            printf(" ");
            if(j==5)
            {
                 printf("\n");
            }
        }
       
}

struct player Player = {'P'};
struct AI AI = {'A'};
Player.score=0;
AI.score=0;
printf("Welcome to Hey, that my fish!\n");
printf("Please enter the row and column of your starting point\n");
int startX;
int startY;

scanf("%d%d", &startX, &startY);
board.coords[startX-1][startY-1].data = Player.symbol;
Player.x=startX-1;
Player.y=startY-1;
Player.score++;
printBoard(board);

start(board,Player, AI);
if(Player.score>AI.score)
{
printf("Game Over, Player wins!");
}
if(Player.score>AI.score)
{
printf("Game Over, AI wins!");
}
if(Player.score==AI.score)
{
printf("Game Over, Draw!");
}
return 0;
}




