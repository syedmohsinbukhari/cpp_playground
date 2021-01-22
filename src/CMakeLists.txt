add_library(intvector STATIC libintvector.cc)
# To make a shared library use the following command instead
#     add_library(intvector SHARED libintvector.cc)

add_executable(vector_with_uint8s vector_with_uint8s.cc)
add_executable(namespace_scope namespace_scope.cc)
add_executable(use_intvector use_intvector.cc)
add_executable(intentional_leak intentional_leak.cc)
