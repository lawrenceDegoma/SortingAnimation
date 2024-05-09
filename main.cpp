#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <unordered_set>
#include <cstdlib>
#include <SFML/Graphics.hpp>

const int ARRAY_SIZE = 600;
const int WINDOW_WIDTH =  800;
const int WINDOW_HEIGHT = 600;

void quickSort(std::vector<int>&, int, int, sf::RenderWindow&);
void drawArray(const std::vector<int>&, sf::RenderWindow&);
void mergeSort(std::vector<int>&, int, int, sf::RenderWindow&);
void merge(std::vector<int>&, int, int, int, sf::RenderWindow&);
void drawButton(sf::RenderWindow&, const sf::Font&, const std::string&, const sf::Vector2f&);
bool isMouseOverButton(const sf::RenderWindow&, const sf::Vector2f&);
void fillArrayWithUnique(std::vector<int>&, int, int);
void bubbleSort(std::vector<int>&, sf::RenderWindow&);

int main() {
    sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
    std::vector<int> nums(ARRAY_SIZE);
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Sorting Visualization");

    srand(time(0));
    fillArrayWithUnique(nums, ARRAY_SIZE, WINDOW_HEIGHT);

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Failed to load font." << std::endl;
        return EXIT_FAILURE;
    }


    window.clear(sf::Color::Black);
    drawArray(nums, window);
    drawButton(window, font, "Merge Sort", sf::Vector2f(50, 50));
    drawButton(window, font, "Quick Sort", sf::Vector2f(200, 50));
    drawButton(window, font, "Bubble Sort", sf::Vector2f(350, 50));
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
                if (!sorting && isMouseOverButton(window, sf::Vector2f(50, 50))) {
                    sorting = true;
                    mergeSort(nums, 0, ARRAY_SIZE - 1, window);
                } else if (!sorting && isMouseOverButton(window, sf::Vector2f(200, 50))) {
                    sorting = true;
                    quickSortClicked = true;
                } else if (!sorting && isMouseOverButton(window, sf::Vector2f(350, 50))) {
                    sorting = true;
                    bubbleSortClicked = true;
                }
            }

            if (!initialDisplayShown) {
                window.clear(sf::Color::Black);
                drawArray(nums, window);
                drawButton(window, font, "Merge Sort", sf::Vector2f(50, 50));
                drawButton(window, font, "Quick Sort", sf::Vector2f(200, 50));
                drawButton(window, font, "Bubble Sort", sf::Vector2f(350, 50));
                window.display();
                initialDisplayShown = true;
            }

            if (!sorting && clock.getElapsedTime() >= updateInterval) {
                window.clear(sf::Color::Black);
                drawArray(nums, window);
                drawButton(window, font, "Merge Sort", sf::Vector2f(50, 50));
                drawButton(window, font, "Quick Sort", sf::Vector2f(200, 50));
                drawButton(window, font, "Bubble Sort", sf::Vector2f(350, 50));
                window.display();
                clock.restart();
            }

            if (quickSortClicked) {
                quickSort(nums, 0, ARRAY_SIZE - 1, window);
                quickSortClicked = false;
            }
            if (bubbleSortClicked) {
                bubbleSort(nums, window);
                bubbleSortClicked = false;
            }
        }
    }

    return EXIT_SUCCESS;
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

            sf::sleep(sf::milliseconds(15));
        }

        std::swap(nums[left], nums[j]);
        drawArray(nums, window);

        sf::sleep(sf::milliseconds(15));

        quickSort(nums, left, j-1, window);
        quickSort(nums, j+1, right, window);
    }
}

void mergeSort(std::vector<int>& arr, int left, int right, sf::RenderWindow& window) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, window);
        mergeSort(arr, mid + 1, right, window);
        merge(arr, left, mid, right, window);
        drawArray(arr, window);
        sf::sleep(sf::milliseconds(15));
    }
}

void merge(std::vector<int>& arr, int left, int mid, int right, sf::RenderWindow& window) {
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

        drawArray(arr, window);
        sf::sleep(sf::milliseconds(5));
    }

    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;

        drawArray(arr, window);
        sf::sleep(sf::milliseconds(5));
    }

    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;

        drawArray(arr, window);
        sf::sleep(sf::milliseconds(5));
    }
}

void drawButton(sf::RenderWindow& window, const sf::Font& font, const std::string& text, const sf::Vector2f& position) {
    sf::Text buttonText(text, font, 20);
    buttonText.setPosition(position);
    window.draw(buttonText);
}

bool isMouseOverButton(const sf::RenderWindow& window, const sf::Vector2f& position) {
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    return mousePosition.x >= position.x && mousePosition.x <= position.x + 100 &&
           mousePosition.y >= position.y && mousePosition.y <= position.y + 30;
}

void drawArray(const std::vector<int>& nums, sf::RenderWindow& window) {
    window.clear();

    float rectWidth = static_cast<float>(WINDOW_WIDTH) / static_cast<float>(ARRAY_SIZE);

    for (int i = 0; i < ARRAY_SIZE; ++i) {
        sf::RectangleShape rect(sf::Vector2f(rectWidth, nums[i]));
        rect.setPosition(i * rectWidth, WINDOW_HEIGHT - nums[i]);
        rect.setFillColor(sf::Color::White);
        window.draw(rect);
    }
    window.display();
}

void fillArrayWithUnique(std::vector<int>& nums, int size, int maxValue) {
    nums.clear();
    std::unordered_set<int> uniqueNumbers;

    while (nums.size() < size) {
        int num = rand() % maxValue + 1;
        if (uniqueNumbers.find(num) == uniqueNumbers.end()) {
            nums.push_back(num);
            uniqueNumbers.insert(num);
        }
    }
}

void bubbleSort(std::vector<int>& nums, sf::RenderWindow& window) {
    int n = nums.size();
    bool swapped;
    for (int i = 0; i < n-1; ++i) {
        swapped = false;
        for (int j = 0; j < n-i-1; ++j) {
            if (nums[j] > nums[j+1]) {
                std::swap(nums[j], nums[j+1]);
                drawArray(nums, window);
                sf::sleep(sf::milliseconds(0.005));
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}