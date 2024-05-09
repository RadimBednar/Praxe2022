#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));
    char text[101], sifrovani;
    printf("Zadejte text, ktery chcete zasifrovat: ");
    gets(text);
    do
    {
        printf("1.Caesarova sifra.\n");
        printf("2.Vigenerova sifra.\n");
        printf("3.Vernamova sifra.\n");
        printf("Zadejte styl sifrovani: ");
        scanf(" %c", &sifrovani);
        switch(sifrovani)
        {
            case '1': //Caesarova sifra
            {
                int posun, i;
                printf("Zadej posun: ");
                scanf("%d", &posun);
                strupr(text);
                printf("Text pred sifrovanim: %s\n", text);
                for(i = 0; text[i] != '\0'; i++)
                {
                    if(text[i] == ' ')
                    {
                        printf(" ");
                        continue;
                    }
                    text[i] += posun;
                    text[i] = (text[i] - 13) % 26 + 'A';
                }
                printf("\nText po sifrovani: %s", text);
                break;
            }
            case '2': //Vigenerova sifra
            {
                break;
            }
            case '3': //Vernamova sifra
            {
                int posun, i;
                strupr(text);
                printf("Text pred sifrovanim: %s\n", text);
                printf("Posun jednotlivych pismen v ASCII tabulce:\n");
                for(i = 0; text[i] != '\0'; i++)
                {
                    if(text[i] == ' ')
                    {
                        printf(" ");
                        continue;
                    }
                    posun = rand() % 26 + 1;
                    printf("%c o %d, ", text[i], posun);
                    text[i] += posun;
                    text[i] = (text[i] - 13) % 26 + 'A';
                }
                printf("\nText po sifrovani: %s", text);
                break;
            }
        }
    }while(sifrovani != '1' && sifrovani != '2' && sifrovani != '3');
    return 0;
}
