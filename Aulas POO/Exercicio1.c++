#include <iostream>
#include <iomanip>
using namespace std;

class TVet {
private:
    double vet[100];
    int n;

public:
    void ler();
    double maior();
    double menor();
    double mediaEx();
};

void TVet::ler() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> vet[i];
    }
}

double TVet::maior() {
    double m = vet[0];
    for (int i = 1; i < n; i++) {
        if (vet[i] > m) {
            m = vet[i];
        }
    }
    return m;
}

double TVet::menor() {
    double m = vet[0];
    for (int i = 1; i < n; i++) {
        if (vet[i] < m) {
            m = vet[i];
        }
    }
    return m;
}

double TVet::mediaEx() {
    double maiorVal = maior();
    double menorVal = menor();
    double soma = 0.0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (vet[i] != maiorVal && vet[i] != menorVal) {
            soma += vet[i];
            count++;
        }
    }
    if (count == 0)
        return 0.0;
    return soma / count;
}
int main() {
    TVet v;
    v.ler();
    cout << fixed << setprecision(2);
    cout << "Maior: " << v.maior() << endl;
    cout << "Menor: " << v.menor() << endl;
    cout << "Media sem extremos: " << v.mediaEx() << endl;
    return 0;
}