#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->spinScale->setValue(this->ui->renderArea->getScale());
    this->ui->spinInterval->setValue(this->ui->renderArea->getIntervalLength());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_ui()
{
    this->ui->spinScale->setValue(this->ui->renderArea->getScale());
    this->ui->spinInterval->setValue(this->ui->renderArea->getIntervalLength());
}

void MainWindow::on_btnAstroid_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Astroid);
    this->ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_btnHuygens_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Huygens);
    this->ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_Cycloid_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Cycloid);
    this->ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_btnHypo_clicked()
{
    this->ui->renderArea->setShape(RenderArea::Hypo_Cycloid);
    this->ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_spinScale_valueChanged(double scale)
{
    this->ui->renderArea->setScale(scale);
    this->ui->renderArea->repaint();
}

void MainWindow::on_spinInterval_valueChanged(double intervalLength)
{
    this->ui->renderArea->setIntervalLength(intervalLength);
    this->ui->renderArea->repaint();
}
