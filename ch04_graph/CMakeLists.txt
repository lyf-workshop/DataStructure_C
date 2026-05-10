add_executable(ch04_main
    main.c
    graph.c
)
target_include_directories(ch04_main PRIVATE ${CMAKE_SOURCE_DIR}/common)
