#include "player.h"
#include <algorithm>

Player::Player(Deck& deck) {
	hand.reserve(11);
}

void Player::Hit(std::shared_ptr<QGraphicsScene> scene, QGraphicsView* gView, bool isFaceDown) {
	hand.emplace_back(deck.Pop());
	hand.back().isFaceDown = isFaceDown;
	DrawHand(scene, gView);
}

QString CardToPath(const Card& card) {
	if (card.isFaceDown) {
			return ":images/textures/Back_1.png";
		}

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

std::vector<Card>& Player::GetHand() {
	return hand;
}

// Player::Player(Player& other) {
//     balance = other.balance;
//     stake = other.stake;
//     handValue = other.handValue;
//     hand = other.hand;
//     Deck& deck;
// }
Player::Player(Player&& other) : deck(Deck::GetDeck()) {
	hand = std::move(other.hand);
}

// Player operator=(Player&) = default;
Player& Player::operator=(Player&& other) {
	if (this != &other) {
			hand = std::move(other.hand);
		}
	return *this;
}

uint8_t Player::GetHandValue() const {
	uint8_t value = 0;
	uint8_t numberOfAces = 0;

	for (const Card& card : hand) {
		if (card.rank == Rank::ACE) {
			numberOfAces++;
			value += 11;
		} else {
			value += std::min(static_cast<int>(card.rank), 10);
		}
	}

	while (value > 21 && numberOfAces > 0) {
		value -= 10;
		numberOfAces--;
	}

	return value;
}