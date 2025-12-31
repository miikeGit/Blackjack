#ifndef SFXMANAGER_H
#define SFXMANAGER_H

#include <memory>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QUrl>

class SFXManager {
public:
	SFXManager();

private:
	std::unique_ptr<QAudioOutput> audioOutput = std::make_unique<QAudioOutput>();
	std::unique_ptr<QMediaPlayer> music = std::make_unique<QMediaPlayer>();
};

#endif
