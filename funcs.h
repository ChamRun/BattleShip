#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

struct xy{
    int x;
    int y;

};
struct ship{
    int all;
    int wells;
    struct xy *addr[5];
    struct ship *next;    
};
struct ship* makeShip(int size){
    struct ship *newShip;
    newShip = (struct ship*) malloc(sizeof(struct ship));
    for (int i = 0; i < size; i++)    {
        newShip->addr[i] = (struct xy*) malloc(sizeof(struct xy));;
    }
    newShip->all = size;
    newShip->wells = size;
    newShip->next = NULL;
    return newShip;
}
void addShip(struct ship *list, struct ship *newShip){
    struct ship *poList = list;
    while (poList->next != NULL)    {
        poList = poList->next;
    }
    poList->next = newShip;
}

struct player{
    char name[20], ground[10][11];
    int points;
};
/*
void valider(int size, int *start, int *end){
    while (*end - *start != size - 1)    {
        printf("Not Valid! Try Again:\nend: ");
        scanf("%d", end);
        scanf("%d", start);
    }
    return 0;
}

void fill(char ground[][11], int a, int b){
}
*/


void enemyEzPrinter(char ground[][11]){
    printf("    a | b | c | d | e | f | g | h | i | j |\n--|---|---|---|---|---|---|---|---|---|---|\n");  
    for (int i = 0; i < 10; i++)    {
        printf("%d | ", i);
        for (int j = 0; j < 10; j++)        {
            if (ground[i][j] == 'w')            {
                printf("~ | ");
            }
            else if ((ground[i][j] == '~') || (ground[i][j] == 's'))            {
                printf("  | ");
            }
            else{
                printf("%c | ", ground[i][j]);
            }
        }
        printf("\n--|---|---|---|---|---|---|---|---|---|---|\n");          
    }
    printf("\n");
}


void putter(char ground[][11], struct ship *list, int xSta, int ySta, int xEnd, int yEnd, int size){
    struct ship *temp = makeShip(size);
    int i = 0;

    if ((xSta == xEnd) && (ySta == yEnd))    {
        temp->addr[0]->x = xSta;
        temp->addr[0]->y = ySta;
        addShip(list, temp);
        ground[xSta][ySta] = 's';
        return;
    }
    


    if (ySta == yEnd){
        while (xSta != xEnd + 1)    {
            ground[xSta][yEnd] = 's';
            temp->addr[i]->x = xSta;
            temp->addr[i]->y = yEnd;
            i++;

            xSta++;
        }
        addShip(list, temp);
        return;
    }

    if (xSta == xEnd){
        while (ySta != yEnd + 1)    {
            ground[xSta][yEnd] = 's';
            temp->addr[i]->x = xSta;
            temp->addr[i]->y = yEnd;
            i++;

            ySta++;
        }
        addShip(list, temp);
        return;
    }
}

void youFill(char ground[][11], struct ship *list){
    for (int i = 0; i < 10; i++)    {
        for (int j = 0; j < 11; j++)        {
            ground[i][j] = '~';
            if (j == 10)            {
                ground[i][j] = '\0';
            }
        }     
    }

    char temp;
    int x, y;

gettinXY:
    printf("Size: 5\nStart Point:");
    scanf("%c", &temp);
    y = charToInt(temp);
    scanf("%d", &x);
    getchar();
    
    if ((9 < x) || (x < 0) || (9 < y) || (y < 0))    {
        printf("%d - %d is ", x, y);
        printf("Out of Sea! Try Again:\n");
        goto gettinXY;
    }
    putter(ground, list, 0, 0, 4, 0, 5);
    putter(ground, list, 2, 2, 4, 2, 3);
    putter(ground, list, 6, 6, 8, 6, 3);
    putter(ground, list, 7, 3, 8, 3, 2);
    putter(ground, list, 0, 6, 1, 6, 2);
    putter(ground, list, 6, 0, 7, 0, 2);
    putter(ground, list, 8, 8, 8, 8, 1);
    putter(ground, list, 8, 8, 8, 8, 1);
    putter(ground, list, 4, 9, 4, 9, 1);
    putter(ground, list, 2, 9, 2, 9, 1);
}


