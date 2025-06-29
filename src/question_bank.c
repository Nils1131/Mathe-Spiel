#include "question_bank.h"

static const question_t questions[] = {
    {"What is the slope of the line y=3x+4?", {"3", "4", "7", "-3"}, 0},
    {"Simplify: 2(x+5)", {"2x+5", "2x+10", "x+10", "2x+5"}, 1},
    {"What is the solution to 3x = 12?", {"4", "5", "3", "12"}, 0},
    {"What is 5^2?", {"10", "25", "5", "15"}, 1},
    {"Solve: 2x + 3 = 7", {"x=2", "x=1", "x=3", "x=4"}, 0},
    {"Which is the quadratic formula?", {
        "(-b +/- sqrt(b^2-4ac))/(2a)",
        "a^2 + b^2 = c^2",
        "(x-h)^2 + (y-k)^2 = r^2",
        "base*height/2"
    }, 0},
    {"What is the area of a circle with radius 3?", {"9pi", "6pi", "3pi", "12pi"}, 0},
    {"Convert 0.75 to a fraction", {"3/4", "1/3", "1/4", "2/3"}, 0},
    {"What is the cube root of 27?", {"3", "9", "6", "4"}, 0},
    {"Factor: x^2 - 9", {"(x+3)(x-3)", "(x+3)^2", "(x-3)^2", "Cannot factor"}, 0},
    {"Find the perimeter of a rectangle with length 5 and width 3.",
     {"16", "15", "18", "8"}, 0},
    {"What is the value of pi (approx)?", {"3.14", "2.17", "2.14", "3.41"}, 0},
    {"Simplify: 5/10", {"1/5", "1/2", "1/3", "1/4"}, 1},
    {"What is 4!", {"24", "16", "12", "8"}, 0},
    {"How many degrees in a right angle?", {"90", "180", "45", "60"}, 0},
    {"Solve: |x| = 5", {"x=5 or x=-5", "x=5", "x=-5", "no solution"}, 0},
    {"What is the square root of 144?", {"12", "14", "10", "16"}, 0},
    {"Solve for y: y/3 = 7", {"y=21", "y=10", "y=14", "y=4"}, 0},
    {"Which property does a parallelogram have?",
     {"Opposite sides parallel", "All angles 90", "Three equal sides", "One pair of parallel sides"}, 0},
    {"What is 2^5?", {"32", "64", "16", "25"}, 0},
    {"Find the median of 3,7,9", {"7", "6", "5", "9"}, 0},
    {"What is 1/8 as a decimal?", {"0.125", "0.25", "0.8", "0.5"}, 0},
    {"What is the greatest common divisor of 12 and 18?", {"6", "12", "18", "4"}, 0},
    {"Solve: 4x - 8 = 0", {"x=2", "x=4", "x=-2", "x=8"}, 0},
    {"Which figure has exactly one pair of parallel sides?",
     {"Trapezoid", "Rectangle", "Rhombus", "Parallelogram"}, 0},
    {"Find the next number in the sequence: 2,4,8,16,?", {"32", "20", "24", "30"}, 0},
    {"What is the formula for the area of a triangle?", {"base*height/2", "base*height", "2*base+height", "base^2+height^2"}, 0},
    {"What is 15% of 200?", {"30", "35", "25", "40"}, 0},
    {"Solve: x^2 = 49", {"x=+/-7", "x=7", "x=-7", "x=49"}, 0},
    {"Which unit is used to measure angles?", {"degrees", "liters", "meters", "grams"}, 0}
};

size_t qb_count(void) {
    return sizeof(questions) / sizeof(questions[0]);
}

const question_t *qb_get(size_t index) {
    if (index < qb_count()) {
        return &questions[index];
    }
    return NULL;
}
