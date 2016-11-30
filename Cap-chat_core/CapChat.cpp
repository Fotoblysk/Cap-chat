//
// Created by fotoblysk on 27.11.16.
//

#include <iostream>
#include "CapChat.h"
#include "SFML/Graphics.hpp"
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>



CapChat::CapChat() {
    std::cout << "hello Cap-chat" << std::endl;
    sf::RenderWindow window;



    window.getDefaultView();
    window.create(sf::VideoMode(800, 600), "SFML window");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Request for closing the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.draw(sf::CircleShape(220));
        sf::Music music;
        if (!music.openFromFile("music.ogg"))

        music.play();

        window.display();
        window.clear();
    }
}
