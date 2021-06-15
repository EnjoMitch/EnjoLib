#ifndef ROOTFACTORY_H
#define ROOTFACTORY_H

#include <Template/CorradePointerFwd.h>
#include "IRootAlgo.hpp"
#include "RootType.hpp"

#include <Util/AutoPtr.hpp>

namespace EnjoLib
{
    class RootFactory
    {
        public:
            RootFactory();
            virtual ~RootFactory();

            /// Creates a root finding algorithm
            /**
            \param type - type of the algorithm
            \param minArg - starting argument
            \param maxArg - maximal argument that will be searched
            \param epsilon - accuracy of the I/O argument (not the function!)
            */
            static Corrade::Containers::Pointer<IRootAlgo> Create(RootType type, double minArg, double maxArg, double eps);

        protected:
        private:
    };
}

#endif // OPTIFACTORY_H
