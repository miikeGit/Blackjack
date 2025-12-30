#include "game.h"

Game::Game()
	: _deck(std::make_shared<Deck>()),
		_player(nullptr),
		_dealer(nullptr),
		_balance(1000),
		_currentBet(0)
{
	_player = std::make_shared<Player>(_deck);
	_dealer = std::make_shared<Player>(_deck);
}

void Game::InitTable() {
	_player->Hit(false);
	_dealer->Hit(false);
	_player->Hit(false);
	_dealer->Hit(true);

	_isDealerDone = false;
}

void Game::ClearTable() {
	_player->GetHand().clear();
	_dealer->GetHand().clear();
	_deck->Reset();
}

void Game::SetBalance(uint32_t newBalance) {
	_balance = newBalance;
}

void Game::SetCurrentBet(uint32_t newBet) {
	_currentBet = newBet;
}

GameState Game::CheckIfEnded() {
	uint8_t playerValue = _player->GetHandValue();
	uint8_t dealerValue = _dealer->GetHandValue();

	if (playerValue > 21) {
		return GameState::LOSS;
	}

	if (_isDealerDone) {
		if (dealerValue > 21) {
			_currentBet *= 2;
			_balance += _currentBet;
			return GameState::WIN;
		}

		if (dealerValue > playerValue) {
			return GameState::LOSS;
		}
		else if (playerValue >= dealerValue) {
			_currentBet *= 2;
			_balance += _currentBet;
			return GameState::WIN;
		}
	}

	return GameState::IN_PROGRESS;
}

void Game::MakeDealerPlay() {
	_dealer->GetHand().back().isFaceDown = false;

	while (_dealer->GetHandValue() < 17) {
		_dealer->Hit(false);
	}

	_isDealerDone = true;
}