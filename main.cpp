#include <iostream>
#include "Utility.h"
#include "Button.h"
#include "Renderer.h"
#include "Sorting.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Sorting Animation");

    std::vector<int> nums(ARRAY_SIZE);
    srand(static_cast<unsigned>(time(0)));
    Utility::fillArrayWithUnique(nums, ARRAY_SIZE, WINDOW_HEIGHT);

    sf::Font font;
    bool fontLoaded = false;
    
    // Try multiple font locations
    std::vector<std::string> fontPaths = {
        "arial.ttf",           // Current directory (build folder)
        "../arial.ttf",        // Parent directory (source folder)
        "/System/Library/Fonts/Arial.ttf",  // macOS system font
        "/System/Library/Fonts/Helvetica.ttc"  // macOS fallback
    };
    
    for (const auto& path : fontPaths) {
        if (font.loadFromFile(path)) {
            fontLoaded = true;
            break;
        }
    }
    
    if (!fontLoaded) {
        std::cerr << "Failed to load font from any location." << std::endl;
        return EXIT_FAILURE;
    }

    // Buttons
    Button mergeSortButton("Merge Sort", font, sf::Vector2f(50, 50));
    Button quickSortButton("Quick Sort", font, sf::Vector2f(200, 50));
    Button bubbleSortButton("Bubble Sort", font, sf::Vector2f(350, 50));

    bool sorting = false;
    bool needsRedraw = true;  // Track when we need to redraw
    
    // Initial draw
    window.clear();
    Renderer::drawArray(nums, window, sf::Color::White);
    mergeSortButton.draw(window);
    quickSortButton.draw(window);
    bubbleSortButton.draw(window);
    window.display();
    needsRedraw = false;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            else if (event.type == sf::Event::MouseButtonPressed && !sorting) {
                // Merge Sort
                if (mergeSortButton.isMouseOver(window)) {
                    sorting = true;
                    Sorter::mergeSort(nums, 0, ARRAY_SIZE - 1, window);
                    Renderer::highlightArray(nums, window);
                    sorting = false;
                    Utility::fillArrayWithUnique(nums, ARRAY_SIZE, WINDOW_HEIGHT);
                    needsRedraw = true;  // Need to redraw after sorting
                }
                // Quick Sort
                else if (quickSortButton.isMouseOver(window)) {
                    sorting = true;
                    Sorter::quickSort(nums, 0, ARRAY_SIZE - 1, window);
                    Renderer::highlightArray(nums, window);
                    sorting = false;
                    Utility::fillArrayWithUnique(nums, ARRAY_SIZE, WINDOW_HEIGHT);
                    needsRedraw = true;  // Need to redraw after sorting
                }
                // Bubble Sort
                else if (bubbleSortButton.isMouseOver(window)) {
                    sorting = true;
                    Sorter::bubbleSort(nums, window);
                    Renderer::highlightArray(nums, window);
                    sorting = false;
                    Utility::fillArrayWithUnique(nums, ARRAY_SIZE, WINDOW_HEIGHT);
                    needsRedraw = true;  // Need to redraw after sorting
                }
            }
        }

        // Only redraw when needed and not sorting
        if (!sorting && needsRedraw) {
            window.clear();
            Renderer::drawArray(nums, window, sf::Color::White);
            mergeSortButton.draw(window);
            quickSortButton.draw(window);
            bubbleSortButton.draw(window);
            window.display();
            needsRedraw = false;  // Reset flag after drawing
        }
    }

    return EXIT_SUCCESS;
}
