#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>

int otazky(int otazka, int *padesat_na_padesat, int *pritel_na_telefonu, int *pomoc_z_publika);
int vyhra(int spravne_odpovedi);
void napovedy(int *padesat_na_padesat, int *pritel_na_telefonu, int *pomoc_z_publika);

int main()
{
    srand(time(NULL));
    int padesat_na_padesat = 0, pritel_na_telefonu = 0, pomoc_z_publika = 0;
    int i, x, spravne_odpovedi = 0, duplikat, otazka = 0, pocet_otazek = 0, pole[15], zapsano, zachytnyBod = 0;
    char volba, odpoved, pokracovani;

    do
    {
        for(i = 0; i < 16; i++)
        {
            otazka = rand() % 15 + 1;
            for (x = 0; x < i; x++)
            {
                duplikat = 0;
                if(i==0)
                {
                    if(otazky(otazka, &padesat_na_padesat, &pritel_na_telefonu, &pomoc_z_publika))
                    {
                        spravne_odpovedi++;
                        if(vyhra(spravne_odpovedi))
                        {
                            printf("Nova hra? Pokud ano zadej 'a': ");
                            scanf(" %c", &volba);
                            spravne_odpovedi = 0;
                            if(volba == 'a' || volba == 'A')
                            {
                                printf("Nova hra:\n");
                            }
                            else
                            {
                                printf("Konec hry.\n");
                                break;
                            }
                        }
                        pole[i] = otazka;
                        break;
                    }
                    else
                    {
                        printf("Konec hry.\n");
                        break;
                    }
                }
                if (pole[x] == otazka)
                {
                    otazka = rand() % 15 + 1;
                    x=0;
                    duplikat = 1;
                }
            }
            if(duplikat == 0)
            {
                if(otazky(otazka, &padesat_na_padesat, &pritel_na_telefonu, &pomoc_z_publika))
                {
                    spravne_odpovedi++;
                    if(vyhra(spravne_odpovedi))
                    {
                        printf("Nova hra? Pokud ano zadej 'a': ");
                        scanf(" %c", &volba);
                        spravne_odpovedi = 0;
                        if(volba == 'a' || volba == 'A')
                        {
                            printf("Nova hra:\n");
                        }
                        else
                        {
                            printf("Konec hry.\n");
                            break;
                        }
                    }
                    pole[i] = otazka;
                }
                else
                {
                    if(spravne_odpovedi >= 5 && spravne_odpovedi <= 9)
                        zachytnyBod = 1;
                    if(spravne_odpovedi >= 10)
                        zachytnyBod = 2;

                    if(zachytnyBod == 1)
                    {
                        printf("Ze zachytneho bodu vyhravate 1000kc.\n");
                    }
                    if(zachytnyBod == 2)
                    {
                        printf("Ze zachytneho bodu vyhravate 32000kc.\n");
                    }
                    printf("Konec teto hry.\n");
                    printf("Nova hra? Pokud ano zadej 'a': ");
                    scanf(" %c", &volba);
                    zachytnyBod = 0;
                    spravne_odpovedi = 0;
                    if(volba == 'a' || volba == 'A')
                    {
                        printf("Nova hra:\n");
                    }
                    else
                    {
                        printf("Konec hry.\n");
                        break;
                    }
                }
            }
        }
    }while(volba == 'a' || volba == 'A');
    return 0;
}

