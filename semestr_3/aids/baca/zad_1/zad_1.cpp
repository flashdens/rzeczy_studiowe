#include <iostream>
#include <string>

using namespace std;

int main() {
    string slowo;
    int iteracje;
    cin >> iteracje;
    for (int j = 0; j < iteracje; j++){
        cin >> slowo;
        int dlugoscSlowa = slowo.size();
        for (int i = dlugoscSlowa - 1; i != 0; --i)
            cout << slowo[i];
        cout << slowo[0] << endl;
        slowo[0] = '\0';
    }
    return 0;
}
