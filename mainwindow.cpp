#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QGraphicsPixmapItem>

QString CardToPath(const Card& card) {
    QString suitRank { QString::number(static_cast<int>(card.suit)) + "_" + QString::number(static_cast<int>(card.rank)) };
    QString path { ":/images/textures/" + suitRank + ".png" };
    return path;
}

MainWindow::MainWindow(Player& player, QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow), _player(player) {

    ui->setupUi(this);
    ui->label->setText("Balance: " + QString::number(player.GetBalance()));

    player.Hit();
    DrawHand(player);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::DrawHand(Player& player) {
    std::vector<Card> hand = player.GetHand();

    QGraphicsScene *scene = nullptr;

    for (const Card& card : hand) {
        QPixmap pixmap(CardToPath(card));
        scene = new QGraphicsScene(this);
        QGraphicsPixmapItem *item = scene->addPixmap(pixmap);
        item->setScale(3);
        ui->graphicsView->setScene(scene);
    }
}
