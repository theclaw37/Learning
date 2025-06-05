#include <iostream>
#include "Problems/problem1182.cpp"

int main() {
    // [[maybe_unused]] auto res = strStr("mississippi", "issip");
    [[ maybe_unused ]] auto res = problem1182::shortestDistanceColor(
        //{ 1, 1, 2, 1, 3, 2, 2, 3, 3 },
        { 2, 3, 2, 2, 3, 2, 1, 2, 2, 1, 3, 2, 2,  3,  3,  1,  2,  3,  2,  2,  3,  3,  2 },
        //6, 6, 6, 6, 6, 6, 6, 6, 9, 9, 9, 9, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15, 15
        //0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22
        { {1,3}, {2,2}, {6,1}, {10, 2}, {20, 1} });
    return 0;
}