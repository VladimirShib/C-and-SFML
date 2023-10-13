add_executable(app3 main.cpp)

target_include_directories(app3 PRIVATE ${SFML_INCLUDE_DIR})
target_compile_features(app3 PUBLIC cxx_std_17)
target_compile_definitions(app3 PRIVATE SFML_STATIC)

target_link_libraries(app3 ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})