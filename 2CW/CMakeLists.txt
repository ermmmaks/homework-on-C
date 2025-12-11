add_library(list list.c)
add_library(queue queue.c)

add_executable(binarySys bynarySys.c)
add_executable(mainQueue mainQueue.c)

target_link_libraries(mainQueue PRIVATE list)
target_link_libraries(mainQueue PRIVATE queue)