#include "listalde.h"

namespace bry
{
    ListaLDE::ListaLDE():inicio(0),fim(0),quantidadeElementos(0)
    {
    }

    void ListaLDE::inserirInicio(int dados)
    {
        try
        {
            No *novoNo=new No(dados);

            if(estaVazia())
            {
                inicio=fim=novoNo;
                quantidadeElementos++;
                return;
            }

            novoNo->setProximo(inicio);
            inicio->setAnterior(novoNo);
            inicio=novoNo;
            quantidadeElementos++;
        }

        catch (std::bad_alloc &erro)
        {
            throw QString("Novo nó não foi criado");
        }
    }

    void ListaLDE::inserirFinal(int dados)
    {
        try
        {
            if(estaVazia())
            {
                inserirInicio(dados);
                return;
            }

            No *novoNo=new No(dados);
            No *atual=fim;

            atual->setProximo(novoNo);
            novoNo->setAnterior(atual);
            fim=novoNo;

            quantidadeElementos++;
        }

        catch (std::bad_alloc &erro)
        {
            throw QString("Novo nó não foi criado");
        }
    }

    void ListaLDE::inserirPosicao(int dados,int posicao)
    {
        try
        {
            if(posicao<0||posicao>quantidadeElementos)
            {
                throw QString("Posição inválida.");
            }

            if(posicao==0)
            {
                inserirInicio(dados);
                return;
            }

            if(posicao==quantidadeElementos)
            {
                inserirFinal(dados);
                return;
            }

            No *novoNo=new No(dados);
            No *atual=inicio;

            for(int i=0;i<posicao;i++)
            {
                atual=atual->getProximo();
            }

            atual->getAnterior()->setProximo(novoNo);
            novoNo->setAnterior(atual->getAnterior());

            novoNo->setProximo(atual);
            atual->setAnterior(novoNo);

            quantidadeElementos++;
        }

        catch (std::bad_alloc &erro)
        {
            throw QString("Novo nó não foi criado");
        }
    }

    int ListaLDE::acessarInicio()const
    {
        if(estaVazia())
        {
            throw QString("Lista está vazia.");
        }

        return inicio->getDados();
    }

    int ListaLDE::acessarFinal()const
    {
        if(estaVazia())
        {
            throw QString("Lista está vazia.");
        }

        if(quantidadeElementos==1)
        {
            return fim->getDados(); //incio da lista
        }

        return fim->getDados();
    }

    int ListaLDE::acessarPosicao(int posicao)const
    {
        if(estaVazia())
        {
            throw QString("Lista está vazia.");
        }

        if(posicao<0||posicao>=quantidadeElementos)
        {
            throw QString("Posição inválida.");
        }

        No *atual=inicio;

        for(int i=0;i<posicao;i++)
        {
            atual=atual->getProximo();
        }

        return atual->getDados();
    }

    void ListaLDE::retirarInicio()
    {
        if(estaVazia())
        {
            throw QString("Lista está vazia.");
        }

        if(quantidadeElementos==1)
        {
            No *pAux=inicio;
            delete pAux;

            inicio=fim=0;
            quantidadeElementos=0;
            return;
        }

        inicio=inicio->getProximo();

        No *pAux=inicio->getAnterior();
        delete pAux;

        inicio->setAnterior(0);
        quantidadeElementos--;
    }

    void ListaLDE::retirarFinal()
    {
        if(estaVazia())
        {
            throw QString("Lista está vazia.");
        }

        if(quantidadeElementos==1)
        {
            retirarInicio();
            return;
        }


        fim=fim->getAnterior();
        No *final=fim->getProximo();
        fim->setProximo(0);

        quantidadeElementos--;
        delete final;
    }

    void ListaLDE::retirarPosicao(int posicao)
    {
        if(estaVazia())
        {
            throw QString("Lista está vazia.");
        }

        if(posicao<0||posicao>=quantidadeElementos)
        {
            throw QString("Posição inválida.");
        }

        if(posicao==0)
        {
            retirarInicio();
            return;
        }

        if(posicao==quantidadeElementos-1)
        {
            retirarFinal();
            return;
        }

        No *atual=inicio;

        for(int i=0;i<posicao;i++)
        {
            atual=atual->getProximo();
        }

        atual->getProximo()->setAnterior(atual->getAnterior());
        atual->getAnterior()->setProximo(atual->getProximo());

        quantidadeElementos--;
        delete atual;
    }

   void ListaLDE::inserirOrdenado(int dados)
    {
        try
        {
            if(estaVazia())
            {
                inserirInicio(dados);
                return;
            }

            No *atual=inicio;
            No *novoNo=new No(dados);

            if(novoNo->getDados()<=atual->getDados())
            {
                novoNo->setProximo(inicio);
                inicio->setAnterior(novoNo);
                inicio=novoNo;
            }

            else
            {
                atual=inicio;

                while(atual->getProximo() && novoNo->getDados()>atual->getProximo()->getDados())
                {
                    atual=atual->getProximo();
                }

                novoNo->setProximo(atual->getProximo());

                if(atual->getProximo())
                {
                    atual->getProximo()->setAnterior(novoNo);
                }

                else
                {
                    fim=novoNo;
                }

                novoNo->setAnterior(atual);
                atual->setProximo(novoNo);
            }

            quantidadeElementos++;
        }

        catch (std::bad_alloc &erro)
        {
            throw QString("Novo nó não foi criado");
        }
    }

    QString ListaLDE::toStringInicioFim()const
    {
        if(estaVazia())
        {
            throw QString("Lista está vazia.");
        }

        bry::No *pAux=inicio;
        QString saida="Dados da lista do inicio para o fim: ";

        for(int i=0;i<quantidadeElementos;i++)
        {
            saida+=pAux->toString();
            pAux=pAux->getProximo();
        }

        return saida;
    }

    QString ListaLDE::toStringFimInicio()const
    {
        if(estaVazia())
        {
            throw QString("Lista está vazia.");
        }

        bry::No *pAux=fim;
        QString saida="Dados da lista do fim para o incio: ";

        for(int i=0;i<quantidadeElementos;i++)
        {
            saida+=pAux->toString();
            pAux=pAux->getAnterior();
        }

        return saida;
    }
}
