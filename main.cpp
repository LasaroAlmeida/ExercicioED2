#include <iostream>
#include "definicoes.h"
using namespace std;

void implementacao()
{
    int numTestes=1,*t;
    cout<<"Digite apenas valores  POSITIVOS"<<endl;
    do
    {
        cout<<"Numero de testes: ";
        cin>>numTestes;
    }
    while(numTestes<=0);
    cout<<"Tamanho dos testes: ";
    Ordenacao vetor[numTestes];
    system("cls");
    for(int i=0;i<numTestes;i++){
        vetor[i].gereAleatorio();
        vetor[i].testes();
    }
    for(int i=0;i<numTestes;i++){
        vetor[i].imprimeDados();
    }
}
int main()
{
    implementacao();
    return 0;
}
