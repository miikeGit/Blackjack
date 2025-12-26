#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QGraphicsPixmapItem>
#include <memory>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(std::make_unique<Ui::MainWindow>()),
    playerScene(std::make_shared<QGraphicsScene>(this)),
    dealerScene(std::make_shared<QGraphicsScene>(this))
{
    Deck& deck = Deck::GetDeck();
    _player = std::make_unique<Player>(deck);
    _dealer = std::make_unique<Player>(deck);

    ui->setupUi(this);
    ui->balance->setText("Balance: " + QString::number(_player->GetBalance()));


    //-------------------
    _player->Hit();
    _dealer->Hit();
    _player->Hit();
    _dealer->Hit();
    _player->DrawHand(playerScene, ui->playerHand);
    _dealer->DrawHand(dealerScene, ui->dealerHand);
}

MainWindow::~MainWindow() {}
