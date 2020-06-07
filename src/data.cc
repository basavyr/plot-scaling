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

int main()
{
    // App();

    int n_data_caches;
    input >> n_data_caches;

    auto x = std::make_unique<data::data>();

    for (auto id = n_data_caches; id > 0; id--)
    {
        input >> x->energyScale >> x->squareScale;
        // std::cout << x->energyScale << " " << x->squareScale;
        // newline();
        std::string line0;
        std::getline(input, line0);
        std::string line1;
        std::getline(input, line1);
        // std::cout << line1;
        std::string number_catcher;
        for (auto xid = line1.begin(); xid < line1.end(); ++xid)
        {
            // number_catcher.append();
            number_catcher.append(xid.base());
            std::cout<<xid.base();
            // if (std::strncmp(xid.base(), "1", 1))
            // {
            //     std::cout << "space";
            //     newline();
            // }
        }
    }
}