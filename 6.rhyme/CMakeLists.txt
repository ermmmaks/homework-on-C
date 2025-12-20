add_executable(rhyme rhyme.c)

add_library(cycleLists cycleLists.c)

target_link_libraries(rhyme PRIVATE cycleLists)