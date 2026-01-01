#include "skinselector.h"
#include "ui_skinselector.h"

SkinSelector::SkinSelector(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::SkinSelector)
{
	ui->setupUi(this);
}

SkinSelector::~SkinSelector()
{
	delete ui;
}
