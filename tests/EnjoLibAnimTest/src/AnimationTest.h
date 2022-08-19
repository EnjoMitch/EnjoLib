#ifndef ANIMATIONTEST_H
#define ANIMATIONTEST_H


class AnimationTest
{
    public:
        AnimationTest();
        virtual ~AnimationTest();
        
        void TestDistrib() const;
        void TestRotor(int skipEvery = 1) const;
        void TestProgressBar() const;
        void TestProgressBarDistrib() const;
        void TestX() const;

    protected:

    private:
};

#endif // ANIMATIONTEST_H
