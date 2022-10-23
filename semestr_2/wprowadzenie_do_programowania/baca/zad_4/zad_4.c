#include <stdio.h>

void minmax(int tab[], int a) {
    int min = tab[0], max = tab[0];;
    for (int i = 1; i < a; i++) {
        if (tab[i] > max)max = tab[i];
        else if (tab[i] < min)min = tab[i];
    }
    printf("%d %d\n", min, max);
}

int main() {
    int x, y;
    int a[500];
    scanf("%d", &x);
    while (x) {
        scanf("%d", &y);
        for (int i = 0; i < y; i++) {
            scanf("%d", &a[i]);
        }
        minmax(a, y);
        x--;
    }
    return 0;
}
