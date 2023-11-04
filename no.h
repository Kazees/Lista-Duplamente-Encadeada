#ifndef NO_H
#define NO_H
#include <QString>

namespace bry
{
    class No
    {
    private:
        int dados;
        No *proximo;
        No *anterior;

    public:
        No();
        No(int dados);

        int getDados() const {return dados;}
        No *getProximo() const {return proximo;}
        No *getAnterior() const {return anterior;}

        void setDados(int newDados);
        void setProximo(No *newProximo);
        void setAnterior(No *newAnterior);

        QString toString()const;
    };
}



#endif // NO_H
