#ifndef BRENT_H
#define BRENT_H

#include <Math/Opti/OptiType.hpp>

namespace EnjoLib{
class OptiSubject;
}
class Brent
{
    public:
        Brent();
        virtual ~Brent();
        void Run() const;
        void test_local_min_one ( double a, double b, double t, EnjoLib::OptiSubject & subj, EnjoLib::OptiType type, const char * title ) const;

    protected:
    private:
};

#endif // BRENT_H
