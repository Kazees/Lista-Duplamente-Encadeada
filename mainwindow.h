#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QIntValidator>
#include <listalde.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonInserirInicio_clicked();

    void on_pushButtonAcessarInicio_clicked();

    void on_pushButtonRetirarInicio_clicked();

    void on_pushButtonInserirFinal_clicked();

    void on_pushButtonAcessarFinal_clicked();

    void on_pushButtonRetirarFinal_clicked();

    void on_pushButtonInserirPosi_clicked();

    void on_pushButtonAcessarPosi_clicked();

    void on_pushButtonRetirarPosi_clicked();

    void on_pushButtonInserirDescres_clicked();

    void on_pushButtonInserirCresc_clicked();


private:
    Ui::MainWindow *ui;
    bry::ListaLDE *l1;
};
#endif // MAINWINDOW_H
