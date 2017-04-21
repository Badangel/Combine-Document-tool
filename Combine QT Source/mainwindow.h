#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QString file_path;
    QDialog *dlg;
    ~MainWindow();

private slots:
    void on_choose_clicked();



    void on_fileroad_textEdited(const QString &filer);
    void on_pushButton_clickedclose();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
