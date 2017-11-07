typedef struct db
{
    char name[50];
    int year;
    char genre1[20];
    char genre2[20];
    char genre3[20];
    char rating[10];
    int runtime;
    float IMDb;
    int Meta;
    int RT;
}DB;

DB movie;

void write(void);

void read(void);

void genre(void);

int counting(char genre[]);

int Auth(void);
