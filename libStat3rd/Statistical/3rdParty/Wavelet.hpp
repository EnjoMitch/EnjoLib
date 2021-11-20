#ifndef WAVELET_H
#define WAVELET_H

namespace EnjoLib {
class VecD;
class Wavelet
{
    
    public:
        Wavelet();
        virtual ~Wavelet();

        EnjoLib::VecD fit(int harmonics, int predictAhead, const EnjoLib::VecD & dy) const;

    protected:

    private:
};
}

#endif // WAVELET_H
