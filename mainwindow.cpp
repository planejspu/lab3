#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <iostream>
#include <QMessageBox>
#include <addressbookmodel.h>

std::vector<QString> phoneNumbers; // stores the phoneNumber
std::vector<QString> phoneNumbersHistory; // stores the phoneHistory to display Call Hiostyr
 int length;
 int calls=0; // number of calls
 int clicks=0; // locate the index of the current digit displayed

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
if (clicks == 3 || clicks == 7) { clicks++;}
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
// call button clicked, unhide cells, popup box, reset clicks to 0
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
for (int i=0;i<addressBook->phoneNumbers.size();i++) {
ui->tableView->showRow(i);
}

QString Numbers[10];
Numbers->push_back(callText + "\n");
for (int i=0; i<2; i++) {
    ui->lblCallHistory->setText(ui->lblCallHistory->text() + Numbers[i]);
    }
        clicks=0;
    }

void MainWindow::on_pushButton_2_clicked()
{

if (clicks == 3 || clicks == 7) { clicks++;}
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
    QRegExp rx("[ABCabc]"); // not enabled used to match characters not numbers
    QRegExp rx2("2"); // enabled per number matches 2 at the current click
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

// Remove the last character.
void MainWindow::on_btnDel_clicked()
{
    QString temp = ui->lblDisplayNumber->text();
    temp.remove(-1,1);
    ui->lblDisplayNumber->setText(temp);
    if (phoneNumbers.size() > 0 || phoneNumbers.size() == 4) {
    phoneNumbers.pop_back();
    if (clicks != 3 || clicks != 7 )
   clicks--;

 }
    for (int i=0;i<addressBook->phoneNumbers.size();i++) {
    ui->tableView->showRow(i);
    }
}

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    ui->lblName->setText(addressBook->getPhoneNumber(index.row()));
}

// display Call History
void MainWindow::on_pushButton_11_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

