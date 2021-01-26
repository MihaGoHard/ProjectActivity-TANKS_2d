add_executable(tanks main.cpp)

target_include_directories(tanks PRIVATE ${SFML_INCLUDE_DIR})
target_compile_features(tanks PUBLIC cxx_std_17)
target_compile_definitions(tanks PRIVATE SFML_STATIC)

target_link_libraries(tanks ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})