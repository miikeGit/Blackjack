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
	uint8_t GetHandValue() const;

	std::vector<Card>& GetHand();

	void Hit(std::shared_ptr<QGraphicsScene> scene, QGraphicsView* gView, bool isFaceDown);

	Player(Player& other);
	Player(Player&& other);

	Player operator=(Player& other);
	Player& operator=(Player&& other);
	~Player() = default;
	void DrawHand(std::shared_ptr<QGraphicsScene> scene, QGraphicsView* gView);
private:
	std::vector<Card> hand;
	Deck& deck = Deck::GetDeck();
};

#endif
