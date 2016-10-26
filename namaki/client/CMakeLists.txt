cmake_minimum_required(VERSION 3.5)


project("namaki")

find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ccache)
endif(CCACHE_FOUND)

# name of the executable
set(bin_name "sample")
set(src "namaki")
set(basic_flags "-std=c++14;-Wall;-Wpedantic;-Wextra;-fdiagnostics-color=always")

add_library(message_obj OBJECT ${src}/messages.pb.cc)
add_executable(${bin_name} $<TARGET_OBJECTS:message_obj> ${src}/main.cpp)

target_compile_options(
    ${bin_name} PUBLIC
    ${basic_flags}
    "-Winline;-Wshadow;-Wuseless-cast;-Wsign-conversion;-Wctor-dtor-privacy"
    #"-Wmissing-include-dirs;-Wduplicated-cond;-Wfloat-equal;-Wlogical-op"
    "-Wmissing-declarations;-Wsuggest-override;-Wconversion;-Wredundant-decls"
    "-Wpadded;-Wnon-virtual-dtor;-Wold-style-cast;-Wcast-align;-Woverloaded-virtual"
    #"-Weffc++"
    #"-Werror"
)

target_compile_options(
    message_obj PUBLIC
    ${basic_flags}
)

#optimization
target_compile_options(
   ${bin_name} PUBLIC
   "-Wstack-protector;-fstack-protector"
   )
target_compile_definitions(${bin_name} PUBLIC "")

# 'src' contains both .h and .cpp
target_sources(${bin_name} PUBLIC
    namaki/client.cpp
)

target_include_directories(${bin_name} PUBLIC namaki)

find_library(ZMQ_LIB NAMES zmq)
find_library(PROTOBUF_LIB NAMES protobuf)
target_link_libraries(${bin_name} PUBLIC
    ${ZMQ_LIB}
    ${PROTOBUF_LIB}
)


