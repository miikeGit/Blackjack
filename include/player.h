#ifndef BLACKJACK_PLAYER_H
#define BLACKJACK_PLAYER_H

#include "deck.h"

#include <memory>

class Player {
public:
	explicit Player(std::shared_ptr<Deck> deck);

	static constexpr uint8_t MAX_HAND_SIZE = 11;

	uint8_t GetHandValue() const;
	std::vector<Card>& GetHand();

	void Hit(bool isFaceDown);

private:
	std::vector<Card> _hand;
	std::shared_ptr<Deck> _deck;
};

#endif
