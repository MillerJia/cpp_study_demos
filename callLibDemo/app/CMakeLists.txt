include_directories(include)
include_directories(ThirdParty/libJcy/include)
#message("this is main")

project(cpp_exe)

file(GLOB_RECURSE SRC_FILE_LIST "*.cpp")

set(MAIN_SOURCE main.cpp)

add_executable(
${PROJECT_NAME} 
${SRC_FILE_LIST}
${MAIN_SOURCE}
)

target_link_libraries(${PROJECT_NAME} third_party_lib)