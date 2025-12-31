#ifndef BLACKJACK_DECK_H
#define BLACKJACK_DECK_H

#include <vector>
#include <cstdint>

enum class Suit { HEARTS = 1, CLUBS, DIAMONDS, SPADES };
enum class Rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };

struct Card {
	Suit suit;
	Rank rank;
	bool isFaceDown = false;
};

class Deck {
public:
	Deck();	

	static constexpr uint8_t DECK_SIZE = 52;

	void Shuffle();
	void Reset();
	Card Pop();

private:
	std::vector<Card> deck;
};

#endif