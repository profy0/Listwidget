#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <QListWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void removeSelection();
    bool isEmpty(QListWidget*);

private slots:
    void on_button1_clicked();

    void on_button2_clicked();

private:
    Ui::MainWindow *ui;
    std::vector <QListWidgetItem*> a,b;
    static const Qt::SortOrder ascOrder = Qt::AscendingOrder;
    static const Qt::SortOrder descOrder = Qt::DescendingOrder;
};
#endif // MAINWINDOW_H
