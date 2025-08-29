#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm> 

using namespace std;

class Time
{
   private:
     string apelido;
     string nome;
     int    pontos;
     int    golsFeitos;
     int    golsSofridos;
   public:
     Time();
     void ler();
     void init(string apelido, string nome);
     int getSaldoGols() const;
     string getNome() const;
     string getApelido() const;
     int getGolsFeitos() const; 
     int getGolsSofridos() const;
     int getPontos() const;
     void computarPartida(int golsFeitos, int golsSofridos);
};

class Jogo
{
  private:
     string  apelidoTimeCasa, apelidoTimeFora;
     int     golsTimeCasa, golsTimeFora;
  public:
     void ler();
     int getGolsTimeCasa() const;  
     int getGolsTimeFora() const;
     string getApelidoTimeCasa() const; 
     string getApelidoTimeFora() const;
};

class Campeonato
{
    private:
      Time vet[100];
      int   qtd;
      void ordenar();
      int obterIndice(string apelido) const;
    public:
      Campeonato();
      void ler();
      void computarJogo(const Jogo &j); 
      void listar() const;
};

//-----------------------------------

Time::Time()
{
   pontos = golsFeitos=golsSofridos = 0;
   nome=apelido="";
}
void Time::ler()
{
   cin >> apelido >> ws;
   getline(cin,nome);  
}
void Time::init(string aApelido, string aNome)
{
  apelido = aApelido; 
  nome = aNome;
}
int Time::getSaldoGols() const
{
  return golsFeitos - golsSofridos;
}
string Time::getNome() const
{
  return nome;
}
string Time::getApelido() const
{
  return apelido;
}
int Time::getGolsFeitos() const
{
  return golsFeitos;
}
int Time::getGolsSofridos() const
{
  return golsSofridos;
}
int Time::getPontos() const
{
  return pontos;
}
void Time::computarPartida(int aGolsFeitos, int aGolsSofridos)
{
  golsFeitos += aGolsFeitos;
  golsSofridos += aGolsSofridos;
  if (aGolsFeitos>aGolsSofridos)
     pontos += 3;
  else if (aGolsFeitos==aGolsSofridos)
     pontos += 1;
};

void Jogo::ler()
{
  cin >> apelidoTimeCasa >> golsTimeCasa >> ws;
  cin.ignore();
  cin >> ws >> golsTimeFora >> apelidoTimeFora;
}
int Jogo::getGolsTimeCasa() const
{
   return golsTimeCasa;
}
int Jogo::getGolsTimeFora() const
{
   return golsTimeFora;
}
string Jogo::getApelidoTimeCasa() const
{
   return apelidoTimeCasa;
}
string Jogo::getApelidoTimeFora() const
{
   return apelidoTimeFora;
}

Campeonato::Campeonato()
{
   qtd = 0;
}
int Campeonato::obterIndice(string apelido) const
{
    bool achou = false;  
    int i=0;
    while (!achou && i<qtd)
       if (vet[i].getApelido() == apelido)
         achou = true;
       else      
         i++;
    return achou?i:-1;  
}

bool compTimes(const Time &a, const Time &b)
{
     if (a.getPontos()!=b.getPontos()) 
        return a.getPontos() > b.getPontos();
     else if (a.getSaldoGols()!=b.getSaldoGols())
        return a.getSaldoGols() > b.getSaldoGols();
     else if (a.getGolsFeitos()!=b.getGolsFeitos())
        return a.getGolsFeitos() > b.getGolsFeitos();
     else
        return a.getNome() < b.getNome();
}

void Campeonato::ordenar()
{
   sort(vet, vet + qtd, compTimes);
}

void Campeonato::ler()
{
   cin >> qtd;
   for(int i=0;i<qtd;i++)
      vet[i].ler();
}

void Campeonato::computarJogo(const Jogo &j)  
{
   int posTimeCasa = obterIndice(j.getApelidoTimeCasa());
   int posTimeFora = obterIndice(j.getApelidoTimeFora());
   if (posTimeFora!=-1 && posTimeCasa!=-1)
   {
       vet[posTimeCasa].computarPartida(j.getGolsTimeCasa(), j.getGolsTimeFora());
       vet[posTimeFora].computarPartida(j.getGolsTimeFora(),j.getGolsTimeCasa());
   }
   ordenar();
}

void Campeonato::listar() const
{
   cout << "#  " << setw(31) << left << "Nome" << " Pts   SG   GP   GC" << endl; 
   int rank=0; 
   for(int i=0;i<qtd;i++)
   {
       if (i==0 || vet[i].getPontos() != vet[i-1].getPontos())
         rank = i+1;
       cout << right << setfill('0') << setw(2) << rank << " "
            << left << setfill(' ') << setw(30) << vet[i].getNome()
            << right << setw(5) << vet[i].getPontos()
            << setw(5) << vet[i].getSaldoGols()
            << setw(5) << vet[i].getGolsFeitos()
            << setw(5) << vet[i].getGolsSofridos() << endl;
   }        
}


int main()
{
   Campeonato c;
   Jogo j;
   int qtd;
   
   c.ler();
   cin >> qtd;
   for(int i=0;i<qtd;i++)  
   {
      j.ler();
      c.computarJogo(j);      
   }
   c.listar();
   return 0;
}