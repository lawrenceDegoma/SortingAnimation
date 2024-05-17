//
// Created by Lawrence Degoma on 5/16/24.
//

#ifndef SORTANIMATION_RENDERER_H
#define SORTANIMATION_RENDERER_H

#include <vector>
#include <SFML/Graphics.hpp>
const int ARRAY_SIZE = 600;
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

class Renderer {
public:
    static void drawArray(const std::vector<int>& nums, sf::RenderWindow& window, sf::Color color);
    static void drawButton(sf::RenderWindow& window, const sf::Font& font, const std::string& text, const sf::Vector2f& position);
    static void highlightArray(const std::vector<int>& nums, sf::RenderWindow& window);
};


#endif //SORTANIMATION_RENDERER_H
