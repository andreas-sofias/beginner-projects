#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<unistd.h>

void game_exit(void);
void game_playing(void); 
void game_choice_menu(); 
int algorithm(int *player_choice, int *computer_choice); 

static int player =0; 
static int computer=0;
int main()
{
        system("clear"); 

        printf("\n|==============================|\n|     ROCK-SCISSORS-PAPER      |\n|==============================|\n");
        printf("\n1.Start Playing!\n2.Exit!\n\nWhat you wanna do: (pick 1 or 2):        ");
        int input; 
        scanf("%d",&input);

        switch (input)
        {       case 1:
                        game_playing(); 
                        game_exit();
                        break;
                case 2: 
                        game_exit();
                        break;
                default: 
                        printf("WRONG INPUT!! TRY AGAIN!!!");
                        game_exit();
                        break;
        }

}

void show_score(int player,int computer) 
{
        printf("PLAYER=%d       PC=%d  \n",player,computer);
        printf("=======================\n");

}

void game_choice_menu(void)
{        
        system("clear");
        show_score(player,computer);
        printf("\nRock, Scissors or Paper? (1 for Rock, 2 for Scissors and 3 for Paper) ");
        int answer;
       do{
        scanf("%d",&answer);} while (answer<1 || answer>3);
        switch (answer)
        {
                case 1: 
                        printf("\nYou chose ROCK");
                        break;
                case 2: 
                        printf("\nYou chose SCISSOR");
                        break;
                case 3: 
                        printf("\nYou choose PAPER");
                        break;
        }
        sleep(1);
        int computer_choice = (rand()% 3)+1;
        switch (computer_choice)
        {
                case 1:
                        printf("\nComputer chose ROCK");
                        break; 
                case 2: 
                        printf("\nComputer chose SCISSOR");
                        break; 
                case 3: 
                        printf("\nComputer chose PAPER");
                        break;

        }
        sleep(1);
        int result;
        result = algorithm(&answer,&computer_choice);
        if (result==2) 
        {
                player++;
                printf("\nYOU WON!!!\n");
                sleep(3);
        }
        else if (result ==1)
        {
                printf("\nDRAW!!!\n");
                sleep(3);
        }

        else if (result==0)
        {
                printf("\nYOU LOSE!!!\n");
                computer++;
                sleep(3);
        }
}

int algorithm(int *player_choice, int *computer_choice)
{

        switch (*player_choice)
        {
                case 1:
                       switch (*computer_choice)
                       {
                                case 1: 
                                        return 1;
                                        break;
                                case 2: 
                                        return 2; 
                                        break;
                                case 3: 
                                        return 0;
                                        break;
                       }
                       break;

                case 2: 
                        switch(*computer_choice)
                        {
                                case 1: 
                                        return 0;
                                        break;
                                case 2: 
                                        return 1; 
                                        break;
                                case 3: 
                                        return 2; 
                                        break; 
                        }
                        break; 

                case 3: 
                        switch(*computer_choice)
                        {
                                case 1: 
                                        return 2;
                                        break;
                                case 2: 
                                        return 1;
                                        break;
                                case 3:
                                        return 0;
                                        break;
                        }

        }
}

void game_playing(void)
{
        for (;;) 
        {
                game_choice_menu();
                system("clear");
                show_score(player,computer);
                printf("\nDo you want to stop? (y for 'yes' or something else for stopping)");

                char reply; 
                scanf(" %c",&reply); 
                 if (reply != 'y') 
                        continue;
                 else 
                        break;
                 //else 
                //       break;




        }

}

void game_exit(void)
{
        system("clear"); 
        printf("THANK YOU FOR PLAYING!!!");
        printf("\n");
}
