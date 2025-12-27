#include "game.h"
#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QGraphicsPixmapItem>
#include <memory>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(std::make_unique<Ui::MainWindow>())
{
    ui->setupUi(this);
    game = Game(std::make_shared<QGraphicsScene>(this), std::make_shared<QGraphicsScene>(this),
                 ui->playerHand, ui->dealerHand);

    // ui->balance->setText("Balance: " + QString::number(_player->GetBalance()));
}

MainWindow::~MainWindow() {}

void MainWindow::on_hitButton_clicked() {
    // _player->Hit();
    // _player->DrawHand(playerScene, ui->playerHand);
}
