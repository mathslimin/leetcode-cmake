message(" CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR} ")
SUBDIRLIST(stringProblems ${CMAKE_CURRENT_SOURCE_DIR})

foreach(problem ${stringProblems})
add_subdirectory(${problem})
endforeach()
