cmake_minimum_required(VERSION 3.16)

project(QTBlackjack VERSION 0.1 LANGUAGES CXX)

if(DEFINED ENV{QTDIR})
    list(APPEND CMAKE_PREFIX_PATH $ENV{QTDIR})
endif()

file(GLOB QT_DISCOVERED_DIRS "C:/Qt/6.*/msvc*_64" "C:/Qt/5.*/msvc*_64" "D:/Qt/6.*/msvc*_64" "D:/Qt/5.*/msvc*_64")
if(QT_DISCOVERED_DIRS)
    list(APPEND CMAKE_PREFIX_PATH ${QT_DISCOVERED_DIRS})
endif()

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/ui)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Multimedia)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Multimedia)

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

if(QT_VERSION_MAJOR EQUAL 6)
    qt_add_executable(QTBlackjack MANUAL_FINALIZATION ${PROJECT_SOURCES})
else()
    add_executable(QTBlackjack ${PROJECT_SOURCES})
endif()

target_include_directories(QTBlackjack PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(QTBlackjack PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Multimedia
)

set_target_properties(QTBlackjack PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

include(GNUInstallDirs)
install(TARGETS QTBlackjack
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(QTBlackjack)
endif()

if(WIN32)
    # Automatically copy required Qt DLLs and plugins (windeployqt) after building
    get_target_property(_qt_qmake_location Qt${QT_VERSION_MAJOR}::qmake LOCATION)
    if(NOT _qt_qmake_location)
        get_target_property(_qt_qmake_location Qt${QT_VERSION_MAJOR}::qmake IMPORTED_LOCATION)
    endif()
    if(_qt_qmake_location)
        get_filename_component(_qt_bin_dir "${_qt_qmake_location}" DIRECTORY)
        find_program(WINDEPLOYQT_EXECUTABLE windeployqt HINTS "${_qt_bin_dir}")
    else()
        find_program(WINDEPLOYQT_EXECUTABLE windeployqt)
    endif()

    if(WINDEPLOYQT_EXECUTABLE)
        add_custom_command(TARGET QTBlackjack POST_BUILD
            COMMAND ${WINDEPLOYQT_EXECUTABLE} --no-compiler-runtime "$<TARGET_FILE:QTBlackjack>"
            COMMENT "Copying Qt DLLs and plugins to output folder with windeployqt..."
        )
    endif()
endif()