void randFill(char ground[][11], struct ship *list){
    for (int i = 0; i < 10; i++)    {
        for (int j = 0; j < 11; j++)        {
            ground[i][j] = '~';
            if (j == 10)            {
                ground[i][j] = '\0';
            }
        }     
    }
    int x, y, jahat;
    srand(time(NULL));
        y = rand() % 2;
        x = rand() % 5;
        putter(ground, list, x, y, x + 4, y, 5);

        y = y + 2;
        x = rand() % 8;
        putter(ground, list, x, y, x, y + 2, 3);
        
        x = rand() % 8;
        putter(ground, list, x, 4, x, 6, 3);
        putter(ground, list, x + 2, 4, x + 2, 6, 3);
        
        x = rand() % 2;
        putter(ground, list, x + 1, 7, x + 2, 7, 2);
        
        x = rand() % 2;
        putter(ground, list, x + 1, 9, x + 2, 7, 2);
        
        y = rand() % 2;
        x = rand() % 3;
        putter(ground, list, 2 + x, 6 + y, 2 + x, 6 + y, 1);
        putter(ground, list, 4 + x, 6 + y, 4 + x, 6 + y, 1);
        putter(ground, list, 2 + x, 8 + y, 2 + x, 8 + y, 1);
        putter(ground, list, 4 + x, 8 + y, 4 + x, 8 + y, 1);

    putter(ground, list, x, y, x, y, 1);
    
    
}


void def1fill(char ground[][11], struct ship *list){
    for (int i = 0; i < 10; i++)    {
        for (int j = 0; j < 11; j++)        {
            ground[i][j] = '~';
            if (j == 10)            {
                ground[i][j] = '\0';
            }
        }     
    }

    putter(ground, list, 0, 0, 4, 0, 5);
    putter(ground, list, 2, 2, 4, 2, 3);
    putter(ground, list, 6, 6, 8, 6, 3);
    putter(ground, list, 7, 3, 8, 3, 2);
    putter(ground, list, 0, 6, 1, 6, 2);
    putter(ground, list, 6, 0, 7, 0, 2);
    putter(ground, list, 8, 8, 8, 8, 1);
    putter(ground, list, 8, 8, 8, 8, 1);
    putter(ground, list, 4, 9, 4, 9, 1);
    putter(ground, list, 2, 9, 2, 9, 1);
}

void def2fill(char ground[][11], struct ship *list){
    for (int i = 0; i < 10; i++)    {
        for (int j = 0; j < 11; j++)        {
            ground[i][j] = '~';
            if (j == 10)            {
                ground[i][j] = '\0';
            }
        }     
    }

    putter(ground, list, 2, 2, 6, 2, 5);
    putter(ground, list, 5, 6, 7, 6, 3);
    putter(ground, list, 1, 8, 3, 8, 3);
    putter(ground, list, 0, 0, 1, 0, 2);
    putter(ground, list, 6, 0, 7, 0, 2);
    putter(ground, list, 1, 5, 2, 5, 2);
    putter(ground, list, 8, 3, 8, 3, 1);
    putter(ground, list, 4, 4, 4, 4, 1);
    putter(ground, list, 7, 9, 7, 9, 1);
    putter(ground, list, 9, 7, 9, 7, 1);
}

void myPrinter(char ground[][11]){
    printf("    a | b | c | d | e | f | g | h | i | j |\n--|---|---|---|---|---|---|---|---|---|---|\n");  
    for (int i = 0; i < 10; i++)    {
        printf("%d | ", i);
        for (int j = 0; j < 10; j++)        {
            if (ground[i][j] == '~'){
                printf("  | ");
            }
            else if (ground[i][j] == 'w')    {
                printf("~ | ");

            }   else
            printf("%c | ", ground[i][j]);
        }
        printf("\n--|---|---|---|---|---|---|---|---|---|---|\n");        
    }
    printf("\n\n");
}
void enemyPrinter(char ground[][11]){
    printf("    a | b | c | d | e | f | g | h | i | j |\n--|---|---|---|---|---|---|---|---|---|---|\n");  
    for (int i = 0; i < 10; i++)    {
        printf("%d | ", i);
        for (int j = 0; j < 10; j++)        {
            if (ground[i][j] == 'w')            {
                printf("~ | ");
            }
            else if ((ground[i][j] == '~') || (ground[i][j] == 's'))            {
                printf("  | ");
            }
            else{
                printf("%c | ", ground[i][j]);
            }
        }
        printf("\n--|---|---|---|---|---|---|---|---|---|---|\n");          
    }
    printf("\n");
}

