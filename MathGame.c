
// Our console math game 

#include <stdio.h> 
#include <stdlib.h>
#include <time.h>

//variables
int levelSelected = 0;
int answerToQuestion;
int totalPoints;

// Function calls (Add another c file and header for these)
void welcomeMessage();
int toCorrectLevel(int a);

//Arrays for questions and answers
char easyQuestionsArray[9][20] = { "1 + 1 = ", "2 + 2 = ", "3 - 1 = ", "4 + 4 = ", "5 - 2 = ", 
"5 + 4 = ", "235 + 420 = ", "149 + 540 = ", "74 + 120 = "};
int easyAnswersArray[9] = { 2, 4, 2, 8, 3, 9, 655, 689, 194};


char intermediateQuestionsArray[5][20] = { "1 x 1 = ", "2 x 2 = ", "3 / 1 = ", "4 x 4 = ", "25 / 5 = " };
int intermediateAnswersArray[5] = { 1, 4, 3, 16, 5 };

char difficultQuestionsArray[5][30] = { "x + 2 = 0, solve x = ", "2x - 10 = 0, solve x = ", "x^2 - 25 = 0, solve x = ", "5x - 100 = 0, solve x = ", "2x - 50 = 0, solve x = " };
int difficultAnswersArray[5] = { -2, 5, 5, 20, 25 };

int main()

{
    srand(time(NULL));
    welcomeMessage();
    scanf("%d", &levelSelected);
    if (levelSelected == 0) {

        printf("Please input an integer\n");
    }
    printf("Your score was %d/10\n",toCorrectLevel(levelSelected));
    return 0;
}

void welcomeMessage() {
    printf("Welcome to the Math Game!!\n");
    printf("Please select a level by entering the number corresponding to the desired level.\n");
    printf("1. Easy\n");
    printf("2. Intermediate\n");
    printf("3. Difficult\n");
}

int toCorrectLevel(int level) {
    if (level == 1) {
        printf("You selected level Easy!\n");
        for (int i = 0; i < 5; i++) {
            //get random value from within array size
            int qRandom = rand() % (sizeof(easyQuestionsArray)/sizeof(easyQuestionsArray[0]));
            //prints question from array
            printf(easyQuestionsArray[qRandom]);
            //checks the value and compares it to answer from array in same index as questions
            scanf("%d", &answerToQuestion);
            if (answerToQuestion == easyAnswersArray[qRandom]) {
                totalPoints++;
            }
        }
        return totalPoints;
    }
    else if (level == 2) {
        printf("You selected level Intermediate!\n");
        for (int i = 0; i < 5; i++) {
            int qRandom = rand() % (sizeof(intermediateQuestionsArray)/sizeof(intermediateQuestionsArray[0]));
            printf(intermediateQuestionsArray[qRandom]);
            scanf("%d", &answerToQuestion);
            if (answerToQuestion == intermediateAnswersArray[qRandom]) {
                totalPoints++;
            }
        }
        return totalPoints;
    }
    else if (level == 3) {
        printf("You selected level Difficult!\n");
        for (int i = 0; i < 5; i++) {
            int qRandom = rand() % (sizeof(difficultQuestionsArray)/sizeof(difficultQuestionsArray[0]));
            printf(difficultQuestionsArray[qRandom]);
            scanf("%d", &answerToQuestion);
            if (answerToQuestion == difficultAnswersArray[qRandom]) {
                totalPoints++;
            }
        }
        return totalPoints;
    }
}


