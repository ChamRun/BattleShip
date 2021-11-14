#include "funcs.h"

int choi;

int vsFriend(){
    char userName[10];
    int pois, i = 0, n, m;

    system("cls");
    FILE *users;
    
    
    struct player me;
    struct player you;
    struct ship *yourShips,*myShips;

        printf("First Player\nChoose User:\n0. Choose From Available Users.\n1. New User.\n");
        scanf("%d", &choi);
        getchar();

        choose1stUser:
        switch (choi)  {
        case 0:
            users = fopen("users.txt", "r+");
            if (users == NULL)            {
                printf("There is No Saved User. Make a new one.\n");
                goto newOne1;
            }

            for (i = 0; fscanf(users, "%s %d", userName, &pois) != EOF; i++)            {
                printf("%d. %s: %d\n", i, userName, pois);
            }
            printf("Enter your user number:    ");
            scanf("%d", &n);
            getchar();
            fclose(users);
            users = fopen("users.txt", "r+");
            for (i = 0; i != n; i++)            {
                fscanf(users, "%s %d", userName, &pois);
            }
            fscanf(users, "%s %d", userName, &pois);
            strcpy(me.name, userName);
            me.points = pois;
        break;

        case 1:
        newOne1:
            users = fopen("users.txt", "a");
            printf("write your user name:    ");
            scanf("%s", userName);
            fprintf(users, "%s 0\n", userName);
            fclose(users);
            strcpy(me.name, userName);
            me.points = 0;


        break;

        default:
            printf("Not Valid! Enter 0 or 1\n");
            goto choose1stUser;
            break;
        }

        system("cls");
        printf("Second Player\nChoose User:\n0. Choose From Available Users.\n1. New User.\n");
        scanf("%d", &choi);
        getchar();
choose2ndUser:
        switch (choi)  {
        case 0:
            users = fopen("users.txt", "r+");
            if (users == NULL)            {
                printf("There is No Saved User. Make a new one.\n");
                goto newOne2;
            }
            
            
            for (i = 0; fscanf(users, "%s %d", userName, &pois) != EOF; i++)            {
                printf("%d. %s: %d\n", i, userName, pois);
            }
            printf("Enter your user number:    ");
            scanf("%d", &m);
            getchar();
            fclose(users);
            users = fopen("users.txt", "r+");
            for (i = 0; i !=m; i++)            {
                fscanf(users, "%s %d", userName, &pois);
            }
            fscanf(users, "%s %d", userName, &pois);
            strcpy(you.name, userName);
            you.points = pois;
        break;

        case 1:
        newOne2:
            users = fopen("users.txt", "a");
            printf("write your user name:    ");
            gets(userName);
            fprintf(users, "%s 0\n", userName);
            fclose(users);
            strcpy(you.name, userName);
            you.points = 0;
        break;

        default:
            printf("Not Valid! Enter 0 or 1\n");
            goto choose2ndUser;
            break;
        }

    system("cls");

    yourShips = makeShip(-1);
    myShips = makeShip(-1);
    def2fill(you.ground, yourShips);
    def1fill(me.ground, myShips);

    int firYouPo = you.points, firMePo = me.points;

    while (1)    {
        oneTurn(&me, &you, yourShips, 0);
        system("cls");

        oneTurn(&you, &me, myShips, 1);
        system("cls");
        
        

        if (yourShips->next == NULL){
            you.points = ((you.points + firYouPo) / 2);
            writePoints(me, you);
            printf("%s Won!\n\n", me.name);
            return 0;
        }
        if (myShips->next == NULL){
            me.points = ((me.points + firMePo) / 2);
            writePoints(me, you);
            printf("%s Won!\n\n", you.name);
            return 1;
        }
    }
    
}


int vsRobot(){
    
    char userName[10];
    int pois, i = 0, n, m;

    system("cls");
    FILE *users;
    
    
    struct player me;
    struct player you;
    struct ship *yourShips,*myShips;

        printf("Choose User:\n0. Choose From Available Users.\n1. New User.\n");
        scanf("%d", &choi);
        getchar();

        chooseVsBot:
        switch (choi)  {
        case 0:
            users = fopen("users.txt", "r+");
            if (users == NULL)            {
                printf("There is No Saved User. Make a new one.\n");
                goto newVsBot;
            }

            for (i = 0; fscanf(users, "%s %d", userName, &pois) != EOF; i++)            {
                printf("%d. %s: %d\n", i, userName, pois);
            }
            printf("Enter your user number:    ");
            scanf("%d", &n);
            getchar();
            fclose(users);
            users = fopen("users.txt", "r+");
            for (i = 0; i != n; i++)            {
                fscanf(users, "%s %d", userName, &pois);
            }
            fscanf(users, "%s %d", userName, &pois);
            strcpy(me.name, userName);
            me.points = pois;
        break;

        case 1:
        newVsBot:
            users = fopen("users.txt", "a");
            printf("write your user name:    ");
            scanf("%s", userName);
            fprintf(users, "%s 0\n", userName);
            fclose(users);
            strcpy(me.name, userName);
            me.points = 0;


        break;

        default:
            printf("Not Valid! Enter 0 or 1\n");
            goto chooseVsBot;
            break;
        }

        system("cls");
        
        switch (choi)  {
        case 0:
            users = fopen("users.txt", "r+");
            if (users == NULL)            {
                goto makeBot;
            }
            
            
            for (i = 0; fscanf(users, "%s %d", userName, &pois) != EOF; i++)            {
                if (strcmp("Bot", userName) == 0)                {
                    break;
                }
            }

            fclose(users);
            strcpy(you.name, "Bot");
            you.points = pois;
        break;

        case 1:
        makeBot:
            users = fopen("users.txt", "a");
            strcpy(you.name, "Bot");
            fprintf(users, "Bot 0\n");
            fclose(users);
            you.points = 0;
        break;

        default:
            break;
        }

    system("cls");

    myShips = makeShip(-1);
    printf("What to do with Ships?\n0. Default\n1. Auto\n");
    int choi;
    scanf("%d", &choi);
    getchar();

    if (choi == 1)    {
        randFill(me.ground, myShips);
    }else    {
        def1fill(me.ground, myShips);
    }
    
    

    yourShips = makeShip(-1);
    def2fill(you.ground, yourShips);

    int firYouPo = you.points, firMePo = me.points;

    while (1)    {
        
        oneTurn(&me, &you, yourShips, 2);
        if (yourShips->next == NULL){
            you.points = ((you.points + firYouPo) / 2);
            writePoints(me, you);
            printf("%s Won!\n\n", me.name);
            return 0;
        }
        system("cls");

        oneTurn(&you, &me, myShips, 3);
        if (myShips->next == NULL){
            me.points = ((me.points + firMePo) / 2);
            writePoints(me, you);
            printf("Bot Won!\n\n");
            return 1;
        }
        system("cls");
        
    }
}
