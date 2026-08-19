#include <stdio.h>
#include <string.h>

typedef struct
{
    char user[100];
    char pass[100];
} Credentials;

Credentials log_data;

int Login(char user[], char pwd[], char credential[])
{
    FILE *login_f = fopen(credential, "r");
    if (!login_f)
    {
        printf("\n[Error] Could not open file: %s\n", credential);
        return 0;
    }

    char line[256];

    while (fgets(line, sizeof(line), login_f))
    {
        if (sscanf(line, "%[^.].%s", log_data.user, log_data.pass) == 2)
        {
            if (strcmp(user, log_data.user) == 0 && strcmp(pwd, log_data.pass) == 0)
            {
                fclose(login_f);
                return 1;
            }
        }
    }

    fclose(login_f);
    printf("\nWrong User Name or Password!\n");
    return 0;
}

int createLogin(char user[], char pwd[], char credential[])
{
    FILE *login_f = fopen(credential, "a");
    if (!login_f)
    {
        printf("\n[Error] Could not open file for writing: %s\n", credential);
        return 0;
    }

    fprintf(login_f, "\n%s.%s", user, pwd);
    fclose(login_f);
    return 1;
}
