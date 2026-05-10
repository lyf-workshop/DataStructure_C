add_executable(ch05_main
    main.c
    sort.c
)
target_include_directories(ch05_main PRIVATE ${CMAKE_SOURCE_DIR}/common)
