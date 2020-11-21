cmake_minimum_required ( VERSION 3.0 )

project ( LAB3_LAB4_ZADANIA )


# Pliki naglowkowe
include_directories (

    ./include
)


# Kompilacja w systemie Windows
# (tryb konsoli zamiast trybu okienkowego)
set (

    CMAKE_EXE_LINKER_FLAGS
    "-Wl,--subsystem,console"
)


# Pliki Zrodlowe
add_executable (

    main

    ./src/main.cpp
)