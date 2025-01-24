cmake_minimum_required(VERSION 3.31)

set(plugin_name "plugin-template")

project(${plugin_name} VERSION 0.1.0 LANGUAGES C CXX)

# set(CMAKE_CXX_FLAGS "-std=c++11 -DTEST -pthread -Wall -O2 -g3 -Wall  -fmessage-length=0 -fPIC")
# set(CMAKE_C_FLAGS "-std=c99 -Wall -O0 -g3 -Wall -fmessage-length=0")

include(FetchContent)

FetchContent_Declare(
    cpr
    GIT_REPOSITORY https://github.com/libcpr/cpr
    GIT_TAG        dec9422db3af470641f8b0d90e4b451c4daebf64) # Replace with your desired git commit from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)

FetchContent_Declare(
    fmt
    GIT_REPOSITORY https://github.com/fmtlib/fmt
    GIT_TAG        e69e5f977d458f2650bb346dadf2ad30c5320281) # 10.2.1
FetchContent_MakeAvailable(fmt)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)

FetchContent_Declare(
    cryptopp_cmake
    GIT_REPOSITORY https://github.com/abdes/cryptopp-cmake.git)
FetchContent_MakeAvailable(cryptopp_cmake)

FetchContent_Declare(
    SQLiteCpp
    GIT_REPOSITORY https://github.com/SRombauts/SQLiteCpp)
FetchContent_MakeAvailable(SQLiteCpp)

include_directories(${PROJECT_SOURCE_DIR}/utils)

add_library(${plugin_name} SHARED ${plugin_name}.cpp)

target_link_libraries(${plugin_name} PRIVATE cpr::cpr)
target_link_libraries(${plugin_name} PRIVATE fmt::fmt)
target_link_libraries(${plugin_name} PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(${plugin_name} PRIVATE cryptopp::cryptopp)
target_link_libraries(${plugin_name} PRIVATE SQLiteCpp)


set_target_properties(${plugin_name} PROPERTIES
    VERSION 1.0
    SOVERSION 1
)