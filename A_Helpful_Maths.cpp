#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

int main() {
    std::string input;
    std::getline(std::cin, input);
    
    std::vector<int> numbers;
    std::stringstream ss(input);
    std::string temp;
    
    while (std::getline(ss, temp, '+')) {
        numbers.push_back(std::stoi(temp));
    }
    
    std::sort(numbers.begin(), numbers.end());
    
    for (size_t i = 0; i < numbers.size(); ++i) {
        if (i > 0) std::cout << "+";
        std::cout << numbers[i];
    }
    
    std::cout << std::endl;
    return 0;
}
