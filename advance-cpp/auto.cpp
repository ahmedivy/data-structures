#include <iostream>
#include <vector>

int main() {
    // Initialize a vector of integers with some values
    std::vector<int> nums = {1, 2, 3, 4, 5};

    // Use the auto keyword to declare a variable and infer its type from the initializer
    auto it = nums.begin();

    // Use the variable to access the first element of the vector
    std::cout << "First element of vector: " << *it << std::endl;

    return 0;
}
