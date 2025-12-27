#ifndef GAME_H
#define GAME_H

#include "Player.h"

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

    void UpdateBalanceUI(QLabel* label);
    std::shared_ptr<Player> GetPlayer() const {
        return _player;
    }

    void InitTable(std::shared_ptr<QGraphicsScene> playerScene, QGraphicsView* playerGView,
                   std::shared_ptr<QGraphicsScene> dealerScene, QGraphicsView* dealerGView);

private:
  Deck& _deck;

  std::shared_ptr<Player> _player;
  std::unique_ptr<Player> _dealer;
};

#endif
