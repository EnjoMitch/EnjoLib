#ifndef BRENTROOT_H
#define BRENTROOT_H

#include <Math/Root/RootSubject.hpp>
#include <Math/Root/RootType.hpp>

class BrentRoot
{
    public:
        BrentRoot();
        virtual ~BrentRoot();
        void Run() const;
        //void test_local_min_one ( double a, double b, double t, EnjoLib::OptiSubject & subj, EnjoLib::OptiType type, std::string title ) const;
        void test_zero_one ( double a, double b, double t, EnjoLib::RootSubject & subj, EnjoLib::RootType type, const char * title ) const;
    protected:
    private:
        void Run(EnjoLib::RootType type) const;
};

#endif // BRENTROOT_H
