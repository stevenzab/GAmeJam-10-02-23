/*
** EPITECH PROJECT, 2022
** B-CPP-500-PAR-5-1-rtype-neilah.abdou-imorou
** File description:
** Music
*/

#include "../include/Music.hpp"

Music::Music()
{
}

Music::~Music()
{
}

void Music::loadSound(std::string what, std::string path)
{
    auto search = sounds.find(what);
    if (search == sounds.end())
        if (!sounds[what].openFromFile(path))
            return;
}

void Music::playSound(std::string what, std::string path) //play a music
{
    auto search = sounds.find(what);
    if (search == sounds.end())
        loadSound(what, path);
    if (sounds[what].getStatus() != sf::SoundSource::Playing)
        sounds[what].play();
}

void Music::stopSound(std::string what, std::string path) //stop a music
{
    auto search = sounds.find(what);
    if (search == sounds.end())
        loadSound(what, path);
    sounds[what].stop();
}

void Music::pauseSound(std::string what) //pause a music
{
    auto search = sounds.find(what);
    if (search == sounds.end())
        return;
    sounds[what].pause();
}

void Music::setVolume(std::string what, int volume) //set the volume
{
    auto search = sounds.find(what);
    if (search == sounds.end())
        return;
    sounds[what].setVolume(volume);
}

void Music::decreaseVolume() //decrease the volume
{
    for (auto &i : sounds)
        i.second.setVolume(i.second.getVolume() - 10);
}

void Music::increaseVolume() //increase the volume
{
    for (auto &i : sounds)
        i.second.setVolume(i.second.getVolume() + 10);
}

void Music::setLoop(std::string what, std::string path) //set the loop
{
    auto search = sounds.find(what);
    if (search == sounds.end())
        loadSound(what, path);
    sounds[what].setLoop(true);
}

void Music::setLoop(std::string what) //set the loop
{
    auto search = sounds.find(what);
    if (search == sounds.end())
        loadSound(what, what);
    sounds[what].setLoop(true);
}
