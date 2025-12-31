#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "game.h"
#include "sfxmanager.h"

#include <QMainWindow>
#include <QPropertyAnimation>
#include <QGraphicsView>
#include <QLabel>

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

	static constexpr uint8_t CARD_SCALE = 3;
	static constexpr uint8_t CARD_SPACING = 40;
	static constexpr uint8_t OFFST_RNG = 100;
	static constexpr uint8_t SHAKE_ANIMATION_DURATION = 200;
	static constexpr uint16_t SIZE_ANIMATION_DURATION = 500;
	static constexpr uint16_t FADE_ANIMATION_DURATION = 500;
	static constexpr uint16_t SLIDE_ANIMATION_DURATION = 500;

protected:
	void resizeEvent(QResizeEvent* event);

private:
	Game game;
	SFXManager sfx;

	std::unique_ptr<Ui::MainWindow> ui;
	std::shared_ptr<QGraphicsScene> _playerScene;
	std::shared_ptr<QGraphicsScene> _dealerScene;

	QPoint calculateRandomOffset();

	QPropertyAnimation* createFadeAnimation(QLabel* label);
	QPropertyAnimation* createSizeAnimation(QPoint pos, QLabel* label);
	QPropertyAnimation* createShakeAnimation(QPoint pos, QLabel* label);

	void InitGame();
	void UpdateUI();
	void ReturnToMenu();
	void InitConnections();
	void ProcessDealersTurn();
	void HandleBet(int amount);
	void EndGame(GameState result);
	void AnimateLabelPopup(QString text);

	QString CardToPath(const Card& card);
	void RenderHand(const std::vector<Card>& hand, std::shared_ptr<QGraphicsScene> scene, QGraphicsView* view);
};

#endif