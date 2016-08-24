#include "new_game.h"
#include "ui_new_game.h"
#include "QMessageBox"
#include "QtWidgets"
#include "connection.h"

New_Game::New_Game(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::New_Game)
{
    ui->setupUi(this);
}

New_Game::~New_Game()
{
    delete ui;
}

void New_Game::on_pushButton_player1_clicked()
{
    username_player1 = ui->lineEdit_player1->text(); //save of playername 1
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this,"Username:Player1",username_player1, QMessageBox::No | QMessageBox::Yes);
    if(reply == QMessageBox::Yes) //is the name correct
    {
        QMessageBox::about(this,"Ready","Nice you are ready");//if yes you are ready
        qDebug() <<"Player1= "<<username_player1<<endl; //Output in QT

    }
    else(reply == QMessageBox::No);//if no enter new name
    {
    }
}

void New_Game::on_pushButton_player2_clicked()
{
     username_player1 = ui->lineEdit_player1->text();//save of playername 1
     username_player2 = ui->lineEdit_player2->text();//save of playername 2
    if(username_player2 == username_player1) //compare both names
    {
        QMessageBox::warning(this,"New Username","Enter new Username"); //same names you have to enter a new name
    }
    else if(username_player2 != username_player1); //not the same names, is this the correct name
    QMessageBox::StandardButton rep;
    rep = QMessageBox::question(this,"Username:Player2",username_player2, QMessageBox::No | QMessageBox::Yes);
    if(rep == QMessageBox::Yes)
    {
        QMessageBox::about(this,"Ready","Nice you are ready"); //if yes you are ready
        qDebug()<<"Player2= "<<username_player2<<endl; //Output in QT


    }
    else(rep == QMessageBox::No); //if no enter new name
    {
    }
}

void New_Game::on_pushButton_3_clicked() //click start button
{
    New_Game::close(); //window is closed
}
