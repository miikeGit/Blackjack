#include "skinselector.h"
#include "ui_skinselector.h"

#include <stdexcept>
#include <QFileDialog>

SkinSelector::SkinSelector(QWidget *parent) :
	QDialog(parent),
	ui(std::make_unique<Ui::SkinSelector>()),
	_texturePackPath(":/textures/")
{
	ui->setupUi(this);
	connect(ui->loadButton, &QPushButton::clicked, this, [this]{
		_texturePackPath = QFileDialog::getExistingDirectory(this, "Select Texture Pack", QDir::homePath(), QFileDialog::ShowDirsOnly);
		accept();
	});
}

SkinSelector::~SkinSelector() {}

const QString SkinSelector::GetSkinPath() const {
	if (ui->back_1->isChecked()) return _texturePackPath + "/Back_1.png";
	if (ui->back_2->isChecked()) return _texturePackPath + "/Back_2.png";
	if (ui->back_3->isChecked()) return _texturePackPath + "/Back_3.png";
	if (ui->back_4->isChecked()) return _texturePackPath + "/Back_4.png";
	if (ui->back_5->isChecked()) return _texturePackPath + "/Back_5.png";

	throw std::runtime_error("No skin chosen.");
}

const QString SkinSelector::GetTexturePackPath() const {
	return _texturePackPath;
}