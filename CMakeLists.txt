cmake_minimum_required(VERSION 3.5)

project("namaki")

find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)
endif(CCACHE_FOUND)

set(${CMAKE_RUNTIME_OUTPUT_DIRECTORY} ${CMAKE_BINARY_DIR})

find_package(PythonLibs REQUIRED)
include_directories(SYSTEM
    ${CMAKE_CURRENT_SOURCE_DIR}/3rd-party/fmt
    ${CMAKE_CURRENT_SOURCE_DIR}/3rd-party/Catch/include
    ${PYTHON_INCLUDE_DIR}
)
set(src ${CMAKE_SOURCE_DIR}/src)
#protobuf source dir
set(pb_dir "${CMAKE_SOURCE_DIR}/protobuf")
# generated files destination
set(pb_dest ${src})

# generate protobuf messages header and implementation
execute_process(
    COMMAND protoc -I=${pb_dir} --cpp_out=${pb_dest} ${pb_dir}/messages.proto
    COMMAND protoc -I=${pb_dir} --python_out=${pb_dest}/proxy ${pb_dir}/messages.proto
)

# name of the executable
set(lib_name "namaki")


add_library(message_obj OBJECT ${src}/messages.pb.cc)
add_library(${lib_name} SHARED $<TARGET_OBJECTS:message_obj> ${src}/connector.cpp)

target_sources(${lib_name} PUBLIC
    ${src}/database.cpp
    ${src}/message.cpp
    ${src}/proxy/proxy.cpp
)

target_compile_options(
    ${lib_name} PUBLIC
    "-Wall;-Wpedantic;-Wextra;-fdiagnostics-color=always"
    "-Winline;-Wshadow;-Wuseless-cast;-Wsign-conversion;-Wctor-dtor-privacy"
    "-Wmissing-include-dirs;-Wduplicated-cond;-Wfloat-equal;-Wlogical-op"
    "-Wmissing-declarations;-Wsuggest-override;-Wconversion;-Wredundant-decls"
    "-Wnon-virtual-dtor;-Wold-style-cast;-Wcast-align;-Woverloaded-virtual"
    "-Weffc++"
    #"-Werror"
)

target_compile_options(
    message_obj PUBLIC
    "-fPIC;-Wall;-Wpedantic"
)

#optimization
target_compile_options(
   ${lib_name} PUBLIC
   "-Wstack-protector;-fstack-protector"
)
target_compile_definitions(${lib_name} PUBLIC "FMT_HEADER_ONLY")

find_library(ZMQ_LIB NAMES zmq)
find_library(PROTOBUF_LIB NAMES protobuf)
find_library(SQLITE3_LIB NAMES sqlite3)

target_link_libraries(${lib_name} PUBLIC
    ${ZMQ_LIB}
    ${PROTOBUF_LIB}
    ${SQLITE3_LIB}
    ${PYTHON_LIBRARY}
)
add_subdirectory(tests)

file(COPY ${src}/proxy/ DESTINATION
    ${CMAKE_BINARY_DIR}/proxy/lib/python3.5/site-packages/namaki)

install(TARGETS ${lib_name}
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)
install(DIRECTORY ${CMAKE_BINARY_DIR}/proxy
    DESTINATION lib
)
install(DIRECTORY ${src}/ DESTINATION include/namaki
    FILES_MATCHING PATTERN "*.h"
)
install(FILES db.sql DESTINATION sql)