void removeShip(struct ship **list, struct ship *toDele){
    struct ship* poList = *list;

    if(poList == toDele){
        *list = poList->next;
        return;
    }
    while ((poList->next != NULL) && (poList->next != toDele))    {
       poList = poList->next;
    }
    poList->next = poList->next->next;
}
void markSunk(char ground[][11], struct ship *theSunk){
    
    for (int i = 0; i < theSunk->all; i++)    {
        int px = -(theSunk->addr[i]->x), py = theSunk->addr[i]->y;
        //printf("tryna clean...\n");
        
        ground[px][py] = 'X';
        //printf("%d:%d -> X\n", px, py);
        //printf("%d:%d -> X\n", px, py);
        if ((9 > px) && (ground[px + 1][py] == '~')){
            ground[px + 1][py] = 'w';
        }
        if((0 < px) && (ground[px - 1][py] == '~')){
            ground[px - 1][py] = 'w';
        }
        if((py < 9) && (ground[px][py + 1] == '~')){
            ground[px][py + 1] = 'w';
        }
        if((0 < py) && (ground[px][py - 1] == '~')){
            ground[px][py - 1] = 'w';
        }

        if((9 > px) && (py < 9) && (ground[px + 1][py + 1] == '~')){
            ground[px + 1][py + 1] = 'w';
        }
        if((9 > px) && (0 < py) && (ground[px + 1][py - 1] == '~')){
            ground[px + 1][py - 1] = 'w';
        }
        if((0 < px) && (py < 9) && (ground[px - 1][py + 1] == '~')){
            ground[px - 1][py + 1] = 'w';
        }
        if((0 < px) && (0 < py) && (ground[px - 1][py - 1] == '~')){
            ground[px - 1][py - 1] = 'w';
        }
    }
    
}
int expload(struct ship *list, int x, int y, struct player *loser){

    //printf("gonna destry %d:%d\n", x, y);
    int plusPoint = 0;
    struct ship *poList = list->next;
    int i;
    while (poList!= NULL)    {
        //printf("search for sheep\n"); 
        i = 0;
        while (i < poList->all)        {
            //printf("searching for block...\n");
            if ((x == poList->addr[i]->x) && (y == poList->addr[i]->y)) {
                //printf("destrying %d:%d\n", x, y);
                poList->wells--;
                poList->addr[i]->x *= -1;
                //poList->addr[i]->y *= -1;
                if(poList->wells == 0){
                    plusPoint = (25 / poList->all) + 1;
                    markSunk(loser->ground, poList);
                    removeShip(&list, poList);
                    return plusPoint;
                }   
            }
            i++;
        }
        poList= poList->next;
    }

    if (list->next == NULL)    {
        printf("Game Overrrr!");
        exit(0);
    }

    return 1;
}

int charToInt(char theChar){
    if (theChar == 'a')    {
        return 0;
    }
    else if (theChar == 'b')    {
        return 1;
    }
    else if (theChar == 'c')    {
        return 2;
    }
    else if (theChar == 'd')    {
        return 3;
    }
    else if (theChar == 'e')    {
        return 4;
    }
    else if (theChar == 'f')    {
        return 5;
    }
    else if (theChar == 'g')    {
        return 6;
    }
    else if (theChar == 'h')    {
        return 7;
    }
    else if (theChar == 'i')    {
        return 8;
    }
    else if (theChar == 'j')    {
        return 9;
    }
    else if (theChar == 'E')    {
        exit(0);
    }
    else if (theChar == 'S')    {
        //saver();
    }   else{
        return -31;   
    }
}

