#include <iostream>

using namespace std;

int main () {
    int kolumny, wysokosc, max = 0, pompy = 0, ostatniaWartosc;
    bool bajoro = false;
    cin >> kolumny;
    for (int i = 0; i < kolumny; ++i) {
        cin >> wysokosc;
        if (!max) {
            max = wysokosc;
        }
        if (wysokosc <= max && wysokosc != ostatniaWartosc){
            bajoro = true;
        }

        if (wysokosc >= max && bajoro){
            if (ostatniaWartosc < wysokosc && i == kolumny-1)
                break;
            pompy++;
            bajoro = false;
        }
        ostatniaWartosc = wysokosc;
        }

    if (!pompy) {
        pompy++;
    }
    cout << pompy << endl;
    return 0;
}
