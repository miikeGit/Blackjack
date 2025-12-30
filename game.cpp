#include "game.h"

Game::Game()
	: _deck(Deck::GetDeck()),
		_player(nullptr),
		_dealer(nullptr),
		_balance(1000),
		_currentBet(0)
{
	_player = std::make_shared<Player>(_deck);
	_dealer = std::make_unique<Player>(_deck);
}

Game::Game(Game&& other) noexcept
	: _deck(other._deck),
		_player(std::move(other._player)),
		_dealer(std::move(other._dealer))
{}

Game& Game::operator=(Game&& other) noexcept {
	if (this != &other) {
			_player = std::move(other._player);
			_dealer = std::move(other._dealer);
		}
	return *this;

}

void Game::InitTable(std::shared_ptr<QGraphicsScene> playerScene, QGraphicsView* playerGView,
										 std::shared_ptr<QGraphicsScene> dealerScene, QGraphicsView* dealerGView) {
	_player->Hit(playerScene, playerGView, false);
	_dealer->Hit(dealerScene, dealerGView, false);
	_player->Hit(playerScene, playerGView, false);
	_dealer->Hit(dealerScene, dealerGView, true);

	_isDealerDone = false;
}

void Game::ClearTable() {
	_player->GetHand().clear();
	_dealer->GetHand().clear();
	_deck.Reset();
}

void Game::SetBalance(uint32_t newBalance) {
	_balance = newBalance;
}

void Game::SetCurrentBet(uint32_t newBet) {
	_currentBet = newBet;
}

std::pair<bool, bool> Game::CheckIfEnded() {
	uint8_t playerValue = _player->GetHandValue();
	uint8_t dealerValue = _dealer->GetHandValue();

	if (playerValue > 21) { // Loss
		ClearTable();
		return {true, false};
	}

	if (_isDealerDone) {
		if (dealerValue > 21) { // Win
			_currentBet *= 2;
			_balance += _currentBet;
			ClearTable();
			return {true, true};
		}

		if (dealerValue > playerValue) { // Loss
			ClearTable();
			return {true, false};
		}
		else if (playerValue >= dealerValue) { // Win
			_currentBet *= 2;
			_balance += _currentBet;
			ClearTable();
			return {true, true};
		}
	}

	// Continue
	return {false, false};
}

void Game::InitDealer(std::shared_ptr<QGraphicsScene> dealerScene, QGraphicsView* dealerGView) {
	// flip facedown card
	_dealer->GetHand().back().isFaceDown = false;
	_dealer->DrawHand(dealerScene, dealerGView);

	while (_dealer->GetHandValue() < 17) {
		_dealer->Hit(dealerScene, dealerGView, false);
	}

	_isDealerDone = true;
}