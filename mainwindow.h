#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <addressbookmodel.h>
#include <QMainWindow>

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
    void on_actionOpen_triggered();

    void on_actionExit_triggered();

    void on_pushButton_1_clicked();

    void on_buttonCall_clicked();

    void on_pushButton_2_clicked();

    void on_btnClear_clicked();

    void on_pushButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

private:
    Ui::MainWindow *ui;
    AddressBookModel *addressBook;

};
#endif // MAINWINDOW_H