int shot(struct player *turner, struct ship *list){
    struct player *shotter = turner;
    int x, y;
    char temp;

    takeXY:
    scanf("%c", &temp);
    
    y = charToInt(temp);
    scanf("%d", &x);
    getchar();

    if (x == -2)    {
        printf("gonna expload all the things...\n");
        for (int i = 0; i < 10; i++)        {
            for (int j = 0; j < 10; j++)            {
                if (shotter->ground[i][j] == 's')    {
                    shotter->ground[i][j] = '#';
                    expload(list, i, j, shotter);
                }
            }   
        }
        return 23;
    }
    
    
    if ((9 < x) || (x < 0) || (9 < y) || (y < 0))    {
        printf("%d - %d is ", x, y);
        printf("Out of Sea! Try Again:\n");
        goto takeXY;
    }

    if ((shotter->ground[x][y] != 's') && (shotter->ground[x][y] != '~')){
        printf("%d - %d", x, y);
        printf(" has been shotted before (its '%c'). Try Again:\n", shotter->ground[x][y]);
        goto takeXY;
    }

    if (shotter->ground[x][y] == 's')    {
        shotter->ground[x][y] = '#';
        printf("prize shot\n");
        return expload(list, x, y, shotter);
    }


    if (shotter->ground[x][y] == '~')    {
        shotter->ground[x][y] = 'w';
        return 0;
    }
    
    return -1;

}

int randShot(struct player *turner, struct ship *list){
    struct player *shotter = turner;
    int x, y;
    srand(time(NULL));
    x = rand() % 10;
    y = rand() % 10;
    while ((9 < x) || (x < 0) || (9 < y) || (y < 0) || ((shotter->ground[x][y] != 's') && (shotter->ground[x][y] != '~')))    {
        x = rand() % 10;
        y = rand() % 10;
    }

    if (shotter->ground[x][y] == 's')    {
        shotter->ground[x][y] = '#';
        return expload(list, x, y, shotter);
    }
    if (shotter->ground[x][y] == '~')    {
        shotter->ground[x][y] = 'w';
        return 0;
    }

    return -1;
}

void armyPrinter(struct ship *list){
    struct ship *poList = list;
    poList = poList->next;
    while (poList != NULL)    {
        printf("%d / %d\n", poList->wells, poList->all);
        poList = poList->next;
    }
}
void shipPrinter(struct ship *theShip){
    printf("a %d sheep\nalive: %d\n", theShip->all, theShip->wells);
    int i = 0;
    while (i < theShip->all)    {
        if (0 <= theShip->addr[i]->x)        {
            printf("%d:%d   ", theShip->addr[i]->x, theShip->addr[i]->y);
        }
        i++;
    }
    printf("\n");
    
}

void myEZprinter(char ground[][11]){
    printf("    a | b | c | d | e | f | g | h | i | j |\n--|---|---|---|---|---|---|---|---|---|---|\n");  
    for (int i = 0; i < 10; i++)    {
        printf("%d | ", i);
        for (int j = 0; j < 10; j++)        {
            if (ground[i][j] == '~'){
                printf("  | ");
            }
            else if (ground[i][j] == 'w')    {
                printf("~ | ");

            }   else
            printf("%c | ", ground[i][j]);
        }
        printf("\n--|---|---|---|---|---|---|---|---|---|---|\n");        
    }
    printf("\n\n");
}

void printScores(){
    FILE *users;
    int lines = 0;

    char buf[13] = {0};
    system("cls");

	users = fopen("users.txt", "r");

	if(users == NULL){
        printf("There is No Saved User.\n");
		return;
	}

	while(fgets(buf, 13, users) != NULL)
		lines++;
    fclose(users);

    char userName[lines][10], tempC[10];
    int pois[lines], temp;
    users = fopen("users.txt", "r");
    
    for (int i = 0; fscanf(users, "%s %d", userName[i], &pois[i]) != EOF; i++)            {
    }

    for (int i = 0; i < (lines - 1); i++)            {
        for (int j = i + 1; j < lines; j++)        {
            if(pois[i] < pois[j]){
                temp = pois[i];
                pois[i] = pois[j];
                pois[j] = temp;
                strcpy(tempC, userName[i]);
                strcpy(userName[i], userName[j]);
                strcpy(userName[j], tempC);
            }
        }
    }

    fclose(users);
    users = fopen("users.txt", "w");
    
    for (int i = 0; i < lines; i++)    {
        printf("%s : %d\n",userName[i], pois[i]);
        fprintf(users, "%s %d\n",userName[i], pois[i]);
    }
    fclose(users);
    printf("\n\n");   
}

