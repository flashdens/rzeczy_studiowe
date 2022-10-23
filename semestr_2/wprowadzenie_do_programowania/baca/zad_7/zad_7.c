#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Element{
    int val;
    struct Element* next;
} Element;

struct Kolejka{
    struct Element *glowa, *ogon;
} Kolejka;

struct Kolejka* stworzKolejke(){
    struct Kolejka* q = (struct Kolejka*)calloc(1, sizeof(Kolejka));
    q->glowa = q->ogon = NULL;
    return q;
}

struct Element* stworzElement(int k){
    struct Element* temp = (struct Element*)calloc(1, sizeof(Kolejka));
    temp->val = k;
    temp->next = NULL;
    return temp;
}

void push(struct Kolejka *q, int wartosc){
    struct Element* temp = stworzElement(wartosc);
    if(!q->ogon){
        q->glowa = q->ogon = temp;
        return;
    }
    temp->val = wartosc;
    temp->next = NULL;
    q->ogon->next = temp;
    q->ogon = temp;
}

void empty(struct Kolejka *q){
    if(!q->glowa)
        printf("TAK\n");
    else printf("NIE\n");
}

void first(struct Kolejka *q){
    if(q->glowa)
        printf("%d\n",q->glowa->val);
}

void pop(struct Kolejka *q){
    if(!q->glowa)
        return;
    struct Element* temp = q->glowa;
    q->glowa = q->glowa->next;
    if(!q->glowa)
        q->ogon = NULL;
    free(temp);
}

int main () {
    int i;
    scanf("%d", &i);
    struct Kolejka *q = stworzKolejke();
    while (i) {
        char k[6];
        scanf("%s", k);
        if (!strcmp(k, "EMPTY"))
            empty(q);
        if (!strcmp(k, "FIRST"))
            first(q);
        if (!strcmp(k, "POP"))
            pop(q);
        if (!strcmp(k, "PUSH")) {
            int ile;
            scanf("%d", &ile);
            push(q, ile);
        }
        i--;
    }
    return 0;
}
