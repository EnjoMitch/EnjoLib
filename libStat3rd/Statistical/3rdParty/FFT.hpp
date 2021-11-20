#ifndef FFT_H
#define FFT_H

namespace EnjoLib {
class VecD;

class FFT
{
    public:
        FFT();
        virtual ~FFT();

        EnjoLib::VecD fit(int harmonics, int predictAhead, const EnjoLib::VecD & dy) const;

    protected:

    private:
};
}

#endif // FFT_H
