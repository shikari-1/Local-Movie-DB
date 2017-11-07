#include <stdio.h>
#include <stdlib.h>
#include"functions.h"
#include<string.h>

void Choice(int choose)
{
    if (choose==1)
    {
        read();
        main();
    }
    else if (choose==2)
    {
        write();
        main();
    }
    else if (choose==3)
    {
        printf("\nCurrently supports genre search only\n");
        printf("\nEnter upto three genres to match:\nEg- Adventure Action Fantasy\n");
        genre();
        main();
    }
}

int main()
{
    int choose;
    printf("\nChoose-\n");
    printf("1. View Db\n");
    printf("2. Add new movie\n3. Query\n4. Exit\n");
    scanf("%d",&choose);
    Choice(choose);
}
