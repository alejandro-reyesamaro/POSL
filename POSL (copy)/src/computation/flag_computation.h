#pragma once

enum Computation { PAR, SEQ };

class FlagComputation
{
    public:
        virtual Computation computation() = 0;
};

class FlagSequentialComputation : public FlagComputation
{
    public:
        Computation computation();
};

class FlagParallelComputation : public FlagComputation
{
    public:
        FlagParallelComputation(int procA, int procB);
        Computation computation();

        int ProcessA, ProcessB;
};
