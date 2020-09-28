#ifndef TESTES_H_INCLUDED
#define TESTES_H_INCLUDED
using namespace std;
class Vetor
{
public:
    Vetor(int tam)
    {
        elementos = new int[tam];
        tamanho=tam;
    }
    ~Vetor()
    {

    }
    int getTamanho()
    {
        return tamanho;
    }


private:
    int *elementos;
    int tamanho;

};


#endif // TESTES_H_INCLUDED
