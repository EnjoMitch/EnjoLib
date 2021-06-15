#ifndef OPTIMULTISUBJECT_H
#define OPTIMULTISUBJECT_H

#include <Util/VecD.hpp>

namespace EnjoLib
{
    class OptiMultiSubject
    {
        public:
            OptiMultiSubject();
            virtual ~OptiMultiSubject();

            //virtual double Get(const EnjoLib::VecD & in) = 0;
            virtual double Get(const double * in, int n) = 0;

            virtual EnjoLib::VecD GetStart() const = 0;
            virtual EnjoLib::VecD GetStep() const = 0;


            struct Bounds
            {
                Bounds(double min, double max) : min(min), max(max) {}
                double min;
                double max;
            };
            virtual stdfwd::vector<Bounds> GetBounds() const;


        protected:
        private:
    };
}

#endif // OPTIMULTISUBJECT_H
