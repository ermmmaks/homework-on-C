add_executable(tests tests.c)

add_library(binaryRep binaryRep.c)

target_link_libraries(tests PRIVATE binaryRep)