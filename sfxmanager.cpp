#include "sfxmanager.h"

SFXManager::SFXManager() {
	audioOutput->setVolume(5.0);

	music->setAudioOutput(audioOutput.get());
	music->setSource(QUrl("qrc:/sfx/background.mp3"));
	music->setLoops(QMediaPlayer::Infinite);
	music->play();
}