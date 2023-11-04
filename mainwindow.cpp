#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    l1=new bry::ListaLDE();
    ui->lineEditValor->setFocus();
    ui->lineEditValor->setValidator(new QIntValidator(-9999,9999));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonInserirInicio_clicked()
{
    try
    {
        if(ui->lineEditValor->text()=="")
        {
            throw QString("Valor inválido.");
        }

        int dados=ui->lineEditValor->text().toInt();
        QString saida;

        l1->inserirInicio(dados);

        saida+=l1->toStringInicioFim();
        saida+='\n'+l1->toStringFimInicio();

        ui->textEditDados->setText(saida);
        ui->lineEditValor->clear();
        ui->lineEditValor->setFocus();
    }

    catch (QString &erro)
    {
        QMessageBox::information(this,"Erro",erro);
        ui->lineEditValor->clear();
        ui->lineEditValor->setFocus();
    }
}


void MainWindow::on_pushButtonAcessarInicio_clicked()
{
    try
    {
        QString saida;

        saida="Valor incial: "+QString::number(l1->acessarInicio());

        ui->textEditDados->setText(saida);
    }

    catch (QString &erro)
    {
        QMessageBox::information(this,"Erro",erro);
        ui->lineEditValor->clear();
        ui->lineEditValor->setFocus();
    }
}


void MainWindow::on_pushButtonRetirarInicio_clicked()
{
    try
    {
        QString saida;

        l1->retirarInicio();

        saida+=l1->toStringInicioFim();
        saida+='\n'+l1->toStringFimInicio();

        ui->textEditDados->setText(saida);
    }

    catch (QString &erro)
    {
        QMessageBox::information(this,"Erro",erro);
        ui->lineEditValor->clear();
        ui->lineEditValor->setFocus();
        ui->textEditDados->clear();
    }
}


void MainWindow::on_pushButtonInserirFinal_clicked()
{
    try
    {
        if(ui->lineEditValor->text()=="")
        {
            throw QString("Valor inválido.");
        }

        int dados=ui->lineEditValor->text().toInt();
        QString saida;

        l1->inserirFinal(dados);

        saida+=l1->toStringInicioFim();
        saida+='\n'+l1->toStringFimInicio();

        ui->textEditDados->setText(saida);
        ui->lineEditValor->clear();
        ui->lineEditValor->setFocus();
    }

    catch (QString &erro)
    {
        QMessageBox::information(this,"Erro",erro);
        ui->lineEditValor->clear();
        ui->lineEditValor->setFocus();
    }
}


void MainWindow::on_pushButtonAcessarFinal_clicked()
{
    try
    {
        QString saida;

        saida="Valor final: "+QString::number(l1->acessarFinal());

        ui->textEditDados->setText(saida);
    }

    catch (QString &erro)
    {
        QMessageBox::information(this,"Erro",erro);
        ui->lineEditValor->clear();
        ui->lineEditValor->setFocus();
    }
}


void MainWindow::on_pushButtonRetirarFinal_clicked()
{
    try
    {
        QString saida;

        l1->retirarFinal();

        saida+=l1->toStringInicioFim();
        saida+='\n'+l1->toStringFimInicio();

        ui->textEditDados->setText(saida);
    }

    catch (QString &erro)
    {
        QMessageBox::information(this,"Erro",erro);
        ui->lineEditValor->clear();
        ui->lineEditValor->setFocus();
        ui->textEditDados->clear();
    }
}


void MainWindow::on_pushButtonInserirPosi_clicked()
{
    try
    {
        if(ui->lineEditValor->text()=="")
        {
            throw QString("Valor inválido.");
        }

        if(ui->lineEditPosicao->text()=="")
        {
            throw QString("Posição inválida.");
        }

        int dados=ui->lineEditValor->text().toInt();
        int posicao=ui->lineEditPosicao->text().toInt();
        QString saida;

        l1->inserirPosicao(dados,posicao);

        saida+=l1->toStringInicioFim();
        saida+='\n'+l1->toStringFimInicio();

        ui->textEditDados->setText(saida);
        ui->lineEditValor->clear();
        ui->lineEditValor->setFocus();
        ui->lineEditPosicao->clear();
    }

    catch (QString &erro)
    {
        QMessageBox::information(this,"Erro",erro);
        ui->lineEditValor->clear();
        ui->lineEditValor->setFocus();
        ui->lineEditPosicao->clear();
    }
}


void MainWindow::on_pushButtonAcessarPosi_clicked()
{
    try
    {
        QString saida;

        if(ui->lineEditPosicao->text()=="")
        {
            throw QString("Posição inválida.");
        }

        int posicao=ui->lineEditPosicao->text().toInt();

        saida="Valor: "+QString::number(l1->acessarPosicao(posicao));

        ui->textEditDados->setText(saida);
        ui->lineEditPosicao->clear();
    }

    catch (QString &erro)
    {
        QMessageBox::information(this,"Erro",erro);
        ui->lineEditValor->clear();
        ui->lineEditValor->setFocus();
        ui->lineEditPosicao->clear();
    }
}


void MainWindow::on_pushButtonRetirarPosi_clicked()
{
    try
    {
        QString saida;

        if(ui->lineEditPosicao->text()=="")
        {
            throw QString("Posição inválida.");
        }

        int posicao=ui->lineEditPosicao->text().toInt();

        l1->retirarPosicao(posicao);

        saida+=l1->toStringInicioFim();
        saida+='\n'+l1->toStringFimInicio();


        ui->textEditDados->setText(saida);
        ui->lineEditPosicao->clear();
    }

    catch (QString &erro)
    {
        QMessageBox::information(this,"Erro",erro);
        ui->lineEditValor->clear();
        ui->lineEditValor->setFocus();
        ui->textEditDados->clear();
        ui->lineEditPosicao->clear();
    }
}


void MainWindow::on_pushButtonInserirDescres_clicked()
{
    try
    {
        if(ui->lineEditValor->text()=="")
        {
            throw QString("Valor inválido.");
        }

        int dados=ui->lineEditValor->text().toInt();
        QString saida;

        l1->inserirOrdenado(dados);

        saida=l1->toStringFimInicio();

        ui->textEditDados->setText(saida);
        ui->lineEditValor->clear();
        ui->lineEditValor->setFocus();
    }

    catch (QString &erro)
    {
        QMessageBox::information(this,"Erro",erro);
        ui->lineEditValor->clear();
        ui->lineEditValor->setFocus();
    }
}


void MainWindow::on_pushButtonInserirCresc_clicked()
{
    try
    {
        if(ui->lineEditValor->text()=="")
        {
            throw QString("Valor inválido.");
        }

        int dados=ui->lineEditValor->text().toInt();
        QString saida;

        l1->inserirOrdenado(dados);

        saida=l1->toStringInicioFim();

        ui->textEditDados->setText(saida);
        ui->lineEditValor->clear();
        ui->lineEditValor->setFocus();
    }

    catch (QString &erro)
    {
        QMessageBox::information(this,"Erro",erro);
        ui->lineEditValor->clear();
        ui->lineEditValor->setFocus();
    }
}

