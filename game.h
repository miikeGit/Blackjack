#ifndef GAME_H
#define GAME_H

#include "player.h"

#include <QGraphicsPixmapItem>
#include <QLabel>
#include <memory>

class Game {
public:
	Game();

	Game(Game&& other) noexcept;
	Game& operator=(Game&& other) noexcept;

	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;

	void InitTable(std::shared_ptr<QGraphicsScene> playerScene, QGraphicsView* playerGView,
								 std::shared_ptr<QGraphicsScene> dealerScene, QGraphicsView* dealerGView);

	std::shared_ptr<Player> GetPlayer() const { return _player; }
	uint32_t GetBalance() const { return _balance; }
	uint32_t GetCurrentBet() const { return _currentBet; }

	void SetBalance(uint32_t newBalance);
	void SetCurrentBet(uint32_t newBet);
private:
	Deck& _deck;

	uint32_t _balance;
	uint32_t _currentBet;
	std::shared_ptr<Player> _player;
	std::unique_ptr<Player> _dealer;
};

#endif
