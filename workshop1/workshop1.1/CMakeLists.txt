add_executable(app1 main.cpp)

target_include_directories(app1 PRIVATE ${SFML_INCLUDE_DIR})
target_compile_features(app1 PUBLIC cxx_std_17)
target_compile_definitions(app1 PRIVATE SFML_STATIC)

target_link_libraries(app1 ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})