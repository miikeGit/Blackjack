#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "game.h"

#include <QMainWindow>
#include <QGraphicsOpacityEffect>
#include <QGraphicsPixmapItem>
#include <QPropertyAnimation>

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
	Game game = Game();

	std::unique_ptr<Ui::MainWindow> ui;
	std::shared_ptr<QGraphicsScene> _playerScene;
	std::shared_ptr<QGraphicsScene> _dealerScene;

	QGraphicsOpacityEffect *betOpacity;

	QPoint calculateRandomPosition();

	QPropertyAnimation* configureSizeAnimation(QPoint pos, QLabel* label);
	QPropertyAnimation* configureShakeAnimation(QPoint pos, QLabel* label);
	QPropertyAnimation* configureFadeAnimation(QLabel* label);

	void animateLabelPopup(QString text);
	void resizeEvent(QResizeEvent* event);
	void UpdateBalanceUI();

private slots:
	void on_hitButton_clicked();
	void on_bet5Button_clicked();
	void on_bet10Button_clicked();
	void on_bet25Button_clicked();
	void on_bet50Button_clicked();
	void on_bet100Button_clicked();
};

#endif