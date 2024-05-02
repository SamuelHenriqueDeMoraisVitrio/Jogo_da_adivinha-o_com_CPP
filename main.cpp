#include <iostream>

using namespace std;

bool chutes(short numSorte, short dificuldade, int *tentativas, short *pontos){
  short numChute = 0;
  short numD2 = -1;

  if(dificuldade == 2){
    numD2 = 16;
    *pontos = 200;
  }else if(dificuldade == 3){
    numD2 = 6;
    *pontos = 300;
  }

  do{

    cout << "\n\tTentativas " << *tentativas << " chute um numero: ";

    cin >> numChute;

    if(numChute < numSorte)cout << "\tSeu numero é menor que o numero da sorte.\n";
    else if(numChute > numSorte) cout << "\tSeu numero é maior que o numero da sorte.\n";

    if(*tentativas > 0 || numChute == numSorte){
      if(dificuldade == 1) *pontos = *pontos - 2;
      else if(dificuldade == 2) *pontos = *pontos - 14;
      else if(dificuldade == 3) *pontos = *pontos - 60;
    }

    *tentativas = *tentativas + 1;
  }while(numChute != numSorte && *tentativas != numD2);

  return (numChute == numSorte);
}

int main(){
  const short numSorte = 42;
  short dificuldade = 0; 
  int tentativas = 0;
  short pontos = 100;

  cout << "\t********************\n";
  cout << "\t*----Hello Word----*\n";
  cout << "\t********************\n";

  cout << "\n\tEscolha sua dificuldade \n facil: 1\n medio: 2\n dificil: 3\n\tdificuldade: ";
  cin >> dificuldade;

  if(chutes(numSorte, dificuldade, &tentativas, &pontos)) cout << "\n\tVocê ganhou, parabéns\n";
  else{
    cout << "\n\tVocê perdeu, quem sabe na proxima.\n";
    pontos = 0;
  }

  cout << "\n\tVocê tentou " << tentativas << " vezes\n\n\t" << pontos << " Pontos\n\n";
}
