add_executable(app1 main.cpp)

set(SFML_STATIC_LIBRARIES TRUE)

find_package(Freetype)
find_package(JPEG)
find_package(SFML 2 COMPONENTS window graphics system)

target_compile_features(app1 PUBLIC cxx_std_17)
target_compile_definitions(app1 PRIVATE SFML_STATIC)

target_link_libraries(app1 ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})