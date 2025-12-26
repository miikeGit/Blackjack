#ifndef BLACKJACK_DECK_H
#define BLACKJACK_DECK_H

#include <vector>

enum class Suit { HEARTS = 1, CLUBS, DIAMONDS, SPADES };
enum class Rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };

struct Card {
  Suit suit;
  Rank rank;
};

class Deck {
public:
  void Shuffle();
  Card Pop();

  static Deck& GetDeck() {
    static Deck deck;
    return deck;
  }

  Deck(const Deck &other) = default;
  Deck(Deck &&other) = default;

  Deck & operator=(const Deck &other) = default;
  Deck & operator=(Deck &&other) = default;
  ~Deck() = default;
private:
  Deck();

  std::vector<Card> deck;
};

#endif
