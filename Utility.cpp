//
// Created by Lawrence Degoma on 5/16/24.
//

#include "Utility.h"

void Utility::fillArrayWithUnique(std::vector<int>& nums, int size, int maxValue){
    nums.clear();
    std::unordered_set<int> uniqueNumbers;

    while (nums.size() < size) {
        int num = rand() % maxValue + 1;
        if (uniqueNumbers.find(num) == uniqueNumbers.end()){
            nums.push_back(num);
            uniqueNumbers.insert(num);
        }
    }
}
