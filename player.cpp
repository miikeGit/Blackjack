#include "player.h"

Player::Player(Deck& deck) : balance(1000), stake(0), handValue(0) {
	hand.reserve(11);
}

void Player::Hit(std::shared_ptr<QGraphicsScene> scene, QGraphicsView* gView) {
	hand.emplace_back(deck.Pop());
	handValue += static_cast<int>(hand.back().rank);
	DrawHand(scene, gView);
}

uint32_t Player::GetBalance() const {
	return balance;
}

QString CardToPath(const Card& card) {
	QString suitRank { QString::number(static_cast<int>(card.suit)) + "_"
				+ QString::number(static_cast<int>(card.rank)) };

	QString path { ":/images/textures/" + suitRank + ".png" };
	return path;
}

void Player::DrawHand(std::shared_ptr<QGraphicsScene> scene, QGraphicsView* gView) {
	uint32_t offset = 0;
	for (const Card& card : hand) {
			QPixmap pixmap(CardToPath(card));
			QGraphicsPixmapItem *item = scene->addPixmap(pixmap);
			item->setScale(3);
			item->setPos(offset, 0);

			offset += 30;
		}
	gView->setScene(scene.get());
}

// Player::Player(Player& other) {
//     balance = other.balance;
//     stake = other.stake;
//     handValue = other.handValue;
//     hand = other.hand;
//     Deck& deck;
// }
Player::Player(Player&& other) : deck(Deck::GetDeck()) {
	balance = other.balance;
	stake = other.stake;
	handValue = other.handValue;
	hand = std::move(other.hand);
}

// Player operator=(Player&) = default;
Player& Player::operator=(Player&& other) {
	if (this != &other) {
			balance = std::move(other.balance);
			stake = std::move(other.stake);
			handValue = std::move(other.handValue);
			hand = std::move(other.hand);
		}
	return *this;
}
