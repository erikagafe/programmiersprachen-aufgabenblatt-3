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



# Build aufgabe 2 und 3
add_executable(aufgabe_2_und_3
        aufgabe_2_und_3.cpp
        glew.c
        )
target_link_libraries(aufgabe_2_und_3
        glfw
        ${GLFW_LIBRARIES}
        nanovg
        ${OPENGL_LIBRARIES}
        )
add_dependencies(aufgabe_2_und_3 glfw nanovg ${COPY_BINARY})


# Build aufgabe_4
add_executable(aufgabe_4
        aufgabe4.cpp
        glew.c
        vec2.cpp
        circle.cpp
        circle.hpp
        color.hpp
        window.hpp
        window.cpp
        )
target_link_libraries(aufgabe_4
        glfw
        ${GLFW_LIBRARIES}
        nanovg
        ${OPENGL_LIBRARIES}
        )
add_dependencies(aufgabe_4 glfw nanovg ${COPY_BINARY})

# Build aufgabe_6
add_executable(aufgabe_6
        aufgabe_6.cpp
        glew.c
        vec2.cpp
        circle.cpp
        circle.hpp
        color.hpp
        window.hpp
        window.cpp

        )
target_link_libraries(aufgabe_6
        glfw
        ${GLFW_LIBRARIES}
        nanovg
        ${OPENGL_LIBRARIES}
        )
add_dependencies(aufgabe_6 glfw nanovg ${COPY_BINARY})

# Build aufgabe_7
add_executable(aufgabe_7
        aufgabe_7.cpp
        glew.c
        vec2.cpp
        circle.cpp
        circle.hpp
        color.hpp
        window.hpp
        window.cpp

        )
target_link_libraries(aufgabe_7
        glfw
        ${GLFW_LIBRARIES}
        nanovg
        ${OPENGL_LIBRARIES}
        )
add_dependencies(aufgabe_7 glfw nanovg ${COPY_BINARY})


add_executable(aufgabe_9
        aufgabe_9.cpp
        glew.c
        )
target_link_libraries(aufgabe_9
        glfw
        ${GLFW_LIBRARIES}
        nanovg
        ${OPENGL_LIBRARIES}
        )
add_dependencies(aufgabe_9 glfw nanovg ${COPY_BINARY})

add_executable(aufgabe_11
        aufgabe11.cpp
        glew.c
        )
target_link_libraries(aufgabe_11
        glfw
        ${GLFW_LIBRARIES}
        nanovg
        ${OPENGL_LIBRARIES}
        )
add_dependencies(aufgabe_11 glfw nanovg ${COPY_BINARY})