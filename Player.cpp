#include "Player.h"

Player::Player(Deck& deck) : balance(1000), stake(0), handValue(0), IsStanding(false), deck(deck)  {
  hand.reserve(5);
}

void Player::Hit() {
  hand.emplace_back(deck.Pop());
  handValue += static_cast<int>(hand.back().rank);
}

void Player::Stand() {
  IsStanding = true;
}

uint32_t Player::GetBalance() const {
  return balance;
}

QString CardToPath(const Card& card) {
    QString suitRank { QString::number(static_cast<int>(card.suit)) + "_"
                     + QString::number(static_cast<int>(card.rank)) };

    QString path { ":/images/textures/" + suitRank + ".png" };
    return path;
}

void Player::DrawHand(std::shared_ptr<QGraphicsScene> scene, QGraphicsView* gView) {
    uint32_t offset = 0;
    for (const Card& card : hand) {
        QPixmap pixmap(CardToPath(card));
        QGraphicsPixmapItem *item = scene->addPixmap(pixmap);
        item->setScale(3);
        item->setPos(offset, offset);

        offset += 30;
    }
    gView->setScene(scene.get());
}
