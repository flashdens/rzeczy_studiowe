#include <stdio.h>

void szyfratoinator (char w[], char c){
    for(int i = 0; w[i]!='\0'; i++){
        if (c == 83)
            w[i] += 3;
        else
            w[i] -= 3;
        if (w[i] < 97)
            w[i] += 26;
        else if (w[i] > 122)
            w[i] -= 26;
    }
    printf("%s\n", w);
}

int main () {
    int x;
    char c, w[30];
    scanf("%d", &x);
    for(int i=0;i<x;i++){
        scanf(" %c", &c);
        scanf("%s", w);
        szyfratoinator(w, c);
    }
    return 0;
}
