// Miloszek Bogacz
#include <iostream>

using namespace std;

void swap (int *a, int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

void wczytajTablice(int *tab, int rozmiar){
    for (int i = 0; i < rozmiar; ++i) {
        cin >> tab[i];
    }
}


int znajdzIdxImpostora (int *tab, int len) {
    for (int i = 0; i < len; ++i) {
        if(tab[i] > tab[i+1])
            return i;
    }
    cout << "OK" << endl;
    return -1;
}

void bubel (int *tab, int len) {
    for (int i = 0; i < len - 1; ++i) {
        for (int j = 0; j < len - 1; ++j) {
            if(tab[j] > tab[j+2])
                swap(&tab[j], &tab[j+2]);
        }
    }
}

int main () {
    int testy, rozmiar;
    cin >> testy;
    for (int i = 0; i < testy; ++i) {
        cin >> rozmiar;
        int tab[rozmiar - 1];
        int len = sizeof(tab)/ sizeof(tab[0]);
        wczytajTablice(tab, rozmiar);
        bubel(tab, len);
        int idx = znajdzIdxImpostora(tab, len);
        if (idx != -1)
            cout << idx << endl;
    }
}
