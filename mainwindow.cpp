#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "decypher.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    string cypheredText = ui->textEdit_Cyphered->toPlainText().toStdString();
    string key = ui->lineEdit_Key->text().toStdString();

    string decypheredText;
    int cypherMode = ui->comboBox->currentIndex();
    switch (cypherMode) {
        case 0: // Caesar
            decypheredText = Decypher::caesar(cypheredText, stoi(key));
            break;
        case 1: // Vigenere
            decypheredText = Decypher::vigenere(cypheredText, key);
            break;
        default: // No cypher
            decypheredText = cypheredText;
            break;
    }

    ui->textEdit_Decyphered->setText(QString::fromStdString(decypheredText));
}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    if (arg1 == "Caesar")
        ui->label_Input->setText("Shift Step:");
    if (arg1 == "Vigenere")
        ui->label_Input->setText("Keyword:");
}
