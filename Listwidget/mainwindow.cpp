#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <QDebug>
#include <QMessageBox>
#include <QListWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int size = 9;

    for(int i=0;i<size;i++) {
        a.push_back(new QListWidgetItem("first" + QString::number(i+1)));
    }
    for(int i=0;i<size;i++) {
        ui->listWidget->addItem(a[i]);
    }

    for(int i=0;i<size;i++) {
        b.push_back(new QListWidgetItem("second" + QString::number(i+1)));
    }
    for(int i=0;i<size;i++) {
        ui->listWidget_2->addItem(b[i]);
    }
    ui->button1->setText("<<<");
    ui->button2->setText(">>>");
   // qDebug() << ui->listWidget->count();
    ui->listWidget->sortItems(ascOrder);
    ui->listWidget_2->sortItems(descOrder);


}

void MainWindow::removeSelection() {
    for(auto& now : this->a) {
        now->setSelected(0);
    }

    for(auto& now : this->b) {
        now->setSelected(0);
    }
}

bool MainWindow::isEmpty(QListWidget* x) {
    if(x->count()==0) {
        QMessageBox::warning(this, "Ошибка", "Пустой лист!");
        return true;
    } else return false;
}


MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_button2_clicked() {

    bool ok = isEmpty(ui->listWidget);

    QList <QListWidgetItem*> a = ui->listWidget->selectedItems();

    if(a.size()==0&&!ok) {
        QMessageBox::warning(this, "Ошибка", "Выберите элементы!");
    }

    for(auto now : a) {
        ui->listWidget->setCurrentItem(now);
        ui->listWidget->takeItem(ui->listWidget->currentRow());
    }

    for(auto now : a) {
        ui->listWidget_2->addItem(now);
    }

    removeSelection();
    ui->listWidget_2->sortItems(descOrder);

}


void MainWindow::on_button1_clicked() {

    bool ok = isEmpty(ui->listWidget_2);

    QList <QListWidgetItem*> b = ui->listWidget_2->selectedItems();

    if(b.size()==0&&!ok) {
        QMessageBox::warning(this, "Ошибка", "Выберите элементы!");
    }

    for(auto now : b) {
        ui->listWidget_2->setCurrentItem(now);
        ui->listWidget_2->takeItem(ui->listWidget_2->currentRow());
    }

    for(auto now : b) {
        ui->listWidget->addItem(now);
    }
    removeSelection();
    ui->listWidget->sortItems(ascOrder);

}
