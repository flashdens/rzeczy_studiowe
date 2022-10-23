#include <stdio.h>
#include <string.h>

int main() {
    int i;
    int male = 0;
    char e[20];
    scanf("%s", e);
    int d = strlen(e);
    if (strlen(e) < 3) return 2137;
    if (strlen(e) < 6) {
        for (i = 0; i < d; i++) {
            e[(d + i)] = e[i % d];
        }
        d *= 2;
    }
    if (e[0] >= 97 && e[0] <= 122) e[0] -= 32;
    for (i = 0; i < strlen(e); i++) {
        if (e[i] == 97 && i != d - 1) e[i] = 52;
        if (e[i] == 115 && i != d - 1) e[i] = 36;
        if (e[i] == 111 && i != d - 1) e[i] = 64;
        if (e[i] >= 97 && e[i] <= 122) male++;
    }
    int t = e[0];
    for (i = d; i > 0; i--) {
        e[i] = e[i - 1];
    }
    e[d+1] = '\0';
    e[1] = t;
    e[0] = 33;
    printf("%s", e);
    printf("%d", male);
    return 0;
}