int otazky(int otazka, int *padesat_na_padesat, int *pritel_na_telefonu, int *pomoc_z_publika)
{
    char odpoved, napoveda, napoveda2_rand;
    int a, b, c, d;
    switch(otazka)
    {
        case 1: //otazka 1
        {
            char spravna_odpoved = 'a', spatna_odpoved1 = 'b', spatna_odpoved2 = 'c', spatna_odpoved3 = 'd', napoveda_rand;
            int i;
            printf("Co znamena Tieto v cestine?\n");
            printf("A)Informace B)Mokry pes C)Kolektiv D)Informatika\n");
            napovedy(padesat_na_padesat, pritel_na_telefonu, pomoc_z_publika);
            scanf(" %c", &napoveda);
            if(napoveda == 'N')
            {
                napoveda = 'n';
            }
            switch(napoveda) //vyber napovedy
            {
                case '1': //50:50
                {
                    (*padesat_na_padesat)++;
                    napoveda_rand = rand() % (3 - 1 + 1) + 1; //generace odpovedi 50:50
                    switch(napoveda_rand) //odpovedi 50:50
                    {
                        case 1:
                        {
                            printf("Vase moznosti jsou '%c' a '%c'.\n", spravna_odpoved, spatna_odpoved1);
                            printf("Zadejte vasi odpoved: ");
                            scanf(" %c", &odpoved);
                            if(odpoved == 'a' || odpoved == 'A')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                        }

                        case 2:
                        {
                            printf("Vase moznosti jsou '%c' a '%c'.\n", spravna_odpoved, spatna_odpoved2);
                            printf("Zadejte vasi odpoved: ");
                            scanf(" %c", &odpoved);
                            if(odpoved == 'a' || odpoved == 'A')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                        }

                        case 3:
                        {
                            printf("Vase moznosti jsou '%c' a '%c'.\n", spravna_odpoved, spatna_odpoved3);
                            printf("Zadejte vasi odpoved: ");
                            scanf(" %c", &odpoved);
                            if(odpoved == 'a' || odpoved == 'A')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                            break;
                        }
                    }
                    case '2': //Pomoc od kamarada
                    {
                        (*pritel_na_telefonu)++;
                        printf("Kamarad: Ahoj.\n");
                        printf("Ja: Ahoj, jsem ve hre milionar a nevim si rady s otazkou: Co znamena Tieto v cestine?\n");
                        printf("Moznosti jsou: A)Informace B)Mokry pes C)Kolektiv D)Informatika.\n");

                        napoveda2_rand = rand() % 3 + 1; //generace odpovedi kamarada

                        switch (napoveda2_rand) //Odpoved kamarada
                        {
                            case 1:
                            {
                                printf("To vim, je to za '%c'.\n", spravna_odpoved);
                                printf("Zadejte odpoved: ");
                                scanf(" %c", &odpoved);
                                if(odpoved == 'a' || odpoved == 'A')
                                {
                                    printf("Spravna odpoved!\n");
                                    return 1;
                                }
                                else
                                {
                                    printf("Spatna odpoved!\n");
                                    return 0;
                                }
                            }

                            case 2:
                            {
                                printf("Hmm, rekl bych ze to je bud '%c' nebo '%c'.\n", spravna_odpoved, spatna_odpoved2);
                                printf("Zadejte odpoved: ");
                                scanf(" %c", &odpoved);
                                if(odpoved == 'a' || odpoved == 'A')
                                {
                                    printf("Spravna odpoved!\n");
                                    return 1;
                                }
                                else
                                {
                                    printf("Spatna odpoved!\n");
                                    return 0;
                                }
                            }

                            case 3:
                            {
                                printf("Promin, ale nemam tuseni.\n");
                                printf("Zadejte odpoved: ");
                                scanf(" %c", &odpoved);
                                if(odpoved == 'a' || odpoved == 'A')
                                {
                                    printf("Spravna odpoved!\n");
                                    return 1;
                                }
                                else
                                {
                                    printf("Spatna odpoved!\n");
                                    return 0;
                                }
                            }
                        }
                        break;
                    }
                    case '3': //Pomoc z publika
                    {
                        (*pomoc_z_publika)++;
                        {
                            a = (rand() % (76 - 1 + 1)) + 25;
                            b = rand() % ((101-a) - 1 + 1);
                            c = rand() % ((101-a-b) - 1 + 1);
                            d = 100-a-b-c;

                            printf("A: %d%% B: %d%% C: %d%% D: %d%%", a, b, c, d);

                            printf("\nZadejte odpoved: ");
                            scanf(" %c", &odpoved);
                            if (odpoved == 'a' || odpoved == 'A')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                        }
                    }
                    case 'n': //bez napovedy
                    {
                        printf("\nZadejte odpoved: ");
                        scanf(" %c", &odpoved);
                        if (odpoved == 'a' || odpoved == 'A')
                        {
                            printf("Spravna odpoved!\n");
                            return 1;
                        }
                        else
                        {
                            printf("Spatna odpoved!\n");
                            return 0;
                        }
                        break;
                    }
                    default:
                    {
                        printf("Zadali jste spatny znak.\n");
                        return 0;
                    }
                }
            }
        }
        case 2: //otazka 2
        {
            char spravna_odpoved = 'c', spatna_odpoved1 = 'a', spatna_odpoved2 = 'b', spatna_odpoved3 = 'd', napoveda_rand;
            int i;
            printf("Kde NESIDLI firma tieto?\n");
            printf("A)Ostrava B)Brno C)Praha D)Zlin\n");
            napovedy(padesat_na_padesat, pritel_na_telefonu, pomoc_z_publika);
            scanf(" %c", &napoveda);
            if(napoveda == 'N')
            {
                napoveda = 'n';
            }
            switch(napoveda) //vyber napovedy
            {
                case '1': //50:50
                {
                    (*padesat_na_padesat)++;
                    napoveda_rand = rand() % (3 - 1 + 1) + 1; //generace odpovedi 50:50
                    switch (napoveda_rand) {
                        case 1:
                            printf("Vase moznosti jsou '%c' a '%c'.\n", spravna_odpoved, spatna_odpoved1);
                            printf("Zadejte vasi odpoved: ");
                            scanf(" %c", &odpoved);
                            if(odpoved == 'c' || odpoved == 'C')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                        case 2:
                            printf("Vase moznosti jsou '%c' a '%c'.\n", spravna_odpoved, spatna_odpoved2);
                            printf("Zadejte vasi odpoved: ");
                            scanf(" %c", &odpoved);
                            if(odpoved == 'c' || odpoved == 'C')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                        case 3:
                            printf("Vase moznosti jsou '%c' a '%c'.\n", spravna_odpoved, spatna_odpoved3);
                            printf("Zadejte vasi odpoved: ");
                            scanf(" %c", &odpoved);
                            if(odpoved == 'c' || odpoved == 'C')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                            break;
                    }
                    case '2': //Pomoc od kamarada
                    {
                        (*pritel_na_telefonu)++;
                        printf("Kamarad: Ahoj.\n");
                        printf("Ja: Ahoj, jsem ve hre milionar a nevim si rady s otazkou: Kde NESIDLI firma tieto?\n");
                        printf("Moznosti jsou: A)Ostrava B)Brno C)Praha D)Zlin.\n");

                        napoveda2_rand = rand() % 3 + 1; //generace odpovedi kamarada
                        switch (napoveda2_rand) //Odpoved kamarada
                        {
                            case 1:
                            {
                                printf("To vim, je to za '%c'.\n", spravna_odpoved);
                                printf("Zadejte odpoved: ");
                                scanf(" %c", &odpoved);
                                if(odpoved == 'c' || odpoved == 'C')
                                {
                                    printf("Spravna odpoved!\n");
                                    return 1;
                                }
                                else
                                {
                                    printf("Spatna odpoved!\n");
                                    return 0;
                                }
                            }

                            case 2:
                            {
                                printf("Hmm, rekl bych ze to je bud '%c' nebo '%c'.\n", spravna_odpoved, spatna_odpoved2);
                                printf("Zadejte odpoved: ");
                                scanf(" %c", &odpoved);
                                if(odpoved == 'c' || odpoved == 'C')
                                {
                                    printf("Spravna odpoved!\n");
                                    return 1;
                                }
                                else
                                {
                                    printf("Spatna odpoved!\n");
                                    return 0;
                                }
                            }

                            case 3:
                            {
                                printf("Promin, ale nemam tuseni.\n");
                                printf("Zadejte odpoved: ");
                                scanf(" %c", &odpoved);
                                if(odpoved == 'c' || odpoved == 'C')
                                {
                                    printf("Spravna odpoved!\n");
                                    return 1;
                                }
                                else
                                {
                                    printf("Spatna odpoved!\n");
                                    return 0;
                                }
                            }
                        }
                        break;
                    }
                    case '3': //Pomoc z publika
                    {
                        (*pomoc_z_publika)++;
                        c = (rand() % (76 - 1 + 1)) + 25;
                        a = rand() % ((101-c) - 1 + 1);
                        b = rand() % ((101-a-c) - 1 + 1);
                        d = 100-a-b-c;

                        printf("A: %d%% B: %d%% C: %d%% D: %d%%", a, b, c, d);

                        printf("\nZadejte odpoved: ");
                        scanf(" %c", &odpoved);
                        if (odpoved == 'c' || odpoved == 'C')
                        {
                            printf("Spravna odpoved!\n");
                            return 1;
                        }
                        else
                        {
                            printf("Spatna odpoved!\n");
                            return 0;
                        }
                    }
                    case 'n': //bez napovedy
                    {
                        printf("\nZadejte odpoved: ");
                        scanf(" %c", &odpoved);
                        if (odpoved == 'c' || odpoved == 'C')
                        {
                            printf("Spravna odpoved!\n");
                            return 1;
                        }
                        else
                        {
                            printf("Spatna odpoved!\n");
                            return 0;
                        }
                        break;
                    }
                    default:
                    {
                        printf("Zadali jste spatny znak.\n");
                        return 0;
                    }
                }
            }
        }
        case 3: //otazka 3
        {
            char spravna_odpoved = 'c', spatna_odpoved1 = 'a', spatna_odpoved2 = 'b', spatna_odpoved3 = 'd', napoveda_rand;
            int i;
            printf("Co nepatri mezi programovaci jazyky?\n");
            printf("A)C# B)C++ C)C- D)PHP\n");
            napovedy(padesat_na_padesat, pritel_na_telefonu, pomoc_z_publika);
            scanf(" %c", &napoveda);
            if(napoveda == 'N')
            {
                napoveda = 'n';
            }
            switch(napoveda) //vyber napovedy
            {
                case '1': //50:50
                {
                    (*padesat_na_padesat)++;
                    napoveda_rand = rand() % (3 - 1 + 1) + 1; //generace odpovedi 50:50
                    switch (napoveda_rand) {
                        case 1:
                            printf("Vase moznosti jsou '%c' a '%c'.\n", spravna_odpoved, spatna_odpoved1);
                            printf("Zadejte vasi odpoved: ");
                            scanf(" %c", &odpoved);
                            if(odpoved == 'c' || odpoved == 'C')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                        case 2:
                            printf("Vase moznosti jsou '%c' a '%c'.\n", spravna_odpoved, spatna_odpoved2);
                            printf("Zadejte vasi odpoved: ");
                            scanf(" %c", &odpoved);
                            if(odpoved == 'c' || odpoved == 'C')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                        case 3:
                            printf("Vase moznosti jsou '%c' a '%c'.\n", spravna_odpoved, spatna_odpoved3);
                            printf("Zadejte vasi odpoved: ");
                            scanf(" %c", &odpoved);
                            if(odpoved == 'c' || odpoved == 'C')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                            break;
                    }
                    case '2': //Pomoc od kamarada
                    {
                        (*pritel_na_telefonu)++;
                        printf("Kamarad: Ahoj.\n");
                        printf("Ja: Ahoj, jsem ve hre milionar a nevim si rady s otazkou: Co nepatri mezi programovaci jazyky?\n");
                        printf("Moznosti jsou: A)C# B)C++ C)C- D)PHP.\n");

                        napoveda2_rand = rand() % 3 + 1; //generace odpovedi kamarada
                        switch (napoveda2_rand) //Odpoved kamarada
                        {
                            case 1:
                            {
                                printf("To vim, je to za '%c'.\n", spravna_odpoved);
                                printf("Zadejte odpoved: ");
                                scanf(" %c", &odpoved);
                                if(odpoved == 'c' || odpoved == 'C')
                                {
                                    printf("Spravna odpoved!\n");
                                    return 1;
                                }
                                else
                                {
                                    printf("Spatna odpoved!\n");
                                    return 0;
                                }
                            }

                            case 2:
                            {
                                printf("Hmm, rekl bych ze to je bud '%c' nebo '%c'.\n", spravna_odpoved, spatna_odpoved2);
                                printf("Zadejte odpoved: ");
                                scanf(" %c", &odpoved);
                                if(odpoved == 'c' || odpoved == 'C')
                                {
                                    printf("Spravna odpoved!\n");
                                    return 1;
                                }
                                else
                                {
                                    printf("Spatna odpoved!\n");
                                    return 0;
                                }
                            }

                            case 3:
                            {
                                printf("Promin, ale nemam tuseni.\n");
                                printf("Zadejte odpoved: ");
                                scanf(" %c", &odpoved);
                                if(odpoved == 'c' || odpoved == 'C')
                                {
                                    printf("Spravna odpoved!\n");
                                    return 1;
                                }
                                else
                                {
                                    printf("Spatna odpoved!\n");
                                    return 0;
                                }
                            }
                        }
                        break;
                    }
                    case '3': //Pomoc z publika
                    {
                        (*pomoc_z_publika)++;
                        c = (rand() % (76 - 1 + 1)) + 25;
                        a = rand() % ((101-c) - 1 + 1);
                        b = rand() % ((101-a-c) - 1 + 1);
                        d = 100-a-b-c;

                        printf("A: %d%% B: %d%% C: %d%% D: %d%%", a, b, c, d);

                        printf("\nZadejte odpoved: ");
                        scanf(" %c", &odpoved);
                        if (odpoved == 'c' || odpoved == 'C')
                        {
                            printf("Spravna odpoved!\n");
                            return 1;
                        }
                        else
                        {
                            printf("Spatna odpoved!\n");
                            return 0;
                        }
                    }
                    case 'n': //bez napovedy
                    {
                        printf("\nZadejte odpoved: ");
                        scanf(" %c", &odpoved);
                        if (odpoved == 'c' || odpoved == 'C')
                        {
                            printf("Spravna odpoved!\n");
                            return 1;
                        }
                        else
                        {
                            printf("Spatna odpoved!\n");
                            return 0;
                        }
                        break;
                    }
                    default:
                    {
                        printf("Zadali jste spatny znak.\n");
                        return 0;
                    }
                }
            }
        }
        case 4: //otazka 4
        {
            char spravna_odpoved = 'a', spatna_odpoved1 = 'b', spatna_odpoved2 = 'c', spatna_odpoved3 = 'd', napoveda_rand;
            int i;
            printf("Jak se v C# nazyva cyklus s podminkou na zacatku?\n");
            printf("A)While B)Do-While C)For D)Neni\n");
            napovedy(padesat_na_padesat, pritel_na_telefonu, pomoc_z_publika);
            scanf(" %c", &napoveda);
            if(napoveda == 'N')
            {
                napoveda = 'n';
            }
            switch(napoveda) //vyber napovedy
            {
                case '1': //50:50
                {
                    (*padesat_na_padesat)++;
                    napoveda_rand = rand() % (3 - 1 + 1) + 1; //generace odpovedi 50:50
                    switch (napoveda_rand) {
                        case 1:
                            printf("Vase moznosti jsou '%c' a '%c'.\n", spravna_odpoved, spatna_odpoved1);
                            printf("Zadejte vasi odpoved: ");
                            scanf(" %c", &odpoved);
                            if(odpoved == 'a' || odpoved == 'A')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                        case 2:
                            printf("Vase moznosti jsou '%c' a '%c'.\n", spravna_odpoved, spatna_odpoved2);
                            printf("Zadejte vasi odpoved: ");
                            scanf(" %c", &odpoved);
                            if(odpoved == 'a' || odpoved == 'A')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                        case 3:
                            printf("Vase moznosti jsou '%c' a '%c'.\n", spravna_odpoved, spatna_odpoved3);
                            printf("Zadejte vasi odpoved: ");
                            scanf(" %c", &odpoved);
                            if(odpoved == 'a' || odpoved == 'A')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                            break;
                    }
                    case '2': //Pomoc od kamarada
                    {
                        (*pritel_na_telefonu)++;
                        printf("Kamarad: Ahoj.\n");
                        printf("Ja: Ahoj, jsem ve hre milionar a nevim si rady s otazkou: Jak se v C# nazyva cyklus s podminkou na zacatku?\n");
                        printf("Moznosti jsou: A)While B)Do-While C)For D)Neni.\n");

                        napoveda2_rand = rand() % 3 + 1; //generace odpovedi kamarada
                        switch (napoveda2_rand) //Odpoved kamarada
                        {
                            case 1:
                            {
                                printf("To vim, je to za '%c'.\n", spravna_odpoved);
                                printf("Zadejte odpoved: ");
                                scanf(" %c", &odpoved);
                                if(odpoved == 'a' || odpoved == 'A')
                                {
                                    printf("Spravna odpoved!\n");
                                    return 1;
                                }
                                else
                                {
                                    printf("Spatna odpoved!\n");
                                    return 0;
                                }
                            }

                            case 2:
                            {
                                printf("Hmm, rekl bych ze to je bud '%c' nebo '%c'.\n", spravna_odpoved, spatna_odpoved2);
                                printf("Zadejte odpoved: ");
                                scanf(" %c", &odpoved);
                                if(odpoved == 'a' || odpoved == 'A')
                                {
                                    printf("Spravna odpoved!\n");
                                    return 1;
                                }
                                else
                                {
                                    printf("Spatna odpoved!\n");
                                    return 0;
                                }
                            }

                            case 3:
                            {
                                printf("Promin, ale nemam tuseni.\n");
                                printf("Zadejte odpoved: ");
                                scanf(" %c", &odpoved);
                                if(odpoved == 'a' || odpoved == 'A')
                                {
                                    printf("Spravna odpoved!\n");
                                    return 1;
                                }
                                else
                                {
                                    printf("Spatna odpoved!\n");
                                    return 0;
                                }
                            }
                        }
                        break;
                    }
                    case '3': //Pomoc z publika
                    {
                        (*pomoc_z_publika)++;
                        a = (rand() % (76 - 1 + 1)) + 25;
                        b = rand() % ((101-a) - 1 + 1);
                        c = rand() % ((101-a-b) - 1 + 1);
                        d = 100-a-b-c;

                        printf("A: %d%% B: %d%% C: %d%% D: %d%%", a, b, c, d);

                        printf("\nZadejte odpoved: ");
                        scanf(" %c", &odpoved);
                        if (odpoved == 'a' || odpoved == 'A')
                        {
                            printf("Spravna odpoved!\n");
                            return 1;
                        }
                        else
                        {
                            printf("Spatna odpoved!\n");
                            return 0;
                        }
                    }
                    case 'n': //bez napovedy
                    {
                        printf("\nZadejte odpoved: ");
                        scanf(" %c", &odpoved);
                        if (odpoved == 'a' || odpoved == 'A')
                        {
                            printf("Spravna odpoved!\n");
                            return 1;
                        }
                        else
                        {
                            printf("Spatna odpoved!\n");
                            return 0;
                        }
                        break;
                    }
                    default:
                    {
                        printf("Zadali jste spatny znak.\n");
                        return 0;
                    }
                }
            }
        }
        case 5: //otazka 5
        {
            char spravna_odpoved = 'd', spatna_odpoved1 = 'a', spatna_odpoved2 = 'b', spatna_odpoved3 = 'c', napoveda_rand;
            int i;
            printf("V jakem roce vznikl jazyk C#?\n");
            printf("A)1999 B)1975 C)1945 D)1972\n");
            napovedy(padesat_na_padesat, pritel_na_telefonu, pomoc_z_publika);
            scanf(" %c", &napoveda);
            if(napoveda == 'N')
            {
                napoveda = 'n';
            }
            switch(napoveda) //vyber napovedy
            {
                case '1': //50:50
                {
                    (*padesat_na_padesat)++;
                    napoveda_rand = rand() % (3 - 1 + 1) + 1; //generace odpovedi 50:50
                    switch (napoveda_rand) {
                        case 1:
                            printf("Vase moznosti jsou '%c' a '%c'.\n", spravna_odpoved, spatna_odpoved1);
                            printf("Zadejte vasi odpoved: ");
                            scanf(" %c", &odpoved);
                            if(odpoved == 'd' || odpoved == 'D')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                        case 2:
                            printf("Vase moznosti jsou '%c' a '%c'.\n", spravna_odpoved, spatna_odpoved2);
                            printf("Zadejte vasi odpoved: ");
                            scanf(" %c", &odpoved);
                            if(odpoved == 'd' || odpoved == 'D')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                        case 3:
                            printf("Vase moznosti jsou '%c' a '%c'.\n", spravna_odpoved, spatna_odpoved3);
                            printf("Zadejte vasi odpoved: ");
                            scanf(" %c", &odpoved);
                            if(odpoved == 'd' || odpoved == 'D')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                            break;
                    }
                    case '2': //Pomoc od kamarada
                    {
                        (*pritel_na_telefonu)++;
                        printf("Kamarad: Ahoj.\n");
                        printf("Ja: Ahoj, jsem ve hre milionar a nevim si rady s otazkou: V jakem roce vznikl jazyk C#?\n");
                        printf("Moznosti jsou: A)1999 B)1975 C)1945 D)1972.\n");

                        napoveda2_rand = rand() % 3 + 1; //generace odpovedi kamarada
                        switch (napoveda2_rand) //Odpoved kamarada
                        {
                            case 1:
                            {
                                printf("To vim, je to za '%c'.\n", spravna_odpoved);
                                printf("Zadejte odpoved: ");
                                scanf(" %c", &odpoved);
                                if(odpoved == 'd' || odpoved == 'D')
                                {
                                    printf("Spravna odpoved!\n");
                                    return 1;
                                }
                                else
                                {
                                    printf("Spatna odpoved!\n");
                                    return 0;
                                }
                            }

                            case 2:
                            {
                                printf("Hmm, rekl bych ze to je bud '%c' nebo '%c'.\n", spravna_odpoved, spatna_odpoved2);
                                printf("Zadejte odpoved: ");
                                scanf(" %c", &odpoved);
                                if(odpoved == 'd' || odpoved == 'D')
                                {
                                    printf("Spravna odpoved!\n");
                                    return 1;
                                }
                                else
                                {
                                    printf("Spatna odpoved!\n");
                                    return 0;
                                }
                            }

                            case 3:
                            {
                                printf("Promin, ale nemam tuseni.\n");
                                printf("Zadejte odpoved: ");
                                scanf(" %c", &odpoved);
                                if(odpoved == 'd' || odpoved == 'D')
                                {
                                    printf("Spravna odpoved!\n");
                                    return 1;
                                }
                                else
                                {
                                    printf("Spatna odpoved!\n");
                                    return 0;
                                }
                            }
                        }
                        break;
                    }
                    case '3': //Pomoc z publika
                    {
                        (*pomoc_z_publika)++;
                        d = (rand() % (76 - 1 + 1)) + 25;
                        a = rand() % ((101-d) - 1 + 1);
                        b = rand() % ((101-a-d) - 1 + 1);
                        c = 100-a-b-d;

                        printf("A: %d%% B: %d%% C: %d%% D: %d%%", a, b, c, d);

                        printf("\nZadejte odpoved: ");
                        scanf(" %c", &odpoved);
                        if (odpoved == 'd' || odpoved == 'D')
                        {
                            printf("Spravna odpoved!\n");
                            return 1;
                        }
                        else
                        {
                            printf("Spatna odpoved!\n");
                            return 0;
                        }
                    }
                    case 'n': //bez napovedy
                    {
                        printf("\nZadejte odpoved: ");
                        scanf(" %c", &odpoved);
                        if (odpoved == 'd' || odpoved == 'D')
                        {
                            printf("Spravna odpoved!\n");
                            return 1;
                        }
                        else
                        {
                            printf("Spatna odpoved!\n");
                            return 0;
                        }
                        break;
                    }
                    default:
                    {
                        printf("Zadali jste spatny znak.\n");
                        return 0;
                    }
                }
            }
        }
        case 6: //otazka 6
        {
            char spravna_odpoved = 'b', spatna_odpoved1 = 'a', spatna_odpoved2 = 'c', spatna_odpoved3 = 'd', napoveda_rand;
            int i;
            printf("Jaky je nejpouzivanejsi programovaci jazyk?\n");
            printf("A)C B)Java C)C++ D)SQL\n");
            napovedy(padesat_na_padesat, pritel_na_telefonu, pomoc_z_publika);
            scanf(" %c", &napoveda);
            if(napoveda == 'N')
            {
                napoveda = 'n';
            }
            switch(napoveda) //vyber napovedy
            {
                case '1': //50:50
                {
                    (*padesat_na_padesat)++;
                    napoveda_rand = rand() % (3 - 1 + 1) + 1; //generace odpovedi 50:50
                    switch (napoveda_rand) {
                        case 1:
                            printf("Vase moznosti jsou '%c' a '%c'.\n", spravna_odpoved, spatna_odpoved1);
                            printf("Zadejte vasi odpoved: ");
                            scanf(" %c", &odpoved);
                            if(odpoved == 'b' || odpoved == 'B')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                        case 2:
                            printf("Vase moznosti jsou '%c' a '%c'.\n", spravna_odpoved, spatna_odpoved2);
                            printf("Zadejte vasi odpoved: ");
                            scanf(" %c", &odpoved);
                            if(odpoved == 'b' || odpoved == 'B')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                        case 3:
                            printf("Vase moznosti jsou '%c' a '%c'.\n", spravna_odpoved, spatna_odpoved3);
                            printf("Zadejte vasi odpoved: ");
                            scanf(" %c", &odpoved);
                            if(odpoved == 'b' || odpoved == 'B')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                            break;
                    }
                    case '2': //Pomoc od kamarada
                    {
                        (*pritel_na_telefonu)++;
                        printf("Kamarad: Ahoj.\n");
                        printf("Ja: Ahoj, jsem ve hre milionar a nevim si rady s otazkou: Jaky je nejpouzivanejsi programovaci jazyk?\n");
                        printf("Moznosti jsou: A)C B)Java C)C++ D)SQL.\n");

                        napoveda2_rand = rand() % 3 + 1; //generace odpovedi kamarada
                        switch (napoveda2_rand) //Odpoved kamarada
                        {
                            case 1:
                            {
                                printf("To vim, je to za '%c'.\n", spravna_odpoved);
                                printf("Zadejte odpoved: ");
                                scanf(" %c", &odpoved);
                                if(odpoved == 'b' || odpoved == 'B')
                                {
                                    printf("Spravna odpoved!\n");
                                    return 1;
                                }
                                else
                                {
                                    printf("Spatna odpoved!\n");
                                    return 0;
                                }
                            }

                            case 2:
                            {
                                printf("Hmm, rekl bych ze to je bud '%c' nebo '%c'.\n", spravna_odpoved, spatna_odpoved2);
                                printf("Zadejte odpoved: ");
                                scanf(" %c", &odpoved);
                                if(odpoved == 'b' || odpoved == 'B')
                                {
                                    printf("Spravna odpoved!\n");
                                    return 1;
                                }
                                else
                                {
                                    printf("Spatna odpoved!\n");
                                    return 0;
                                }
                            }

                            case 3:
                            {
                                printf("Promin, ale nemam tuseni.\n");
                                printf("Zadejte odpoved: ");
                                scanf(" %c", &odpoved);
                                if(odpoved == 'b' || odpoved == 'B')
                                {
                                    printf("Spravna odpoved!\n");
                                    return 1;
                                }
                                else
                                {
                                    printf("Spatna odpoved!\n");
                                    return 0;
                                }
                            }
                        }
                        break;
                    }
                    case '3': //Pomoc z publika
                    {
                        (*pomoc_z_publika)++;
                        b = (rand() % (76 - 1 + 1)) + 25;
                        a = rand() % ((101-b) - 1 + 1);
                        c = rand() % ((101-a-b) - 1 + 1);
                        d = 100-a-b-c;

                        printf("A: %d%% B: %d%% C: %d%% D: %d%%", a, b, c, d);

                        printf("\nZadejte odpoved: ");
                        scanf(" %c", &odpoved);
                        if (odpoved == 'b' || odpoved == 'B')
                        {
                            printf("Spravna odpoved!\n");
                            return 1;
                        }
                        else
                        {
                            printf("Spatna odpoved!\n");
                            return 0;
                        }
                    }
                    case 'n': //bez napovedy
                    {
                        printf("\nZadejte odpoved: ");
                        scanf(" %c", &odpoved);
                        if (odpoved == 'b' || odpoved == 'B')
                        {
                            printf("Spravna odpoved!\n");
                            return 1;
                        }
                        else
                        {
                            printf("Spatna odpoved!\n");
                            return 0;
                        }
                        break;
                    }
                    default:
                    {
                        printf("Zadali jste spatny znak.\n");
                        return 0;
                    }
                }
            }
        }
        case 7: //otazka 7
        {
            char spravna_odpoved = 'a', spatna_odpoved1 = 'b', spatna_odpoved2 = 'c', spatna_odpoved3 = 'd', napoveda_rand;
            int i;
            printf("Co vede napeti v pocitaci?\n");
            printf("A)Zdroj B)Graficka karta C)Zakladova Deska D)Pameti RAM\n");
            napovedy(padesat_na_padesat, pritel_na_telefonu, pomoc_z_publika);
            scanf(" %c", &napoveda);
            if(napoveda == 'N')
            {
                napoveda = 'n';
            }
            switch(napoveda) //vyber napovedy
            {
                case '1': //50:50
                {
                    (*padesat_na_padesat)++;
                    napoveda_rand = rand() % (3 - 1 + 1) + 1; //generace odpovedi 50:50
                    switch (napoveda_rand) {
                        case 1:
                            printf("Vase moznosti jsou '%c' a '%c'.\n", spravna_odpoved, spatna_odpoved1);
                            printf("Zadejte vasi odpoved: ");
                            scanf(" %c", &odpoved);
                            if(odpoved == 'a' || odpoved == 'A')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                        case 2:
                            printf("Vase moznosti jsou '%c' a '%c'.\n", spravna_odpoved, spatna_odpoved2);
                            printf("Zadejte vasi odpoved: ");
                            scanf(" %c", &odpoved);
                            if(odpoved == 'a' || odpoved == 'A')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                        case 3:
                            printf("Vase moznosti jsou '%c' a '%c'.\n", spravna_odpoved, spatna_odpoved3);
                            printf("Zadejte vasi odpoved: ");
                            scanf(" %c", &odpoved);
                            if(odpoved == 'a' || odpoved == 'A')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                            break;
                    }
                    case '2': //Pomoc od kamarada
                    {
                        (*pritel_na_telefonu)++;
                        printf("Kamarad: Ahoj.\n");
                        printf("Ja: Ahoj, jsem ve hre milionar a nevim si rady s otazkou: Co vede napeti v pocitaci?\n");
                        printf("Moznosti jsou: A)Zdroj B)Graficka karta C)Zakladova Deska D)Pameti RAM.\n");

                        napoveda2_rand = rand() % 3 + 1; //generace odpovedi kamarada
                        switch (napoveda2_rand) //Odpoved kamarada
                        {
                            case 1:
                            {
                                printf("To vim, je to za '%c'.\n", spravna_odpoved);
                                printf("Zadejte odpoved: ");
                                scanf(" %c", &odpoved);
                                if(odpoved == 'a' || odpoved == 'A')
                                {
                                    printf("Spravna odpoved!\n");
                                    return 1;
                                }
                                else
                                {
                                    printf("Spatna odpoved!\n");
                                    return 0;
                                }
                            }

                            case 2:
                            {
                                printf("Hmm, rekl bych ze to je bud '%c' nebo '%c'.\n", spravna_odpoved, spatna_odpoved2);
                                printf("Zadejte odpoved: ");
                                scanf(" %c", &odpoved);
                                if(odpoved == 'a' || odpoved == 'A')
                                {
                                    printf("Spravna odpoved!\n");
                                    return 1;
                                }
                                else
                                {
                                    printf("Spatna odpoved!\n");
                                    return 0;
                                }
                            }

                            case 3:
                            {
                                printf("Promin, ale nemam tuseni.\n");
                                printf("Zadejte odpoved: ");
                                scanf(" %c", &odpoved);
                                if(odpoved == 'a' || odpoved == 'A')
                                {
                                    printf("Spravna odpoved!\n");
                                    return 1;
                                }
                                else
                                {
                                    printf("Spatna odpoved!\n");
                                    return 0;
                                }
                            }
                        }
                        break;
                    }
                    case '3': //Pomoc z publika
                    {
                        (*pomoc_z_publika)++;
                        a = (rand() % (76 - 1 + 1)) + 25;
                        b = rand() % ((101-a) - 1 + 1);
                        c = rand() % ((101-a-b) - 1 + 1);
                        d = 100-a-b-c;

                        printf("A: %d%% B: %d%% C: %d%% D: %d%%", a, b, c, d);

                        printf("\nZadejte odpoved: ");
                        scanf(" %c", &odpoved);
                        if (odpoved == 'a' || odpoved == 'A')
                        {
                            printf("Spravna odpoved!\n");
                            return 1;
                        }
                        else
                        {
                            printf("Spatna odpoved!\n");
                            return 0;
                        }
                    }
                    case 'n': //bez napovedy
                    {
                        printf("\nZadejte odpoved: ");
                        scanf(" %c", &odpoved);
                        if (odpoved == 'a' || odpoved == 'A')
                        {
                            printf("Spravna odpoved!\n");
                            return 1;
                        }
                        else
                        {
                            printf("Spatna odpoved!\n");
                            return 0;
                        }
                        break;
                    }
                    default:
                    {
                        printf("Zadali jste spatny znak.\n");
                        return 0;
                    }
                }
            }
        }
        case 8: //otazka 8
        {
            char spravna_odpoved = 'a', spatna_odpoved1 = 'b', spatna_odpoved2 = 'c', spatna_odpoved3 = 'd', napoveda_rand;
            int i;
            printf("Tieto je firma puvodem z?\n");
            printf("A)Finsko B)Svedsko C)Cesko D)USA\n");
            napovedy(padesat_na_padesat, pritel_na_telefonu, pomoc_z_publika);
            scanf(" %c", &napoveda);
            if(napoveda == 'N')
            {
                napoveda = 'n';
            }
            switch(napoveda) //vyber napovedy
            {
                case '1': //50:50
                {
                    (*padesat_na_padesat)++;
                    napoveda_rand = rand() % (3 - 1 + 1) + 1; //generace odpovedi 50:50
                    switch (napoveda_rand) {
                        case 1:
                            printf("Vase moznosti jsou '%c' a '%c'.\n", spravna_odpoved, spatna_odpoved1);
                            printf("Zadejte vasi odpoved: ");
                            scanf(" %c", &odpoved);
                            if(odpoved == 'a' || odpoved == 'A')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                        case 2:
                            printf("Vase moznosti jsou '%c' a '%c'.\n", spravna_odpoved, spatna_odpoved2);
                            printf("Zadejte vasi odpoved: ");
                            scanf(" %c", &odpoved);
                            if(odpoved == 'a' || odpoved == 'A')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                        case 3:
                            printf("Vase moznosti jsou '%c' a '%c'.\n", spravna_odpoved, spatna_odpoved3);
                            printf("Zadejte vasi odpoved: ");
                            scanf(" %c", &odpoved);
                            if(odpoved == 'a' || odpoved == 'A')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                            break;
                    }
                    case '2': //Pomoc od kamarada
                    {
                        (*pritel_na_telefonu)++;
                        printf("Kamarad: Ahoj.\n");
                        printf("Ja: Ahoj, jsem ve hre milionar a nevim si rady s otazkou: Tieto je firma puvodem z?\n");
                        printf("Moznosti jsou: A)Finsko B)Svedsko C)Cesko D)USA.\n");

                        napoveda2_rand = rand() % 3 + 1; //generace odpovedi kamarada
                        switch (napoveda2_rand) //Odpoved kamarada
                        {
                            case 1:
                            {
                                printf("To vim, je to za '%c'.\n", spravna_odpoved);
                                printf("Zadejte odpoved: ");
                                scanf(" %c", &odpoved);
                                if(odpoved == 'a' || odpoved == 'A')
                                {
                                    printf("Spravna odpoved!\n");
                                    return 1;
                                }
                                else
                                {
                                    printf("Spatna odpoved!\n");
                                    return 0;
                                }
                            }

                            case 2:
                            {
                                printf("Hmm, rekl bych ze to je bud '%c' nebo '%c'.\n", spravna_odpoved, spatna_odpoved2);
                                printf("Zadejte odpoved: ");
                                scanf(" %c", &odpoved);
                                if(odpoved == 'a' || odpoved == 'A')
                                {
                                    printf("Spravna odpoved!\n");
                                    return 1;
                                }
                                else
                                {
                                    printf("Spatna odpoved!\n");
                                    return 0;
                                }
                            }

                            case 3:
                            {
                                printf("Promin, ale nemam tuseni.\n");
                                printf("Zadejte odpoved: ");
                                scanf(" %c", &odpoved);
                                if(odpoved == 'a' || odpoved == 'A')
                                {
                                    printf("Spravna odpoved!\n");
                                    return 1;
                                }
                                else
                                {
                                    printf("Spatna odpoved!\n");
                                    return 0;
                                }
                            }
                        }
                        break;
                    }
                    case '3': //Pomoc z publika
                    {
                        (*pomoc_z_publika)++;
                        a = (rand() % (76 - 1 + 1)) + 25;
                        b = rand() % ((101-a) - 1 + 1);
                        c = rand() % ((101-a-b) - 1 + 1);
                        d = 100-a-b-c;

                        printf("A: %d%% B: %d%% C: %d%% D: %d%%", a, b, c, d);

                        printf("\nZadejte odpoved: ");
                        scanf(" %c", &odpoved);
                        if (odpoved == 'a' || odpoved == 'A')
                        {
                            printf("Spravna odpoved!\n");
                            return 1;
                        }
                        else
                        {
                            printf("Spatna odpoved!\n");
                            return 0;
                        }
                    }
                    case 'n': //bez napovedy
                    {
                        printf("\nZadejte odpoved: ");
                        scanf(" %c", &odpoved);
                        if (odpoved == 'a' || odpoved == 'A')
                        {
                            printf("Spravna odpoved!\n");
                            return 1;
                        }
                        else
                        {
                            printf("Spatna odpoved!\n");
                            return 0;
                        }
                        break;
                    }
                    default:
                    {
                        printf("Zadali jste spatny znak.\n");
                        return 0;
                    }
                }
            }
        }
        case 9: //otazka 9
        {
            char spravna_odpoved = 'a', spatna_odpoved1 = 'b', spatna_odpoved2 = 'c', spatna_odpoved3 = 'd', napoveda_rand;
            int i;
            printf("Jak se znaci datovy typ znaku?\n");
            printf("A)char B)int C)float D)void\n");
            napovedy(padesat_na_padesat, pritel_na_telefonu, pomoc_z_publika);
            scanf(" %c", &napoveda);
            if(napoveda == 'N')
            {
                napoveda = 'n';
            }
            switch(napoveda) //vyber napovedy
            {
                case '1': //50:50
                {
                    (*padesat_na_padesat)++;
                    napoveda_rand = rand() % (3 - 1 + 1) + 1; //generace odpovedi 50:50
                    switch (napoveda_rand) {
                        case 1:
                            printf("Vase moznosti jsou '%c' a '%c'.\n", spravna_odpoved, spatna_odpoved1);
                            printf("Zadejte vasi odpoved: ");
                            scanf(" %c", &odpoved);
                            if(odpoved == 'a' || odpoved == 'A')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                        case 2:
                            printf("Vase moznosti jsou '%c' a '%c'.\n", spravna_odpoved, spatna_odpoved2);
                            printf("Zadejte vasi odpoved: ");
                            scanf(" %c", &odpoved);
                            if(odpoved == 'a' || odpoved == 'A')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                        case 3:
                            printf("Vase moznosti jsou '%c' a '%c'.\n", spravna_odpoved, spatna_odpoved3);
                            printf("Zadejte vasi odpoved: ");
                            scanf(" %c", &odpoved);
                            if(odpoved == 'a' || odpoved == 'A')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                            break;
                    }
                    case '2': //Pomoc od kamarada
                    {
                        (*pritel_na_telefonu)++;
                        printf("Kamarad: Ahoj.\n");
                        printf("Ja: Ahoj, jsem ve hre milionar a nevim si rady s otazkou: Jak se znaci datovy typ znaku?\n");
                        printf("Moznosti jsou: A)char B)int C)float D)void.\n");

                        napoveda2_rand = rand() % 3 + 1; //generace odpovedi kamarada
                        switch (napoveda2_rand) //Odpoved kamarada
                        {
                            case 1:
                            {
                                printf("To vim, je to za '%c'.\n", spravna_odpoved);
                                printf("Zadejte odpoved: ");
                                scanf(" %c", &odpoved);
                                if(odpoved == 'a' || odpoved == 'A')
                                {
                                    printf("Spravna odpoved!\n");
                                    return 1;
                                }
                                else
                                {
                                    printf("Spatna odpoved!\n");
                                    return 0;
                                }
                            }

                            case 2:
                            {
                                printf("Hmm, rekl bych ze to je bud '%c' nebo '%c'.\n", spravna_odpoved, spatna_odpoved2);
                                printf("Zadejte odpoved: ");
                                scanf(" %c", &odpoved);
                                if(odpoved == 'a' || odpoved == 'A')
                                {
                                    printf("Spravna odpoved!\n");
                                    return 1;
                                }
                                else
                                {
                                    printf("Spatna odpoved!\n");
                                    return 0;
                                }
                            }

                            case 3:
                            {
                                printf("Promin, ale nemam tuseni.\n");
                                printf("Zadejte odpoved: ");
                                scanf(" %c", &odpoved);
                                if(odpoved == 'a' || odpoved == 'A')
                                {
                                    printf("Spravna odpoved!\n");
                                    return 1;
                                }
                                else
                                {
                                    printf("Spatna odpoved!\n");
                                    return 0;
                                }
                            }
                        }
                        break;
                    }
                    case '3': //Pomoc z publika
                    {
                        (*pomoc_z_publika)++;
                        a = (rand() % (76 - 1 + 1)) + 25;
                        b = rand() % ((101-a) - 1 + 1);
                        c = rand() % ((101-a-b) - 1 + 1);
                        d = 100-a-b-c;

                        printf("A: %d%% B: %d%% C: %d%% D: %d%%", a, b, c, d);

                        printf("\nZadejte odpoved: ");
                        scanf(" %c", &odpoved);
                        if (odpoved == 'a' || odpoved == 'A')
                        {
                            printf("Spravna odpoved!\n");
                            return 1;
                        }
                        else
                        {
                            printf("Spatna odpoved!\n");
                            return 0;
                        }
                    }
                    case 'n': //bez napovedy
                    {
                        printf("\nZadejte odpoved: ");
                        scanf(" %c", &odpoved);
                        if (odpoved == 'a' || odpoved == 'A')
                        {
                            printf("Spravna odpoved!\n");
                            return 1;
                        }
                        else
                        {
                            printf("Spatna odpoved!\n");
                            return 0;
                        }
                        break;
                    }
                    default:
                    {
                        printf("Zadali jste spatny znak.\n");
                        return 0;
                    }
                }
            }
        }
        case 10: //otazka 10
        {
            char spravna_odpoved = 'a', spatna_odpoved1 = 'b', spatna_odpoved2 = 'c', spatna_odpoved3 = 'd', napoveda_rand;
            int i;
            printf("Jakym slovem se oznacuji pocitacove soucastky?\n");
            printf("A)Hardware B)Data C)Software D)Naradi\n");
            napovedy(padesat_na_padesat, pritel_na_telefonu, pomoc_z_publika);
            scanf(" %c", &napoveda);
            if(napoveda == 'N')
            {
                napoveda = 'n';
            }
            switch(napoveda) //vyber napovedy
            {
                case '1': //50:50
                {
                    (*padesat_na_padesat)++;
                    napoveda_rand = rand() % (3 - 1 + 1) + 1; //generace odpovedi 50:50
                    switch (napoveda_rand) {
                        case 1:
                            printf("Vase moznosti jsou '%c' a '%c'.\n", spravna_odpoved, spatna_odpoved1);
                            printf("Zadejte vasi odpoved: ");
                            scanf(" %c", &odpoved);
                            if(odpoved == 'a' || odpoved == 'A')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                        case 2:
                            printf("Vase moznosti jsou '%c' a '%c'.\n", spravna_odpoved, spatna_odpoved2);
                            printf("Zadejte vasi odpoved: ");
                            scanf(" %c", &odpoved);
                            if(odpoved == 'a' || odpoved == 'A')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                        case 3:
                            printf("Vase moznosti jsou '%c' a '%c'.\n", spravna_odpoved, spatna_odpoved3);
                            printf("Zadejte vasi odpoved: ");
                            scanf(" %c", &odpoved);
                            if(odpoved == 'a' || odpoved == 'A')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                            break;
                    }
                    case '2': //Pomoc od kamarada
                    {
                        (*pritel_na_telefonu)++;
                        printf("Kamarad: Ahoj.\n");
                        printf("Ja: Ahoj, jsem ve hre milionar a nevim si rady s otazkou: Jakym slovem se oznacuji pocitacove soucastky?\n");
                        printf("Moznosti jsou: A)Hardware B)Data C)Software D)Naradi.\n");

                        napoveda2_rand = rand() % 3 + 1; //generace odpovedi kamarada
                        switch (napoveda2_rand) //Odpoved kamarada
                        {
                            case 1:
                            {
                                printf("To vim, je to za '%c'.\n", spravna_odpoved);
                                printf("Zadejte odpoved: ");
                                scanf(" %c", &odpoved);
                                if(odpoved == 'a' || odpoved == 'A')
                                {
                                    printf("Spravna odpoved!\n");
                                    return 1;
                                }
                                else
                                {
                                    printf("Spatna odpoved!\n");
                                    return 0;
                                }
                            }

                            case 2:
                            {
                                printf("Hmm, rekl bych ze to je bud '%c' nebo '%c'.\n", spravna_odpoved, spatna_odpoved2);
                                printf("Zadejte odpoved: ");
                                scanf(" %c", &odpoved);
                                if(odpoved == 'a' || odpoved == 'A')
                                {
                                    printf("Spravna odpoved!\n");
                                    return 1;
                                }
                                else
                                {
                                    printf("Spatna odpoved!\n");
                                    return 0;
                                }
                            }

                            case 3:
                            {
                                printf("Promin, ale nemam tuseni.\n");
                                printf("Zadejte odpoved: ");
                                scanf(" %c", &odpoved);
                                if(odpoved == 'a' || odpoved == 'A')
                                {
                                    printf("Spravna odpoved!\n");
                                    return 1;
                                }
                                else
                                {
                                    printf("Spatna odpoved!\n");
                                    return 0;
                                }
                            }
                        }
                        break;
                    }
                    case '3': //Pomoc z publika
                    {
                        (*pomoc_z_publika)++;
                        a = (rand() % (76 - 1 + 1)) + 25;
                        b = rand() % ((101-a) - 1 + 1);
                        c = rand() % ((101-a-b) - 1 + 1);
                        d = 100-a-b-c;

                        printf("A: %d%% B: %d%% C: %d%% D: %d%%", a, b, c, d);

                        printf("\nZadejte odpoved: ");
                        scanf(" %c", &odpoved);
                        if (odpoved == 'a' || odpoved == 'A')
                        {
                            printf("Spravna odpoved!\n");
                            return 1;
                        }
                        else
                        {
                            printf("Spatna odpoved!\n");
                            return 0;
                        }
                    }
                    case 'n': //bez napovedy
                    {
                        printf("\nZadejte odpoved: ");
                        scanf(" %c", &odpoved);
                        if (odpoved == 'a' || odpoved == 'A')
                        {
                            printf("Spravna odpoved!\n");
                            return 1;
                        }
                        else
                        {
                            printf("Spatna odpoved!\n");
                            return 0;
                        }
                        break;
                    }
                    default:
                    {
                        printf("Zadali jste spatny znak.\n");
                        return 0;
                    }
                }
            }
        }
        case 11: //otazka 11
        {
            char spravna_odpoved = 'b', spatna_odpoved1 = 'a', spatna_odpoved2 = 'c', spatna_odpoved3 = 'd', napoveda_rand;
            int i;
            printf("Kdo je zakladatelem Tieta?\n");
            printf("A)Elon Musk B)Kimmo Alkio C)Steve Jobs D)Mark Zuckerberg\n");
            napovedy(padesat_na_padesat, pritel_na_telefonu, pomoc_z_publika);
            scanf(" %c", &napoveda);
            if(napoveda == 'N')
            {
                napoveda = 'n';
            }
            switch(napoveda) //vyber napovedy
            {
                case '1': //50:50
                {
                    (*padesat_na_padesat)++;
                    napoveda_rand = rand() % (3 - 1 + 1) + 1; //generace odpovedi 50:50
                    switch (napoveda_rand) {
                        case 1:
                            printf("Vase moznosti jsou '%c' a '%c'.\n", spravna_odpoved, spatna_odpoved1);
                            printf("Zadejte vasi odpoved: ");
                            scanf(" %c", &odpoved);
                            if(odpoved == 'b' || odpoved == 'B')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                        case 2:
                            printf("Vase moznosti jsou '%c' a '%c'.\n", spravna_odpoved, spatna_odpoved2);
                            printf("Zadejte vasi odpoved: ");
                            scanf(" %c", &odpoved);
                            if(odpoved == 'b' || odpoved == 'B')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                        case 3:
                            printf("Vase moznosti jsou '%c' a '%c'.\n", spravna_odpoved, spatna_odpoved3);
                            printf("Zadejte vasi odpoved: ");
                            scanf(" %c", &odpoved);
                            if(odpoved == 'b' || odpoved == 'B')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                            break;
                    }
                    case '2': //Pomoc od kamarada
                    {
                        (*pritel_na_telefonu)++;
                        printf("Kamarad: Ahoj.\n");
                        printf("Ja: Ahoj, jsem ve hre milionar a nevim si rady s otazkou: Kdo je zakladatelem Tieta?\n");
                        printf("Moznosti jsou: A)Elon Musk B)Kimmo Alkio C)Steve Jobs D)Mark Zuckerberg.\n");

                        napoveda2_rand = rand() % 3 + 1; //generace odpovedi kamarada
                        switch (napoveda2_rand) //Odpoved kamarada
                        {
                            case 1:
                            {
                                printf("To vim, je to za '%c'.\n", spravna_odpoved);
                                printf("Zadejte odpoved: ");
                                scanf(" %c", &odpoved);
                                if(odpoved == 'b' || odpoved == 'B')
                                {
                                    printf("Spravna odpoved!\n");
                                    return 1;
                                }
                                else
                                {
                                    printf("Spatna odpoved!\n");
                                    return 0;
                                }
                            }

                            case 2:
                            {
                                printf("Hmm, rekl bych ze to je bud '%c' nebo '%c'.\n", spravna_odpoved, spatna_odpoved2);
                                printf("Zadejte odpoved: ");
                                scanf(" %c", &odpoved);
                                if(odpoved == 'b' || odpoved == 'B')
                                {
                                    printf("Spravna odpoved!\n");
                                    return 1;
                                }
                                else
                                {
                                    printf("Spatna odpoved!\n");
                                    return 0;
                                }
                            }

                            case 3:
                            {
                                printf("Promin, ale nemam tuseni.\n");
                                printf("Zadejte odpoved: ");
                                scanf(" %c", &odpoved);
                                if(odpoved == 'b' || odpoved == 'B')
                                {
                                    printf("Spravna odpoved!\n");
                                    return 1;
                                }
                                else
                                {
                                    printf("Spatna odpoved!\n");
                                    return 0;
                                }
                            }
                        }
                        break;
                    }
                    case '3': //Pomoc z publika
                    {
                        (*pomoc_z_publika)++;
                        b = (rand() % (76 - 1 + 1)) + 25;
                        a = rand() % ((101-b) - 1 + 1);
                        c = rand() % ((101-a-b) - 1 + 1);
                        d = 100-a-b-c;

                        printf("A: %d%% B: %d%% C: %d%% D: %d%%", a, b, c, d);

                        printf("\nZadejte odpoved: ");
                        scanf(" %c", &odpoved);
                        if (odpoved == 'b' || odpoved == 'B')
                        {
                            printf("Spravna odpoved!\n");
                            return 1;
                        }
                        else
                        {
                            printf("Spatna odpoved!\n");
                            return 0;
                        }
                    }
                    case 'n': //bez napovedy
                    {
                        printf("\nZadejte odpoved: ");
                        scanf(" %c", &odpoved);
                        if (odpoved == 'b' || odpoved == 'B')
                        {
                            printf("Spravna odpoved!\n");
                            return 1;
                        }
                        else
                        {
                            printf("Spatna odpoved!\n");
                            return 0;
                        }
                        break;
                    }
                    default:
                    {
                        printf("Zadali jste spatny znak.\n");
                        return 0;
                    }
                }
            }
        }
        case 12: //otazka 12
        {
            char spravna_odpoved = 'a', spatna_odpoved1 = 'b', spatna_odpoved2 = 'c', spatna_odpoved3 = 'd', napoveda_rand;
            int i;
            printf("Jake pismeno pridame ke klavese 'Alt' pro napsani '#'?\n");
            printf("A)X B)B C)F D)Q\n");
            napovedy(padesat_na_padesat, pritel_na_telefonu, pomoc_z_publika);
            scanf(" %c", &napoveda);
            if(napoveda == 'N')
            {
                napoveda = 'n';
            }
            switch(napoveda) //vyber napovedy
            {
                case '1': //50:50
                {
                    (*padesat_na_padesat)++;
                    napoveda_rand = rand() % (3 - 1 + 1) + 1; //generace odpovedi 50:50
                    switch (napoveda_rand) {
                        case 1:
                            printf("Vase moznosti jsou '%c' a '%c'.\n", spravna_odpoved, spatna_odpoved1);
                            printf("Zadejte vasi odpoved: ");
                            scanf(" %c", &odpoved);
                            if(odpoved == 'a' || odpoved == 'A')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                        case 2:
                            printf("Vase moznosti jsou '%c' a '%c'.\n", spravna_odpoved, spatna_odpoved2);
                            printf("Zadejte vasi odpoved: ");
                            scanf(" %c", &odpoved);
                            if(odpoved == 'a' || odpoved == 'A')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                        case 3:
                            printf("Vase moznosti jsou '%c' a '%c'.\n", spravna_odpoved, spatna_odpoved3);
                            printf("Zadejte vasi odpoved: ");
                            scanf(" %c", &odpoved);
                            if(odpoved == 'a' || odpoved == 'A')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                            break;
                    }
                    case '2': //Pomoc od kamarada
                    {
                        (*pritel_na_telefonu)++;
                        printf("Kamarad: Ahoj.\n");
                        printf("Ja: Ahoj, jsem ve hre milionar a nevim si rady s otazkou: Jake pismeno pridame ke klavese 'Alt' pro napsani '#'?\n");
                        printf("Moznosti jsou: A)X B)B C)F D)Q.\n");

                        napoveda2_rand = rand() % 3 + 1; //generace odpovedi kamarada
                        switch (napoveda2_rand) //Odpoved kamarada
                        {
                            case 1:
                            {
                                printf("To vim, je to za '%c'.\n", spravna_odpoved);
                                printf("Zadejte odpoved: ");
                                scanf(" %c", &odpoved);
                                if(odpoved == 'a' || odpoved == 'A')
                                {
                                    printf("Spravna odpoved!\n");
                                    return 1;
                                }
                                else
                                {
                                    printf("Spatna odpoved!\n");
                                    return 0;
                                }
                            }

                            case 2:
                            {
                                printf("Hmm, rekl bych ze to je bud '%c' nebo '%c'.\n", spravna_odpoved, spatna_odpoved2);
                                printf("Zadejte odpoved: ");
                                scanf(" %c", &odpoved);
                                if(odpoved == 'a' || odpoved == 'A')
                                {
                                    printf("Spravna odpoved!\n");
                                    return 1;
                                }
                                else
                                {
                                    printf("Spatna odpoved!\n");
                                    return 0;
                                }
                            }

                            case 3:
                            {
                                printf("Promin, ale nemam tuseni.\n");
                                printf("Zadejte odpoved: ");
                                scanf(" %c", &odpoved);
                                if(odpoved == 'a' || odpoved == 'A')
                                {
                                    printf("Spravna odpoved!\n");
                                    return 1;
                                }
                                else
                                {
                                    printf("Spatna odpoved!\n");
                                    return 0;
                                }
                            }
                        }
                        break;
                    }
                    case '3': //Pomoc z publika
                    {
                        (*pomoc_z_publika)++;
                        a = (rand() % (76 - 1 + 1)) + 25;
                        b = rand() % ((101-a) - 1 + 1);
                        c = rand() % ((101-a-b) - 1 + 1);
                        d = 100-a-b-c;

                        printf("A: %d%% B: %d%% C: %d%% D: %d%%", a, b, c, d);

                        printf("\nZadejte odpoved: ");
                        scanf(" %c", &odpoved);
                        if (odpoved == 'a' || odpoved == 'A')
                        {
                            printf("Spravna odpoved!\n");
                            return 1;
                        }
                        else
                        {
                            printf("Spatna odpoved!\n");
                            return 0;
                        }
                    }
                    case 'n': //bez napovedy
                    {
                        printf("\nZadejte odpoved: ");
                        scanf(" %c", &odpoved);
                        if (odpoved == 'a' || odpoved == 'A')
                        {
                            printf("Spravna odpoved!\n");
                            return 1;
                        }
                        else
                        {
                            printf("Spatna odpoved!\n");
                            return 0;
                        }
                        break;
                    }
                    default:
                    {
                        printf("Zadali jste spatny znak.\n");
                        return 0;
                    }
                }
            }
        }
        case 13: //otazka 13
        {
            char spravna_odpoved = 'c', spatna_odpoved1 = 'a', spatna_odpoved2 = 'b', spatna_odpoved3 = 'd', napoveda_rand;
            int i;
            printf("Jaky ukoncovaci znak ma retezec?\n");
            printf("A)'#' B)'0' C)'\\0' D)'%'\n");
            napovedy(padesat_na_padesat, pritel_na_telefonu, pomoc_z_publika);
            scanf(" %c", &napoveda);
            if(napoveda == 'N')
            {
                napoveda = 'n';
            }
            switch(napoveda) //vyber napovedy
            {
                case '1': //50:50
                {
                    (*padesat_na_padesat)++;
                    napoveda_rand = rand() % (3 - 1 + 1) + 1; //generace odpovedi 50:50
                    switch (napoveda_rand) {
                        case 1:
                            printf("Vase moznosti jsou '%c' a '%c'.\n", spravna_odpoved, spatna_odpoved1);
                            printf("Zadejte vasi odpoved: ");
                            scanf(" %c", &odpoved);
                            if(odpoved == 'c' || odpoved == 'C')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                        case 2:
                            printf("Vase moznosti jsou '%c' a '%c'.\n", spravna_odpoved, spatna_odpoved2);
                            printf("Zadejte vasi odpoved: ");
                            scanf(" %c", &odpoved);
                            if(odpoved == 'c' || odpoved == 'C')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                        case 3:
                            printf("Vase moznosti jsou '%c' a '%c'.\n", spravna_odpoved, spatna_odpoved3);
                            printf("Zadejte vasi odpoved: ");
                            scanf(" %c", &odpoved);
                            if(odpoved == 'c' || odpoved == 'C')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                            break;
                    }
                    case '2': //Pomoc od kamarada
                    {
                        (*pritel_na_telefonu)++;
                        printf("Kamarad: Ahoj.\n");
                        printf("Ja: Ahoj, jsem ve hre milionar a nevim si rady s otazkou: Jaky ukoncovaci znak ma retezec\n");
                        printf("Moznosti jsou: A)'#' B)'0' C)'\\0' D)'%'.\n");

                        napoveda2_rand = rand() % 3 + 1; //generace odpovedi kamarada
                        switch (napoveda2_rand) //Odpoved kamarada
                        {
                            case 1:
                            {
                                printf("To vim, je to za '%c'.\n", spravna_odpoved);
                                printf("Zadejte odpoved: ");
                                scanf(" %c", &odpoved);
                                if(odpoved == 'c' || odpoved == 'C')
                                {
                                    printf("Spravna odpoved!\n");
                                    return 1;
                                }
                                else
                                {
                                    printf("Spatna odpoved!\n");
                                    return 0;
                                }
                            }

                            case 2:
                            {
                                printf("Hmm, rekl bych ze to je bud '%c' nebo '%c'.\n", spravna_odpoved, spatna_odpoved2);
                                printf("Zadejte odpoved: ");
                                scanf(" %c", &odpoved);
                                if(odpoved == 'c' || odpoved == 'C')
                                {
                                    printf("Spravna odpoved!\n");
                                    return 1;
                                }
                                else
                                {
                                    printf("Spatna odpoved!\n");
                                    return 0;
                                }
                            }

                            case 3:
                            {
                                printf("Promin, ale nemam tuseni.\n");
                                printf("Zadejte odpoved: ");
                                scanf(" %c", &odpoved);
                                if(odpoved == 'c' || odpoved == 'C')
                                {
                                    printf("Spravna odpoved!\n");
                                    return 1;
                                }
                                else
                                {
                                    printf("Spatna odpoved!\n");
                                    return 0;
                                }
                            }
                        }
                        break;
                    }
                    case '3': //Pomoc z publika
                    {
                        (*pomoc_z_publika)++;
                        c = (rand() % (76 - 1 + 1)) + 25;
                        a = rand() % ((101-c) - 1 + 1);
                        b = rand() % ((101-a-c) - 1 + 1);
                        d = 100-a-b-c;

                        printf("A: %d%% B: %d%% C: %d%% D: %d%%", a, b, c, d);

                        printf("\nZadejte odpoved: ");
                        scanf(" %c", &odpoved);
                        if (odpoved == 'c' || odpoved == 'C')
                        {
                            printf("Spravna odpoved!\n");
                            return 1;
                        }
                        else
                        {
                            printf("Spatna odpoved!\n");
                            return 0;
                        }
                    }
                    case 'n': //bez napovedy
                    {
                        printf("\nZadejte odpoved: ");
                        scanf(" %c", &odpoved);
                        if (odpoved == 'c' || odpoved == 'C')
                        {
                            printf("Spravna odpoved!\n");
                            return 1;
                        }
                        else
                        {
                            printf("Spatna odpoved!\n");
                            return 0;
                        }
                        break;
                    }
                    default:
                    {
                        printf("Zadali jste spatny znak.\n");
                        return 0;
                    }
                }
            }
        }
        case 14: //otazka 14
        {
            char spravna_odpoved = 'c', spatna_odpoved1 = 'a', spatna_odpoved2 = 'b', spatna_odpoved3 = 'd', napoveda_rand;
            int i;
            printf("Co z urcenych neni cyklus?\n");
            printf("A)For B)While C)If D)Do-While\n");
            napovedy(padesat_na_padesat, pritel_na_telefonu, pomoc_z_publika);
            scanf(" %c", &napoveda);
            if(napoveda == 'N')
            {
                napoveda = 'n';
            }
            switch(napoveda) //vyber napovedy
            {
                case '1': //50:50
                {
                    (*padesat_na_padesat)++;
                    napoveda_rand = rand() % (3 - 1 + 1) + 1; //generace odpovedi 50:50
                    switch (napoveda_rand) {
                        case 1:
                            printf("Vase moznosti jsou '%c' a '%c'.\n", spravna_odpoved, spatna_odpoved1);
                            printf("Zadejte vasi odpoved: ");
                            scanf(" %c", &odpoved);
                            if(odpoved == 'c' || odpoved == 'C')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                        case 2:
                            printf("Vase moznosti jsou '%c' a '%c'.\n", spravna_odpoved, spatna_odpoved2);
                            printf("Zadejte vasi odpoved: ");
                            scanf(" %c", &odpoved);
                            if(odpoved == 'c' || odpoved == 'C')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                        case 3:
                            printf("Vase moznosti jsou '%c' a '%c'.\n", spravna_odpoved, spatna_odpoved3);
                            printf("Zadejte vasi odpoved: ");
                            scanf(" %c", &odpoved);
                            if(odpoved == 'c' || odpoved == 'C')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                            break;
                    }
                    case '2': //Pomoc od kamarada
                    {
                        (*pritel_na_telefonu)++;
                        printf("Kamarad: Ahoj.\n");
                        printf("Ja: Ahoj, jsem ve hre milionar a nevim si rady s otazkou: Co z urcenych neni cyklus?\n");
                        printf("Moznosti jsou: A)For B)While C)If D)Do-While.\n");

                        napoveda2_rand = rand() % 3 + 1; //generace odpovedi kamarada
                        switch (napoveda2_rand) //Odpoved kamarada
                        {
                            case 1:
                            {
                                printf("To vim, je to za '%c'.\n", spravna_odpoved);
                                printf("Zadejte odpoved: ");
                                scanf(" %c", &odpoved);
                                if(odpoved == 'c' || odpoved == 'C')
                                {
                                    printf("Spravna odpoved!\n");
                                    return 1;
                                }
                                else
                                {
                                    printf("Spatna odpoved!\n");
                                    return 0;
                                }
                            }

                            case 2:
                            {
                                printf("Hmm, rekl bych ze to je bud '%c' nebo '%c'.\n", spravna_odpoved, spatna_odpoved2);
                                printf("Zadejte odpoved: ");
                                scanf(" %c", &odpoved);
                                if(odpoved == 'c' || odpoved == 'C')
                                {
                                    printf("Spravna odpoved!\n");
                                    return 1;
                                }
                                else
                                {
                                    printf("Spatna odpoved!\n");
                                    return 0;
                                }
                            }

                            case 3:
                            {
                                printf("Promin, ale nemam tuseni.\n");
                                printf("Zadejte odpoved: ");
                                scanf(" %c", &odpoved);
                                if(odpoved == 'c' || odpoved == 'C')
                                {
                                    printf("Spravna odpoved!\n");
                                    return 1;
                                }
                                else
                                {
                                    printf("Spatna odpoved!\n");
                                    return 0;
                                }
                            }
                        }
                        break;
                    }
                    case '3': //Pomoc z publika
                    {
                        (*pomoc_z_publika)++;
                        c = (rand() % (76 - 1 + 1)) + 25;
                        a = rand() % ((101-c) - 1 + 1);
                        b = rand() % ((101-a-c) - 1 + 1);
                        d = 100-a-b-c;

                        printf("A: %d%% B: %d%% C: %d%% D: %d%%", a, b, c, d);

                        printf("\nZadejte odpoved: ");
                        scanf(" %c", &odpoved);
                        if (odpoved == 'c' || odpoved == 'C')
                        {
                            printf("Spravna odpoved!\n");
                            return 1;
                        }
                        else
                        {
                            printf("Spatna odpoved!\n");
                            return 0;
                        }
                    }
                    case 'n': //bez napovedy
                    {
                        printf("\nZadejte odpoved: ");
                        scanf(" %c", &odpoved);
                        if (odpoved == 'c' || odpoved == 'C')
                        {
                            printf("Spravna odpoved!\n");
                            return 1;
                        }
                        else
                        {
                            printf("Spatna odpoved!\n");
                            return 0;
                        }
                        break;
                    }
                    default:
                    {
                        printf("Zadali jste spatny znak.\n");
                        return 0;
                    }
                }
            }
        }
        case 15: //otazka 15
        {
            char spravna_odpoved = 'b', spatna_odpoved1 = 'a', spatna_odpoved2 = 'c', spatna_odpoved3 = 'd', napoveda_rand;
            int i;
            printf("Jake je priblizne zastoupeni zen v tietu?\n");
            printf("A)5%% B)20%% C)35%% D)50%%\n");
            napovedy(padesat_na_padesat, pritel_na_telefonu, pomoc_z_publika);
            scanf(" %c", &napoveda);
            if(napoveda == 'N')
            {
                napoveda = 'n';
            }
            switch(napoveda) //vyber napovedy
            {
                case '1': //50:50
                {
                    (*padesat_na_padesat)++;
                    napoveda_rand = rand() % (3 - 1 + 1) + 1; //generace odpovedi 50:50
                    switch (napoveda_rand) {
                        case 1:
                            printf("Vase moznosti jsou '%c' a '%c'.\n", spravna_odpoved, spatna_odpoved1);
                            printf("Zadejte vasi odpoved: ");
                            scanf(" %c", &odpoved);
                            if(odpoved == 'b' || odpoved == 'B')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                        case 2:
                            printf("Vase moznosti jsou '%c' a '%c'.\n", spravna_odpoved, spatna_odpoved2);
                            printf("Zadejte vasi odpoved: ");
                            scanf(" %c", &odpoved);
                            if(odpoved == 'b' || odpoved == 'B')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                        case 3:
                            printf("Vase moznosti jsou '%c' a '%c'.\n", spravna_odpoved, spatna_odpoved3);
                            printf("Zadejte vasi odpoved: ");
                            scanf(" %c", &odpoved);
                            if(odpoved == 'b' || odpoved == 'B')
                            {
                                printf("Spravna odpoved!\n");
                                return 1;
                            }
                            else
                            {
                                printf("Spatna odpoved!\n");
                                return 0;
                            }
                            break;
                    }
                    case '2': //Pomoc od kamarada
                    {
                        (*pritel_na_telefonu)++;
                        printf("Kamarad: Ahoj.\n");
                        printf("Ja: Ahoj, jsem ve hre milionar a nevim si rady s otazkou: Jake je priblizne zastoupeni zen v tietu?\n");
                        printf("Moznosti jsou: A)5%% B)20%% C)35%% D)50%%.\n");

                        napoveda2_rand = rand() % 3 + 1; //generace odpovedi kamarada
                        switch (napoveda2_rand) //Odpoved kamarada
                        {
                            case 1:
                            {
                                printf("To vim, je to za '%c'.\n", spravna_odpoved);
                                printf("Zadejte odpoved: ");
                                scanf(" %c", &odpoved);
                                if(odpoved == 'b' || odpoved == 'B')
                                {
                                    printf("Spravna odpoved!\n");
                                    return 1;
                                }
                                else
                                {
                                    printf("Spatna odpoved!\n");
                                    return 0;
                                }
                            }

                            case 2:
                            {
                                printf("Hmm, rekl bych ze to je bud '%c' nebo '%c'.\n", spravna_odpoved, spatna_odpoved2);
                                printf("Zadejte odpoved: ");
                                scanf(" %c", &odpoved);
                                if(odpoved == 'b' || odpoved == 'B')
                                {
                                    printf("Spravna odpoved!\n");
                                    return 1;
                                }
                                else
                                {
                                    printf("Spatna odpoved!\n");
                                    return 0;
                                }
                            }

                            case 3:
                            {
                                printf("Promin, ale nemam tuseni.\n");
                                printf("Zadejte odpoved: ");
                                scanf(" %c", &odpoved);
                                if(odpoved == 'b' || odpoved == 'B')
                                {
                                    printf("Spravna odpoved!\n");
                                    return 1;
                                }
                                else
                                {
                                    printf("Spatna odpoved!\n");
                                    return 0;
                                }
                            }
                        }
                        break;
                    }
                    case '3': //Pomoc z publika
                    {
                        (*pomoc_z_publika)++;
                        b = (rand() % (76 - 1 + 1)) + 25;
                        a = rand() % ((101-b) - 1 + 1);
                        c = rand() % ((101-a-b) - 1 + 1);
                        d = 100-a-b-c;

                        printf("A: %d%% B: %d%% C: %d%% D: %d%%", a, b, c, d);

                        printf("\nZadejte odpoved: ");
                        scanf(" %c", &odpoved);
                        if (odpoved == 'b' || odpoved == 'B')
                        {
                            printf("Spravna odpoved!\n");
                            return 1;
                        }
                        else
                        {
                            printf("Spatna odpoved!\n");
                            return 0;
                        }
                    }
                    case 'n': //bez napovedy
                    {
                        printf("\nZadejte odpoved: ");
                        scanf(" %c", &odpoved);
                        if (odpoved == 'b' || odpoved == 'B')
                        {
                            printf("Spravna odpoved!\n");
                            return 1;
                        }
                        else
                        {
                            printf("Spatna odpoved!\n");
                            return 0;
                        }
                        break;
                    }
                    default:
                    {
                        printf("Zadali jste spatny znak.\n");
                        return 0;
                    }
                }
            }
        }
    }
}

