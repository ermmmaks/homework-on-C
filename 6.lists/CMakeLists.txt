add_executable(sortList sortList.c)

add_library(lists lists.c)

target_link_libraries(sortList PRIVATE lists)