#include "game.h"

Game::Game()
    : _deck(Deck::GetDeck()),
      _player(nullptr),
      _dealer(nullptr)
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

void Game::UpdateBalanceUI(QLabel* label) {
    label->setText("Balance: " + QString::number(_player->GetBalance()));
}

void Game::InitTable(std::shared_ptr<QGraphicsScene> playerScene, QGraphicsView* playerGView,
                     std::shared_ptr<QGraphicsScene> dealerScene, QGraphicsView* dealerGView) {
    _player->Hit(playerScene, playerGView);
    _dealer->Hit(dealerScene, dealerGView);
    _player->Hit(playerScene, playerGView);
    _dealer->Hit(dealerScene, dealerGView);
}
