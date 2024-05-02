#include <iostream>

using namespace std;

bool chutes(short numSorte, short dificuldade, short *tentativas){
  short numChute = 0;
  short numD2 = -1;

  if(dificuldade == 2) numD2 = 16;
  else if(dificuldade == 3) numD2 = 6;

  do{

    cout << "\n\tTentativas " << *tentativas << " chute um numero: ";
    *tentativas = *tentativas + 1;
    cin >> numChute;

    if(numChute < numSorte)cout << "\tSeu numero é menor que o numero da sorte.\n";
    else if(numChute > numSorte) cout << "\tSeu numero é maior que o numero da sorte.\n";

  }while(numChute != numSorte && *tentativas != numD2);

  return (numChute == numSorte);
}

int main(){
  const short numSorte = 42;
  short dificuldade = 0; 
  short tentativas = 0;

  cout << "\t********************\n";
  cout << "\t*----Hello Word----*\n";
  cout << "\t********************\n";

  cout << "\n\tEscolha sua dificuldade \n facil: 1\n medio: 2\n dificil: 3\n\tdificuldade: ";
  cin >> dificuldade;

  if(chutes(numSorte, dificuldade, &tentativas)) cout << "\n\tVocê ganhou, parabéns\n";
  else cout << "\n\tVocê perdeu, quem sabe na proxima.\n";

  cout << "\n\tSeu tentou " << tentativas << " vezes\n\n";
}
