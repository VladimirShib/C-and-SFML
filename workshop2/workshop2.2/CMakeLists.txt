add_executable(app2 main.cpp)

target_include_directories(app2 PRIVATE ${SFML_INCLUDE_DIR})
target_compile_features(app2 PUBLIC cxx_std_17)
target_compile_definitions(app2 PRIVATE SFML_STATIC)

target_link_libraries(app2 ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})