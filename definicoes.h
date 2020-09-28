#ifndef DEFINICOES_H_INCLUDED
#define DEFINICOES_H_INCLUDED

class Ordenacao
{
public:
    Ordenacao();
    ~Ordenacao();
    void gereAleatorio();
    void imprime(bool op);
    void testes();
    void imprimeDados();



private:
    ///0-> bubbluSort//1->ShellSort// 2-> QuickSort // 3-> qsort
    double tempo[4];
    long long comparacoes[3]= {0};
    long long  movimentacoes[3]= {0};
    void redefineVet();
    int *vet;
    int *auxiliar;
    int tam;
    void setVet();
    void bubbleSort();
    void shellSort();
    void quickSort(int * vetor,int inicio, int q);
    void auxQuickSort();
    void swap(int *a, int *b);
    void qsortSTD();
};


#endif // DEFINICOES_H_INCLUDED
