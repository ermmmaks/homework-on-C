add_executable(mainBin mainBin.c)
add_executable(double double.c)

add_library(binaryRep binaryRep.c)

target_link_libraries(mainBin PRIVATE binaryRep)