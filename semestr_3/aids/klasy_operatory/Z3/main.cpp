#include <iostream>
#include "Z3.h"

int main () {
    Z3 zespolona1 (2,2);
    Z3 zespolona2 (69, 4);
    zespolona1.rzeczywista = 2;
    zespolona1.urojona = 2;
    zespolona2.rzeczywista = 69;
    zespolona2.urojona = 4;
    cout << "Dla liczb urojonych " << zespolona1.rzeczywista << "+" << zespolona1.urojona << "i oraz " << zespolona2.rzeczywista << "+" << zespolona2.urojona << "i" << endl;
    Z3 zespolona3 = zespolona1 + zespolona2;
    cout << "+: " << zespolona3.rzeczywista << "+" << zespolona3.urojona << "i" << endl;
    zespolona3 = zespolona1 - zespolona2;
    cout << "-: " << zespolona3.rzeczywista << "+" << zespolona3.urojona << "i" << endl;
    zespolona3 = zespolona1 * zespolona2;
    cout << "*: " << zespolona3.rzeczywista << "+" << zespolona3.urojona << "i" << endl;
    zespolona3 = zespolona1 / zespolona2;
    cout << "/: " << zespolona3.rzeczywista << "+" << zespolona3.urojona << "i" << endl;
    zespolona1.rzeczywista = 2;
    zespolona1.urojona = 2;
    zespolona2.rzeczywista = 69;
    zespolona2.urojona = 4;
    zespolona3 = zespolona1 += zespolona2;
    cout << "+=: " << zespolona3.rzeczywista << "+" << zespolona3.urojona << "i" << endl;
    zespolona1.rzeczywista = 2;
    zespolona1.urojona = 2;
    zespolona2.rzeczywista = 69;
    zespolona2.urojona = 4;
    zespolona3 = zespolona1 -= zespolona2;
    cout << "-=: " << zespolona3.rzeczywista << "+" << zespolona3.urojona << "i" << endl;
    zespolona1.rzeczywista = 2;
    zespolona1.urojona = 2;
    zespolona2.rzeczywista = 69;
    zespolona2.urojona = 4;
    zespolona3 = zespolona1 *= zespolona2;
    cout << "*=: " << zespolona3.rzeczywista << "+" << zespolona3.urojona << "i" << endl;
    zespolona1.rzeczywista = 2;
    zespolona1.urojona = 2;
    zespolona2.rzeczywista = 69;
    zespolona2.urojona = 4;
    zespolona3 = zespolona1 /= zespolona2;
    cout << "/=: " << zespolona3.rzeczywista << "+" << zespolona3.urojona << "i" << endl;
    cout << "Zespolona1 ";
    cout << zespolona1;
    cout << "Zespolona2 ";
    cout << zespolona2;
    return 0;
}
