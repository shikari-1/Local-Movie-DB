#include<stdio.h>
#include<stdlib.h>
#include"functions.h"
#include<string.h>

void write(void)
{
    if(!Auth())
    {
        printf("\nDenied\n");                   //pass=harambe
        return;
    }
    printf("\nAuthenticated\n");
    FILE *f1;
    f1=fopen("test.dat","ab");
    getchar();
    printf("\nMovie name:\n");
    scanf("%99[^\n]",movie.name);
    getchar();
    printf("\nYear released:\n");
    scanf("%d",&movie.year);
    getchar();
    printf("\nEnter 1st genre:\n");
    scanf("%s",movie.genre1);
    getchar();
    printf("\nEnter 2nd genre:\n");
    scanf("%s",movie.genre2);
    getchar();
    printf("\nIf there is no 3rd genre enter 'none'. Otherwise, enter 3rd genre:\n");
    scanf("%s",movie.genre3);
    getchar();
    printf("\nEnter censor rating:\n");
    scanf("%s",movie.rating);
    getchar();
    printf("\nEnter movie runtime in minutes:\n");
    scanf("%d",&movie.runtime);
    getchar();
    printf("\nEnter IMDb score:\n");
    scanf("%f",&movie.IMDb);
    getchar();
    printf("\nEnter Metascore:\n");
    scanf("%d",&movie.Meta);
    getchar();
    printf("\nEnter Rotten Tomatoes score:\n");
    scanf("%d",&movie.RT);
    getchar();
    printf("\nChoose\n1. Confirm entry\n");
    printf("2. Cancel\n");
    int choose;
    scanf("%d",&choose);
    if(choose==2)
        return;
    fwrite(&movie,sizeof(DB),1,f1);
    printf("\nRecord added successfully!\n");
    fclose(f1);
}

void print(void)
{
    printf("\nMovie:      %s\nYear:       %d\nGenre:      %s, %s",movie.name,movie.year,movie.genre1,movie.genre2);
    if (strcmp(movie.genre3,"none")!=0)
        printf(", %s\n",movie.genre3);
    else
        printf("\n");
    printf("Rating:     %s\nRuntime:    %d minutes\nIMDb:       %0.1f\nMetacritic: %d\nRottenT:    %d \n",movie.rating,movie.runtime,movie.IMDb,movie.Meta,movie.RT);
}

void read(void)
{
    FILE *f1;
    f1=fopen("test.dat","rb");
    int pcount=0;
    while (fread(&movie,sizeof(DB),1,f1)!=NULL)
    {
        print();
        pcount++;
    }
    printf("\nRecords: %d\n",pcount);
    fclose(f1);
}

void genre(void)
{
    char genres[60],genre1[20],genre2[20],genre3[20];
    getchar();
    scanf("%99[^\n]",genres);
    int i,spacec=0,space[4];
    for (i=0;i<strlen(genres);i++)
    {
        if (genres[i]==' ')
        {
            spacec++;
            space[spacec-1]=i;
        }
    }
    if(spacec>2)
    {
        printf("\nIncorrect syntax\n");
        return;
    }
    FILE *f1;
    f1=fopen("test.dat","rb");
    int pcount=0;
    int genrecount=spacec+1;
    printf("\nSearching for genre: %s\n",genres);
    if (genrecount==1)
    {
         strcpy(genre1,genres);
         while (fread(&movie,sizeof(DB),1,f1)!=NULL)
         {
            if(counting(genre1))
            {
                print();
                pcount++;
            }
         }
    }
    else if (genrecount==2)
    {
        strncpy(genre1,genres,space[0]);
        genre1[space[0]]='\0';
        strncpy(genre2,genres+space[0]+1,strlen(genres)-space[0]-1);
        genre2[strlen(genres)-space[0]-1]='\0';
        while (fread(&movie,sizeof(DB),1,f1)!=NULL)
         {
            if(counting(genre1)*counting(genre2))
            {
                print();
                pcount++;
            }
         }
    }
    else
    {
        strncpy(genre1,genres,space[0]);
        genre1[space[0]]='\0';
        strncpy(genre2,genres+space[0]+1,space[1]-space[0]-1);
        genre2[space[1]-space[0]-1]='\0';
        strncpy(genre3,genres+space[1]+1,strlen(genres)-space[1]-1);
        genre3[strlen(genres)-space[1]-1]='\0';
        while (fread(&movie,sizeof(DB),1,f1)!=NULL)
        {
            if(counting(genre1)*counting(genre2)*counting(genre3))
            {
                print();
                pcount++;
            }
        }
    }
    printf("\nRecords: %d\n",pcount);
    fclose(f1);
}

int counting(char genre[])
{
    int counter=0;
    if(strcmp(genre,movie.genre1)==0)
        counter++;
    else if(strcmp(genre,movie.genre2)==0)
        counter++;
    else if(strcmp(genre,movie.genre3)==0)
        counter++;
    return counter;
}

int Auth(void)
{
    printf("\nPassword:\n");
    char pass[10];
    scanf("%s",pass);
    if(strcmp(pass,"harambe")==0)
        return 1;
    else
        return 0;
}
