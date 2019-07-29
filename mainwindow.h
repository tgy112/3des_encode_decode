#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "decode.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_decode_clicked();

    void on_encode_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
