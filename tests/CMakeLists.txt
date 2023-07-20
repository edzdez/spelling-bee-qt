include_directories(../src/lib)

add_executable(test_trie
        testtrie.cpp testtrie.h)

target_link_libraries(test_trie
        Qt5::Core
        Qt5::Test
        spelling_bee_lib
)