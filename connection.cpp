#include "connection.h"
#include "ui_connection.h"
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QtWidgets>
#include <QString>
#include "new_game.h"
#include <QTimer>

QString username_player1; //variable fot player 1 name
QString username_player2; //variable fot player 1 name
connection::connection(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::connection)
{
    ui->setupUi(this);
    arduino_is_available = false; //availability of the arduino
    arduino_port_name = ""; //Arduinos port name
    arduino = new QSerialPort; // deklaration of an new QSerialPort
    timer = new QTimer(this); //deklaration of QTimer


    connect(timer, SIGNAL(timeout()),this,SLOT(timerfunktion())); //Timer´s Signal and Slot function
    timer->start(1000); //Timer starts
    // dirt hack
    connect(ui->pushButton_2, SIGNAL(clicked()),this,SLOT(name_changed())); //Signal and Slot for giving names from New_Game



    qDebug() << "Number of available ports: " << QSerialPortInfo::availablePorts().length(); //find available ports
    foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
        qDebug() << "Has vendor ID: " << serialPortInfo.hasVendorIdentifier(); // find Vendor ID
        if(serialPortInfo.hasVendorIdentifier()){
            qDebug() << "Vendor ID: " << serialPortInfo.vendorIdentifier();//show Vendor ID
        }
        qDebug() << "Has Produkt ID: " << serialPortInfo.hasProductIdentifier(); //find Produkt ID
        if(serialPortInfo.hasProductIdentifier()){
            qDebug() << "Produkt ID: " << serialPortInfo.productIdentifier();//show Produkt ID
        }
    }

    foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) { //search for Vendor ID and Produkt ID in avialable Ports
        if(serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()){
            if(serialPortInfo.vendorIdentifier() == arduino_uno_vendor_id){
                if(serialPortInfo.productIdentifier() == arduino_uno_produkt_id){
                    arduino_port_name = serialPortInfo.portName();
                    arduino_is_available = true; //Port Arduino is available
                }
            }
        }
    }
    if(arduino_is_available){ //Settings for the Arduino Port
        arduino->setPortName(arduino_port_name);
        arduino->open(QIODevice::ReadWrite);
        arduino->setBaudRate(QSerialPort::Baud9600);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        arduino->setFlowControl(QSerialPort::NoFlowControl);

    }
    else{ //Output if Arduino Port is not found
        QMessageBox::warning(this,"Connection Error","Arduino not found");
    }
}

connection::~connection()
{
    if(arduino->isOpen()){ //open Arduino
        arduino->close();
    }
    delete ui;
}

void connection::on_pushButton_clicked() //click on NewGame
{
 connection::arduino_send(); //Send data to the Arduino

    New_Game new_game; //Deklaration of an new class
    new_game.setModal(true);
    new_game.exec(); // Window New Game is open

}

void connection::arduino_send() //Send data to the Arduino
{
    if(arduino->isWritable()){ //Arduino is ready for reading data
        QByteArray reset;
        reset.append('R');
        arduino->write(reset); //reset is send to Arduino
        qDebug() << "Data is send" << reset << endl; //Output in QT when data is send


    }
    else{
        qDebug() << "Data not send" << endl;//Output if no data is send to the Arduino
    }
}
void connection::arduino_read() //reading data from the Arduino
{
    int c = 0;
    char * dataBuffer; //Databuffer initialized
    int size = arduino->bytesAvailable(); //availability of the arduino
    dataBuffer = new char[size+1];
    c = arduino->read(dataBuffer,size); //Databuffer is filled with arduino data
    dataBuffer[c]='\0';
    if(c == 0)
    {
        qDebug() <<"arduino read update"<<endl; //Output in QT if there is no data read
    }
    else{
    ui->textBrowser->append(dataBuffer); // Output from databuffer in the TextBrowser
    qDebug() <<"data is read"<<dataBuffer<<endl;//Output in QT if data is read
    delete dataBuffer; //rset databuffer
    }
}



void connection::timerfunktion() //Slot of timerfunction
{
    arduino_read(); //reading data from the Arduino
}

void connection::name_changed() //change playername
{
    ui->textBrowser_2->append(username_player1); //Output in the Text Browser of playername 1
    ui->textBrowser_3->append(username_player2); //Output in the Text Browser of playername 2
}

void connection::on_pushButton_2_clicked()
{
    name_changed(); //do namechange
}
