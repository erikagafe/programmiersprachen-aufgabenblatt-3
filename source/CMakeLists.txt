# Build example
add_executable(example
        example.cpp
        glew.c
        window.hpp
        window.cpp
        rectangle.hpp
        rectangle.cpp
        circle.hpp
        circle.cpp
        )
target_link_libraries(example
        glfw
        ${GLFW_LIBRARIES}
        nanovg
        ${OPENGL_LIBRARIES}
        )
add_dependencies(example glfw nanovg ${COPY_BINARY})

# Build tests
add_executable(tests
        glew.c
        tests.cpp
        vec2.cpp
        mat2.cpp
        color.hpp
        rectangle.hpp
        rectangle.cpp
        circle.cpp
        circle.hpp
        window.hpp
        window.cpp)
target_link_libraries(tests
        glfw
        ${GLFW_LIBRARIES}
        nanovg
        ${OPENGL_LIBRARIES}
        )



