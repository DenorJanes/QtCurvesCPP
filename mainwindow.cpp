#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->spinScale->setValue(this->ui->renderArea->getScale());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_btnAstroid_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Astroid);
    this->ui->spinScale->setValue(this->ui->renderArea->getScale());

    this->ui->renderArea->repaint();
}

void MainWindow::on_btnHuygens_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Huygens);
    this->ui->spinScale->setValue(this->ui->renderArea->getScale());

    this->ui->renderArea->repaint();
}

void MainWindow::on_Cycloid_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Cycloid);
    this->ui->spinScale->setValue(this->ui->renderArea->getScale());

    this->ui->renderArea->repaint();
}

void MainWindow::on_btnHypo_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Hypo_Cycloid);
    this->ui->spinScale->setValue(this->ui->renderArea->getScale());

    this->ui->renderArea->repaint();
}

void MainWindow::on_spinScale_valueChanged(double scale)
{
    this->ui->renderArea->setScale(scale);
    this->ui->renderArea->repaint();
}
