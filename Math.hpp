#ifndef MATH_HPP
#define MATH_HPP

float lerp(float Start, float End, float Param) {
    return (1 - Param) * Start + Param * End;
}

#endif //MATH_HPP