// display Directory
void MainWindow::on_pushButton_12_clicked()
{
       ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_3_clicked()
{
    if (clicks == 3 || clicks == 7) { clicks++;}
        if (phoneNumbers.size() < 10) {
        phoneNumbers.push_back("3") ;
        QString temp = ui->lblDisplayNumber->text();
        if (temp.length() == 3 || temp.length() == 7) {
            temp.append("-");
        }
        if (temp.length() < 12) {
        temp.append("3");
        ui->lblDisplayNumber->setText(temp);

        }
        }
        QRegExp rx("[ABCabc]"); // not enabled used to match characters not numbers
        QRegExp rx2("3"); // enabled per number matches 2 at the current click
        for (int i = 0; i< addressBook->phoneNumbers.size(); i++) {
          if  (!(rx2.indexIn(addressBook->phoneNumbers[i],clicks) == clicks))
               ui->tableView->hideRow(i);
    }
        clicks++;
}

void MainWindow::on_pushButton_4_clicked()
{
    if (clicks == 3 || clicks == 7) { clicks++;}
        if (phoneNumbers.size() < 10) {
        phoneNumbers.push_back("4") ;
        QString temp = ui->lblDisplayNumber->text();
        if (temp.length() == 3 || temp.length() == 7) {
            temp.append("-");
        }
        if (temp.length() < 12) {
        temp.append("4");
        ui->lblDisplayNumber->setText(temp);

        }
        }
        QRegExp rx("[ABCabc]"); // not enabled used to match characters not numbers
        QRegExp rx2("4"); // enabled per number matches 2 at the current click
        for (int i = 0; i< addressBook->phoneNumbers.size(); i++) {
          if  (!(rx2.indexIn(addressBook->phoneNumbers[i],clicks) == clicks))
               ui->tableView->hideRow(i);
    }
        clicks++;
}

void MainWindow::on_pushButton_5_clicked()
{
    if (clicks == 3 || clicks == 7) { clicks++;}
        if (phoneNumbers.size() < 10) {
        phoneNumbers.push_back("5") ;
        QString temp = ui->lblDisplayNumber->text();
        if (temp.length() == 3 || temp.length() == 7) {
            temp.append("-");
        }
        if (temp.length() < 12) {
        temp.append("5");
        ui->lblDisplayNumber->setText(temp);

        }
        }
        QRegExp rx("[ABCabc]"); // not enabled used to match characters not numbers
        QRegExp rx2("5"); // enabled per number matches 2 at the current click
        for (int i = 0; i< addressBook->phoneNumbers.size(); i++) {
          if  (!(rx2.indexIn(addressBook->phoneNumbers[i],clicks) == clicks))
               ui->tableView->hideRow(i);
    }
        clicks++;
}

void MainWindow::on_pushButton_6_clicked()
{
    if (clicks == 3 || clicks == 7) { clicks++;}
        if (phoneNumbers.size() < 10) {
        phoneNumbers.push_back("6") ;
        QString temp = ui->lblDisplayNumber->text();
        if (temp.length() == 3 || temp.length() == 7) {
            temp.append("-");
        }
        if (temp.length() < 12) {
        temp.append("6");
        ui->lblDisplayNumber->setText(temp);

        }
        }
        QRegExp rx("[ABCabc]"); // not enabled used to match characters not numbers
        QRegExp rx2("6"); // enabled per number matches 2 at the current click
        for (int i = 0; i< addressBook->phoneNumbers.size(); i++) {
          if  (!(rx2.indexIn(addressBook->phoneNumbers[i],clicks) == clicks))
               ui->tableView->hideRow(i);
    }
        clicks++;
}

void MainWindow::on_pushButton_9_clicked()
{
    if (clicks == 3 || clicks == 7) { clicks++;}
        if (phoneNumbers.size() < 10) {
        phoneNumbers.push_back("7") ;
        QString temp = ui->lblDisplayNumber->text();
        if (temp.length() == 3 || temp.length() == 7) {
            temp.append("-");
        }
        if (temp.length() < 12) {
        temp.append("7");
        ui->lblDisplayNumber->setText(temp);

        }
        }
        QRegExp rx("[ABCabc]"); // not enabled used to match characters not numbers
        QRegExp rx2("7"); // enabled per number matches 2 at the current click
        for (int i = 0; i< addressBook->phoneNumbers.size(); i++) {
          if  (!(rx2.indexIn(addressBook->phoneNumbers[i],clicks) == clicks))
               ui->tableView->hideRow(i);
    }
        clicks++;
}

void MainWindow::on_pushButton_8_clicked()
{
    if (clicks == 3 || clicks == 7) { clicks++;}
        if (phoneNumbers.size() < 10) {
        phoneNumbers.push_back("8") ;
        QString temp = ui->lblDisplayNumber->text();
        if (temp.length() == 3 || temp.length() == 7) {
            temp.append("-");
        }
        if (temp.length() < 12) {
        temp.append("8");
        ui->lblDisplayNumber->setText(temp);

        }
        }
        QRegExp rx("[ABCabc]"); // not enabled used to match characters not numbers
        QRegExp rx2("8"); // enabled per number matches 2 at the current click
        for (int i = 0; i< addressBook->phoneNumbers.size(); i++) {
          if  (!(rx2.indexIn(addressBook->phoneNumbers[i],clicks) == clicks))
               ui->tableView->hideRow(i);
    }
        clicks++;
}

void MainWindow::on_pushButton_7_clicked()
{
    if (clicks == 3 || clicks == 7) { clicks++;}
        if (phoneNumbers.size() < 10) {
        phoneNumbers.push_back("9") ;
        QString temp = ui->lblDisplayNumber->text();
        if (temp.length() == 3 || temp.length() == 7) {
            temp.append("-");
        }
        if (temp.length() < 12) {
        temp.append("9");
        ui->lblDisplayNumber->setText(temp);

        }
        }
        QRegExp rx("[ABCabc]"); // not enabled used to match characters not numbers
        QRegExp rx2("9"); // enabled per number matches 2 at the current click
        for (int i = 0; i< addressBook->phoneNumbers.size(); i++) {
          if  (!(rx2.indexIn(addressBook->phoneNumbers[i],clicks) == clicks))
               ui->tableView->hideRow(i);
    }
        clicks++;
}

void MainWindow::on_pushButton_10_clicked()
{
    if (clicks == 3 || clicks == 7) { clicks++;}
        if (phoneNumbers.size() < 10) {
        phoneNumbers.push_back("0") ;
        QString temp = ui->lblDisplayNumber->text();
        if (temp.length() == 3 || temp.length() == 7) {
            temp.append("-");
        }
        if (temp.length() < 12) {
        temp.append("0");
        ui->lblDisplayNumber->setText(temp);

        }
        }
        QRegExp rx("[ABCabc]"); // not enabled used to match characters not numbers
        QRegExp rx2("0"); // enabled per number matches 2 at the current click
        for (int i = 0; i< addressBook->phoneNumbers.size(); i++) {
          if  (!(rx2.indexIn(addressBook->phoneNumbers[i],clicks) == clicks))
               ui->tableView->hideRow(i);
    }
        clicks++;
}
