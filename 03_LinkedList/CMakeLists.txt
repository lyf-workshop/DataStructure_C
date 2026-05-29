add_executable(03_LinkedList
        main.cpp
        singly_linked_list.cpp
        doubly_linked_list.cpp
        static_linked_list.cpp)
target_include_directories(03_LinkedList PRIVATE ${CMAKE_SOURCE_DIR}/common)
