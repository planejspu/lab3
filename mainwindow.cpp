#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <iostream>
#include <QMessageBox>
#include <addressbookmodel.h>
 std::vector<QString> phoneNumbers;
 int length;
 int clicks;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    addressBook(new AddressBookModel(this))
{
    ui->setupUi(this);
    ui->tableView->setModel((addressBook));



}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open Address Book"), "",
        tr("Address Book (*.csv);; All Files(*)"));

    addressBook->openFile(fileName);
}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_pushButton_1_clicked()
{

    clicks++;
    if (phoneNumbers.size() < 10) {
    phoneNumbers.push_back("1") ;
    QString temp = ui->lblDisplayNumber->text();
    if (temp.length() == 3 || temp.length() == 7) {
        temp.append("-");
    }
        if (temp.length() < 12) {
        temp.append("1");
        ui->lblDisplayNumber->setText(temp);
    }
    }

    QRegExp rx("1");
    for (int i = 0; i< addressBook->phoneNumbers.size(); i++) {
    if (!(rx.indexIn(addressBook->phoneNumbers[i],clicks) == clicks))

     ui->tableView->hideRow(i);

}



}



void MainWindow::on_buttonCall_clicked()
{

QString callText;
QMessageBox *callContact = new QMessageBox;

    for (int i=0;i<phoneNumbers.size(); i++){
        if (i == 3 || i == 6){

            callText += "-" + phoneNumbers[i];

        }
        else
            callText +=  phoneNumbers[i];

}
callContact->setStandardButtons(QMessageBox::Ok);

//QString name = addressBook->firstNames[1];
//addressBook->phoneNumbers[2];


callContact->setText("Calling " + callText + "...");


int ret = callContact->exec();

switch (ret) {
    case QMessageBox::Ok: {
        phoneNumbers.clear();
        ui->lblDisplayNumber->setText("");
        }

}






}


void MainWindow::on_pushButton_2_clicked()
{
    clicks++;
    if (phoneNumbers.size() < 10) {
    phoneNumbers.push_back("2") ;
    QString temp = ui->lblDisplayNumber->text();
    if (temp.length() == 3 || temp.length() == 7) {
        temp.append("-");
    }
    if (temp.length() < 12) {
    temp.append("2");
    ui->lblDisplayNumber->setText(temp);

    }
    }

//    QRegExp rx("1");
//    for (int i = 0; i< 10; i++) {
//    if (!(rx.indexIn(addressBook->phoneNumbers[i],1) == 1))

//     ui->tableView->hideRow(i);

//}

    QRegExp rx("2");
    for (int i = 0; i< addressBook->phoneNumbers.size(); i++) {
    if (!(rx.indexIn(addressBook->phoneNumbers[i],clicks) == clicks))

     ui->tableView->hideRow(i);

}



}

void MainWindow::on_btnClear_clicked()
{
    ui->lblDisplayNumber->clear();
}

void MainWindow::on_pushButton_clicked()
{

    QString temp = ui->lblDisplayNumber->text();
    length = temp.length();
    temp.remove(length-1,1);
    ui->lblDisplayNumber->setText(temp);
    phoneNumbers.pop_back();
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    ui->lblName->setText(addressBook->getPhoneNumber(index.row()));
}
