project(unique-email-addresses)
cmake_minimum_required(VERSION 3.0.0)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../../../include)
message("include dir:${CMAKE_CURRENT_SOURCE_DIR}/../../../include")
aux_source_directory(. PROBLEMS)


foreach(PROBLEM ${PROBLEMS})
    get_filename_component(PROBLEM_NAME ${PROBLEM} NAME_WE)
    add_executable(${PROBLEM_NAME}.exe ${PROBLEM})
    target_link_libraries(
        ${PROBLEM_NAME}.exe
        gtest
        ${CMAKE_THREAD_LIBS_INIT}
    )
endforeach()
