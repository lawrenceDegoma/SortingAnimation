//
// Created by Lawrence Degoma on 5/2/24.
//

#ifndef SORTANIMATION_SORTING_H
#define SORTANIMATION_SORTING_H
#include <algorithm>
#include <vector>
#include <SFML/System/Sleep.hpp>
#include <SFML/Graphics.hpp>
#include "Renderer.h"

class Sorter{
private:
    static void merge(std::vector<int>& arr, int left, int mid, int right, sf::RenderWindow& window);
    static int partition(std::vector<int>& nums, int left, int right, sf::RenderWindow& window);
public:
    static void quickSort(std::vector<int>& nums, int left, int right, sf::RenderWindow& window);
    static void mergeSort(std::vector<int>& arr, int left, int right, sf::RenderWindow& window);
    static void bubbleSort(std::vector<int>&, sf::RenderWindow&);
};

#endif //SORTANIMATION_SORTING_H
