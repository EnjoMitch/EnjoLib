#ifndef _WRITER_CONDITIONAL_H
#define _WRITER_CONDITIONAL_H

#include <Ios/Ostream.hpp>
#include <Util/Str.hpp>

namespace EnjoLib {
class WriterConditional
{
public:
	WriterConditional(EnjoLib::Ostream & ostr, bool shouldWrite);
	virtual ~WriterConditional();
	
	void Write(const EnjoLib::Str & text);
	
protected:   

private:
    bool m_shouldWrite;
    EnjoLib::Ostream & m_ostr;    
};

}
#endif // _WRITER_CONDITIONAL_H
