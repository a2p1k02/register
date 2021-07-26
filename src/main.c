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

main()
{
    sign_up();
    return 0;
}
