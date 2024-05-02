////
//// Created by Lawrence Degoma on 5/2/24.
////
//
//#include "Sorting.h"
//
//void quickSort(std::vector<int>& nums, int left, int right, sf::RenderWindow& window){
//    if (left < right){
//        int pivot = nums[left];
//        int i = left;
//        int j = right+1;
//
//        while (true){
//            do{
//                i++;
//            }
//            while (nums[i] < pivot && i <= right);
//
//            do{
//                j--;
//            }
//            while (nums[j] > pivot);
//
//            if (i >= j)
//                break;
//
//            std::swap(nums[i], nums[j]);
//
//            window.clear(sf::Color::White);
//            for (int k=0; k<ARRAY_SIZE; ++k){
//                sf::RectangleShape rect(sf::Vector2f(WINDOW_WIDTH / ARRAY_SIZE, nums[k]));
//                rect.setPosition(k * (WINDOW_WIDTH / ARRAY_SIZE), (WINDOW_HEIGHT - nums[k]));
//
//                rect.setFillColor(sf::Color::Magenta);
//                rect.setOutlineColor(sf::Color::Black);
//                rect.setOutlineThickness(1);
//                window.draw(rect);
//            }
//            window.display();
//        }
//
//        std::swap(nums[left], nums[j]);
//
//        quickSort(nums, left, j-1, window);
//        quickSort(nums, j+1, right, window);
//    }
//}