#include <stdio.h>
#include <stdlib.h>

#define LOGIN_LENGTH        20
#define PASSWORD_LENGTH     32

void create_database(char login[], char password[])
{
    FILE* file;
    file = fopen("database.txt", "a");

    fputs("|", file);
    fputs(login, file);
    fputs("\t\t|", file);
    fputs(password, file);
    fputs("\t\t\t\t|\n", file);

    fclose(file);
}

void sign_up()
{
    printf("\t\t\t\tSign Up\n");
   
    printf("\n\t\t\tLogin: ");
    char login[LOGIN_LENGTH];
    scanf("%s", login);

    printf("\n\t\t\tPassword: ");
    char password[PASSWORD_LENGTH];
    scanf("%s", password);

    create_database(login, password);

    printf("\n\t\tRegistration completed successfully!\n");
}

void sign_in()
{
    printf("\t\t\tSign In\n");
}

main()
{
    printf("What you need?\n1 - Sign Up\n2 - Sign In\n");
    int choice;
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        sign_up();
        break;
     case 2:
        sign_in();
        break;
    }

    return 0;
}
