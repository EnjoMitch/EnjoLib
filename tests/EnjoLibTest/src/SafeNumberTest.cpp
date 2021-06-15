#include "SafeNumberTest.h"
#include <STD/Iostream.hpp>
#include <Math/SafeNumber.hpp>

using namespace std;
using namespace EnjoLib;

SafeNumberTest::SafeNumberTest()
{
}

SafeNumberTest::~SafeNumberTest()
{
    //dtor
}

void SafeNumberTest::Run()
{
    const SafeNumber<float> nom(5), denom(10), zero(0);
    SafeNumber<float> nonconst(100);
    const SafeNumber<int> integer(2);
    cout << "Res div = " << nom / denom << endl;
    cout << "Res mul = " << nom.val * denom.val << endl;
    cout << "Res int = " << nom / integer << endl;
    nonconst /= denom;
    cout << "Res non const = " << nonconst << endl;
    try
    {
        cout << "Res zero = " << nom / zero << endl;
    }
    catch (std::exception & ex)
    {
        cout << "Successfully thrown\n " << ex.what() << endl;
    }
    try
    {
        nonconst /= zero;
    }
    catch (std::exception & ex)
    {
        cout << "Successfully thrown\n " << ex.what() << endl;
    }
}