int vyhra(int spravne_odpovedi)
{
    char pokracovani;
    switch (spravne_odpovedi)
    {
        case 1:
        {
            printf("Mate 100kc.\n");
            printf("Chcete pokracovat dale? Jestli ano, zadejte 'a', jinak zadejte 'n':");
            scanf(" %c", &pokracovani);
            if (pokracovani == 'a' || pokracovani == 'A')
            {
                printf("Pokracujeme dal.\n");
                return 0;
            }
            else if(pokracovani == 'n' || pokracovani == 'N')
            {
                printf("Vase vyhra je 100kc.\n");
                printf("Konec teto hry.\n");
                return 1;
            }
            break;
        }
        case 2:
        {
            printf("Mate 200kc.\n");
            printf("Chcete pokracovat dale? Jestli ano, zadejte 'a', jinak zadejte 'n':");
            scanf(" %c", &pokracovani);
            if (pokracovani == 'a' || pokracovani == 'A')
            {
                printf("Pokracujeme dal.\n");
                return 0;
            }
            else if(pokracovani == 'n' || pokracovani == 'N')
            {
                printf("Vase vyhra je 200kc.\n");
                printf("Konec teto hry.\n");
                return 1;
            }
            break;
        }
        case 3:
        {
            printf("Mate 300kc.\n");
            printf("Chcete pokracovat dale? Jestli ano, zadejte 'a', jinak zadejte 'n':");
            scanf(" %c", &pokracovani);
            if (pokracovani == 'a' || pokracovani == 'A')
            {
                printf("Pokracujeme dal.\n");
                return 0;
            }
            else if(pokracovani == 'n' || pokracovani == 'N')
            {
                printf("Vase vyhra je 300kc.\n");
                printf("Konec teto hry.\n");
                return 1;
            }
            break;
        }
        case 4:
        {
            printf("Mate 500kc.\n");
            printf("Chcete pokracovat dale? Jestli ano, zadejte 'a', jinak zadejte 'n':");
            scanf(" %c", &pokracovani);
            if (pokracovani == 'a' || pokracovani == 'A')
            {
                printf("Pokracujeme dal.\n");
                return 0;
            }
            else if(pokracovani == 'n' || pokracovani == 'N')
            {
                printf("Vase vyhra je 500kc.\n");
                printf("Konec teto hry.\n");
                return 1;
            }
            break;
        }
        case 5:
        {
            printf("Dosahli jste 1. zachytneho bodu.\n");
            printf("Mate 1000kc.\n");
            printf("Chcete pokracovat dale? Jestli ano, zadejte 'a', jinak zadejte 'n':");
            scanf(" %c", &pokracovani);
            if (pokracovani == 'a' || pokracovani == 'A')
            {
                printf("Pokracujeme dal.\n");
                return 0;
            }
            else if(pokracovani == 'n' || pokracovani == 'N')
            {
                printf("Vase vyhra je 1000kc.\n");
                printf("Konec teto hry.\n");
                return 1;
            }
            break;
        }
        case 6:
        {
            printf("Mate 2000kc.\n");
            printf("Chcete pokracovat dale? Jestli ano, zadejte 'a', jinak zadejte 'n':");
            scanf(" %c", &pokracovani);
            if (pokracovani == 'a' || pokracovani == 'A')
            {
                printf("Pokracujeme dal.\n");
                return 0;
            }
            else if(pokracovani == 'n' || pokracovani == 'N')
            {
                printf("Vase vyhra je 2000kc.\n");
                printf("Konec teto hry.\n");
                return 1;
            }
            break;
        }
        case 7:
        {
            printf("Mate 4000kc.\n");
            printf("Chcete pokracovat dale? Jestli ano, zadejte 'a', jinak zadejte 'n':");
            scanf(" %c", &pokracovani);
            if (pokracovani == 'a' || pokracovani == 'A')
            {
                printf("Pokracujeme dal.\n");
                return 0;
            }
            else if(pokracovani == 'n' || pokracovani == 'N')
            {
                printf("Vase vyhra je 4000kc.\n");
                printf("Konec teto hry.\n");
                return 1;
            }
            break;
        }
        case 8:
        {
            printf("Mate 8000kc.\n");
            printf("Chcete pokracovat dale? Jestli ano, zadejte 'a', jinak zadejte 'n':");
            scanf(" %c", &pokracovani);
            if (pokracovani == 'a' || pokracovani == 'A')
            {
                printf("Pokracujeme dal.\n");
                return 0;
            }
            else if(pokracovani == 'n' || pokracovani == 'N')
            {
                printf("Vase vyhra je 8000kc.\n");
                printf("Konec teto hry.\n");
                return 1;
            }
            break;
        }
        case 9:
        {
            printf("Mate 16000kc.\n");
            printf("Chcete pokracovat dale? Jestli ano, zadejte 'a', jinak zadejte 'n':");
            scanf(" %c", &pokracovani);
            if (pokracovani == 'a' || pokracovani == 'A')
            {
                printf("Pokracujeme dal.\n");
                return 0;
            }
            else if(pokracovani == 'n' || pokracovani == 'N')
            {
                printf("Vase vyhra je 16000kc.\n");
                printf("Konec teto hry.\n");
                return 1;
            }
            break;
        }
        case 10:
        {
            printf("Dosahli jste 2. zachytneho bodu.\n");
            printf("Mate 32000kc.\n");
            printf("Chcete pokracovat dale? Jestli ano, zadejte 'a', jinak zadejte 'n':");
            scanf(" %c", &pokracovani);
            if (pokracovani == 'a' || pokracovani == 'A')
            {
                printf("Pokracujeme dal.\n");
                return 0;
            }
            else if(pokracovani == 'n' || pokracovani == 'N')
            {
                printf("Vase vyhra je 32000kc.\n");
                printf("Konec teto hry.\n");
                return 1;
            }
            break;
        }
        case 11:
        {
            printf("Mate 64000kc.\n");
            printf("Chcete pokracovat dale? Jestli ano, zadejte 'a', jinak zadejte 'n':");
            scanf(" %c", &pokracovani);
            if (pokracovani == 'a' || pokracovani == 'A')
            {
                printf("Pokracujeme dal.\n");
                return 0;
            }
            else if(pokracovani == 'n' || pokracovani == 'N')
            {
                printf("Vase vyhra je 64000kc.\n");
                printf("Konec teto hry.\n");
                return 1;
            }
            break;
        }
        case 12:
        {
            printf("Mate 150000kc.\n");
            printf("Chcete pokracovat dale? Jestli ano, zadejte 'a', jinak zadejte 'n':");
            scanf(" %c", &pokracovani);
            if (pokracovani == 'a' || pokracovani == 'A')
            {
                printf("Pokracujeme dal.\n");
                return 0;
            }
            else if(pokracovani == 'n' || pokracovani == 'N')
            {
                printf("Vase vyhra je 150000kc.\n");
                printf("Konec teto hry.\n");
                return 1;
            }
            break;
        }
        case 13:
        {
            printf("Mate 500000kc.\n");
            printf("Chcete pokracovat dale? Jestli ano, zadejte 'a', jinak zadejte 'n':");
            scanf(" %c", &pokracovani);
            if (pokracovani == 'a' || pokracovani == 'A')
            {
                printf("Pokracujeme dal.\n");
                return 0;
            }
            else if(pokracovani == 'n' || pokracovani == 'N')
            {
                printf("Vase vyhra je 500000kc.\n");
                printf("Konec teto hry.\n");
                return 1;
            }
            break;
        }
        case 14:
        {
            printf("Mate 500000kc.\n");
            printf("Chcete pokracovat dale? Jestli ano, zadejte 'a', jinak zadejte 'n':");
            scanf(" %c", &pokracovani);
            if (pokracovani == 'a' || pokracovani == 'A')
            {
                printf("Pokracujeme dal.\n");
                return 0;
            }
            else if(pokracovani == 'n' || pokracovani == 'N')
            {
                printf("Vase vyhra je 500000kc.\n");
                printf("Konec teto hry.\n");
                return 1;
            }
            break;
        }
        case 15:
        {
            printf("Mate 1000000kc.\n");
            printf("Vyborne, vyhrali jste!\n");
            return 1;
        }
    }
}

