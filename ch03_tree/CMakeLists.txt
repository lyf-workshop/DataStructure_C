add_executable(ch03_main
    main.c
    binary_tree.c
    bst.c
)
target_include_directories(ch03_main PRIVATE ${CMAKE_SOURCE_DIR}/common)
