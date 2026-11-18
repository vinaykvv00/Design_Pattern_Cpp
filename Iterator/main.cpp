#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>

int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // traditional iterator loop
    for (int i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;

    for (auto it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    for (int num : vec)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Iterators
    //*it means to read a value
    //  ++it means to move the iterator to the next element
    //  it = vec.begin() initializes the iterator to the first element of the vector
    //  it != vec.end() checks if the iterator has reached the end of the vector

    std::cout << "Using iterator comments:" << std::endl;
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << " , ";
    }
    std::cout << std::endl;

    return 0;
}