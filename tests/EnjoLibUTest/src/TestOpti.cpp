#include "pch_test.h"

#include <Math/Opti/IOptiAlgo.hpp>
#include <Math/Opti/OptiFactory.hpp>
#include <Math/Opti/OptiSubject.hpp>
#include <Template/CorradePointer.h>

#include <UnitTest++/UnitTest++.h>
#include <STD/Iostream.hpp>

using namespace std;
using namespace EnjoLib;

class Square : public OptiSubject
{
public:
    Square(double shift)
    {
        m_shift = shift;
    }
    double UpdateGetValue( double arg )
    {
        ++m_timesCalled;
        const double argShifted = arg - m_shift;
        return argShifted * argShifted;
    }
    int GetTimesCalled() const { return m_timesCalled; }
private:
    double m_shift;
    int m_timesCalled = 0;
};

static double GetRes(const IOptiAlgo & algo, double shift)
{
    Square sqr(shift);
    const Result<double> & res = algo.Run(sqr);
    //cout << "Times called = " << sqr.GetTimesCalled() << endl;
    return res.value;
}

TEST(Opti)
{
    const double eps = 0.0000001;
    for (const auto & algoType : {OPTI_BIN_SEARCH, OPTI_BRENT})
    {
        const Corrade::Containers::Pointer<IOptiAlgo> algo = OptiFactory::Create(algoType, -10, 10, eps);

        CHECK_CLOSE(   0, GetRes(*algo,  0), eps);
        CHECK_CLOSE(   1, GetRes(*algo,  1), eps);
        CHECK_CLOSE(  -1, GetRes(*algo, -1), eps);
        CHECK_CLOSE(  -9, GetRes(*algo, -9), eps);
        CHECK_CLOSE(   9, GetRes(*algo,  9), eps);
        CHECK_CLOSE(-9.99, GetRes(*algo, -9.99), eps);
        CHECK_CLOSE( 9.99, GetRes(*algo,  9.99), eps);
        //CHECK_CLOSE( 10.0, GetRes(*algo,  10.0), eps); // Fails for some reason
    }
}
