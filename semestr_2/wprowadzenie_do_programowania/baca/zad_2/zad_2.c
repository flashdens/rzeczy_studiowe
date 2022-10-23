#include <stdio.h>
#include <stdbool.h>
int main(){
    int R;
    int C;
    int l=0;
    int n = 0;
    bool czyWcinac = true;
    int m = 0;
    scanf("%d %d",&R, &C);
    while(R*2>n){
    for(int i = 0; i<R; i++){
        for(int j = 0; j<C; j++){
            if(j==0 && czyWcinac==true){
                m++;
                printf("  ");
                if(m==2)czyWcinac = false;
                continue;
            }
            if(l%2==0) printf("+-");
            else printf("|.");
        }
        if(l%2==0) printf("+\n");
        else printf("|\n");
        l++;
        n++;
    }
    }
    for(int i=0; i<C; i++){
        printf("+-");
    }
    printf("+\n");
    return 0;
}
