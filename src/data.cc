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
        std::cout << n << " ";
    }
    newline();
}

int main()
{
    // App();

    int n_data_caches;
    input >> n_data_caches;

    //! read from a file N times in a certain way
    // double x, y;
    // for (auto id = 0; id < n_data_caches; ++id)
    // {
    //     input >> x >> y;
    //     std::string line;
    //     std::string line1;
    //     std::getline(input, line);
    //     std::getline(input, line1);
    //     std::cout<<line1;
    //     // std::cout << x << " " << y;
    //     newline();
    // }

    auto x = std::make_unique<data::data>();

    // std::vector<int> integers_from_string;
    int row_id=0;
    for (auto id = n_data_caches; id > 0; id--)
    {
        input >> x->energyScale >> x->squareScale;
        std::string discarded_line;
        std::string current_line;
        std::getline(input, discarded_line);
        std::getline(input, current_line);
        std::string number_catcher;
        std::string space = " ";
        std::string endline = "\n";
        std::vector<int> cached_numbers;
        for (auto id = 0; id < current_line.size(); ++id)
        {
            auto yy = current_line.at(id);
            std::string c_yy{yy};
            number_catcher.append(c_yy);
            if (c_yy == space)
            {
                cached_numbers.emplace_back(std::stoi(number_catcher));
                number_catcher.clear();
            }
            if (id == current_line.size() - 1)
            {
                cached_numbers.emplace_back(std::stoi(number_catcher));
                number_catcher.clear();
            }
        }
        x->plotScales.emplace_back(cached_numbers);
        printArray<int>(x->plotScales.at(row_id));
        row_id++;
    }
}