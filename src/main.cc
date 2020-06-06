#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <chrono>

inline void newline() { std::cout << '\n'; }

void App()
{
    auto now = std::chrono::system_clock::now();
    auto date = std::chrono::system_clock::to_time_t(now);
    auto Date = ctime(&date);
    std::cout << Date;
    newline();
}

std::vector<double> getValuesFromPlot(std::vector<int> &squares, double energyScale, int squareScale)
{
    std::vector<double> extractedValues;
    for (int id = 0; id < squares.size(); ++id)
    {
        auto currentSquareNumber = squares.at(id);
        auto currentExtractedValue = static_cast<double>(currentSquareNumber * energyScale / squareScale);
        extractedValues.emplace_back(currentExtractedValue);
    }
    return extractedValues;
}

template <typename T>
double avg(std::vector<T> &v)
{
    double sum = 0.0;
    for (auto id = 0; id < v.size(); ++id)
    {
        sum += v.at(id);
    }
    return static_cast<double>(sum / v.size());
}

template <typename T>
void showArray(const std::vector<T> &v)
{
    for (auto &&n : v)
        std::cout << n << " ";
    newline();
}

void computeEnergies(std::vector<int> &source, double enScale, int sqScale)
{
    auto x = getValuesFromPlot(source, enScale, sqScale);
    std::cout << avg<double>(x);
    newline();
}

int main()
{
    App();
    //sensharma
    const double Sensh_enScale = 100.0;
    const int Sensh_sqScale = 6;
    const double Tanab_enScale = 100.0;
    const int Tanab_sqScale = 15;
    std::vector<int> Sensh_TPSM_yrast = {1, 3, 1, 3, 1, 8, 1};
    std::vector<int> Sensh_TPSM_tw1 = {5, 11, 10, 8, 3};
    std::vector<int> Sensh_TPSM_tw2 = {4, 1, 3, 6};
    std::cout << "Sensharma 2019";
    newline();
    computeEnergies(Sensh_TPSM_yrast, Sensh_enScale, Sensh_sqScale);
    computeEnergies(Sensh_TPSM_tw1, Sensh_enScale, Sensh_sqScale);
    computeEnergies(Sensh_TPSM_tw2, Sensh_enScale, Sensh_sqScale);
    std::vector<int> Sensh_QTR_yrast = {1, 3, 3, 3, 5, 9, 1};
    std::vector<int> Sensh_QTR_tw1 = {4, 3, 5, 4, 2};
    std::vector<int> Sensh_QTR_tw2 = {6, 1, 10, 12};
    computeEnergies(Sensh_QTR_yrast, Sensh_enScale, Sensh_sqScale);
    computeEnergies(Sensh_QTR_tw1, Sensh_enScale, Sensh_sqScale);
    computeEnergies(Sensh_QTR_tw2, Sensh_enScale, Sensh_sqScale);
    std::vector<int> Tanab_bands24 = {5, 5, 10, 15, 15, 5};
    std::vector<int> Tanab_band1 = {5, 10, 3, 10, 5, 5, 45};
    std::cout << "Tanabe 2017";
    newline();
    computeEnergies(Tanab_band1, Tanab_enScale, Tanab_sqScale);
    computeEnergies(Tanab_bands24, Tanab_enScale, Tanab_sqScale);
    //MATTA
    const double Matta_enScale_411 = 50.0;
    const int Matta_sqScale_411 = 9;
    const double Matta_enScale_412 = 100.0;
    const int Matta_sqScale_412 = 15;
    std::vector<int> Matta_fig411 = {18, 13, 38, 10};
    std::vector<int> Matta_fig412_yrast = {1, 5, 5, 5, 10, 21};
    std::vector<int> Matta_fig412_wobbling = {6, 5, 11, 10, 5};
    std::cout << "Matta 2015";
    newline();
    computeEnergies(Matta_fig411, Matta_enScale_411, Matta_sqScale_411);
    computeEnergies(Matta_fig412_yrast, Matta_enScale_412, Matta_sqScale_412);
    computeEnergies(Matta_fig412_wobbling, Matta_enScale_412, Matta_sqScale_412);
    //CHEN
    const int Chen_sqScale_4a = 12;
    const int Chen_sqScale_4b = 16;
    const double Chen_enScale_4a = 100.0;
    const double Chen_enScale_4b = 1000.0;
    const int Chen_sqScale_6en = 14;
    const int Chen_sqScale_6freq = 11;
    const double Chen_enScale_6en = 1000.0;
    const double Chen_enScale_6Freq = 100.0;
    std::vector<int> Chen_fig4_a = {1, 2, 4, 5, 7, 8, 8, 7};
    std::vector<int> Chen_fig4_b = {4, 4, 3, 1, 1, 1, 1, 1, 2};
    std::vector<int> Chen_fig6_yrast = {5, 5, 3, 2, 1, 1, 1, 1};
    std::vector<int> Chen_fig6_wobbling = {8, 5, 3, 1, 1, 1, 1};
    std::vector<int> Chen_fig6_freq = {25, 12, 3, 3, 4, 5, 10};
    std::cout << "Chen 2015";
    newline();
    computeEnergies(Chen_fig4_a, Chen_enScale_4a, Chen_sqScale_4a);
    computeEnergies(Chen_fig4_b, Chen_enScale_4b, Chen_sqScale_4b);
    computeEnergies(Chen_fig6_yrast, Chen_enScale_6en, Chen_sqScale_6en);
    computeEnergies(Chen_fig6_wobbling, Chen_enScale_6en, Chen_sqScale_6en);
    computeEnergies(Chen_fig6_freq, Chen_enScale_6Freq, Chen_sqScale_6freq);
}