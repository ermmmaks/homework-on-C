add_executable(main main.c)

add_library(double doudle.c)

target_link_libraries(main PRIVATE double)