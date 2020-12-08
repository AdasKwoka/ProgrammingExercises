cmake_minimum_required ( VERSION 3.0 )

project ( Lab3_zadania_SQLite )


# Pliki naglowkowe
include_directories (

    ./include
    ./libs/sqlite3/include
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

# Biblioteki dynamiczne (".lib" -> ".dll")
target_link_libraries (
    
    main

    ${CMAKE_CURRENT_SOURCE_DIR}/libs/sqlite3/sqlite3.lib
)