#include "Brent.h"
#include "BrentRoot.h"
#include "Nelder.h"
#include "MultiDimIter.h"
#include "CoutBufTest.h"
#include "CoutBufTestEL.h"
#include "SafeNumberTest.h"
#include "BashTest.h"
#include "ScalingTest.h"
#include "CentroidTest.h"
#include "KMeansTest.h"
#include "ClusteringTest.h"
#include "StandardizationTest.h"
#include "AxisRescaleTest.h"
#include "GeneralMathTest.h"
#include "MeanWeightedTest.h"
#include "UniquePtrTest.h"
#include "VectorDTest.h"
#include "ThreadedLoopTplTest.hpp"
#include "StrColourTest.hpp"
//#include "CoutBufTest.h"

#include <Util/Tokenizer.hpp>
#include <Util/CoutBuf.hpp>

using namespace std;
using namespace EnjoLib;

int main()
{
    ELO
    Tokenizer tok;
    Str testMsg = "EURCAD|Feed|Data";
    auto ret = tok.Tokenize(testMsg, '|');
    LOG << ret.at(0) << Endl;
    LOG << ret.at(1) << Endl;
    LOG << ret.at(2) << Endl;
    
    

    ScalingTest().Run();
    KMeansTest();
    CentroidTest();
    BashTest();
    Brent().Run();
    BrentRoot().Run();
    Nelder().Run();
    MultiDimIter().Run();
    ClusteringTest().Run();
    SafeNumberTest().Run();
    StandardizationTest();
    MeanWeightedTest();
    AxisRescaleTest().Run();
    GeneralMathTest();
    VectorDTest();
    ThreadedLoopTplTest();
    
    UniquePtrTest();
    
    StrColourTest();
    CoutBufTest();
    CoutBufTestEL();
    
    return 0;
}






