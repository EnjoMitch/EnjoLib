#ifndef IHASMUTEX_HPP
#define IHASMUTEX_HPP

namespace std
{
    class mutex;
}

class IHasMutex
{
    public:
        IHasMutex();
        virtual ~IHasMutex();

        virtual std::mutex GetMutex() = 0;
        int ret() {return 0;}

    protected:

    private:
};

#endif // IHASMUTEX_HPP
