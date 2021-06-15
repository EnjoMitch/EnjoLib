#ifndef PCA_H
#define PCA_H

#include "Matrix.hpp"
#include "../Util/VecD.hpp"

namespace EnjoLib
{
class PCA
{
    public:
        PCA(const Matrix & xxx, int numFeaturesToLeave);
        PCA(const EnjoLib::Str & fileNameBase);
        PCA();
        virtual ~PCA();

        Matrix Transform(const Matrix & xxx) const;
        Matrix InverseTransform(const Matrix & xxx) const;

        void LoadFromStr(const EnjoLib::Str & str);
        EnjoLib::Str Serialize(const EnjoLib::Str & fileNameBase) const;

        Matrix GetFeatureVector() const { return m_featVec; }
        VecD GetOriginalMean() const { return m_origMean; }

    protected:

    private:
        static const EnjoLib::Str STR_MEAN;
        static const EnjoLib::Str STR_FEAT;
        VecD m_origMean;
        Matrix m_featVec;
        
        static const char DELIM = 'P';
};
}

#endif // PCA_H
