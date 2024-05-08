#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <SFML/Graphics.hpp>


const int ARRAY_SIZE = 100;
const int WINDOW_WIDTH =  800;
const int WINDOW_HEIGHT = 600;

void quickSort(std::vector<int>&, int, int, sf::RenderWindow&);
void drawArray(const std::vector<int>&, sf::RenderWindow&);

int main() {
    std::vector<int> nums(ARRAY_SIZE);
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Quick Sort");

    srand(time(0));
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        nums[i] = rand() % WINDOW_HEIGHT + 1;
    }

    drawArray(nums, window);

    bool clicked = false;
    while (!clicked && window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                clicked = true;
            }
        }
    }

    if (clicked) {
        quickSort(nums, 0, ARRAY_SIZE - 1, window);
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }
    return 0;
}

void quickSort(std::vector<int>& nums, int left, int right, sf::RenderWindow& window){
    if (left < right){
        int pivot = nums[left];
        int i = left;
        int j = right+1;

        while (true){
            do{
                i++;
            }
            while (i <= right && nums[i] < pivot);

            do{
                j--;
            }
            while (j >= left && nums[j] > pivot);

            if (i >= j)
                break;

            std::swap(nums[i], nums[j]);
            drawArray(nums, window);

            sf::sleep(sf::milliseconds(50));
        }

        std::swap(nums[left], nums[j]);
        drawArray(nums, window);

        // Introduce a delay (adjust as needed)
        sf::sleep(sf::milliseconds(50));

        quickSort(nums, left, j-1, window);
        quickSort(nums, j+1, right, window);
    }
}

void drawArray(const std::vector<int>& nums, sf::RenderWindow& window) {
    window.clear();
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        sf::RectangleShape rect(sf::Vector2f(WINDOW_WIDTH / ARRAY_SIZE, nums[i]));
        rect.setPosition((i * (WINDOW_WIDTH / ARRAY_SIZE)), WINDOW_HEIGHT - nums[i]);

        rect.setFillColor(sf::Color::White);
        window.draw(rect);
    }
    window.display();
}