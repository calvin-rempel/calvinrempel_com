/*this is a simple program designed to give a random flashcard from a text file, give me a chance to answer it, and then give me a delay*/
/*it is currently VERY easy to break. I have put pretty well no effort into sanitizing user input, and if the textfile is not properly
formatted, it too will break the program*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
    char fName[20] = {};
    char fString[1000] = {};
    char cards[100][1000] = {}; /*card number, card string*/
    int cardStats[100][2] = {}; //[card number][0 - right, 1- wrong]
    int numberCards = 0;
    int counter = 0;
    long timer_start = 0;
    int minutes = 0;
    int seconds = 0;
    int minute_start = 0;
    int second_start = 0;
    int randNumber = 0;
    char rightWrong = 0;
    FILE * fp;

    /*init randomizer*/
    srand(time(NULL));
    rand();


    /*open deck to read*/
    printf("Please enter the name of the stack you want: ");
    scanf("%s", fName);
    if((fp = fopen(fName, "r")) == NULL)
    {
        printf("File Could Not Be Found");
        return -1;
    }
    //get number of items, and copy items into memory
    while(!feof(fp))
    {
        fgets(fString, 1000, fp);
        for(counter = 0; fString[counter] != '\0'; ++counter) /*copy string into an array*/
            cards[numberCards][counter] = fString[counter];
        ++numberCards;
    }
    fclose(fp);

    /*set timer length*/
    printf("Please Enter the Time in the Format MM:SS\n");
    scanf("%d:%d", &minute_start, &second_start);

    minutes = minute_start;
    seconds = second_start;

    /*timer and random card picker*/
    while(1)
    {
        //check to see if all cards have been done at least once
        for(counter = 0; (cardStats[counter][0] > 0 || cardStats[counter][1] > 0) && counter < numberCards; ++counter);
        if(counter < numberCards)
        {
            //if no, randomly choose a card add one to the random number until you get a card that hasn't been done yet. Prepare for overflow
             randNumber = rand() % numberCards;
             while(cardStats[randNumber][0] > 0) /*if this is one that has been answered correctly, we need to choose a different card*/
             {
                 ++randNumber;
                 /*prevent overflow*/
                 if(randNumber == numberCards)
                    randNumber = 0;
             }
        }
        else
        {
            /*check to see if we have got all correct, of if there are still some wrong answers out there*/
            for(counter = 0; cardStats[counter][1] == 0 && counter < numberCards; ++counter);
            if(counter == numberCards) /*if we are done and all the answers are correct*/
            {
                for(counter = 0; counter < numberCards; ++counter)
                    cardStats[counter][0] = cardStats[counter][1] = 0; /*reset this array*/
            }
            else
                randNumber = counter;
        }


        //if all cards have been done at least once, go through the stack and - in order - do the ones the user got wrong.
            //once the end of the stack has been reached, reset the card stats and begin again.



       for(counter = 0; cards[randNumber][counter] != '|'; ++counter)
           printf("%c", cards[randNumber][counter]);
       printf("\n\nPress any Key to see answer...");
       getch();
       printf("\n\n");
       ++counter;
       for(; cards[randNumber][counter] != '\0'; ++counter)
           printf("%c", cards[randNumber][counter]);
        /*check to see if the user was correct or incorrect. If incorrect, we will do this same card again next time*/
        printf("\nDid you get that (R)ight or (W)rong?");

        rightWrong = 0;
        while(rightWrong != 'W' && rightWrong != 'R')
            rightWrong = toupper(getch());
        if(rightWrong == 'W')
            cardStats[randNumber][1]++;
        else
            {
                cardStats[randNumber][0]++;
                cardStats[randNumber][1] = 0;
            }

        printf("\nTimer Resumes\n");

           while(1)
            {
                printf("\r%02d:%02d", minutes, seconds);

                /*create a one second delay*/
                timer_start = time(NULL); //clock();
                while(time(NULL) < (timer_start + 1));

                /*handle minute/second decrement*/
                --seconds;
                if(seconds < 0)
                {
                    seconds = 59;
                    --minutes;
                    if(minutes < 0)
                    {
                        printf("\a\n");
                        minutes = minute_start;
                        seconds = second_start;
                        break;
                    }
                }
                if(minutes == (minute_start - 1) && seconds == second_start)
                    system("cls"); /*clear the previous answer off the screen after one minute*/
            }
    }

    //randomly display a card
    //time delay
    //randomly display a card
    //time delay
    //choose the first one encountered where wrong is greater the right

    return 0;
}
