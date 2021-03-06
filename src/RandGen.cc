#include "RandGen.h"
#include <ctime>
#include <cstdlib>
#include <iostream>

RandGen::RandGen(unsigned int seed) : seed{seed} {
    if (seed == 1) {
        std::cerr << "Initializing random generator with seed 1 is not permitted, exiting..." << std::endl;
        exit(EXIT_FAILURE);
    }
    std::srand(seed);
}

void RandGen::resetRandSeq() {
    std::srand(1);
}

unsigned int RandGen::getRandom(unsigned int options) {
    if (!options) return 0;
    return rand() % options;
}


RandGen &RandGen::getInstance(unsigned int seed) {
    if (seed == 1) seed = time(NULL);
    static RandGen instance{seed};
    return instance;
}

