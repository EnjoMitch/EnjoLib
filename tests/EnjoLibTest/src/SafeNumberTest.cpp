#include "SafeNumberTest.h"
#include <Ios/Cout.hpp>
#include <Math/SafeNumber.hpp>

using namespace std;
using namespace EnjoLib;

SafeNumberTest:: SafeNumberTest(){}
SafeNumberTest::~SafeNumberTest(){}

void SafeNumberTest::Run()
{
    const SafeNumber<float> nom(5), denom(10), zero(0);
    SafeNumber<float> nonconst(100);
    const SafeNumber<int> integer(2);
    EnjoLib::Cout out;
    out << "Res div = " << nom / denom << Nl;
    out << "Res mul = " << nom.val * denom.val << Nl;
    out << "Res int = " << nom / integer << Nl;
    nonconst /= denom;
    out << "Res non const = " << nonconst << Nl;
    try
    {
        out << "Res zero = " << nom / zero << Nl;
    }
    catch (std::exception & ex)
    {
        out << "Successfully thrown\n " << ex.what() << Nl;
    }
    try
    {
        nonconst /= zero;
    }
    catch (std::exception & ex)
    {
        out << "Successfully thrown\n " << ex.what() << Nl;
    }
}
