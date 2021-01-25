find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

add_library(vector STATIC libvector.cc)
# To make a shared library use the following command instead
#     add_library(vector SHARED libvector.cc)

add_executable(vector_with_uint8s vector_with_uint8s.cc)
add_executable(namespace_scope namespace_scope.cc)
add_executable(use_vector use_vector.cc)
add_executable(intentional_leak intentional_leak.cc)
add_executable(opengl_window opengl_window.cc)
add_executable(structured_bindings structured_bindings.cc)

target_link_libraries(opengl_window glfw)
target_link_libraries(opengl_window OpenGL::GL)
target_link_libraries(opengl_window GLEW::GLEW)
