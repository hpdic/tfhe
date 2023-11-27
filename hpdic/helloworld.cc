#include <tfhe/tfhe.h>
#include <tfhe/tfhe_io.h>

#include <tfhe/numeric_functions.h>

#include <iostream>
#include <cassert>

int main() {

    std::cout << "Hello TFHE from HPDIC." << std::endl;

    /**
     * Working on src/test/arithmetic_test.cpp
     */
    static const Torus32 MESSAGE1 = 123456789;
    static const Torus32 MESSAGE2 = 987654321;

    Torus32 reps1 = gaussian32(MESSAGE1, 0);
    Torus32 reps2 = gaussian32(MESSAGE2, 0);

    assert(MESSAGE1 == reps1);
    assert(MESSAGE2 == reps2);

    reps1 = gaussian32(MESSAGE1, 0.01);
    reps2 = gaussian32(MESSAGE2, 0.5);

    assert(MESSAGE1 != reps1);
    assert(MESSAGE2 != reps2);

    for (int32_t i = 2; i < 200; i++)
    {
        Torus32 v = uniformTorus32_distrib(generator);
        Torus32 w = approxPhase(v, i);
        double dv = t32tod(v);
        double dw = t32tod(w);
        printf("%d, %lf, %lf, %lf\n", i, dv, dw, i*dw);
    }

    for (int32_t i = 2; i < 200; i++)
    {
        Torus32 v = uniformTorus32_distrib(generator);
        int32_t w = modSwitchFromTorus32(v, i);
        double dv = t32tod(v);
        double dw = double(w) / double(i);
    }

    for (int32_t i = 2; i < 200; i++)
    {
        int32_t j = uniformTorus32_distrib(generator) % i;
        Torus32 v = modSwitchToTorus32(j, i);
        double dv = t32tod(v);
        printf("%d, %d, %lf, %lf\n", j, i, dv, double(j)/i);
    }
}