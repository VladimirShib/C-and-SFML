add_executable(app4 main.cpp)

target_include_directories(app4 PRIVATE ${SFML_INCLUDE_DIR})
target_compile_features(app4 PUBLIC cxx_std_17)
target_compile_definitions(app4 PRIVATE SFML_STATIC)

target_link_libraries(app4 ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})