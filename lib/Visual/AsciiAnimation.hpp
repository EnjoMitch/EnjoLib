#ifndef ASCIIANIMATION_HPP
#define ASCIIANIMATION_HPP

namespace EnjoLib {
class Str;

class AsciiAnimation
{
public:
    void AnimationPropeller(int * idx) const;
    void Animation09AZ(int * idx) const;
    void AnimationCustom(int * idx, const Str & animSeries) const;

private:
};
}

#endif // ASCIIANIMATION_HPP
