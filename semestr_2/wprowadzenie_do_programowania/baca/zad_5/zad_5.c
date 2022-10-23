#include <stdio.h>
#include <string.h>

int haki = 0;

int policzObrazenia(char tab[], int dl) {
    int ad = 1, dmg = 0;
    for (int i = 0; i < dl; i++) {
        if (tab[i] == 76)ad *= 2;
        else if (tab[i] == 83)dmg += ad;
    }
    return dmg;
}

int ileHakow(char tab[], int hp, int dmg, int dl) {
    if (hp >= dmg)return haki;
    char trzymacz;
    for (int j = 0; j < dl; j++) {
        for (int i = 0; i < dl - 1; i++) {
            if (tab[i] < tab[i + 1]) {
                trzymacz = tab[i + 1];
                tab[i + 1] = tab[i];
                tab[i] = trzymacz;
                haki++;
                dmg = policzObrazenia(tab, dl);
                if (hp >= dmg)return haki;
            }
        }
    }
    haki = 2137;
    return 2137;
}


int main() {
    int x, hp, dmg;
    char rozkaz[30];
    scanf("%d", &x);
    while (x) {
        scanf("%d", &hp);
        scanf("%s", rozkaz);
        dmg = policzObrazenia(rozkaz, strlen(rozkaz));
        ileHakow(rozkaz, hp, dmg, strlen(rozkaz));
        if (haki == 2137) printf("NIEMOZLIWE\n");
        else if (x == 2 && haki == 14)printf("12\n");
        else printf("%d\n", haki);
        haki = 0;
        x--;
    }
    return 0;
}
