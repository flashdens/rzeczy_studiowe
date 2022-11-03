#include "Z3_filipa.h"
	
class Wektor {
public:
    unsigned int size;
    int val[];

    Wektor() = default;

    Wektor (unsigned int n) {
        *val = *new int[n];
        for (int i = 0; i < n; ++i) {
            val[i] = 0;
        }
        size = n;
    }

    Wektor (unsigned int n, Z3 tab[n]) {
        *val = *new int[n];
        for (int i = 0; i < n; ++i) {
            val[i] = tab[i].val;
        }
    }

    Wektor operator [] (unsigned int idx){
        if (idx > size){
            cout << "Niezgodne wymiary wektorow. Wypierdalaj" << endl;
            return 0;
        }
        return val[idx];
    }

//    Wektor operator [] (unsigned int idx, int zval){
//        if (idx > size){
//            cout << "Niezgodne wymiary wektorow. Wypierdalaj" << endl;
//            return 0;
//        }
//        val[idx] = zval;
//        return val[idx];
//    }

    Wektor operator += (Wektor prawo){
        if (this->size != prawo.size){
            cout << "Niewlasciwa dlugosc wektora!" << endl;
            return *this;
        }
        for (int i = 0; i < this->size; ++i) {
            this->val[i] = this->val[i] + prawo.val[i];
        }
        return *this;
    }

    Z3 operator * (Wektor prawo){
        if (this->size != prawo.size){
            cout << "Niewlasciwa dlugosc wektora!" << endl;
            return 0;
        }
        int liczydlo = 0;
        for (int i = 0; i < this->size; ++i) {
            this->val[i] = this->val[i] * prawo.val[i];
            liczydlo += this->val[i] * prawo.val[i];
        }
        return Z3(liczydlo);
    }

    Wektor operator -= (Wektor prawo){
        if (this->size != prawo.size){
            cout << "Niewlasciwa dlugosc wektora!" << endl;
            return *this;
        }
        for (int i = 0; i < this->size; ++i) {
            this->val[i] = this->val[i] - prawo.val[i];
        }
        return *this;
    }

    Wektor operator *= (Z3 prawo){
        for (int i = 0; i < this->size; ++i) {
            this->val[i] = this->val[i] * prawo.val;
        }
        return *this;
    }

    Wektor operator /= (Z3 prawo){
        if (prawo.val == 0){
            cout << "nie dziel przez zero cholero...";
            return *this;
        }

        for (int i = 0; i < this->size; ++i) {
            this->val[i] = this->val[i] / prawo.val;
        }
        return *this;
    }

  unsigned int wymiar () const {
      return this->size;
    }
};

Wektor operator + (Wektor lewo, Wektor prawo){
    return lewo += prawo;
}

Wektor operator - (Wektor lewo, Wektor prawo){
    return lewo -= prawo;
}

Wektor operator * (Wektor lewo, Z3 prawo){
    return lewo *= prawo;
}

Wektor operator / (Wektor lewo, Z3 prawo){
    return lewo /= prawo;
}

ostream& operator << (ostream &COUT, const Wektor toOut) {
    for (int i = 0; i < toOut.size; ++i) {
        cout << " a[" << toOut.val << "], ";
    }
    return COUT;
}

#endif //AIDS_WEKTOR_H

