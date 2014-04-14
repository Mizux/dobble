cmake_minimum_required(VERSION 2.8)
project(dobble)

if(UNIX AND NOT APPLE)
  set(C_WARNFLAGS
    #-Werror
    -Wall
    -Wextra
    -Wconversion
    -Wpointer-arith
    -Wcast-align
    -fno-strict-aliasing
    -Wno-long-long
    -Wshadow
  )
  foreach(arg ${C_WARNFLAGS})
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${arg}")
  endforeach(arg ${C_WARNFLAGS})

  set(CXX_WARNFLAGS
    ${C_WARNFLAGS}
    -pedantic
    #-pedantic-errors
    -Weffc++
    -Wold-style-cast
  )
  foreach(arg ${CXX_WARNFLAGS})
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${arg}")
  endforeach(arg ${CXX_WARNFLAGS})
endif()

find_package(Boost REQUIRED)
include_directories(SYSTEM ${Boost_INCLUDE_DIRS})
link_directories(${Boost_LIBRARY_DIRS})

find_package(Qt4 COMPONENTS QtCore QtGui QtOpenGL REQUIRED)
include(${QT_USE_FILE})
add_definitions(${QT_DEFINITIONS})

include_directories("include")

set(_HDR
  include/dobble/item.hpp
  include/dobble/card.hpp
  include/dobble/deck.hpp
  include/plop.hpp
  src/main_window.hpp
)
qt4_wrap_cpp(_HDR_MOC ${_HDR})

set(_SRC
  src/card.cpp
  src/deck.cpp
  src/item.cpp
  src/main.cpp
  src/main_window.cpp
  src/plop.cpp
)
add_executable(${PROJECT_NAME} ${_HDR} ${_HDR_MOC} ${_SRC})
target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES} ${QT_LIBRARIES})
