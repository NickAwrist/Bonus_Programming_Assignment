cmake_minimum_required(VERSION 3.22)
project(Bonus_Programming_Assignment C)

set(CMAKE_C_STANDARD 99)

add_executable(Bonus_Programming_Assignment main.c direct-mapped.c fully-associative.c n-way.c hexToBinary.c leak_detector_c.c binaryToDecimal.c)
