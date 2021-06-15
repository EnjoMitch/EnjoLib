#include "ThreadedLoopTplTest.hpp"

#include <Util/VecD.hpp>
#include <Template/LoopThreadedTpl.hpp>


#include <cmath>
#include <sstream>
#include <STD/Iostream.hpp>

using namespace std;
using namespace EnjoLib;

static double Conv(const int & aaa)
{
    //return aaa;
    for (int i = 0; i < 50; ++i)
    {   // Artificial load to rationalize the decrease the distribution cost relative to processing cost
        double in = log(pow(aaa / 10.0, 2) * 10);
        ostringstream oss;
        oss << in;
        istringstream iss(oss.str());
        double out;
        iss >> out;
    }
    double in = log(pow(aaa / 10.0, 2) * 10);
    ostringstream oss;
    oss << in;
    istringstream iss(oss.str());
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
