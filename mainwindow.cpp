#include "game.h"
#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QGraphicsOpacityEffect>
#include <QParallelAnimationGroup>
#include <QRandomGenerator>

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

	InitConnections();
	UpdateUI();
}

MainWindow::~MainWindow() {}

void MainWindow::InitConnections() {
	connect(ui->bet5Button, &QPushButton::clicked, this, [this](){ HandleBet(5); });
	connect(ui->bet10Button, &QPushButton::clicked, this, [this]{ HandleBet(10); });
	connect(ui->bet25Button, &QPushButton::clicked, this, [this]{ HandleBet(25); });
	connect(ui->bet50Button, &QPushButton::clicked, this, [this]{ HandleBet(50); });
	connect(ui->bet100Button, &QPushButton::clicked, this, [this]{ HandleBet(100); });
	connect(ui->hitButton, &QPushButton::clicked, this, [this]{ game.GetPlayer()->Hit(_playerScene, ui->playerHand);});
}

void MainWindow::resizeEvent(QResizeEvent* event) {
	QMainWindow::resizeEvent(event);
	ui->BetSize->move((centralWidget()->width() - ui->BetSize->width()) / 2,
										(centralWidget()->height() - ui->BetSize->height()) / 2);
}

QPoint MainWindow::calculateRandomOffset() {
	return {QRandomGenerator::global()->bounded(-OFFST_RNG, OFFST_RNG),
					QRandomGenerator::global()->bounded(-OFFST_RNG, OFFST_RNG)};
}

QPropertyAnimation* MainWindow::createSizeAnimation(QPoint position, QLabel* label) {
	auto *sizeAnimation = new QPropertyAnimation(label, "geometry");
	QRect rect(position, label->size());

	sizeAnimation->setDuration(SIZE_ANIMATION_DURATION);
	sizeAnimation->setStartValue(rect);
	sizeAnimation->setKeyValueAt(0.5, rect.adjusted(-15, -20, 15, 20));
	sizeAnimation->setEndValue(rect);
	sizeAnimation->setEasingCurve(QEasingCurve::OutBack);

	return sizeAnimation;
}

QPropertyAnimation* MainWindow::createShakeAnimation(QPoint position, QLabel* label) {
	auto *shakeAnimation = new QPropertyAnimation(label, "pos");
	shakeAnimation->setDuration(SHAKE_ANIMATION_DURATION);
	shakeAnimation->setLoopCount(2);
	shakeAnimation->setKeyValueAt(0, position + QPoint(-7, 4));
	shakeAnimation->setKeyValueAt(0.5, position + QPoint(3, -5));
	shakeAnimation->setEndValue(position);

	return shakeAnimation;
}

QPropertyAnimation* MainWindow::createFadeAnimation(QLabel* label) {
	auto *opacityEffect = new QGraphicsOpacityEffect(label);
	label->setGraphicsEffect(opacityEffect);

	auto *fadeAnimation = new QPropertyAnimation(opacityEffect, "opacity");
	fadeAnimation->setDuration(FADE_ANIMATION_DURATION);
	fadeAnimation->setStartValue(1.0);
	fadeAnimation->setEndValue(0.0);

	return fadeAnimation;
}

void MainWindow::AnimateLabelPopup(QString text) {
	auto *popup = new QLabel(text, this);

	popup->setStyleSheet("font-family: 'balatro'; font-size: 30px; font-weight: bold;");
	popup->setAttribute(Qt::WA_DeleteOnClose);
	popup->setAlignment(Qt::AlignCenter);

	popup->adjustSize();

	QPoint randomPos = centralWidget()->rect().center() + calculateRandomOffset() -
										 QPoint(popup->width() / 2, popup->height() / 2);
	popup->move(randomPos);

	auto *popupGroup = new QParallelAnimationGroup(popup);
	popupGroup->addAnimation(createSizeAnimation(randomPos, popup));
	popupGroup->addAnimation(createShakeAnimation(randomPos, popup));
	popupGroup->addAnimation(createFadeAnimation(popup));

	connect(popupGroup, &QParallelAnimationGroup::finished, popup, &QLabel::deleteLater);
	popup->show();
	popupGroup->start(QAbstractAnimation::DeleteWhenStopped);

	ui->BetSize->adjustSize();

	QPoint center(
		centralWidget()->rect().center().x() - ui->BetSize->width() / 2,
		centralWidget()->rect().center().y() - ui->BetSize->height() / 2
	);

	auto currentBetGroup = new QParallelAnimationGroup(ui->BetSize);
	currentBetGroup->addAnimation(createSizeAnimation(center, ui->BetSize));
	currentBetGroup->addAnimation(createShakeAnimation(center, ui->BetSize));
	currentBetGroup->start(QAbstractAnimation::DeleteWhenStopped);
}

void MainWindow::UpdateUI() {
	ui->balance->setText("$" + QString::number(game.GetBalance()));
	ui->BetSize->setText(QString::number(game.GetCurrentBet()));

	ui->bet100Button->setEnabled(game.GetBalance() >= 100);
	ui->bet50Button->setEnabled(game.GetBalance() >= 50);
	ui->bet25Button->setEnabled(game.GetBalance() >= 25);
	ui->bet10Button->setEnabled(game.GetBalance() >= 10);
	ui->bet5Button->setEnabled(game.GetBalance() >= 5);

	if (game.GetBalance() < 5)
		ui->balance->setStyleSheet("color: red;");
	else
		ui->balance->setStyleSheet("");
}

void MainWindow::HandleBet(int amount) {
	game.SetBalance(game.GetBalance() - amount);
	game.SetCurrentBet(game.GetCurrentBet() + amount);
	UpdateUI();
	AnimateLabelPopup("+ " + QString::number(amount));
}