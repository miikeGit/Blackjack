#include "player.h"

Player::Player(std::shared_ptr<Deck> deck) : _deck(deck) {
	_hand.reserve(11);
}

void Player::Hit(bool isFaceDown) {
	_hand.emplace_back(_deck->Pop());
	_hand.back().isFaceDown = isFaceDown;
}

std::vector<Card>& Player::GetHand() {
	return _hand;
}

uint8_t Player::GetHandValue() const {
	uint8_t value = 0;
	uint8_t numberOfAces = 0;

	for (const Card& card : _hand) {
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