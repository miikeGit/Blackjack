#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "game.h"

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
    Game game;
    std::shared_ptr<QGraphicsScene> playerScene;
    std::shared_ptr<QGraphicsScene> dealerScene;
    std::unique_ptr<Ui::MainWindow> ui;
private slots:
    void on_hitButton_clicked();
};

#endif
