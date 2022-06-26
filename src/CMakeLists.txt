set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

file (GLOB_RECURSE CORE_SOURCES CONFIGURE_DEPENDS "*.cpp")
file (GLOB_RECURSE CORE_HEADERS CONFIGURE_DEPENDS "*.hpp")

set (CORE_INCLUDE_DIRS "")
foreach (_headerFile ${CORE_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND CORE_INCLUDE_DIRS ${_dir})
endforeach()
list (REMOVE_DUPLICATES CORE_INCLUDE_DIRS)


add_executable(core ${CORE_SOURCES})
target_include_directories(core PRIVATE ${CORE_HEADERS})
target_link_libraries(core PRIVATE Threads::Threads)
