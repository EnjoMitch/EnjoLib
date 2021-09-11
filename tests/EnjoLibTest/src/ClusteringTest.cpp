#include "ClusteringTest.h"
#include <Statistical/KMeans1d.hpp>
#include <Util/CoutBuf.hpp>

using namespace std;
using namespace EnjoLib;

ClusteringTest::ClusteringTest(){}
ClusteringTest::~ClusteringTest(){}

void ClusteringTest::Run()
{
    ELO
    KMeans1d kmeans(false);
    EnjoLib::VecF op;
    op.push_back((0));
    op.push_back((2));
    op.push_back((12));
    op.push_back((14));

    LOG << "in:" << Endl;
    for (const float & o : op)
    {
        LOG << o << Endl;
        kmeans.AddObservation(o);
    }
    int reductions = 2;
    EnjoLib::VecF ret = kmeans.Reduce(reductions);

    LOG << "\nout: (reductions = " << reductions << ")" << Endl;
    for (const float & o : ret)
    {
        LOG << o << Endl;
    }
        //float result = ret.at(0).level;
        //float expected = 1;

        //float result = ret.at(1).level;
        //float expected = 13;

}
