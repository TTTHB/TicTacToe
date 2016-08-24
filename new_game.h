#ifndef NEW_GAME_H
#define NEW_GAME_H

#include <QDialog>

namespace Ui {
class New_Game;
}

extern QString username_player1; //extern Qstring playername 1
extern QString username_player2;//estern Qstring playername 2
class New_Game : public QDialog
{
    Q_OBJECT

public:
    explicit New_Game(QWidget *parent = 0);
    ~New_Game();

private slots:

    void on_pushButton_player1_clicked(); //sends "OK"  for playername 1

    void on_pushButton_player2_clicked(); //sends "OK"  for playername 2

    void on_pushButton_3_clicked(); //sart button

private:
    Ui::New_Game *ui;
};

#endif // NEW_GAME_H
