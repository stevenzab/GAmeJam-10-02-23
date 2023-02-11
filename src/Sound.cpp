/*
** EPITECH PROJECT, 2023
** jam1
** File description:
** Sound
*/

#include "../include/Sound.hpp"

Sound::Sound()
{
}

Sound::~Sound()
{
}

void Sound::loadSound(std::string what, std::string path)
{
    if (!buffers[what].loadFromFile(path))
        return;
    sounds[what].setBuffer(buffers[what]);
}

void Sound::playSound(std::string what, std::string path) //play a music
{
    auto search = sounds.find(what);
    if (search == sounds.end())
        loadSound(what, path);
    if (sounds[what].getStatus() != sf::SoundSource::Playing) {
        sounds[what].play();
    }
}

void Sound::stopSound(std::string what, std::string path) //stop a music
{
    auto search = sounds.find(what);
    if (search == sounds.end())
        loadSound(what, path);
    sounds[what].stop();
}

void Sound::pauseSound(std::string what) //pause a music
{
    auto search = sounds.find(what);
    if (search == sounds.end())
        return;
    sounds[what].pause();
}

void Sound::setVolume(std::string what, int volume) //set the volume
{
    auto search = sounds.find(what);
    if (search == sounds.end())
        return;
    sounds[what].setVolume(volume);
}

void Sound::decreaseVolume() //decrease the volume
{
    for (auto &i : sounds)
        i.second.setVolume(i.second.getVolume() - 10);
}

void Sound::increaseVolume() //increase the volume
{
    for (auto &i : sounds)
        i.second.setVolume(i.second.getVolume() + 10);
}

void Sound::setLoop(std::string what, std::string path) //set the loop
{
    auto search = sounds.find(what);
    if (search == sounds.end())
        loadSound(what, path);
    sounds[what].setLoop(true);
}

void Sound::setLoop(std::string what) //set the loop
{
    auto search = sounds.find(what);
    if (search == sounds.end())
        loadSound(what, what);
    sounds[what].setLoop(true);
}

