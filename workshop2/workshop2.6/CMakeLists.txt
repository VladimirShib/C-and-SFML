add_executable(app6 main.cpp)

target_include_directories(app6 PRIVATE ${SFML_INCLUDE_DIR})
target_compile_features(app6 PUBLIC cxx_std_17)
target_compile_definitions(app6 PRIVATE SFML_STATIC)

target_link_libraries(app6 ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})