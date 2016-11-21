set(test_name "namaki_test")

add_executable(${test_name} main.cpp)
target_include_directories(${test_name}
    PUBLIC ${CMAKE_SOURCE_DIR}/src
)

target_sources(${test_name} PUBLIC
    database_test.cpp
    ${CMAKE_SOURCE_DIR}/src/database.cpp
)
target_compile_options(${test_name} PUBLIC "-Wall;-Wpedantic;-Wextra")
target_link_libraries(${test_name} ${lib_name})

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/data/db-fixture.sh
    ${CMAKE_BINARY_DIR}/db-fixture.sh COPYONLY
)
configure_file(
    ${CMAKE_SOURCE_DIR}/db.sql
    ${CMAKE_BINARY_DIR}/db.sql COPYONLY
)
