// Knuth Shuffle Algorithm in C++

#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <algorithm>
#include <numeric>

//param: `upper_bound` is the upper bound of the range (exclusive)
//return: A random number within the range [1, upper_bound]
int GenerateRandomNumber(int upper_bound){
    return (rand() % (upper_bound + 1));
}

std::vector<int> KnuthShuffle(std::vector<int> arr){
    // The way Knuth Shuffle works is simple
    // An index separates the input array into 2. The left side being unshuffled, and the right being shuffled.
    // The algorithm then randomly picks an index from the unshuffled array to the latest shuffled arr and swaps the two.

    for (int current_index = arr.size() - 1; current_index > 0; current_index--){
        int random_index = GenerateRandomNumber(current_index);
        std::swap(arr[current_index], arr[random_index]);
    }

    return arr;
}

int main() {
    srand(time(0));

    // Create an array of 5,000 integers whose values start at 1 and end at 5,000. 
    int ceiling = 5000;
    std::vector<int> sorted_arr(ceiling);
    std::iota(sorted_arr.begin(), sorted_arr.end(), 1);
    std::vector<int> shuffled_arr = KnuthShuffle(sorted_arr);

    return 0;
}