cmake_minimum_required(VERSION 3.5)

project(Qt-E VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package( ...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)


set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        login.h
        login.cpp
        newaccount.h
        newaccount.cpp 
        mainscreen.h
        mainscreen.cpp
        resources.qrc
	newgame.cpp
        newgame.h
        newaccount.cpp
        gameplay.h
        gameplay.cpp
        target.h
        target.cpp
        graphicsscene.cpp
        graphicsscene.h
        qte.h
        qte.cpp
        level.h
        level.cpp
        leveleditor.cpp
        leveleditor.h
        eventmanager.h
        eventmanager.cpp
        commandmanager.h
        commandmanager.cpp
        action_i.h
        addtarget.h
        addtarget.cpp
        addqte.h
        addqte.cpp
        removeqte.h
        removeqte.cpp
        removetarget.h
        removetarget.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(Qt-E
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(Qt-E SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(Qt-E
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(Qt-E PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(Qt-E PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(Qt-E)
endif()

######################################################################################
# Add Qt lib
# https://blog.nathanosman.com/2017/11/24/using-windeployqt-with-cpack.html
######################################################################################

if (WIN32)
    get_target_property(_qmake_executable Qt${QT_VERSION_MAJOR}::qmake IMPORTED_LOCATION)
    get_filename_component(_qt_bin_dir "${_qmake_executable}" DIRECTORY)
    find_program(WINDEPLOYQT_EXECUTABLE windeployqt HINTS "${_qt_bin_dir}")

    add_custom_command(TARGET Qt-E POST_BUILD
        COMMAND "${CMAKE_COMMAND}" -E
            env PATH="${_qt_bin_dir}" "${WINDEPLOYQT_EXECUTABLE}"
                --verbose 0
                --no-compiler-runtime
                \"$<TARGET_FILE:Qt-E>\"
        COMMENT "Deploying Qt..."
    )

endif(WIN32)

###############################################################################
##########          TESTING
###############################################################################
set(CMAKE_CXX_STANDARD 11)

# GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
  )

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(tests tests.cpp commandmanager.cpp addtarget.cpp addqte.cpp level.cpp)
target_include_directories(tests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(tests gtest_main Qt${QT_VERSION_MAJOR}::Widgets)

include(GoogleTest)
gtest_discover_tests(tests)
enable_testing()


###############################################################################
##########          DOXYGEN
###############################################################################
find_package(Doxygen)

if(NOT DOXYGEN_FOUND)
message(FATAL_ERROR "Doxygen is needed to build the documentation.")
endif()

set(doxyfile ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile)

add_custom_target(BuildDoc ALL
  COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile}
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/..
  COMMENT "Generating Doxygen documentation"
  VERBATIM
)
