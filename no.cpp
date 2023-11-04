#include "no.h"

namespace bry
{

    No::No():dados(0),proximo(0),anterior(0)
    {
    }

    No::No(int dados):dados(dados),proximo(0),anterior(0)
    {
    }

    void No::setDados(int newDados)
    {
        dados = newDados;
    }

    void No::setProximo(No *newProximo)
    {
        proximo = newProximo;
    }

    void No::setAnterior(No *newAnterior)
    {
        anterior = newAnterior;
    }

    QString No::toString()const
    {
        return "|"+QString::number(dados)+"|->";
    }
}

