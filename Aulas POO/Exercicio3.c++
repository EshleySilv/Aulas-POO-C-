#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;


class TVertice
{
   private:
     double x,y;
   public:
     void ler();  
     double distancia(TVertice v); 
};

class TPoligono
{
   private:
     TVertice vet[1000];
     int     qtd;
   public:
     void ler();
     double perimetro();
};


void TVertice::ler()
{
   cin >> x >> y;
}

double TVertice::distancia(TVertice v)
{
   return sqrt(pow(x - v.x, 2) + pow(y - v.y, 2));
}

void TPoligono::ler()
{
   cin >> qtd;
   for (int i = 0; i < qtd; i++)
      vet[i].ler();
}

double TPoligono::perimetro()
{
   double perim = vet[qtd-1].distancia(vet[0]);
   for (int i = 0; i < qtd-1; i++)
      perim += vet[i].distancia(vet[i+1]);
   return perim;
}


int main()
{
    TPoligono p;
    p.ler();
    cout << fixed << setprecision(2);
    cout << "perimetro - " << p.perimetro() << endl;
    return 0;
}