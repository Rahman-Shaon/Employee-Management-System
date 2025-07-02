#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

struct login
{
    char username[32];
    char password[32];
};

void login()
{
    int found = 0;
    char username[32];
    char password[32];

    struct login l;
    FILE *ptr;

    ptr = fopen("login.txt", "rb");

    if (ptr == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    while (found < 1)
    {
        printf("Enter your username : ");
        fgets(username, sizeof(username), stdin);
        printf("Enter your password : ");
        fgets(password, sizeof(password), stdin);

        username[strcspn(username, "\n")] = 0;
        password[strcspn(password, "\n")] = 0;

        // rewind(ptr);

        while (fread(&l, sizeof(l), 1, ptr))
        {
            if (strcmp(username, l.username) == 0 && strcmp(password, l.password) == 0)
            {
                found = 1;
                printf("loging successful");
                break;
            }
        }
        if (!found)
        {
            printf("Wrong Password or username\nTry Again\n");
        }
    }

    fclose(ptr);
    printf("Press any key to continue");
    getch();
    system("cls");
}

void regist()
{
    FILE *ptr;
    ptr = fopen("login.txt", "ab+");

    if (ptr == NULL)
    {
        printf("Error opening file\n");
        return;
    }

    struct login l;

    printf("Enter your username : ");
    fgets(l.username, 32, stdin);
    printf("Enter your password : ");
    fgets(l.password, 32, stdin);

    l.username[strcspn(l.username, "\n")] = 0;
    l.password[strcspn(l.password, "\n")] = 0;

    fwrite(&l, sizeof(l), 1, ptr);
    fclose(ptr);

    printf("Congratulation Registration Successfull!!\n\n\n\n\n\n\n");
    printf("Press any key to continue");
    getch();
    system("cls");
    login();
}

int main()
{
    int choose;

    printf("\t\t\t\tWellcome to Employee management System\n");

    while (1)
    {
        printf("Choose any option for login or Registration\n");
        printf("1. Login\n2. Registration\n3. Exit\n");

        scanf("%d", &choose);
        getchar();
        if (choose == 1)
            login();
        else if (choose == 2)
            regist();
        else if (choose == 3)
            break;
    }

    return 0;
}