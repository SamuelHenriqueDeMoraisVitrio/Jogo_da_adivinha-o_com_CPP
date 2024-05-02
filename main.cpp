#include <iostream>

using namespace std;

bool chutes(short numSorte, short dificuldade){
  short numChute = 0;
  short tentativas = 1;
  short numD2 = 0;

  if(dificuldade == 2) numD2 = 16;
  else if(dificuldade == 3) numD2 = 6;

  do{

    cout << "\n\tTentativas " << tentativas - 1 << " chute um numero: ";
    cin >> numChute;
    tentativas++;
  }while(numChute != numSorte && tentativas != numD2);

  return (numChute == numSorte);
}

int main(){
  const short numSorte = 42;
  short dificuldade = 0; 

  cout << "\t********************\n";
  cout << "\t*----Hello Word----*\n";
  cout << "\t********************\n";

  cout << "\n\tEscolha sua dificuldade \n facil: 1\n medio: 2\n dificil: 3\n\tdificuldade: ";
  cin >> dificuldade;

  if(chutes(numSorte, dificuldade)) cout << "\n\tVocê ganhou, parabéns\n";
  else cout << "\n\tVocê perdeu, quem sabe na proxima.\n";
}
