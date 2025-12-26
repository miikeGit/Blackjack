#include "mainwindow.h"
#include "Player.h"

#include <QApplication>


int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Deck deck = Deck::GetDeck();
    Player player(deck);
    MainWindow w(player);
    w.show();
    return app.exec();
}
