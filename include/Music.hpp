/*
** EPITECH PROJECT, 2023
** jam1
** File description:
** Music
*/

#ifndef MUSIC_HPP_
#define MUSIC_HPP_
    #include <map>
    #include <memory>
    #include "SFML/Audio.hpp"

class Music{
    public:
        Music();
        ~Music();

        /// @brief Loads music in memory
        /// @param what Music name
        /// @param path Music path
        void loadSound(std::string what, std::string path);

        /// @brief Plays music in memory
        /// @param what Music name
        /// @param path Music path
        void playSound(std::string what, std::string path); //play a music

        /// @brief Stops a playing music in memory
        /// @param what Music name
        /// @param path Music path
        void stopSound(std::string what, std::string path); //stop a music

        /// @brief Pauses a playing music in memory
        /// @param what Music name
        /// @param path Music path
        void pauseSound(std::string what); //pause a music

        /// @brief Set the volume
        /// @param what Music name
        /// @param int volume value
        void setVolume(std::string what, int); //set the volume

        /// @brief Decreases the volume
        void decreaseVolume(); //decrease the volume

        /// @brief Increases the volume
        void increaseVolume(); //increase the volume

        /// @brief Sets music in a loop
        /// @param what Music name
        /// @param path Music path
        void setLoop(std::string what, std::string path); //set the loop

        /// @brief Sets Music in a loop
        /// @param what Music name
        void setLoop(std::string what);

    protected:
    private:
        std::map<std::string, sf::Music> sounds;
};

#endif /* !MUSIC_HPP_ */
