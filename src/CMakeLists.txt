include_directories(.)

add_library(spelling_bee_lib
        lib/trie.cpp lib/trie.h
        lib/utils.cpp lib/utils.h)

target_link_libraries(spelling_bee_lib
        Qt5::Core)

add_executable(spelling_bee_qt
        main.cpp
        ui/mainwindow.cpp ui/mainwindow.h ui/mainwindow.ui)

target_link_libraries(spelling_bee_qt
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        Qt5::Network
        spelling_bee_lib)

