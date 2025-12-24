#ifndef BLACKJACK_PLAYER_H
#define BLACKJACK_PLAYER_H

#include <cstdint>
#include "Deck.h"

class Player {
public:
  explicit Player(Deck& deck);
  void Hit();
  void Stand();

private:
  ~Player() = default;

  Player(Player&) = delete;
  Player(Player&&) = delete;

  Player operator=(Player&) = delete;
  Player operator=(Player&&) = delete;

  uint32_t balance;
  uint32_t stake;
  uint8_t handValue;
  std::vector<Card> hand;
  bool IsStanding;
  Deck& deck;
};

#endif