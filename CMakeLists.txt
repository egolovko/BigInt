cmake_minimum_required(VERSION 3.20)
project(Lab2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Lab2
        src/main.cpp
        src/BigInt.h
        src/BigInt.cpp
        src/multers/AbstractMulter.h
        src/multers/BasicMulter.h
        src/multers/BasicMulter.cpp
        src/multers/KaratsubaMulter.h
        src/multers/KaratsubaMulter.cpp
        src/multers/ShonhageMulter.h
        src/multers/ShonhageMulter.cpp
        src/multers/Toom3Multer.cpp
        src/multers/Toom3Multer.h
        src/prime_testers/LLT.cpp
        src/prime_testers/LLT.h
        src/prime_testers/MRT.cpp
        src/prime_testers/MRT.h
        src/random_generators/LCG.cpp
        src/random_generators/LCG.h src/prime_testers/SST.cpp src/prime_testers/SST.h src/prime_testers/LT.cpp src/prime_testers/LT.h src/prime_testers/QFT.cpp src/prime_testers/QFT.h src/dividers/NewtonRaphsonDivider.cpp src/dividers/NewtonRaphsonDivider.h src/dividers/AbstractDivider.h src/dividers/Pow2Divider.cpp src/dividers/Pow2Divider.h src/dividers/CombinedP2NRDivider.cpp src/dividers/CombinedP2NRDivider.h)
