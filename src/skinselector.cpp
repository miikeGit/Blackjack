#include "skinselector.h"
#include "ui_skinselector.h"
#include <stdexcept>

SkinSelector::SkinSelector(QWidget *parent) :
	QDialog(parent),
	ui(std::make_unique<Ui::SkinSelector>())
{
	ui->setupUi(this);
}

SkinSelector::~SkinSelector() {}

const QString SkinSelector::GetSkinPath() const {
	if (ui->back_1->isChecked()) return ":/textures/Back_1.png";
	if (ui->back_2->isChecked()) return ":/textures/Back_2.png";
	if (ui->back_3->isChecked()) return ":/textures/Back_3.png";
	if (ui->back_4->isChecked()) return ":/textures/Back_4.png";
	if (ui->back_5->isChecked()) return ":/textures/Back_5.png";

	throw std::runtime_error("No skin chosen.");
}