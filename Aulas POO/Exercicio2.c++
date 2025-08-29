#include <iostream>
#include <string>
using namespace std;

class TMatriz {
private:
    char mat[100][100];
    int n, m;

public:
    void ler();
    void transposta();
    void mostrar();
};

void TMatriz::ler() {
    cin >> n >> m;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string linha;
        getline(cin, linha);
        for (int j = 0; j < m; j++) {
            mat[i][j] = linha[j];
        }
    }
}

void TMatriz::transposta() {
    char nova[100][100];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            nova[i][j] = mat[j][i];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            mat[i][j] = nova[i][j];
        }
    }
    int aux = n;
    n = m;
    m = aux;
}

void TMatriz::mostrar() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mat[i][j];
        }
        cout << endl;
    }
}

int main() {
    TMatriz a;
    a.ler();
    a.transposta();
    a.mostrar();
    return 0;
}