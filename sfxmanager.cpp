#include "sfxmanager.h"

SFXManager::SFXManager() {
	audioOutput->setVolume(0.5);

	music->setAudioOutput(audioOutput.get());
	music->setSource(QUrl("qrc:/sfx/background.mp3"));
	music->setLoops(QMediaPlayer::Infinite);
	music->play();

	betUp->setSource(QUrl("qrc:/sfx/betUp.wav"));
	betUp->setVolume(1.0);

	button->setSource(QUrl("qrc:/sfx/button.wav"));
	button->setVolume(1.0);

	card->setSource(QUrl("qrc:/sfx/card.wav"));
	card->setVolume(1.0);
}