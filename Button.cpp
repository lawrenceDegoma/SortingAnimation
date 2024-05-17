//
// Created by Lawrence Degoma on 5/16/24.
//

#include "Button.h"

Button::Button(const std::string& text, const sf::Font& font, const sf::Vector2f& position) : position(position), text(text, font, 20){
    this->text.setPosition(position);
}

void Button::draw(sf::RenderWindow& window){
    window.draw(text);
}

bool Button::isMouseOver(const sf::RenderWindow& window){
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    return mousePosition.x >= position.x && mousePosition.x <= position.x + 100 && mousePosition.y >= position.y && mousePosition.y <= position.y + 30;
}
