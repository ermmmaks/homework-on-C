add_executable(main main.c)
add_library(binaryRep binaryRep.c)

target_link_libraries(main PRIVATE binaryRep)