#include <stdio.h>
#include <stdbool.h>

void kadane(char tab[], int dlugosc, int jedynkiLimit) {
    int max = 0, jedynkiLokalne = 0;
    int aktualne = 0;
    for (int i = 0; i < dlugosc; i++) {
        bool czyZmienionoMax = false;
        for (int j = i; j < dlugosc; j++) {
            if (tab[j] == 48)
                aktualne++;
            else {
                jedynkiLokalne++;
                if (jedynkiLokalne > jedynkiLimit) {
                    if (aktualne > max)
                        max = aktualne;
                    aktualne = 0;
                    jedynkiLokalne = 0;
                    czyZmienionoMax = true;
                    break;
                }
                if (!czyZmienionoMax)
                    aktualne++;
            }
        }
        if (czyZmienionoMax == false) {
            if (aktualne > max)
            max = aktualne;
            break;
        }
        aktualne = 0;
        jedynkiLokalne = 0;
    }
    printf("%d\n", max);
}

int main() {
    char t[500000];
    int iteracje, dlugosc, jedynki;
    scanf("%d", &iteracje);
    while (iteracje) {
        scanf("%d %d\n", &dlugosc, &jedynki);
        scanf("%s", t);
        kadane(t, dlugosc, jedynki);
        iteracje--;
    }
    return 0;
}
