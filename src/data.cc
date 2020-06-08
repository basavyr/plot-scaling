#include "data.hh"

inline void newline()
{
    std::cout << '\n';
}

void App()
{
    auto now = std::chrono::system_clock::now();
    auto date = std::chrono::system_clock::to_time_t(now);
    auto date_as_string = ctime(&date);
    newline();
    std::cout << std::string(date_as_string);
    newline();
}

std::ifstream input("../data/data.in");

template <typename T>
void showIT(T &&arg)
{
    std::cout << arg;
    newline();
}

template <typename T>
void printArray(std::vector<T> &v)
{
    for (auto &&n : v)
    {
        showIT(n);
    }
}

int main()
{
    // App();

    int n_data_caches;
    input >> n_data_caches;

    auto x = std::make_unique<data::data>();

    std::vector<int> integers_from_string;
    for (auto id = n_data_caches; id > 0; id--)
    {
        input >> x->energyScale >> x->squareScale;
        // std::cout << x->energyScale << " " << x->squareScale;
        // newline();
        std::string discarded_line;
        std::getline(input, discarded_line);
        std::string current_line;
        std::getline(input, current_line);
        // std::cout << line1;
        std::string number_catcher;
        std::string space = " ";
        for (auto id = 0; id < current_line.size(); ++id)
        {
            auto yy = current_line.at(id);
            std::string c_yy{yy};
            number_catcher.append(c_yy);
            if (c_yy == space)
            {
                integers_from_string.emplace_back(std::stoi(number_catcher));
                // std::cout << number_catcher;
                // newline();
                number_catcher.clear();
            }
        }
    }
    printArray<int>(integers_from_string);
}