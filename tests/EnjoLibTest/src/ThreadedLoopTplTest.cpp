#include "ThreadedLoopTplTest.hpp"

#include <Util/VecD.hpp>
#include <Util/CoutBuf.hpp>
#include <Ios/Osstream.hpp>
#include <Ios/Isstream.hpp>
#include <Math/GeneralMath.hpp>
#include <Template/LoopThreadedTpl.hpp>


using namespace std;
using namespace EnjoLib;

static double Conv(const int & aaa)
{
    const GeneralMath gmat;
    //return aaa;
    for (int i = 0; i < 50; ++i)
    {   // Artificial load to rationalize the decrease the distribution cost relative to processing cost
        double in = gmat.Log(gmat.PowInt(aaa / 10.0, 2) * 10);
        Osstream oss;
        oss << in;
        Isstream iss(oss.str());
        double out;
        iss >> out;
    }
    double in = gmat.Log(gmat.PowInt(aaa / 10.0, 2) * 10);
    Osstream oss;
    oss << in;
    Isstream iss(oss.str());
    double out;
    iss >> out;
    return out;
}

ThreadedLoopTplTest::ThreadedLoopTplTest()
{
    vector<int> lines;
    for (int i = 0; i < 5000; ++i)
        lines.push_back(i);
    //LoopThreadedTpl<int, double> loopThreadedTpl(lines.size(), &Conv);
    //std::function<double(const int&)> f_conv = &Conv;
    std::function<decltype(Conv)> f_conv = &Conv;
    const EnjoLib::VecD & out = ConvertVectorThreaded(lines, f_conv); // Alternative without the filtering

    //cout << "\n";
    //for (const double & o : out)
      //  cout << o << endl;

}

ThreadedLoopTplTest::~ThreadedLoopTplTest()
{
    //dtor
}
