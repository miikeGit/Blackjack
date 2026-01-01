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

private:
	std::unique_ptr<Ui::SkinSelector> ui;
};

#endif
