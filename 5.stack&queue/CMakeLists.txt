add_library(stack stack.c)

add_executable(bracketBalance bracketBalance.c)
add_executable(sortStation sortStation.c)

target_link_libraries(bracketBalance PRIVATE stack)
target_link_libraries(sortStation PRIVATE stack)