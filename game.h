#ifndef GAME_H
#define GAME_H

#include "Player.h"

#include <QGraphicsPixmapItem>
#include <memory>

class Game {
public:
    Game();
    Game(std::shared_ptr<QGraphicsScene> playerScene,
        std::shared_ptr<QGraphicsScene> dealerScene,
        QGraphicsView* playerHandView,
        QGraphicsView* dealerHandView);
    
    Game(Game&& other) noexcept;
    Game& operator=(Game&& other) noexcept;
    
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

private:
  Deck& _deck;

  std::shared_ptr<QGraphicsScene> _playerScene;
  std::shared_ptr<QGraphicsScene> _dealerScene;

  QGraphicsView* _playerHandView;
  QGraphicsView* _dealerHandView;

  std::unique_ptr<Player> _player;
  std::unique_ptr<Player> _dealer;
};

#endif
