#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LATWY_ZAKRES 25
#define LATWY_PROBY 8

#define SREDNI_ZAKRES 50
#define SREDNI_PROBY 7

#define TRUDNY_ZAKRES 100
#define TRUDNY_PROBY 6

#define ULTRA_ZAKRES 1000
#define ULTRA_PROBY 10

void losowanko(int MAX_LICZBA, int MAX_PROB)
{
    int proby = 0;
    int podana_liczba = 0;
    int random = rand() % MAX_LICZBA + 1;
    printf("Witaj w grze Zgadnij liczbe!\n");
    printf("Masz %d prob, aby zgadnac liczbe od 1 do %d.\n", MAX_PROB, MAX_LICZBA);
    printf("Sprobuj zgadnac pierwsza liczbe: ");

    do {
        proby++;
        scanf("%d", &podana_liczba);
        if (podana_liczba > random) {
            printf("Za duza bratku!\n");
        } else if (podana_liczba < random) {
            printf("Za maly bracie...\n");
        }
        if (podana_liczba != random) {
            printf("Pozostalo prob: %d\n", MAX_PROB - proby);
            printf("Sprobuj jeszcze raz: ");
        }
    } while (podana_liczba != random && proby < MAX_PROB);
    if (podana_liczba == random) {
        printf("Masz wyjebane i bylo ci dane. Poprawna liczba to: %d\n", random);
        printf("Zgadles w %d probach. Niezly z ciebie koksownik. \n", proby);
    } else if (proby == MAX_PROB) {
        printf("Wariacie w tyle prob przegrac to trzeba byc toba. Poprawna liczba to: %d\n", random);
    }
}

void menu()
{
    printf("=============MENU=============\n");
    printf("1. Poziom Latwy             8)\n");
    printf("2. Poziom Sredni            :P\n");
    printf("3. Poziom Trudny            :O\n");
    printf("4. Poziom Ultra Psychol     :X\n");
    printf("Wybierz wpisujac liczbe(1,2,3)\n");
    printf("==============================\n\n");

    printf("Poziom: ");
}

int main(void)
{
    srand(time(NULL));
    int poziom;
    char wybor;
    do {
        menu();
        scanf("%d", &poziom);

        switch (poziom) {
            case 1: printf("Naprawde wybrales tryb latwy? xd\n");
                losowanko(LATWY_ZAKRES,LATWY_PROBY);
                break;
            case 2: printf("Poziom mid tak jak ty, tryb sredni haha\n");
                losowanko(SREDNI_ZAKRES,SREDNI_PROBY);
                break;
            case 3: printf("Ale masz wielkie jajca kolezko, tryb trudny!\n");
                losowanko(TRUDNY_ZAKRES,TRUDNY_PROBY);
                break;
            case 4: printf("Takich dwoch jak ty to nie ma nawet jednego, tryb ultra :D\n");
                losowanko(ULTRA_ZAKRES,ULTRA_PROBY);
                break;
            default: printf("Nie ma takiej opcji w menu!\n");
                break;
        }

        printf("\nCzy chcesz zagrac jeszcze raz? (t/n): ");
        fflush(stdout);
        scanf(" %c", &wybor);
    } while (wybor == 't' || wybor == 'T');

    return 0;
}
