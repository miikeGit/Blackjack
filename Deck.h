#ifndef BLACKJACK_DECK_H
#define BLACKJACK_DECK_H

#include <vector>
#include <cstdint>

enum class Suit { HEARTS = 1, CLUBS, DIAMONDS, SPADES };
enum class Rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };

struct Card {
  Suit suit;
  Rank rank;
  uint8_t value;
};

class Deck {
public:
  void Shuffle();
  Card Pop();

  static Deck& GetDeck() {
    static Deck deck;
    return deck;
  }

  Deck(const Deck &other) = delete;
  Deck(Deck &&other) = delete;

  Deck & operator=(const Deck &other) = delete;
  Deck & operator=(Deck &&other) = delete;
  ~Deck() = default;
private:
  Deck();

  std::vector<Card> deck;
};

#endif
