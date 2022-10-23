#ifndef Z3_Z3_H
#define Z3_Z3_H

using namespace std;

class Z3 {
public:
    float rzeczywista;
    float urojona;

    Z3 () {
        rzeczywista = urojona = 0;
    }

    Z3 (float _rzeczywista, float _urojona) {
        rzeczywista = _rzeczywista;
        urojona = _urojona;
    }

    operator short int () {
        int modRzeczywista = (short int) this->rzeczywista;
        int modUrojona = (short int) this->urojona;
        switch (modRzeczywista % 3) {
            case 0:
                this->rzeczywista = 0;
                break;
            case 1:
                this->rzeczywista = 1;
                break;
            case 2:
                this->rzeczywista = 2;
                break;
        }

        switch (modUrojona % 3) {
            case 0:
                this->urojona = 0;
                break;
            case 1:
                this->urojona = 1;
                break;
            case 2:
                this->urojona = 2;
                break;
        }
    }


    Z3 operator += (Z3& temp){
        Z3 wynik;
        wynik.rzeczywista = rzeczywista + temp.rzeczywista;
        wynik.urojona = urojona + temp.urojona;
        return wynik;
    }

    Z3 operator -= (Z3& temp){
        Z3 wynik;
        wynik.rzeczywista = rzeczywista - temp.rzeczywista;
        wynik.urojona = urojona - temp.urojona;
        return wynik;
    }

    Z3 operator *= (Z3& temp){
        Z3 wynik;
        wynik.rzeczywista = rzeczywista * temp.rzeczywista;
        wynik.urojona = urojona * temp.urojona;
        return wynik;
    }

    Z3 operator /= (Z3& temp){
        Z3 wynik;
        if (temp.rzeczywista == 0 || temp.urojona == 0){
            cout << ("Nie dziel przez zero cholero...") << endl;
            return *this;
        }
        wynik.rzeczywista = rzeczywista / temp.rzeczywista;
        wynik.urojona = urojona / temp.urojona;
        return wynik;
    }

    friend ostream& operator<<(ostream &strumyk, Z3 doWypisania);

};

Z3 operator+ (Z3& lewo, Z3& prawo){
    return lewo += prawo;
}

Z3 operator- (Z3& lewo, Z3 prawo){
    return lewo -= prawo;
}

Z3 operator* (Z3& lewo, Z3 prawo){
    return lewo *= prawo;
}

Z3 operator/ (Z3& lewo, Z3 prawo){
    if (prawo.rzeczywista == 0 || prawo.urojona == 0){
        cout << "Nie dziel przez zero cholero..." << endl;
        return lewo;
    }
    return lewo /= prawo;
}

ostream& operator<<(ostream& strumyk,Z3 doWypisania){
    doWypisania.operator short ();
    strumyk << "%3: " << doWypisania.rzeczywista << "+" << doWypisania.urojona << "i" << endl;
    return strumyk;
}
#endif //Z3_Z3_H

