#ifndef MOVINGWINDOW_H
#define MOVINGWINDOW_H

#include "../Util/VecD.hpp"
#include "Matrix.hpp"

namespace EnjoLib
{
class MovingWindow
{
    public:
        MovingWindow(int len, const EnjoLib::VecD & dataIn);
        virtual ~MovingWindow();

        bool IsValid() const;
        int GetNumSets() const;

        EnjoLib::Matrix GetSets() const;

    protected:

    private:
        int m_len;
        EnjoLib::VecD m_dataIn;
};
}

#endif // MOVINGWINDOW_H
