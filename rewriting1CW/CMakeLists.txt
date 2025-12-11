add_library(1 1.c)
add_library(2 2.c)
add_library(3 3.c)

add_executable(main1 main1.c)
add_executable(main2 main2.c)
add_executable(main3 main3.c)

target_link_libraries(main1 PRIVATE 1)
target_link_libraries(main2 PRIVATE 2)
target_link_libraries(main3 PRIVATE 3)
