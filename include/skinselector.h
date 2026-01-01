#ifndef SKINSELECTOR_H
#define SKINSELECTOR_H

#include <QDialog>
#include <memory>

namespace Ui {
	class SkinSelector;
}

class SkinSelector : public QDialog
{
	Q_OBJECT

public:
	explicit SkinSelector(QWidget *parent = nullptr);
	~SkinSelector();

	const QString GetSkinPath() const;
	const QString GetTexturePackPath() const;

private:
	std::unique_ptr<Ui::SkinSelector> ui;
	QString _texturePackPath;
};

#endif
