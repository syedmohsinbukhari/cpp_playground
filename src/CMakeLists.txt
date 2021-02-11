find_package(Threads REQUIRED)

add_library(vector STATIC libvector.cc)
# To make a shared library use the following command instead
#     add_library(vector SHARED libvector.cc)

add_executable(vector_with_uint8s vector_with_uint8s.cc)
add_executable(namespace_scope namespace_scope.cc)
add_executable(use_vector use_vector.cc)
add_executable(intentional_leak intentional_leak.cc)
add_executable(structured_bindings structured_bindings.cc)
add_executable(custom_timer custom_timer.cc)
add_executable(stdthreads stdthreads.cc)
add_executable(use_istream use_istream.cc)
add_executable(use_memset use_memset.cc)
add_executable(use_plusplus use_plusplus.cc)
add_executable(use_pointer_play use_pointer_play.cc)

target_link_libraries(stdthreads PRIVATE Threads::Threads)
