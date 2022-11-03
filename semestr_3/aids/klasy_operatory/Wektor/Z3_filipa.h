using namespace std;

class Z3 {

public:
    short int val;

    Z3(){
        this->val = 0;
    }

    Z3(short int x){
        this->val = x % 3;
    }

    Z3 operator += (const Z3& a){
        return this->val = (this->val + a.val) % 3;
    }

    Z3 operator -= (const Z3& a){
        return this->val = (this->val - a.val) % 3;
    }

    Z3 operator * (const Z3& a){
        return this->val = (this->val * a.val) % 3;
    }

    Z3 operator / (const Z3& a){
        if(a.val == 0){
            cout << "Nie dziel przez 0!" << endl;
            return this->val = this->val;
        }
        else {
            return this->val = (this->val / a.val) % 3;
        }
    }

    Z3 operator /= (const Z3& a){
        if(a.val == 0){
            cout << "Nie dziel przez 0!" << endl;
            return this->val = this->val;
        }
        else {
            return this->val = (this->val / a.val) % 3;
        }
    }

    Z3 operator *= (const Z3& a){
        return this->val = (this->val * a.val) % 3;
    }


};

Z3 operator+(Z3& a, Z3& b){
    return Z3(a+b);
}

Z3 operator-(Z3& a, Z3& b){
    return Z3(a-b);
}

Z3 operator*(Z3& a, Z3& b){
    return Z3(a*b);
}

Z3 operator/(Z3& a, Z3& b){
    if(b.val == 0){
        cout << "Nie dziel przez 0!" << endl;
        return a;
    }
    else {
        return Z3(a / b);
    }
}

ostream& operator<<(ostream& stream, const Z3& z3){
    stream << z3.val;
    return stream;
}

