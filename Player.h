#ifndef BLACKJACK_PLAYER_H
#define BLACKJACK_PLAYER_H

#include "Deck.h"

#include <cstdint>

class Player {
public:
  explicit Player(Deck& deck);
  void Hit();
  void Stand();

  Player(Player&) = delete;
  Player(Player&&) = delete;

  Player operator=(Player&) = delete;
  Player operator=(Player&&) = delete;
private:
  ~Player() = default;

  uint32_t balance;
  uint32_t stake;
  uint8_t handValue;
  std::vector<Card> hand;
  bool IsStanding;
  Deck& deck;
};

#endif
