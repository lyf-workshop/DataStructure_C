add_executable(ch02_main
    main.c
    stack.c
    queue.c
)
target_include_directories(ch02_main PRIVATE ${CMAKE_SOURCE_DIR}/common)
