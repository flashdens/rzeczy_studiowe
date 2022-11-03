#include <iostream>
#include <stack>

using namespace std;

void wczytajTablice(int *tab, int rozmiar){
    for (int i = 0; i < rozmiar; ++i) {
        cin >> tab[i];
    }
}

void wypiszTablice(int *tab, int rozmiar){
    for (int i = 0; i < rozmiar; ++i) {
        cout << tab[i] << " ";
    }
    cout << endl;
}

void swap (int *a, int *b){
    int temp = *b;
    *b = *a;
    *a = temp;
}

int partycjonuj (int tab[], int low, int high) {
    int pivot = tab[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (tab[j] <= pivot) {
            i++;
            swap(&tab[i], &tab[j]);
        }
    }
    swap(&tab[i+1], &tab[high]);
    return (i+1);
}

void sortuj (int tab[], int low, int high) {
    stack<int> stos;
    stos.push(low);
    stos.push(high);
    while (!stos.empty()){
        high = stos.top();
        stos.pop();
        low = stos.top();
        stos.pop();
        int pivot = partycjonuj(tab, low, high);
        if (pivot - 1 > low){
            stos.push(low);
            stos.push(pivot-1);
        }
        if (pivot + 1 < high) {
            stos.push(pivot+1);
            stos.push(high);
        }
    }
}

int main () {
int testy, rozmiar;
cin >> testy;
    for (int i = 0; i < testy; ++i) {
        cin >> rozmiar;
        int tab[rozmiar-1];
        wczytajTablice(tab, rozmiar);
        sortuj(tab, 0, rozmiar-1);
        wypiszTablice(tab, rozmiar);
    }
}
