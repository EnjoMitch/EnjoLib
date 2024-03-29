#ifndef OPTIMULTISUBJECT_H
#define OPTIMULTISUBJECT_H

#include <Util/VecFwd.hpp>
#include <Template/ArrayFwd.hpp>

namespace EnjoLib
{
    class OptiMultiSubject
    {
        public:
            OptiMultiSubject();
            virtual ~OptiMultiSubject();

            //virtual double Get(const EnjoLib::VecD & in) = 0;
            virtual FP Get(const FP * in, int n) = 0;

            virtual EnjoLib::VecD GetStart() const = 0;
            virtual EnjoLib::VecD GetStep() const = 0;


            struct Bounds
            {
                Bounds(double min = 0, double max = 0) : min(min), max(max) {}
                double min;
                double max;
            };
            virtual EnjoLib::Array<Bounds> GetBounds() const;


        protected:
        private:
    };
}

#endif // OPTIMULTISUBJECT_H
