#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Player.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(Player& player, QWidget *parent = nullptr);
    ~MainWindow();
private:
    void DrawHand(Player& player);

    Ui::MainWindow *ui;
    Player& _player;
};

#endif
