#include "game.h"

Game::Game()
	: _deck(std::make_shared<Deck>()),
		_player(std::make_shared<Player>(_deck)),
		_dealer(std::make_shared<Player>(_deck)),
		_balance(INITIAL_BALANCE),
		_currentBet(0)
{}

void Game::InitTable() {
	_player->Hit(false);
	_dealer->Hit(false);
	_player->Hit(false);
	_dealer->Hit(true);

	_isDealersTurn = false;
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

GameState Game::GetCurrentState() {
	uint8_t playerValue = _player->GetHandValue();
	uint8_t dealerValue = _dealer->GetHandValue();

	if (playerValue > 21) {
		return GameState::LOSS;
	}
	else if (playerValue == 21) {
		return GameState::WIN;
	}

	if (_isDealersTurn) {
		if (dealerValue < 17) {
			return GameState::IN_PROGRESS;
		}

		if (dealerValue > 21 || playerValue >= dealerValue) {
			return GameState::WIN;
		} else {
			return GameState::LOSS;
		}
	}

	return GameState::IN_PROGRESS;
}

void Game::DealerHit() {
	_dealer->Hit(false);
}

void Game::RevealDealersCard() {
	_dealer->GetHand().at(1).isFaceDown = false;
}

void Game::SetDealersTurn(bool isDealersTurn) {
	_isDealersTurn = isDealersTurn;
}