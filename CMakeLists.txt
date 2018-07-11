set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
add_executable( fbo fbo.cpp use_utils.cpp )
target_link_libraries( fbo Common )
