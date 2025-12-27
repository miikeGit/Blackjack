#include "game.h"

Game::Game()
    : _deck(Deck::GetDeck()),
      _playerScene(nullptr),
      _dealerScene(nullptr),
      _playerHandView(nullptr),
      _dealerHandView(nullptr),
      _player(nullptr),
      _dealer(nullptr)
{
}

Game::Game(std::shared_ptr<QGraphicsScene> playerScene,
           std::shared_ptr<QGraphicsScene> dealerScene,
           QGraphicsView* playerHandView,
           QGraphicsView* dealerHandView)
        :
    _playerScene(playerScene), _dealerScene(dealerScene),
    _playerHandView(playerHandView), _dealerHandView(dealerHandView),
    _deck(Deck::GetDeck())
{
    _player = std::make_unique<Player>(_deck);
    _dealer = std::make_unique<Player>(_deck);
}

Game::Game(Game&& other) noexcept
    : _deck(other._deck),
      _playerScene(std::move(other._playerScene)),
      _dealerScene(std::move(other._dealerScene)),
      _playerHandView(other._playerHandView),
      _dealerHandView(other._dealerHandView),
      _player(std::move(other._player)),
      _dealer(std::move(other._dealer))
{
}

Game& Game::operator=(Game&& other) noexcept {
    if (this != &other) {
        _playerScene = std::move(other._playerScene);
        _dealerScene = std::move(other._dealerScene);
        _playerHandView = other._playerHandView;
        _dealerHandView = other._dealerHandView;
        _player = std::move(other._player);
        _dealer = std::move(other._dealer);
    }
    return *this;
}
