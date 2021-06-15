#ifndef CROSSVALIDATION_H
#define CROSSVALIDATION_H

namespace EnjoLib
{
enum class CVAlgo
{
    STRATIFIED,
    SHUFFLED
};

class CrossValidation
{
    public:
        CrossValidation(unsigned numCVs, unsigned szData);
        virtual ~CrossValidation();



        bool IsTrain(int icv, int i, CVAlgo algo) const;

        bool IsTrainStratified(int icv, int i) const;
        bool IsTrainShuffled(int icv, int i) const;

    protected:

    private:

        unsigned m_numCVs = 3;
        unsigned m_szData = 0;
};
}

#endif // CROSSVALIDATION_H
