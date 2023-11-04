#ifndef LISTALDE_H
#define LISTALDE_H
#include <QString>
#include <no.h>

namespace bry
{
    class ListaLDE
    {
    private:
        No *inicio;
        No *fim;
        int quantidadeElementos;

    public:
        ListaLDE();
        ~ListaLDE();

        int getQuantidadeElementos()const {return quantidadeElementos;}

        bool estaVazia()const {return quantidadeElementos==0;} //ou inicio==0
        void inserirInicio(int dados);
        void inserirFinal(int dados);
        void inserirPosicao(int dados,int posicao);

        int acessarInicio()const;
        int acessarFinal()const;
        int acessarPosicao(int posicao)const;

        void retirarInicio();
        void retirarFinal();
        void retirarPosicao(int posicao);

        void inserirOrdenado(int dados);

        QString toStringInicioFim()const;
        QString toStringFimInicio()const;
    };
}

#endif // LISTALDE_H
