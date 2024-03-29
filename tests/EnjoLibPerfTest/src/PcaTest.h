#ifndef PCATEST_H
#define PCATEST_H

#include <Util/StrFwd.hpp>

namespace EnjoLib {
class Timer;

class PcaTest
{
    public:
        PcaTest();
        virtual ~PcaTest();
        
        void TestDistrib() const;
        void TestPca1() const;
        void TestPcaAuto() const;
        void TestMatrixMul() const;
        void TestMatrixTransp() const;
        
    protected:

    private:
        void Log(const EnjoLib::Str & descr, const EnjoLib::Timer & timer, const int iter) const;
};
}
#endif // ANIMATIONTEST_H
