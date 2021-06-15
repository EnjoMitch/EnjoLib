#include "PCA.hpp"
#include "Statistical.hpp"
#include "EigenAbstract.hpp"

#include "../Util/Tokenizer.hpp"
#include "../Util/ProtocolCreator.h"
#include "../Util/ProtocolCreatorFile.hpp"
#include "../Util/CharManipulationsTplVec.hpp"
#include "../Template/CorradePointer.h"


#include <Util/CoutBuf.hpp>
#include <Util/Except.hpp>

using namespace std;
using namespace EnjoLib;

const EnjoLib::Str PCA::STR_MEAN = "-mean";
const EnjoLib::Str PCA::STR_FEAT = "-feat";

PCA::~PCA(){}
PCA:: PCA(){}
PCA:: PCA(const Matrix & xxx, int numFeaturesToLeave)
{
    const Statistical stat;
    const Corrade::Containers::Pointer<EigenAbstract> eigen = EigenAbstract::CreateDefault();
    const Matrix & covMat = stat.CovarianceMatrix(xxx);
    m_origMean = stat.MeanCols(xxx);
    m_featVec = eigen->GetSortedFeatureVectorNumber(covMat, numFeaturesToLeave);
}

PCA:: PCA(const EnjoLib::Str & fileNameBase)
{
    const CharManipulationsTplVec cman;
    const Tokenizer tok;
    EnjoLib::Osstream oss;
    Str lineMean;
    try
    {
        lineMean = tok.GetLines(fileNameBase + STR_MEAN).at(0);
        //cout << "11lineMean = " << lineMean << endl;
        m_origMean = cman.ToNumbersVec<double>(tok.Tokenize(lineMean));
    }
    catch (std::exception & ex)
    {
        oss << "PCA:: PCA() Mean: " << ex.what() << ", lineMean = " << lineMean << NL2;
        throw EnjoLib::ExceptRuntimeError(oss.str());
    }
    try
    {
        m_featVec.clear();
        const VecStr & linesFeat = tok.GetLines(fileNameBase + STR_FEAT);
        for (const Str & lineFeat : linesFeat)
        {
            //cout << "lineFeat = " << lineFeat << endl;
            if (lineFeat.empty())
            {
                continue;
            }
            const VecD & feat = cman.ToNumbersVec<double>(tok.Tokenize(lineFeat));
            m_featVec.push_back(feat);
        }
    }
    catch (std::exception & ex)
    {
        oss << "PCA:: PCA() Feat: " << ex.what() << NL2;
        throw EnjoLib::ExceptRuntimeError(oss.str());
    }
}

void PCA::LoadFromStr(const EnjoLib::Str & str)
{
    const CharManipulationsTplVec cman;
    const Tokenizer tok;
    EnjoLib::Osstream oss;
    const VecStr & meanLines = tok.Tokenize(str, DELIM);
    Str lineMean;
    try
    {
        lineMean = meanLines.at(0);
        m_origMean = cman.ToNumbersVec<double>(tok.Tokenize(lineMean));
    }
    catch (std::exception & ex)
    {
        oss << "PCA:: PCA() Mean: " << ex.what() << ", lineMean = " << lineMean << NL2;
        throw EnjoLib::ExceptRuntimeError(oss.str());
    }
    try
    {
        m_featVec.FromStr(meanLines.at(1));
    }
    catch (std::exception & ex)
    {
        oss << "PCA:: PCA() Feat: " << ex.what() << NL2;
        throw EnjoLib::ExceptRuntimeError(oss.str());
    }
}


Matrix PCA::Transform(const Matrix & xxx) const
{
    //cout << "Transform " << xxx.SizeStr() << endl;
    //cout << "Transform " << m_featVec.Print() << endl;
    const Matrix & xadjMean  = xxx.AdjustMeanCols(m_origMean);
    const Matrix & xadjMeanT = xadjMean.T();
    const Matrix & ret = m_featVec * xadjMeanT;
    return ret.T();
}

Matrix PCA::InverseTransform(const Matrix & xxx) const
{
    const Matrix & mul = m_featVec.T() * xxx.T();
    const Matrix & ret = mul.ApplyMeanRows(m_origMean);
    return ret.T();
}

EnjoLib::Str PCA::Serialize(const EnjoLib::Str & fileNameBase) const
{
    ProtocolCreatorFile fmean(fileNameBase + STR_MEAN, '\n');
    ProtocolCreatorFile ffeat(fileNameBase + STR_FEAT, '\n');
    fmean.AddStr(m_origMean.Print());
    ffeat.AddStr(m_featVec.Print());
    
    ProtocolCreator pcc(DELIM);
    pcc.AddStr(m_origMean.Print());
    pcc.AddStr(m_featVec.ToStr());
    
    const Str & prot = pcc.Get();
    return prot;
}
