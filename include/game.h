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
	
	uint32_t GetBalance()    const { return _balance;      }
	uint32_t GetCurrentBet() const { return _currentBet;   }
	bool IsDealersTurn()			 const { return _isDealersTurn; }

	GameState GetCurrentState();

	void DealerHit();
	void RevealDealersCard();
	void SetCurrentBet(uint32_t newBet);
	void SetBalance(uint32_t newBalance);
	void SetDealersTurn(bool isDealersTurn);

private:
	uint32_t _balance;
	uint32_t _currentBet;

	bool _isDealersTurn = false;

	std::shared_ptr<Deck> _deck;
	std::shared_ptr<Player> _player;
	std::shared_ptr<Player> _dealer;
};

#endif
