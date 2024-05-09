#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main()
{
    int i, delkaHesla, volba;
    char heslo[delkaHesla], odpoved;
    srand(time(NULL));

    do {

    printf("Zadejte delku hesla: ");
    scanf("%d",&delkaHesla);

    printf("Jestli chcete v hesle cisla, zadejte '1'\n");
    printf("Jestli chcete v hesle velke a male pismena, zadejte '2'\n");
    printf("Jestli chcete v hesle specialni znaky, zadejte '3'\n");
    printf("Jestli chcete v hesle cisla a velke a male pismena, zadejte '4'\n");
    printf("Jestli chcete v hesle cisla a specialni znaky, zadejte '5'\n");
    printf("Jestli chcete v hesle velke a male pismena a specialni znaky, zadejte '6'\n");
    printf("Jestli chcete v hesle vsechny 3 veci, zadejte '7'\n");
    printf("Zadejte volbu: ");
    scanf("%d", &volba);

    switch (volba) {
        case 1:
            for (i = 0; i < delkaHesla; i++) {
                heslo[i] = rand() % (57 - 48 + 1) + 48;
            }
            heslo[i] = '\0';
            printf("Vygenerovane heslo: %s", heslo);
            break;
        case 2:
            for (i = 0; i < delkaHesla; i++) {
                if (rand() % 2) {
                    heslo[i] = rand() % (90 - 65 + 1) + 65;
                } else {
                    heslo[i] = rand() % (122 - 97 + 1) + 97;
                }
            }
            heslo[i] = '\0';
            printf("Vygenerovane heslo: %s", heslo);
            break;
        case 3:
            for (i = 0; i < delkaHesla; i++) {
                if (rand() % 4 == 1) {
                    heslo[i] = rand() % (47 - 33 + 1) + 33;
                } else if (rand() % 4 == 2) {
                    heslo[i] = rand() % (64 - 58 + 1) + 58;
                } else if (rand() % 4 == 3) {
                    heslo[i] = rand() % (96 - 91 + 1) + 91;
                } else {
                    heslo[i] = rand() % (126 - 123 + 1) + 123;
                }
            }
            heslo[i] = '\0';
            printf("Vygenerovane heslo: %s", heslo);
            break;
        case 4:
            for (i = 0; i < delkaHesla; i++)
            {
                if(rand() % 3 == 1)
                {
                    heslo[i] = rand() % (90 - 65 + 1) + 65;
                }
                else if(rand() % 3 == 2)
                {
                    heslo[i] = rand() % (122 - 97 + 1) + 97;
                }
                else
                {
                    heslo[i] = rand() % (57 - 48 + 1) + 48;
                }
            }
            heslo[i] = '\0';
            printf("Vygenerovane heslo: %s", heslo);
            break;
        case 5:
            for (i = 0; i < delkaHesla; i++)
            {
                if (rand() % 5 == 1) {
                    heslo[i] = rand() % (47 - 33 + 1) + 33;
                } else if (rand() % 5 == 2) {
                    heslo[i] = rand() % (64 - 58 + 1) + 58;
                } else if (rand() % 5 == 3) {
                    heslo[i] = rand() % (96 - 91 + 1) + 91;
                } else if (rand() % 5 == 4){
                    heslo[i] = rand() % (126 - 123 + 1) + 123;
                }
                else{
                    heslo[i] = rand() % (57 - 48 + 1) + 48;
                }
            }
            heslo[i] = '\0';
            printf("Vygenerovane heslo: %s", heslo);
            break;
        case 6:
            for (i = 0; i < delkaHesla; i++)
            {
                if(rand() % 2)
                {
                    heslo[i] = rand() % (47 - 33 + 1) + 33;
                }
                else
                {
                    heslo[i] = rand() % (126 - 58 + 1) + 58;
                }
            }
            heslo[i] = '\0';
            printf("Vygenerovane heslo: %s", heslo);
            break;
        case 7:
            for(i=0; i < delkaHesla; i++)
            {
                heslo[i] = rand() % (126 - 33 + 1) + 33;
            }
            heslo[i] = '\0';
            printf("Vygenerovane heslo: %s", heslo);
            break;
    }
        printf("\nJestli chcete vygenerovat nove heslo, napiste 'a'\n");
        scanf(" %c", &odpoved);
    }while(odpoved == 'a');

    return 0;
}