#include "deck.h"

#include <algorithm>
#include <stdexcept>
#include <QRandomGenerator64>

Deck::Deck() {
	deck.reserve(52);
	Reset();
}

void Deck::Shuffle() {
	std::ranges::shuffle(deck, *QRandomGenerator::global());
}

void Deck::Reset() {
	deck.clear();

	for (int i = 1; i < 5; i++) {
		for (int j = 1; j < 14; j++) {
			deck.emplace_back(static_cast<Suit>(i), static_cast<Rank>(j));
		}
	}

	Shuffle();
}

Card Deck::Pop() {
	if (deck.empty())
		throw std::runtime_error("The deck is empty!");

	const Card tmp = deck.back();
	deck.pop_back();
	return tmp;
}