#include <iostream>

using namespace std;

bool chutes(short numSorte){
  short numChute = 0;
  short tentativas = 0;

  do{
    cout << "\n\tTentativa " << tentativas << " chute um numero: ";
    cin >> numChute;
    tentativas++;
  }while(numChute != numSorte);

  return (numChute == numSorte);
}

int main(){
  const short numSorte = 42;

  cout << "\t********************\n";
  cout << "\t*----Hello Word----*\n";
  cout << "\t********************\n";

  const bool ganhou =  chutes(numSorte);

  cout << "\n\tSua vitoria é " << ganhou << "\n";
}
