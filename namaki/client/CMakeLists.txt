cmake_minimum_required(VERSION 3.5)

project("namaki")

find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)
endif(CCACHE_FOUND)

# name of the executable
set(lib_name "namakiclient")
set(src_dir ${CMAKE_CURRENT_SOURCE_DIR}/namaki)
set(fmt_dir ${CMAKE_CURRENT_SOURCE_DIR}/3rd-party/fmt/)

#protobuf source dir
set(pb_dir "${CMAKE_SOURCE_DIR}/namaki")

# generate protobuf messages header and implementation
execute_process(COMMAND protoc -I=${pb_dir} --cpp_out=${pb_dir} ${pb_dir}/messages.proto)
add_library(message_obj OBJECT ${src_dir}/messages.pb.cc)
add_library(${lib_name} STATIC $<TARGET_OBJECTS:message_obj> ${src_dir}/connector.cpp)

target_include_directories(${lib_name} PUBLIC namaki)
target_include_directories(${lib_name} SYSTEM PUBLIC ${fmt_dir})

target_sources(${lib_name} PUBLIC
    ${src_dir}/database.cpp
)
target_compile_options(
    ${lib_name} PUBLIC
    "-Wall;-Wpedantic;-Wextra;-fdiagnostics-color=always"
    "-Winline;-Wshadow;-Wuseless-cast;-Wsign-conversion;-Wctor-dtor-privacy"
    "-Wmissing-include-dirs;-Wduplicated-cond;-Wfloat-equal;-Wlogical-op"
    "-Wmissing-declarations;-Wsuggest-override;-Wconversion;-Wredundant-decls"
    "-Wnon-virtual-dtor;-Wold-style-cast;-Wcast-align;-Woverloaded-virtual"
    #"-Weffc++"
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
)

add_subdirectory(tests)
