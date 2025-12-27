#ifndef BLACKJACK_PLAYER_H
#define BLACKJACK_PLAYER_H

#include "deck.h"

#include <cstdint>
#include <memory>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>

class Player {
public:
  explicit Player(Deck& deck);

  uint32_t GetBalance() const;

  void Hit();
  void DrawHand(std::shared_ptr<QGraphicsScene> scene, QGraphicsView* gView);

  // Player(Player& other);
  // Player(Player&& other);

  // Player operator=(Player&) = default;
  // Player operator=(Player&&) = default;
  ~Player() = default;
private:

  uint32_t balance;
  uint32_t stake;
  uint8_t handValue;
  std::vector<Card> hand;
  Deck& deck;
};

#endif
