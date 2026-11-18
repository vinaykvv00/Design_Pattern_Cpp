#include <iostream>
#include <iterator>
#include <unordered_map>
#include <vector>

int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // traditional iterator loop
    //     for (int i = 0; i < vec.size(); ++i)
    //     {
    //         std::cout << vec[i] << " ";
    //     }
    //     std::cout << std::endl;

    //     for (auto it = vec.begin(); it != vec.end(); ++it)
    //     {
    //         std::cout << *it << " ";
    //     }
    //     std::cout << std::endl;

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

    // further show intent to not to modify the vector while iterating
    std::cout << "Using const_iterator:" << std::endl;
    for (std::vector<int>::const_iterator it = vec.cbegin(); it != vec.cend(); ++it)
    {
        std::cout << *it << " , ";
        //(*it)++; illegal, cannot modify through const_iterator
    }
    std::cout << std::endl;

    // reverse iterator
    std::cout << "Using reverse_iterator:" << std::endl;
    for (std::vector<int>::reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it)
    {
        std::cout << *it << " , ";
    }
    std::cout << std::endl;

    // controlling advance iterator
    std::cout << "Controlling advance iterator:" << std::endl;
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
    {
        std::cout << *it << " , ";
        if (it != vec.end())
        {
            ++it; // advance iterator by one more step
        }
    }
    std::cout << std::endl;

    // range based loops
    std::cout << "Using range-based for loop:" << std::endl;
    for (const int &num : vec)
    {
        std::cout << num << " , ";
    }
    std::cout << std::endl;

    // unmap ds
    std::cout << "unordered_map iterator examples" << std::endl;
    std::unordered_map<int, std::string> umap = {{1, "one"}, {2, "two"}, {3, "three"}};
    for (std::unordered_map<int, std::string>::iterator it = umap.begin(); it != umap.end(); ++it)
    {
        std::cout << it->first << " : " << it->second << " , ";
    }
    std::cout << std::endl;

    return 0;
}