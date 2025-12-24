#include "Deck.h"

#include <algorithm>
#include <cstdint>
#include <random>
#include <stdexcept>

Deck::Deck() {
  deck.reserve(52);

  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 13; j++) {
      uint8_t value = (j > 10) ? 10 : j;
      deck.emplace_back(static_cast<Suit>(i), static_cast<Rank>(value));
    }
  }
}

void Deck::Shuffle() {
  auto rng = std::default_random_engine{};
  std::ranges::shuffle(deck, rng);
}

Card Deck::Pop() {
  if (deck.empty())
    throw std::runtime_error("The deck is empty!");

  const Card tmp = deck.back();
  deck.pop_back();
  return tmp;
}