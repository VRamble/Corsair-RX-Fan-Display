cmake_minimum_required(VERSION 3.16)
project(CORFD CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
        ${CMAKE_SOURCE_DIR}/app/gui
        ${CMAKE_SOURCE_DIR}/app/serial
        ${CMAKE_SOURCE_DIR}/common
        ${CMAKE_SOURCE_DIR}/lib/external
)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

find_package(SDL2_ttf REQUIRED)
include_directories(${SDL2_TTF_INCLUDE_DIRS})

file(GLOB APP_SRCS app/*.cpp)
file(GLOB_RECURSE GUI_SRCS app/gui/*.cpp)
file(GLOB SERIAL_SRCS app/serial/*.cpp)
file(GLOB COMMON_SRCS common/*.cpp)

file(GLOB_RECURSE ALL_INCLUDE_DIRS RELATIVE ${CMAKE_SOURCE_DIR} app/gui/*.h app/gui/*.hpp)
foreach (header ${ALL_INCLUDE_DIRS})
    get_filename_component(header_path ${header} DIRECTORY)
    list(APPEND INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/${header_path})
endforeach()
list(REMOVE_DUPLICATES INCLUDE_DIRS)
include_directories(${INCLUDE_DIRS})


add_executable(CORFD
        ${APP_SRCS}
        ${GUI_SRCS}
        ${SERIAL_SRCS}
        ${COMMON_SRCS}
)

target_link_libraries(CORFD
        ${SDL2_LIBRARIES}
        ${SDL2_TTF_LIBRARIES}
        GL
        dl
        SDL2_ttf
)

add_custom_command(TARGET CORFD POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/app/gui/assets $<TARGET_FILE_DIR:CORFD>/gui/assets
)