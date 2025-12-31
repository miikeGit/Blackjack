cmake_minimum_required(VERSION 3.16)

project(QTBlackjack VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/ui)

find_package(Qt6 REQUIRED COMPONENTS Widgets Multimedia)

set(PROJECT_SOURCES
        src/main.cpp
        src/deck.cpp
        src/game.cpp
        src/player.cpp
        src/mainwindow.cpp
        src/sfxmanager.cpp

        include/deck.h
        include/game.h
        include/player.h
        include/mainwindow.h
        include/sfxmanager.h
        include/AnimatedCard.h

        assets/assets.qrc

        ui/mainwindow.ui
)

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${PROJECT_SOURCES})

qt_add_executable(QTBlackjack MANUAL_FINALIZATION ${PROJECT_SOURCES})

target_include_directories(QTBlackjack PRIVATE include)
target_link_libraries(QTBlackjack PRIVATE Qt6::Widgets Qt6::Multimedia)
set_target_properties(QTBlackjack PROPERTIES WIN32_EXECUTABLE TRUE)

include(GNUInstallDirs)
install(TARGETS QTBlackjack
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

qt_finalize_executable(QTBlackjack)