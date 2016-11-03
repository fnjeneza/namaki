cmake_minimum_required(VERSION 3.5)


project("namaki")

find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)
endif(CCACHE_FOUND)

# name of the executable
set(bin_name "namakic")
set(src "namaki")
#protobuf source dir
set(pb_dir "${CMAKE_SOURCE_DIR}/namaki")

# generate protobuf messages header and implementation
execute_process(COMMAND protoc -I=${pb_dir} --cpp_out=${pb_dir} ${pb_dir}/messages.proto)
add_library(message_obj OBJECT ${src}/messages.pb.cc)
add_library(${bin_name} SHARED $<TARGET_OBJECTS:message_obj> ${src}/connector.cpp)

target_compile_options(
    ${bin_name} PUBLIC
    "-fPIC;-Wall;-Wpedantic;-Wextra;-fdiagnostics-color=always"
    "-Winline;-Wshadow;-Wuseless-cast;-Wsign-conversion;-Wctor-dtor-privacy"
    "-Wmissing-include-dirs;-Wduplicated-cond;-Wfloat-equal;-Wlogical-op"
    "-Wmissing-declarations;-Wsuggest-override;-Wconversion;-Wredundant-decls"
    "-Wpadded;-Wnon-virtual-dtor;-Wold-style-cast;-Wcast-align;-Woverloaded-virtual"
    #"-Weffc++"
    #"-Werror"
)

target_compile_options(
    message_obj PUBLIC
    "-fPIC;-Wall;-Wpedantic"
)

#optimization
target_compile_options(
   ${bin_name} PUBLIC
   "-Wstack-protector;-fstack-protector"
   )
target_compile_definitions(${bin_name} PUBLIC "")

target_include_directories(${bin_name} PUBLIC namaki)

find_library(ZMQ_LIB NAMES zmq)
find_library(PROTOBUF_LIB NAMES protobuf)
target_link_libraries(${bin_name} PUBLIC
    ${ZMQ_LIB}
    ${PROTOBUF_LIB}
)
