#ifndef ANIMATEDCARD_H
#define ANIMATEDCARD_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>

class AnimatedCard :  public QObject, public QGraphicsItem {
	Q_OBJECT
	Q_INTERFACES(QGraphicsItem)
	Q_PROPERTY(QPointF pos READ pos WRITE setPos)
public:
	AnimatedCard(const QPixmap& pixmap, QGraphicsItem* parent = nullptr)
		: QGraphicsItem(parent), _pixmap(pixmap) {}

	QRectF boundingRect() const override {
		return QRectF(0, 0, _pixmap.width(), _pixmap.height());
	}

	void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override {
		Q_UNUSED(option);
		Q_UNUSED(widget);
		painter->drawPixmap(0, 0, _pixmap);
	}

private:
	QPixmap _pixmap;
};

#endif
