#ifndef LOOPTHREADED_H
#define LOOPTHREADED_H

namespace EnjoLib
{
    class LoopThreaded
    {
        public:
            LoopThreaded(int szz, int numCores);
            virtual ~LoopThreaded();

            int GetIdxOfDatasetForIteration(int i) const;
            int GetSize() const;
            int GetNumCores() const;

        protected:

        private:
            int m_sz;
            int m_nCores;
    };
}

#endif // LOOPTHREADED_H
