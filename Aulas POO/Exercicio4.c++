#include <iostream>


using namespace std;

class TVetInt {
private:
    int vet[100];
    int n;

public:
    void ler();
    void inverter();
    void listar();
};

void TVetInt::ler() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> vet[i];
    }
}

void TVetInt::inverter() {
    for (int i = 0; i < n / 2; i++) {
        int temp = vet[i];
        vet[i] = vet[n - 1 - i];
        vet[n - 1 - i] = temp;
    }
}

void TVetInt::listar() {
    for (int i = 0; i < n; i++) {
        cout << vet[i];
        if (i != n - 1) cout << " ";
    }
    cout << endl;
}

int main() {
    TVetInt v;
    v.ler();
    v.inverter();
    v.listar();
    return 0;
}
