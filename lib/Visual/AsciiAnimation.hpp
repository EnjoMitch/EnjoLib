#ifndef ASCIIANIMATION_HPP
#define ASCIIANIMATION_HPP

namespace EnjoLib {
class Str;

class AsciiAnimation
{
public:
    explicit AsciiAnimation(int skipEvery = 1);
    virtual ~AsciiAnimation();
    
    void AnimationPropeller(int * idx) const;
    void Animation09AZ(int * idx) const;
    void AnimationCustom(int * idx, const Str & animSeries) const;

private:
    int m_skipEvery = 1;
};
}

#endif // ASCIIANIMATION_HPP
