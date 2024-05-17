//
// Created by Lawrence Degoma on 5/16/24.
//

#ifndef SORTANIMATION_BUTTON_H
#define SORTANIMATION_BUTTON_H
#include <SFML/Graphics.hpp>
#include <string>

class Button {
private:
    sf::Vector2f position;
    sf::Text text;
public:
    Button(const std::string& text, const sf::Font& font, const sf::Vector2f& position);
    void draw(sf::RenderWindow& window);
    bool isMouseOver(const sf::RenderWindow& window);
};


#endif //SORTANIMATION_BUTTON_H
