#ifndef BLACKJACK_DECK_H
#define BLACKJACK_DECK_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <random>

enum class Suit { HEARTS, CLUBS, DIAMONDS, SPADES };
enum class Rank { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };

struct Card {
  Suit suit;
  Rank rank;
};

class Deck {
public:
  Deck() {
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 13; j++) {
        int value = j;
        if (j > 10) {
          value = 10;
        }
        deck.emplace_back(static_cast<Suit>(i), static_cast<Rank>(value));
      }
    }
  }

  void Print() {
    for (const auto card : deck) {
      std::cout << static_cast<char>(card.suit) << " " << static_cast<int>(card.rank) << "\n";
    }
  }

  void Shuffle() {
    auto rng = std::default_random_engine{};
    std::ranges::shuffle(deck, rng);
  }

  bool Empty() const {
    return deck.empty();
  }

  Card Pop() {
    const Card tmp = deck.back();
    deck.pop_back();
    return tmp;
  }

private:
  std::vector<Card> deck;
};

#endif