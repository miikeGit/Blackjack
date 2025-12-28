#include "game.h"

Game::Game()
	: _deck(Deck::GetDeck()),
		_player(nullptr),
		_dealer(nullptr),
		_balance(10000),
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
	_player->Hit(playerScene, playerGView);
	_dealer->Hit(dealerScene, dealerGView);
	_player->Hit(playerScene, playerGView);
	_dealer->Hit(dealerScene, dealerGView);
}

void Game::SetBalance(uint32_t newBalance) {
	_balance = newBalance;
}

void Game::SetCurrentBet(uint32_t newBet) {
	_currentBet = newBet;
}
