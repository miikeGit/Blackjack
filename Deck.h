#ifndef BLACKJACK_DECK_H
#define BLACKJACK_DECK_H

#include <vector>

enum class Suit { HEARTS, CLUBS, DIAMONDS, SPADES };
enum class Rank { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };

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

private:
  Deck();
  ~Deck() = default;

  Deck(const Deck &other) = delete;
  Deck(Deck &&other) = delete;

  Deck & operator=(const Deck &other) = delete;
  Deck & operator=(Deck &&other) = delete;

  std::vector<Card> deck;
};

#endif