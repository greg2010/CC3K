#ifndef A05_RANDGEN_H
#define A05_RANDGEN_H

class RandGen {
public:
    static RandGen & getInstance(unsigned int seed);
    // Resets sequence to an initial state
    void resetRandSeq();

    // Generates a random number between 0..options-1
    unsigned int getRandom(unsigned int options);

    RandGen(RandGen const&) = delete;
    void operator=(RandGen const&)  = delete;

private:
    // Construct with seed. If no seed is provided, takes current time in seconds as seed
    RandGen(unsigned int seed);
    unsigned int seed;
};


#endif //A05_RANDGEN_H
