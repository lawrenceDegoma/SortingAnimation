//
// Created by Lawrence Degoma on 5/16/24.
//

#include "Renderer.h"

void Renderer::drawArray(const std::vector<int>& nums, sf::RenderWindow& window, sf::Color color) {
    window.clear();
    float rectWidth = static_cast<float>(WINDOW_WIDTH) / static_cast<float>(ARRAY_SIZE);

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        sf::RectangleShape rect(sf::Vector2f(rectWidth, nums[i]));
        rect.setPosition(i * rectWidth, WINDOW_HEIGHT - nums[i]);
        rect.setFillColor(color);
        window.draw(rect);
    }
    window.display();
}

void Renderer::drawButton(sf::RenderWindow& window, const sf::Font& font, const std::string& text, const sf::Vector2f& position){
    sf::Text buttonText(text, font, 20);
    buttonText.setPosition(position);
    window.draw(buttonText);
}

void Renderer::highlightArray(const std::vector<int>& nums, sf::RenderWindow& window) {
    float rectWidth = static_cast<float>(WINDOW_WIDTH) / static_cast<float>(ARRAY_SIZE);

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        window.clear();

        for (int j = 0; j < ARRAY_SIZE; ++j) {
            sf::RectangleShape rect(sf::Vector2f(rectWidth, nums[j]));
            rect.setPosition(j * rectWidth, WINDOW_HEIGHT - nums[j]);
            rect.setFillColor(j <= i ? sf::Color::Green : sf::Color::White);
            window.draw(rect);
        }

        window.display();
        sf::sleep(sf::milliseconds(2));
    }

    // After highlighting green, reset to white
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        window.clear();

        for (int j = 0; j < ARRAY_SIZE; ++j) {
            sf::RectangleShape rect(sf::Vector2f(rectWidth, nums[j]));
            rect.setPosition(j * rectWidth, WINDOW_HEIGHT - nums[j]);
            rect.setFillColor(sf::Color::White);
            window.draw(rect);
        }

        window.display();
    }
}
