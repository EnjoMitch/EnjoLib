#ifndef GAUSSIAN_H
#define GAUSSIAN_H

namespace EnjoLib {
class VecD;

class Gaussian
{
    public:
        Gaussian();
        virtual ~Gaussian();

        EnjoLib::VecD fit(double alpha, int predictAhead, const EnjoLib::VecD & dy) const;

    protected:

    private:
};
}

#endif // GAUSSIAN_H
