#ifndef DATASETS_HPP
#define DATASETS_HPP

#include <Statistical/Matrix.hpp>

class DataSets
{
    public:
        DataSets();
        virtual ~DataSets();

        static EnjoLib::Matrix GetIris();
        static EnjoLib::Matrix GetPDF();

        static EnjoLib::Matrix GetPDFTransform1();
        static EnjoLib::Matrix GetPDFTransform2();

    protected:

    private:
};

#endif // DATASETS_HPP
