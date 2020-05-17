#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <iostream>
#include <QMessageBox>
#include <addressbookmodel.h>
 std::vector<QString> phoneNumbers;
 std::vector<QString> phoneNumbersHistory;
 int length;
 int calls=0;
 int clicks=0;
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

if (clicks == 3) { clicks++;}
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
 clicks++;


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




callContact->setText("Calling " + callText + "...");

int ret = callContact->exec();

switch (ret) {
    case QMessageBox::Ok: {
        phoneNumbers.clear();
        ui->lblDisplayNumber->setText("");
        }

}
for (int i=0;i<500;i++) {
ui->tableView->showRow(i);
}



QString Numbers[10];
Numbers->push_back(callText + "\n");
for (int i=0; i<2; i++) {
ui->lblCallHistory->setText(ui->lblCallHistory->text() + Numbers[i]);
}




}


void MainWindow::on_pushButton_2_clicked()
{
 // 2 = abc

if (clicks == 3) { clicks++;}
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



    QRegExp rx("[ABCabc]");
    QRegExp rx2("2");
    for (int i = 0; i< addressBook->phoneNumbers.size(); i++) {

      if  (!(rx2.indexIn(addressBook->phoneNumbers[i],clicks) == clicks))
           ui->tableView->hideRow(i);
}

    clicks++;

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

void MainWindow::on_pushButton_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_12_clicked()
{
       ui->stackedWidget->setCurrentIndex(0);
}
