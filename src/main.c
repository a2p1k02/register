#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <editline/readline.h>

#define BUFF_SIZE 1024

typedef enum {
    false = 0,
    true = 1,
}bool;

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

bool check_login(char* login)
{
    FILE* file;
    file = fopen("database.txt", "r");

    size_t login_length = strlen(login);
    char* c_index;
    char login_exist[login_length];
    
    bool login_checked;

    char c[BUFF_SIZE];

    while (fgets(c, BUFF_SIZE, file) != NULL)
        c_index = strstr(c, login);
    
    for (int i = 0; i < login_length; i++) 
        login_exist[i] = c_index[i];
    
    if (strcmp(login_exist, login) == 0)
        login_checked = true;
    else
        login_checked = false;

    return login_checked;

}

void sign_up()
{
    printf("\nSign Up\n\n");

    char* login = readline("Login: ");
    add_history(login);

    printf("\n");

    char* password = readline("Password: ");
    add_history(password);

    if (check_login(login) == true) {
        printf("\nRegistration not completed!\nLogin already exists!\n");
    } else {
        create_database(login, password);
        printf("\nRegistration completed successfully!\n");
    }

    free(login);
    free(password);
}

int main()
{
    sign_up();
    //printf("%d", check_login("a2p1k03"));
    return 0;
}
