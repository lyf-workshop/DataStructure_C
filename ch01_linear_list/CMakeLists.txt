add_executable(ch01_main
    main.c
    array_list.c
    linked_list.c
)
target_include_directories(ch01_main PRIVATE ${CMAKE_SOURCE_DIR}/common)
