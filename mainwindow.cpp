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
    _playerScene = std::make_shared<QGraphicsScene>(this);
    _dealerScene = std::make_shared<QGraphicsScene>(this);

    game.UpdateBalanceUI(ui->balance);
    game.InitTable(_playerScene, ui->playerHand,
                   _dealerScene, ui->dealerHand);
}

MainWindow::~MainWindow() {}

void MainWindow::on_hitButton_clicked() {
    game.GetPlayer()->Hit(_playerScene, ui->playerHand);
}
