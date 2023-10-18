add_executable(app5 main.cpp)

target_include_directories(app5 PRIVATE ${SFML_INCLUDE_DIR})
target_compile_features(app5 PUBLIC cxx_std_17)
target_compile_definitions(app5 PRIVATE SFML_STATIC)

target_link_libraries(app5 ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})