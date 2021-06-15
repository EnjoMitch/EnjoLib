#include "DataSets.hpp"
#include <Util/VecD.hpp>

#include <initializer_list>

using namespace std;
using namespace EnjoLib;

DataSets::DataSets(){}
DataSets::~DataSets(){}

Matrix DataSets::GetIris()
{
    Matrix ret;
    ret.push_back({5.1, 3.5, 1.4, 0.2});
    ret.push_back({4.9, 3.0, 1.4, 0.2});
    ret.push_back({4.7, 3.2, 1.3, 0.2});
    ret.push_back({4.6, 3.1, 1.5, 0.2});
    ret.push_back({5.0, 3.6, 1.4, 0.2});
    ret.push_back({5.4, 3.9, 1.7, 0.4});
    ret.push_back({4.6, 3.4, 1.4, 0.3});
    ret.push_back({5.0, 3.4, 1.5, 0.2});
    ret.push_back({4.4, 2.9, 1.4, 0.2});
    ret.push_back({4.9, 3.1, 1.5, 0.1});
    return ret;
}

Matrix DataSets::GetPDF()
{
    Matrix data;
    data.push_back({2.5, 2.4});
    data.push_back({0.5, 0.7});
    data.push_back({2.2, 2.9});
    data.push_back({1.9, 2.2});
    data.push_back({3.1, 3.0});
    data.push_back({2.3, 2.7});
    data.push_back({2  , 1.6});
    data.push_back({1  , 1.1});
    data.push_back({1.5, 1.6});
    data.push_back({1.1, 0.9});
    return data;
}

Matrix DataSets::GetPDFTransform1()
{
    Matrix ret;

    ret.push_back({-.827970186});
    ret.push_back({1.77758033});
    ret.push_back({-.992197494});
    ret.push_back({-.274210416});
    ret.push_back({-1.67580142});
    ret.push_back({-.912949103});
    ret.push_back({.0991094375});
    ret.push_back({1.14457216});
    ret.push_back({.438046137});
    ret.push_back({1.22382056});

    return ret;
}

Matrix DataSets::GetPDFTransform2()
{
    Matrix ret;

    ret.push_back({-.827970186, -.175115307});
    ret.push_back({1.77758033, .142857227});
    ret.push_back({-.992197494, .384374989});
    ret.push_back({-.274210416, .130417207});
    ret.push_back({-1.67580142, -.209498461});
    ret.push_back({-.912949103, .175282444});
    ret.push_back({.0991094375, -.349824698});
    ret.push_back({1.14457216, .0464172582});
    ret.push_back({.438046137, .0177646297});
    ret.push_back({1.22382056, -.162675287});


    return ret;
}











