#include "LoopThreadedTpl.hpp"

// Example:
//#include <Template/LoopThreadedTpl.hpp>
/*
static Tick GetTick(const string & s)
{
    return Tick(s);
}

Ticks::Ticks(const string & symbolName, const VecStr & lines, bool skipHeader)
{
    LoopThreadedTpl<string, Tick> loopThreadedTpl(lines.size(), &GetTick, symbolName);
    //loopThreadedTpl.AddInputVector(lines); // Alternative without the filtering
    //m_ticks = loopThreadedTpl.AddInputVectorGetOutputVector(lines); // Alternative without the filtering
    for( int i = 0; i < int(lines.size()); ++i )
    {
        if (skipHeader)
        {
            skipHeader = false;
            continue;
        }
        loopThreadedTpl.AddInput(i, lines[i]);
    }
    m_ticks = loopThreadedTpl.GetOutputVector();
}

    // Or:
    std::function<decltype(Conv)> f_conv = &Conv;
    const EnjoLib::VecD & out = ConvertVectorThreaded(lines, f_conv); // Alternative without the filtering
*/
