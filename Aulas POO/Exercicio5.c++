#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Produto {
private:
    string n;
    double p;
    double d;

public:
    void ler();
    double precoFinal() const;
    void mostrar() const;
};

void Produto::ler() {
    getline(cin, n);
    cin >> p >> d;
}

double Produto::precoFinal() const {
    return p * (1 - d / 100.0);
}

void Produto::mostrar() const {
    cout << fixed << setprecision(2);
    cout << n << " " << precoFinal() << endl;
}

int main() {
    Produto prod;
    prod.ler();
    prod.mostrar();
    return 0;
}