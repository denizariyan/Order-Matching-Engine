set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

aux_source_directory(. DIR_SRCS)

add_executable(core ${DIR_SRCS})
target_link_libraries(core PRIVATE Threads::Threads)
