#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#define CLEAR "cls"
#define SLEEP(x) Sleep((x) * 1000)
#else
#include <unistd.h>
#define CLEAR "clear"
#define SLEEP(x) sleep(x)
#endif

int main() {
    char name[100];
    char date[20];
    int i;

    printf("[Please enter the current date in \"yyyy-mm-dd\" format]: ");
    scanf("%19s", date);

    printf("[Please enter your name]: ");
    scanf(" %[^\n]%*c", name);

    printf("**The input has been processed successfully.**\n");

    SLEEP(3);

    system(CLEAR);

    for (i = 0; i < 101; i++) printf("+");
    printf("\n");

    for (i = 1; i <= 5; i++) {
        int j;
        for (j = 0; j < i; j++) printf("*");

        if (i == 2)
            printf("                                        [Magrathea ver 0.1]                               ");
        else if (i == 3)
            printf("                   Magrathea, where a shining planet is created in a wasteland with no grass,         ");
        else if (i == 4)
            printf("           a place where unseen potential is discovered and gems are polished by the hands of experts,    ");
        else if (i == 5)
            printf("                                        Welcome to Magrathea.                                           ");
        else
            printf("                                                                                                       ");

        for (j = 5; j >= i; j--) printf("*");
        printf("\n");
    }


    for (i = 0; i < 101; i++) printf("+");
    printf("\n");


    printf("[User]: %s                                   [Execution Time]: %s\n", name, date);
    

    for (i = 0; i < 101; i++) printf("=");
    printf("\n");

    return 0;
}
