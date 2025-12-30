#ifndef GAME_H
#define GAME_H

#include "player.h"

enum class GameState {
	IN_PROGRESS,
	WIN,
	LOSS
};

class Game {
public:
	Game();

	void InitTable();
	void ClearTable();

	std::shared_ptr<Player> GetPlayer() const { return _player; }
	std::shared_ptr<Player> GetDealer() const { return _dealer; }
	
	uint32_t GetBalance()    const { return _balance;    }
	uint32_t GetCurrentBet() const { return _currentBet; }

	GameState CheckIfEnded();

	void SetBalance(uint32_t newBalance);
	void SetCurrentBet(uint32_t newBet);
	void MakeDealerPlay();

private:
	uint32_t _balance;
	uint32_t _currentBet;

	bool _isDealerDone = false;

	std::shared_ptr<Deck> _deck;
	std::shared_ptr<Player> _player;
	std::shared_ptr<Player> _dealer;
};

#endif
