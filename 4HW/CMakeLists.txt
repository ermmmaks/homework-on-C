add_executable(main main.c)

add_library(optSort optSort.c)

target_link_libraries(main PRIVATE optSort)