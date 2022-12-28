//chochlik drukarski
#include <stdio.h>

int main(){
    int rozmiarTestu, liczbaPlakatow=0, zjadacz;
    scanf("%d",&rozmiarTestu);
    int wysokosc[rozmiarTestu];
    for(int i=0; i<rozmiarTestu ;i++){
        scanf("%d",&zjadacz);
        scanf("%d",&wysokosc[i]);
    }
    for (int obecny=0;obecny<rozmiarTestu;obecny++){
        if (wysokosc[obecny]==0)
            continue;
        int nastepny = obecny+1;
        while (wysokosc[obecny]<=wysokosc[nastepny]){
            if (wysokosc[obecny]==wysokosc[nastepny])
                wysokosc[nastepny]=0;
            nastepny++;
        }
        liczbaPlakatow++;

    }
    printf("%d", liczbaPlakatow);
    return 0;
}
