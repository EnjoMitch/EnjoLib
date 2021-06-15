#ifndef PROGRESSMONIT_H
#define PROGRESSMONIT_H

#include <Util/Str.hpp>

namespace EnjoLib
{
class ProgressMonit
{
    public:
        ProgressMonit(int numBars = 25);
        virtual ~ProgressMonit();
        int GetPercentDoneInt(size_t i, size_t sz) const;
        EnjoLib::Str GetProgressBar(size_t i, size_t sz) const;
        void PrintPercentDone(size_t i, size_t sz) const;
        double GetTimeLeft(size_t i, size_t sz, double elapsedSeconds) const; // Use Timer for elapsedSeconds
    protected:
    private:

        int m_numBars;
};
}
#endif // PROGRESSMONIT_H
