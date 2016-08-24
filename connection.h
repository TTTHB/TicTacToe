#ifndef CONNECTION_H
#define CONNECTION_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QTimer>

namespace Ui {
class connection;
}

class connection : public QMainWindow
{
    Q_OBJECT

public:
    explicit connection(QWidget *parent = 0);
    ~connection();
     void name_changed(); //This function draws playernames in the textBrowser


private slots:
    void on_pushButton_clicked(); //This function starts a new game and open an second window

    void arduino_read(); //this function reads the arduino data

    void arduino_send(); //this function send data to the arduino

    void timerfunktion(); //Slot for reading arduino data

    void on_pushButton_2_clicked(); //shows playernames

private:
    Ui::connection *ui;
    QSerialPort *arduino; //Arduino is QSerial Port
    static const quint16 arduino_uno_vendor_id = 9025; //Vendor ID from Arduino
    static const quint16 arduino_uno_produkt_id = 67; //Produkt ID from Arduino
    QString arduino_port_name; //Port Name from Arduino
    bool arduino_is_available; //Arduino is available
    QTimer *timer; //deklaration from the timer


};

#endif // CONNECTION_H
