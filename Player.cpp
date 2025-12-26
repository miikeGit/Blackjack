#include "Player.h"

Player::Player(Deck& deck) : balance(1000), stake(0), handValue(0), IsStanding(false), deck(deck)  {
  hand.reserve(5);
}

void Player::Hit() {
  hand.emplace_back(deck.Pop());
  handValue += static_cast<int>(hand.back().rank);
}

void Player::Stand() {
  IsStanding = false;
}

uint32_t Player::GetBalance() const {
  return balance;
}

std::vector<Card> Player::GetHand() const {
    return hand;
}
