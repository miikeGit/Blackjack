#ifndef SKINSELECTOR_H
#define SKINSELECTOR_H

#include <QDialog>

namespace Ui {
	class SkinSelector;
}

class SkinSelector : public QDialog
{
	Q_OBJECT

public:
	explicit SkinSelector(QWidget *parent = nullptr);
	~SkinSelector();

private:
	Ui::SkinSelector *ui;
};

#endif // SKINSELECTOR_H
