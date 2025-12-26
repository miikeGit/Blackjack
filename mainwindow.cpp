#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QGraphicsPixmapItem>
#include <memory>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(std::make_shared<Ui::MainWindow>()),
    scene(std::make_shared<QGraphicsScene>(this))
{
    Deck& deck = Deck::GetDeck();
    _player = std::make_unique<Player>(deck);
    _dealer = std::make_unique<Player>(deck);

    ui->setupUi(this);
    ui->balance->setText("Balance: " + QString::number(_player->GetBalance()));

    _player->Hit();
    _dealer->Hit();
    _player->Hit();
    _dealer->Hit();
    _player->DrawHand(scene, ui->playerHand);
    _dealer->DrawHand(scene, ui->dealerHand);
}

MainWindow::~MainWindow() {}
