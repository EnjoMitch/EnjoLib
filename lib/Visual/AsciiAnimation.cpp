#include <Visual/AsciiAnimation.hpp>

#include <Util/Str.hpp>
#include <Util/CoutBuf.hpp>

using namespace EnjoLib;

void AsciiAnimation::AnimationPropeller(int * idx) const
{
    const Str anim = "|/-\\";
    AnimationCustom(idx, anim);
}

void AsciiAnimation::Animation09AZ(int * idx) const
{
    const Str anim = "0123456789ABCDEFGHIJKLMNOPQRSTUWXYZ";
    AnimationCustom(idx, anim);
}

void AsciiAnimation::AnimationCustom(int * idx, const EnjoLib::Str & animSeries) const
{
    Cout out;
    out << '\b' << animSeries.at((*idx)++ % animSeries.size());
    out.Flush();
}
