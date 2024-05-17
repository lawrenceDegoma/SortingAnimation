#include <iostream>
#include "Utility.h"
#include "Button.h"
#include "Renderer.h"
#include "Sorting.h"

int main() {
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    std::vector<int> nums(ARRAY_SIZE);
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Sorting Animation");

    srand(time(0));
    Utility::fillArrayWithUnique(nums, ARRAY_SIZE, WINDOW_HEIGHT);
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Failed to load font." << std::endl;
        return EXIT_FAILURE;
    }

    Renderer::drawArray(nums, window, sf::Color::White);

    Button mergeSortButton("Merge Sort", font, sf::Vector2f(50, 50));
    Button quickSortButton("Quick Sort", font, sf::Vector2f(200, 50));
    Button bubbleSortButton("Bubble Sort", font, sf::Vector2f(350, 50));

    mergeSortButton.draw(window);
    quickSortButton.draw(window);
    bubbleSortButton.draw(window);
    window.display();

    bool sorting = false;
    bool quickSortClicked = false;
    bool bubbleSortClicked = false;
    bool initialDisplayShown = false;

    sf::Clock clock;
    const sf::Time updateInterval = sf::milliseconds(500);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::MouseButtonPressed) {
                if (!sorting && mergeSortButton.isMouseOver(window)) {
                    sorting = true;
                    Sorter::mergeSort(nums, 0, ARRAY_SIZE - 1, window);
                    Renderer::highlightArray(nums, window);
                } else if (!sorting && quickSortButton.isMouseOver(window)) {
                    sorting = true;
                    quickSortClicked = true;
                } else if (!sorting && bubbleSortButton.isMouseOver(window)) {
                    sorting = true;
                    bubbleSortClicked = true;
                }
            }
            if (!initialDisplayShown) {
                Renderer::drawArray(nums, window, sf::Color::White);

                mergeSortButton.draw(window);
                quickSortButton.draw(window);
                bubbleSortButton.draw(window);

                window.display();
                initialDisplayShown = true;
            }

            if (!sorting && clock.getElapsedTime() >= updateInterval) {
                Renderer::drawArray(nums, window, sf::Color::White);

                mergeSortButton.draw(window);
                quickSortButton.draw(window);
                bubbleSortButton.draw(window);

                window.display();
                clock.restart();
            }

            if (quickSortClicked) {
                Sorter::quickSort(nums, 0, ARRAY_SIZE - 1, window);
                Renderer::highlightArray(nums, window);
                quickSortClicked = false;
            }
            if (bubbleSortClicked) {
                Sorter::bubbleSort(nums, window);
                Renderer::highlightArray(nums, window);
                bubbleSortClicked = false;
            }
        }
    }

    return EXIT_SUCCESS;
}

