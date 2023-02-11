/*
** EPITECH PROJECT, 2023
** jam1
** File description:
** Sound
*/


#ifndef SOUND_HPP_
#define SOUND_HPP_

    #include <map>
    #include <memory>
    #include "SFML/Audio.hpp"

class Sound {
    public:
        Sound();
        ~Sound();

        /// @brief Loads sound in memory
        /// @param what sound name
        /// @param path sound path
        void loadSound(std::string what, std::string path);

        /// @brief Plays sound in memory
        /// @param what sound name
        /// @param path sound path
        void playSound(std::string what, std::string path); //play a sound

        /// @brief Stops a playing sound in memory
        /// @param what sound name
        /// @param path sound path
        void stopSound(std::string what, std::string path); //stop a sound

        /// @brief Pauses a playing sound in memory
        /// @param what sound name
        /// @param path sound path
        void pauseSound(std::string what); //pause a sound

        /// @brief Set the volume
        /// @param what sound name
        /// @param int volume value
        void setVolume(std::string what, int); //set the volume

        /// @brief Decreases the volume
        void decreaseVolume(); //decrease the volume

        /// @brief Increases the volume
        void increaseVolume(); //increase the volume

        /// @brief Sets sound in a loop
        /// @param what sound name
        /// @param path sound path
        void setLoop(std::string what, std::string path); //set the loop

        /// @brief Sets sound in a loop
        /// @param what sound name
        void setLoop(std::string what);

    protected:
    private:
        std::map<std::string, sf::Sound> sounds;
        std::map<std::string, sf::SoundBuffer> buffers;
};

#endif /* !SOUND_HPP_ */
