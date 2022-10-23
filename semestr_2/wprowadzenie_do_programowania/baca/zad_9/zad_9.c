#include <stdio.h>
#include <stdbool.h>

int main() {
    int litery = 0;
    int znakiLokalne = 0;
    int wyrazy = 0;
    int max = 0;
    bool spaced = false;
    bool nowaLinijka = false;
    bool poczatek = true;
    char e;
    while((e=getchar()) != EOF) {
        switch (e) {
            case 10:
                if (znakiLokalne > max)
                    max = znakiLokalne;
                znakiLokalne = 0;
                nowaLinijka = true;
                spaced = false;
                continue;
            case 32:
                if (!spaced)
                    spaced = true;
                znakiLokalne++;
                break;
            case 9:
                if (!spaced)
                    spaced = true;
                znakiLokalne++;
                break;
            default:
                if ((e>= 65 && e<=90) || (e>=97 && e<=122)){
                    litery++;
                if (spaced){
                    wyrazy++;
                    spaced = false;
                }
                if (nowaLinijka){
                    wyrazy++;
                    nowaLinijka = false;
                }
                if (poczatek)
                    wyrazy++;
                    poczatek = false;
        }
                znakiLokalne++;
        }
    }
    if (!max)
        max = znakiLokalne;
        printf("%d %d %d", litery, wyrazy, max);
        return 0;
}
