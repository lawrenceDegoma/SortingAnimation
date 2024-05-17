//
// Created by Lawrence Degoma on 5/2/24.
//

#include "Sorting.h"

void Sorter::quickSort(std::vector<int>& nums, int left, int right, sf::RenderWindow& window) {
    if (left < right) {
        int pivotIndex = partition(nums, left, right, window);

        quickSort(nums, left, pivotIndex - 1, window);
        quickSort(nums, pivotIndex + 1, right, window);
    } else if (left == 0 && right == nums.size() - 1) {
        Renderer::highlightArray(nums, window);
    }
}

int Sorter::partition(std::vector<int>& nums, int left, int right, sf::RenderWindow& window) {
    int pivot = nums[left];
    int i = left + 1;
    int j = right;

    while (i <= j) {
        while (i <= right && nums[i] <= pivot) {
            i++;
        }

        while (j >= left && nums[j] > pivot) {
            j--;
        }

        if (i < j) {
            std::swap(nums[i], nums[j]);
            Renderer::drawArray(nums, window, sf::Color::Red);
            sf::sleep(sf::milliseconds(15));
        }
    }

    std::swap(nums[left], nums[j]);
    Renderer::drawArray(nums, window, sf::Color::Red);
    sf::sleep(sf::milliseconds(15));

    return j;
}



void Sorter::mergeSort(std::vector<int>& arr, int left, int right, sf::RenderWindow& window) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, window);
        mergeSort(arr, mid + 1, right, window);

        merge(arr, left, mid, right, window);

        Renderer::drawArray(arr, window, sf::Color::Red);
        sf::sleep(sf::milliseconds(7));
    }
}

void Sorter::merge(std::vector<int>& arr, int left, int mid, int right, sf::RenderWindow& window) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;

        Renderer::drawArray(arr, window, sf::Color::Red);
        sf::sleep(sf::milliseconds(2));
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;

        Renderer::drawArray(arr, window, sf::Color::Red);
        sf::sleep(sf::milliseconds(5));
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;

        Renderer::drawArray(arr, window, sf::Color::Red);
        sf::sleep(sf::milliseconds(5));
    }
}


void Sorter::bubbleSort(std::vector<int>& nums, sf::RenderWindow& window) {
    int n = nums.size();
    bool swapped;

    for (int i = 0; i < n - 1; ++i) {
        swapped = false;

        for (int j = 0; j < n - i - 1; ++j) {
            if (nums[j] > nums[j + 1]) {
                std::swap(nums[j], nums[j + 1]);
                Renderer::drawArray(nums, window, sf::Color::Red);
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }
    Renderer::drawArray(nums, window, sf::Color::Green);
}
