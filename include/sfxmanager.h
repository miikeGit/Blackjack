#ifndef SFXMANAGER_H
#define SFXMANAGER_H

#include <memory>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QUrl>
#include <QSoundEffect>

class SFXManager {
public:
	SFXManager();

	std::unique_ptr<QSoundEffect> betUp = std::make_unique<QSoundEffect>();
	std::unique_ptr<QSoundEffect> button = std::make_unique<QSoundEffect>();
	std::unique_ptr<QSoundEffect> card = std::make_unique<QSoundEffect>();
private:
	std::unique_ptr<QAudioOutput> audioOutput = std::make_unique<QAudioOutput>();
	std::unique_ptr<QMediaPlayer> music = std::make_unique<QMediaPlayer>();
};

#endif
