cmake_minimum_required(VERSION 3.20)

project(plugin)

set(CMAKE_GENERATOR_PLATFORM Win32)
set(CMAKE_CONFIGURATION_TYPES "Release" CACHE STRING "" FORCE)
set(CMAKE_BUILD_TYPE Release CACHE STRING "" FORCE)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    dllmain.cpp
    ASM/SendPacket.cpp
    ASM/ShowGameMessage.cpp
)

set(HEADERS
    ASM/SendPacket.h
    ASM/ShowGameMessage.h
)

add_library(${PROJECT_NAME} SHARED ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

if(WIN32)
    target_compile_definitions(${PROJECT_NAME} PRIVATE
        WIN32_LEAN_AND_MEAN
        NOMINMAX
    )
    
    target_link_libraries(${PROJECT_NAME} PRIVATE
        kernel32
        user32
    )
endif()

target_compile_options(${PROJECT_NAME} PRIVATE
    $<$<CONFIG:Release>:/O2 /Ob2 /DNDEBUG>
)