#include <iostream>
#include <vector>
#include <initializer_list>

static std::vector<std::vector<int>> v;

int main()
{
    std::cout << v.size() << "\n";
    auto x = {1, 2, 3};
    auto x1 = {1, 2, 3};
    v.emplace_back(x);
    v.emplace_back(x1);
    std::cout << v.size() << "\n";
}