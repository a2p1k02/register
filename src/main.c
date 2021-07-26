#include <stdio.h>
#include <stdlib.h>
#include <editline/readline.h>

#define LOGIN_LENGTH        20
#define PASSWORD_LENGTH     32

void create_database(char* login, char* password)
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
    printf("\nSign Up\n\n");

    char* login = readline("Login: ");
    add_history(login);

    printf("\n");

    char* password = readline("Password: ");
    add_history(password);

    create_database(login, password);

    printf("\nRegistration completed successfully!\n");

    free(login);
    free(password);
}

void sign_in()
{
    printf("\t\t\tSign In\n");
}

main()
{
    printf("What you need?\n1 - Sign Up\n2 - Sign In\n");
    int choice;
    printf("> ");
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
