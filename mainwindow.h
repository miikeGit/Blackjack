#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Player.h"

#include <QMainWindow>
#include <QGraphicsPixmapItem>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private:
    std::shared_ptr<QGraphicsScene> playerScene;
    std::shared_ptr<QGraphicsScene> dealerScene;
    std::unique_ptr<Ui::MainWindow> ui;
    std::unique_ptr<Player> _player;
    std::unique_ptr<Player> _dealer;
};

#endif
