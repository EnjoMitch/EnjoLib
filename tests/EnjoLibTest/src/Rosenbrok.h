#ifndef ROSENBROK_H
#define ROSENBROK_H

#include <Math/FP.hpp>

class Rosenbrok
{
    public:
        Rosenbrok();
        virtual ~Rosenbrok();
        EnjoLib::FP Eval( const EnjoLib::FP x[2] ) const;
    protected:
    private:
};

#endif // ROSENBROK_H
