#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
//#include "Application.h"
#include <SFML/Graphics.hpp>

//void print(int [], int);

const int ARRAY_SIZE = 100;
const int WINDOW_WIDTH =  800;
const int WINDOW_HEIGHT = 600;

void quickSort(std::vector<int>&, int, int, sf::RenderWindow&);

int main() {
    std::vector<int> nums(ARRAY_SIZE);
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Quick Sort");

    srand(time(0));
    for (int i=0; i< ARRAY_SIZE; ++i){
        nums[i] = rand() % WINDOW_HEIGHT + 1;
    }

    quickSort(nums, 0, ARRAY_SIZE -1, window);

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
    }
//    Application app(ARRAY_SIZE, WINDOW_WIDTH, WINDOW_HEIGHT, "Quick Sort");
//    app.run();
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
            while (nums[i] < pivot && i <= right);

            do{
                j--;
            }
            while (nums[j] > pivot);

            if (i >= j)
                break;

            std::swap(nums[i], nums[j]);


            window.clear(sf::Color::White);
            for (int k=0; k<ARRAY_SIZE; ++k){
                sf::RectangleShape rect(sf::Vector2f(WINDOW_WIDTH / ARRAY_SIZE, nums[k]));
                rect.setPosition(k * (WINDOW_WIDTH / ARRAY_SIZE), (WINDOW_HEIGHT - nums[k]));

                rect.setFillColor(sf::Color::Magenta);
                rect.setOutlineColor(sf::Color::Black);
                rect.setOutlineThickness(1);
                window.draw(rect);
//                sf::sleep(sf::microseconds(10000));
            }
            window.display();
        }

        std::swap(nums[left], nums[j]);

        quickSort(nums, left, j-1, window);
        quickSort(nums, j+1, right, window);
    }
}
