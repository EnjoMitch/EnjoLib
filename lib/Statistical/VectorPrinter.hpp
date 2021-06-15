#ifndef VECTORPRINTER_H
#define VECTORPRINTER_H

#include <Util/Str.hpp>
namespace EnjoLib
{
//template<class T>
class VectorPrinter
{
    public:
        VectorPrinter();
        virtual ~VectorPrinter();

        EnjoLib::Str Print(int precision = 0) const; // TODO
        EnjoLib::Str PrintScilab( const char * varName ) const;
        EnjoLib::Str PrintPython( const char * varName ) const;

    protected:

    private:

};
}

#endif // VECTORPRINTER_H
