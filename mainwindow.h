#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "game.h"

#include <QMainWindow>
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

	static constexpr uint8_t OFFST_RNG = 100;
	static constexpr uint8_t SHAKE_ANIMATION_DURATION = 200;
	static constexpr uint16_t SIZE_ANIMATION_DURATION = 500;
	static constexpr uint16_t FADE_ANIMATION_DURATION = 500;

protected:
	void resizeEvent(QResizeEvent* event);

private:
	Game game;

	std::unique_ptr<Ui::MainWindow> ui;
	std::shared_ptr<QGraphicsScene> _playerScene;
	std::shared_ptr<QGraphicsScene> _dealerScene;

	QPoint calculateRandomOffset();

	QPropertyAnimation* createSizeAnimation(QPoint pos, QLabel* label);
	QPropertyAnimation* createShakeAnimation(QPoint pos, QLabel* label);
	QPropertyAnimation* createFadeAnimation(QLabel* label);

	void HandleBet(int amount);
	void AnimateLabelPopup(QString text);
	void UpdateUI();
	void InitConnections();
};

#endif