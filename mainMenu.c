#include "gamePlays.h"

int main(){
    int choice;
mM: printf("What to do?\n0. Play With Your Friend.\n1. Play With Bot.\n2. Load Game.\n3. Load last game.\n4. Settings.\n5. Score Board.\n7. Exit.\n");
    scanf("%d", &choice);
    getchar();

    switch (choice)    {
    case 0:
        vsFriend();
    break;

    case 1:
        vsRobot();
    break;

    case 2:
    
    break;

    case 3:
    
    break;

    case 4:
    
    break;

    case 5:
        printScores();
    break;

    case 6:
        printf("in the middle of the game, you can use this Shortcut Keys:\nE: Exit\nS: Save Game\n\n");

    break;

    case 7:
        printf("Thanks for playing!\npress any key to exit.\n");
        getchar();
        return 0;
    break;

    default:
        goto mM;
    break;
    }

    goto mM;
}