void napovedy(int *padesat_na_padesat, int *pritel_na_telefonu, int *pomoc_z_publika)
{
    if((*padesat_na_padesat == 0) && (*pritel_na_telefonu == 0) && (*pomoc_z_publika == 0))
        printf("Dostupne napovedy: 1) 50:50 2) Pritel na telefonu 3) Zeptat se publika, pokud nechcete napovedu, zadejte 'n': ");
    if((*padesat_na_padesat >= 1) && (*pritel_na_telefonu == 0) && (*pomoc_z_publika == 0))
        printf("Dostupne napovedy: 2) Pritel na telefonu 3) Zeptat se publika, pokud nechcete napovedu, zadejte 'n': ");
    if((*padesat_na_padesat == 0) && (*pritel_na_telefonu >= 1) && (*pomoc_z_publika == 0))
        printf("Dostupne napovedy: 1) 50:50 3) Zeptat se publika, pokud nechcete napovedu, zadejte 'n': ");
    if((*padesat_na_padesat == 0) && (*pritel_na_telefonu == 0) && (*pomoc_z_publika >= 1))
        printf("Dostupne napovedy: 1) 50:50 2) Pritel na telefonu, pokud nechcete napovedu, zadejte 'n': ");
    if((*padesat_na_padesat >= 1) && (*pritel_na_telefonu >= 1) && (*pomoc_z_publika == 0))
        printf("Dostupna napoveda: 3) Zeptat se publika, pokud nechcete napovedu, zadejte 'n': ");
    if((*padesat_na_padesat >= 1) && (*pritel_na_telefonu == 0) && (*pomoc_z_publika >= 1))
        printf("Dostupna napoveda: 2) Pritel na telefonu, pokud nechcete napovedu, zadejte 'n': ");
    if((*padesat_na_padesat == 0) && (*pritel_na_telefonu >= 1) && (*pomoc_z_publika >= 1))
        printf("Dostupna napoveda: 1) 50:50, pokud nechcete napovedu, zadejte 'n': ");
    if((*padesat_na_padesat >= 1) && (*pritel_na_telefonu >= 1) && (*pomoc_z_publika >= 1))
        printf("Nemate dostupnou zadnou napovedu, zadej 'n': ");
}