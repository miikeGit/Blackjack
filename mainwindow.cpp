#include "game.h"
#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QGraphicsOpacityEffect>
#include <QParallelAnimationGroup>
#include <QGraphicsPixmapItem>
#include <memory>
#include <qrandom.h>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(std::make_unique<Ui::MainWindow>())
{
	ui->setupUi(this);

	ui->dealerHand->hide();
	ui->playerHand->hide();
	ui->standButton->hide();
	ui->hitButton->hide();

	_playerScene = std::make_shared<QGraphicsScene>(this);
	_dealerScene = std::make_shared<QGraphicsScene>(this);

	UpdateBalanceUI();
	game.InitTable(_playerScene, ui->playerHand,
								 _dealerScene, ui->dealerHand);
}

MainWindow::~MainWindow() {}

void MainWindow::on_hitButton_clicked() {
	game.GetPlayer()->Hit(_playerScene, ui->playerHand);
}

void MainWindow::resizeEvent(QResizeEvent* event) {
	QMainWindow::resizeEvent(event);
	ui->BetSize->move((centralWidget()->width() - ui->BetSize->width()) / 2,
										(centralWidget()->height() - ui->BetSize->height()) / 2);
}

QPoint MainWindow::calculateRandomPosition() {
	auto *random = QRandomGenerator::global();
	int offsetLimit = 100;

	int offsetX = random->bounded(-offsetLimit, offsetLimit);
	int offsetY = random->bounded(-offsetLimit, offsetLimit);

	int centerX = (centralWidget()->width() - 200) / 2;
	int centerY = (centralWidget()->height() - 100) / 2;

	return {centerX + offsetX, centerY + offsetY};
}

QPropertyAnimation* MainWindow::configureSizeAnimation(QPoint position, QLabel* label) {
	QPropertyAnimation *sizeAnimation = new QPropertyAnimation(label, "geometry");
	QRect targetRect(position.x(), position.y(), label->width(), label->height());

	sizeAnimation->setDuration(500);
	sizeAnimation->setStartValue(targetRect);
	sizeAnimation->setKeyValueAt(0.5, targetRect.adjusted(-15, -20, 15, 20));
	sizeAnimation->setEndValue(targetRect);
	sizeAnimation->setEasingCurve(QEasingCurve::OutBack);

	return sizeAnimation;
}

QPropertyAnimation* MainWindow::configureShakeAnimation(QPoint position, QLabel* label) {
	QPropertyAnimation *shakeAnimation = new QPropertyAnimation(label, "pos");
	shakeAnimation->setDuration(200);
	shakeAnimation->setLoopCount(2);
	shakeAnimation->setKeyValueAt(0, position + QPoint(-7, 4));
	shakeAnimation->setKeyValueAt(0.5, position + QPoint(3, -5));
	shakeAnimation->setEndValue(position);

	return shakeAnimation;
}

QPropertyAnimation* MainWindow::configureFadeAnimation(QLabel* label) {
	QGraphicsOpacityEffect *opacityEffect = new QGraphicsOpacityEffect(label);
	label->setGraphicsEffect(opacityEffect);

	QPropertyAnimation *fadeAnimation = new QPropertyAnimation(opacityEffect, "opacity");
	fadeAnimation->setDuration(500);
	fadeAnimation->setStartValue(1.0);
	fadeAnimation->setEndValue(0.0);

	return fadeAnimation;
}

void MainWindow::animateLabelPopup(QString text) {
	QLabel *popupLabel = new QLabel(text, this);

	QFont balatroFont("balatro");
	balatroFont.setPixelSize(30);
	balatroFont.setBold(true);
	popupLabel->setFont(balatroFont);
	popupLabel->setFixedSize(200, 100);
	popupLabel->setAlignment(Qt::AlignCenter);

	QPoint randomPos = calculateRandomPosition();
	popupLabel->move(randomPos);

	QPropertyAnimation *size = configureSizeAnimation(randomPos, popupLabel);
	QPropertyAnimation *shake = configureShakeAnimation(randomPos, popupLabel);
	QPropertyAnimation *fade = configureFadeAnimation(popupLabel);

	QPoint center = {(centralWidget()->width() - ui->BetSize->width()) / 2,
									 (centralWidget()->height() - ui->BetSize->height()) / 2};
	QPropertyAnimation *size2 = configureSizeAnimation(center, ui->BetSize);
	QPropertyAnimation *shake2 = configureShakeAnimation(center, ui->BetSize);

	QParallelAnimationGroup *group = new QParallelAnimationGroup(popupLabel);
	group->addAnimation(size);
	group->addAnimation(shake);
	group->addAnimation(fade);

	QParallelAnimationGroup *group2 = new QParallelAnimationGroup(ui->BetSize);
	group2->addAnimation(size2);
	group2->addAnimation(shake2);


	popupLabel->show();
	group->start(QAbstractAnimation::DeleteWhenStopped);
	group2->start(QAbstractAnimation::DeleteWhenStopped);
}

void MainWindow::UpdateBalanceUI() {
	ui->balance->setText("$" + QString::number(game.GetBalance()));
	ui->BetSize->setText(QString::number(game.GetCurrentBet()));

	if (game.GetBalance() < 100) ui->bet100Button->setEnabled(false);
	if (game.GetBalance() < 50) ui->bet50Button->setEnabled(false);
	if (game.GetBalance() < 25) ui->bet25Button->setEnabled(false);
	if (game.GetBalance() < 10) ui->bet10Button->setEnabled(false);
	if (game.GetBalance() < 5) ui->bet5Button->setEnabled(false);
}

void MainWindow::on_bet5Button_clicked() {
	game.SetBalance(game.GetBalance() - 5);
	game.SetCurrentBet(game.GetCurrentBet() + 5);
	UpdateBalanceUI();
	animateLabelPopup("+ " + QString::number(5));
}

void MainWindow::on_bet10Button_clicked() {
	game.SetBalance(game.GetBalance() - 10);
	game.SetCurrentBet(game.GetCurrentBet() + 10);
	UpdateBalanceUI();
	animateLabelPopup("+ " + QString::number(10));
}

void MainWindow::on_bet25Button_clicked(){
	game.SetBalance(game.GetBalance() - 25);
	game.SetCurrentBet(game.GetCurrentBet() + 25);
	UpdateBalanceUI();
	animateLabelPopup("+ " + QString::number(25));
}

void MainWindow::on_bet50Button_clicked() {
	game.SetBalance(game.GetBalance() - 50);
	game.SetCurrentBet(game.GetCurrentBet() + 50);
	UpdateBalanceUI();
	animateLabelPopup("+ " + QString::number(50));
}

void MainWindow::on_bet100Button_clicked() {
	game.SetBalance(game.GetBalance() - 100);
	game.SetCurrentBet(game.GetCurrentBet() + 100);
	UpdateBalanceUI();
	animateLabelPopup("+ " + QString::number(100));
}