void writePoints (struct player firP, struct player secP){
    FILE *users;
    users = fopen("users.txt", "r");

    char userNames[100][10];
    int pois[100];

    int i;
    for (i = 0; fscanf(users, "%s %d", userNames[i], &pois[i]) != EOF; i++)            {
    }
    fclose(users);

    users = fopen("users.txt", "w");
    for (int j = 0; j != i; j++)            {
        if (strcmp(firP.name, userNames[j]) == 0)        {
            pois[j] = firP.points;
        }
        
        if (strcmp(secP.name, userNames[j]) == 0)        {
            pois[j] = secP.points;
        }
        fprintf(users, "%s %d\n", userNames[j], pois[j]);
    }
    fclose(users);


}

void oneTurn (struct player *me, struct player *you, struct ship *yourShips, int c){
    
    if (c == 0) {
        printf("%s's point: %d    %s's point: %d\n", me->name, me->points, you->name, you->points);
        printf("\n");
        printf("\n%s's sea:\n", me->name);
        enemyEzPrinter(me->ground);
        printf("\n%s's sea:\n", you->name);
        enemyEzPrinter(you->ground);
        printf("%s's turn:\n", me->name);
        int n = shot(you, yourShips);
        if (yourShips->next == NULL){
            return;
        }

        while (n != 0)  {
            me->points += n;
            system("cls");
            printf("%s's point: %d    %s's point: %d\n", me->name, me->points, you->name, you->points);
            printf("\n");
            printf("\n%s's sea:\n", me->name);
            enemyEzPrinter(me->ground);
            printf("\n%s's sea:\n", you->name);
            enemyEzPrinter(you->ground);
            printf("%s's prize:\n", me->name);
            n = shot(you, yourShips);
            if (yourShips->next == NULL){
                return;
            }
        }
    }

    if (c == 1) {
        printf("%s's point: %d    %s's point: %d\n", you->name, you->points, me->name, me->points);
        printf("\n");
        printf("\n%s's sea:\n", you->name);
        enemyEzPrinter(you->ground);
        printf("\n%s's sea:\n", me->name);
        enemyEzPrinter(me->ground);
        printf("%s's turn:\n", me->name);
        int n = shot(you, yourShips);
        if (yourShips->next == NULL){
            return;
        }

        while (n != 0)  {
            me->points += n;
            system("cls");
            printf("%s's point: %d    %s's point: %d\n", you->name, you->points, me->name, me->points);
            printf("\n");
            printf("\n%s's sea:\n", you->name);
            enemyEzPrinter(you->ground);
            printf("\n%s's sea:\n", me->name);
            enemyEzPrinter(me->ground);
            printf("%s's prize:\n", me->name);
            n = shot(you, yourShips);
            if (yourShips->next == NULL){
                return;
            }
        }
    }

    if (c == 2) {
        printf("%s's point: %d    %s's point: %d\n", me->name, me->points, you->name, you->points);
        printf("\n");
        printf("%s's sea:\n", me->name);
        myEZprinter(me->ground);
        printf("\n%s's sea:\n", you->name);
        enemyEzPrinter(you->ground);
        printf("%s's turn:\n", me->name);
        int n = shot(you, yourShips);
        if (yourShips->next == NULL){
            return;
        }

        while (n != 0)  {
            me->points += n;
            system("cls");
            printf("%s's point: %d    %s's point: %d\n", me->name, me->points, you->name, you->points);
            printf("\n");
            printf("%s's sea:\n", me->name);
            myEZprinter(me->ground);
            printf("\n%s's sea:\n", you->name);
            enemyEzPrinter(you->ground);
            printf("%s's prize:\n", me->name);
            n = shot(you, yourShips);
            if (yourShips->next == NULL){
                return;
            }
        }
    }

    if (c == 3)     {
        int n = randShot(you, yourShips);
        if (yourShips->next == NULL){
            return;
        }

        while (n != 0)  {
            me->points += n;
            n = randShot(you, yourShips);
            if (yourShips->next == NULL){
                return;
            }
        }
    }
}