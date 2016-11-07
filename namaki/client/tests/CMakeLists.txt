set(test_name "namaki_test")

add_executable(${test_name} main.cpp)

target_include_directories(${test_name}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../namaki
)

target_include_directories(${test_name} SYSTEM
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../3rd-party/Catch/include
)

target_sources(${test_name} PUBLIC
    database_test.cpp
)
target_compile_options(${test_name} PUBLIC "-Wall;-Wpedantic;-Wextra")

target_link_libraries(${test_name} PUBLIC ${lib_name})

configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/data/db-fixture.sh
    ${CMAKE_BINARY_DIR}/db-fixture.sh COPYONLY
)
configure_file(
    ${CMAKE_SOURCE_DIR}/db-init.sql
    ${CMAKE_BINARY_DIR}/db-init.sql COPYONLY
)
