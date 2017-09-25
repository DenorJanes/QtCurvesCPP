#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    update_ui();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_ui()
{
    this->ui->spinScale->setValue(this->ui->renderArea->getScale());
    this->ui->spinInterval->setValue(this->ui->renderArea->getIntervalLength());
    this->ui->spinStepCount->setValue(this->ui->renderArea->getStepCount());
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

void MainWindow::on_spinStepCount_valueChanged(int stepCount)
{
    this->ui->renderArea->setStepCount(stepCount);
    this->ui->renderArea->repaint();
}

void MainWindow::on_btnBackground_clicked()
{
    QColor color = QColorDialog::getColor(ui->renderArea->getBackgroundColor(),this, "Select Color");
    ui->renderArea->setBackgroundColor(color);
}

void MainWindow::on_btnShapeColor_clicked()
{
    QColor color = QColorDialog::getColor(ui->renderArea->getShapeColor(),this, "Select Color");
    ui->renderArea->setShapeColor(color);
}

void MainWindow::on_btnFancy_clicked()
{
    ui->renderArea->setShape(RenderArea::Fancy);
    ui->renderArea->repaint();
    update_ui();
}

void MainWindow::on_btnStarfish_clicked()
{
    ui->renderArea->setShape(RenderArea::Starfish);
    ui->renderArea->repaint();
    update_ui();
}
