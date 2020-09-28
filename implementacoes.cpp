#include <iostream>
#include "definicoes.h"
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <math.h>
#include <iomanip>
using namespace std;
Ordenacao::Ordenacao()
{
    setVet();
}

Ordenacao::~Ordenacao()
{
    delete [] vet;
    delete [] auxiliar;
}

void Ordenacao::setVet()
{

    int aux=1;
    do
    {
        cin>>aux;
    }
    while(aux<=0);
    tam=aux;
    auxiliar=new int[aux];
    vet=new int[aux];
}

void Ordenacao::testes()
{

    auto inicio= chrono::high_resolution_clock::now();
    bubbleSort();
    auto fim= chrono::high_resolution_clock::now() - inicio;
    long long nanoseconds =chrono::duration_cast<chrono::nanoseconds>(fim).count();
    tempo[0]=nanoseconds*pow(10,-6);

    redefineVet();

    auto ini=  chrono::high_resolution_clock::now();
    shellSort();
    auto end= chrono::high_resolution_clock::now() - ini;
    long long nanosecond =chrono::duration_cast<chrono::nanoseconds>(end).count();
    tempo[1]=nanosecond*pow(10,-6);

    redefineVet();

    auto i= chrono::high_resolution_clock::now();
    auxQuickSort();
    auto f= chrono::high_resolution_clock::now() - i;
    long long nanosecon =chrono::duration_cast<chrono::nanoseconds>(f).count();
    tempo[2]=nanosecon*pow(10,-6);

    auto in= chrono::high_resolution_clock::now();
    qsortSTD();
    auto fi= chrono::high_resolution_clock::now() - in;
    long long nanoseco =chrono::duration_cast<chrono::nanoseconds>(fi).count();
    tempo[3]=nanoseco*pow(10,-6);


}

void Ordenacao::imprimeDados()
{
    cout<<"\n\tTamanho do vetor: "<<tam<<endl;
    cout<<"Algoritmo\t|Tempo(ms)|\t|Comparacoes|\t|Movimentacoes|"<<endl;
    string algoritmos[]= {"BubbleSort\t","ShellSort\t","Quicksort\t","qsort\t"};
    cout<< fixed << setprecision(5);
    for(int i=0; i<3; i++)
    {
        cout<<algoritmos[i]<<setw(12)<<tempo[i]<<"\t "<<setw(12)<<comparacoes[i]<<"\t " <<setw(12)<<movimentacoes[i]<<"\t"<<endl;
    }
    cout<<algoritmos[3]<<"\t"<<setw(12)<<tempo[3]<<endl;

}
void Ordenacao::gereAleatorio()
{
    srand(time(NULL));
    int temp;
    for(int i=0; i<this->tam; i++)
    {
        temp=(rand()%200000)+(-5000);
        vet[i]=auxiliar[i]=temp;
    }
}


int compare(const void* a, const void* b)
{
    const int* x = (int*) a;
    const int* y = (int*) b;

    if (*x > *y)
        return 1;
    else if (*x < *y)
        return -1;

    return 0;
}
void Ordenacao::qsortSTD()
{
    qsort(vet,tam,sizeof(int),compare);

}
void Ordenacao::imprime(bool op)
{
    for(int i=0; i<tam; i++)
    {
        if(op)
            cout<<vet[i]<<"\t";
        else
            cout<<auxiliar[i]<<"\t";

    }
    cout<<endl;
}
void Ordenacao::swap(int *a, int *b)
{
    int aux=*a;
    *a=*b;
    *b=aux;
}
void Ordenacao::bubbleSort()
{
    int i,j;
    for(i=0; i<tam-1; i++)
    {
        for(j=0; j< tam-i-1; j++)
        {
            comparacoes[0]+=1;
            if(auxiliar[j] > auxiliar[j+1])
            {
                swap(&auxiliar[j],&auxiliar[j+1]);
                movimentacoes[0]+=1;
            }
        }
    }
}

void Ordenacao::redefineVet()
{
    for(int i=0; i<tam; i++)
    {
        auxiliar[i]=vet[i];
    }
}

void Ordenacao::shellSort()
{
    for(int indice= tam/2; indice > 0 ; indice/=2)
    {
        for(int i=indice; i<tam; i++)
        {
            int aux= auxiliar[i];
            int j;
            comparacoes[1]+=1;
            for(j=i; j>=indice && auxiliar[j- indice] > aux; j-=indice)
            {
                auxiliar[j]=auxiliar[j-indice];
                movimentacoes[1]+=1;

            }
            auxiliar[j]=aux;
            movimentacoes[1]+=1;
        }
    }
}
void Ordenacao::auxQuickSort()
{
    quickSort(auxiliar,0,tam-1);
}
void Ordenacao::quickSort(int *vetor, int inicio, int q)
{

    int m= (int)(inicio+ q)/2;
    int pivo=vetor[m];
    int i=inicio;
    int j=q;
    do
    {
        while(vetor[i]< pivo)
        {
            i+=1;
            comparacoes[2]+=1;
        }
        while(vetor[j]> pivo)
        {
            j-=1;
            comparacoes[2]+=1;
        }
        if(i<=j)
        {
            swap(&vetor[i], &vetor[j]);
            movimentacoes[2]+=1;
            i++;
            j--;
        }
    }
    while(i<=j);
    if(inicio < j)
    {
        quickSort(vetor,inicio,j);
    }
    if(i< q)
    {
        quickSort(vetor,i,q);
    }

}
