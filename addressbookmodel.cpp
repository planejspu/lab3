#include "addressbookmodel.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <iostream>

AddressBookModel::AddressBookModel(QObject *parent)

    :QAbstractTableModel(parent)
{

}

int AddressBookModel::rowCount(const QModelIndex &parent) const
{
    return firstNames.size();
}

int AddressBookModel::columnCount(const QModelIndex &parent) const
{
    return 3;
}

QVariant AddressBookModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        switch(index.column()) {
        case 0:
            return firstNames.at(index.row());
        case 1:
             return lastNames.at(index.row());
        case 2:
             return phoneNumbers.at(index.row());

//      return QString("Row%1, Column%2")
//              .arg(index.row())
//              .arg(index.column());
        }

}
    return QVariant();
}

void AddressBookModel::openFile(QString filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::information(0, "error", file.errorString());
        return;
    }
    QTextStream in(&file);
    firstNames.clear();
    lastNames.clear();
    phoneNumbers.clear();

    for(int i=0; !in.atEnd();i++){
       QString line = in.readLine();
       QStringList fields = line.split(",");
        if (i ==0) continue;
       for (int j = 0; j < fields.length(); j++) {
           std::cout << "[" << j << "]" << fields[j].toStdString();
       }
       std::cout << std::endl;

       firstNames.push_back(fields[0]);
       lastNames.push_back(fields[1]);
       phoneNumbers.push_back(fields[7]);
    }
    file.close();
    emit layoutChanged();
}

QString AddressBookModel::getPhoneNumber(int index)
{
    return phoneNumbers.at(index);

}
