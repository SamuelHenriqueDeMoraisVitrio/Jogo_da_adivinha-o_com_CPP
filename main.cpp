/*
  Um algoritmo que tem como objetivo ser um jogo com 3 niveis de dificuldade, 
sendo elas: [facil, medio, dificil].
  O jogo terá um numero sorteado e o objetivo do jogador é descobrir o numero sorteado pelo metodo de tentativa e erro.
*/
#include <iostream> //Biblioteca principal de entrada e saida padrão

using namespace std; // using std para agilizar o proscesso de codar os 'cout' e 'cin'.

bool chutes(short numSorte, short dificuldade, int *tentativas, short *pontos); // Mostrando minha função para o codigo.

bool chutes(short numSorte, short dificuldade, int *tentativas, short *pontos){ // Declarando função.
  short numChute = 0; // Dando um valor inicial para numChute.
  short numD2 = -1; // Valor inicial para numD2.

  if(dificuldade == 2){ // Se escolha da dificuldade seja media, faça numD2 == 16 e iniciar com 200 pontos.
    numD2 = 16;
    *pontos = 200;
  }else if(dificuldade == 3){ // Se dificuldade for igual a dificil numD2 == 6 e iniciar com 300 pontos.
    numD2 = 6;
    *pontos = 300;
  }

  do{

    cout << "\n\tTentativas " << *tentativas << " chute um numero: "; // Mostra o numero da tentativa indo de 0 a infinito dependendo da dificuldade escolhida.

    cin >> numChute; // lê o valor chutado.

    if(numChute < numSorte)cout << "\t\033[1;91mSeu numero é menor que o numero da sorte.\x1b[0m\n"; // Se o numero chutado for menor que numro sorteado vai escrever em vermelho uma mensagem sobre.
    else if(numChute > numSorte) cout << "\t\033[1;33mSeu numero é maior que o numero da sorte.\x1b[0m\n"; // Se o numero chutado for maior que numro sorteado vai escrever em amarelo uma mensagem sobre.

    if(*tentativas > 0 || numChute == numSorte){ // Condição para pular a primeira execução e caso acerte.
      if(dificuldade == 1) *pontos = *pontos - 2; // Faz a diminuição de pontos de acordo com dificuldade escolhida.
      else if(dificuldade == 2) *pontos = *pontos - 14; // Faz a diminuição de pontos de acordo com dificuldade escolhida.
      else if(dificuldade == 3) *pontos = *pontos - 60; // Faz a diminuição de pontos de acordo com dificuldade escolhida.
    }

    *tentativas = *tentativas + 1; // Acrescenta 1 a tentativas.
  }while(numChute != numSorte && *tentativas != numD2); // Vai continuar perguntando o valor sorteado até que acerte ou acabe o numero definido de tentativas(O numero de tentativas será definido de acordo com o nivel de dificuldade escolhida pelo jogador.).

  return (numChute == numSorte); // Retorna um valor boleano sendo 1 : 0
}

int main(){
  const short numSorte = 42; // O numero sorteado
  short dificuldade = 0; // Valor inicial para dificuldade
  int tentativas = 0; // valor inicial para o numero de tentativas
  short pontos = 100; // valor inicial de pontos, para caso seja escolhida a dificuldade 1.

  cout << "\t********************\n";
  cout << "\t*----Hello Word----*\n";
  cout << "\t********************\n";

  cout << "\n\tEscolha sua dificuldade \n \x1b[1;96mfacil: 1\n \x1b[1;90mmedio: 2\n \x1b[1;95mdificil: 3\n\t\x1b[0mdificuldade: ";
  cin >> dificuldade; // Escolhe a dificuldade.

  if(chutes(numSorte, dificuldade, &tentativas, &pontos)) cout << "\n\t\x1b[1;33mVocê ganhou, parabéns\n"; // Aqui vai executar a função chutes e quado finalizar vai retornar um valor boleano, sendo que se for verdadeiro, aparecerá a mensagem para o jogador que ele ganhou.
  else{
    cout << "\n\t\033[91mVocê perdeu, quem sabe na proxima.\n"; // Caso contrario mostrará a mensagem que perdeu.
    pontos = 0; // E vai perder a pontuação.
  }

  cout << "\n\tVocê tentou " << tentativas << " vezes\n\n\t" << pontos << " Pontos\n\n"; // Mostra o numero de vezes que chutou até acertar ou até perder, e mostra sua pontuação final.
}
