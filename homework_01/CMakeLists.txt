cmake_minimum_required(VERSION 3.11)

project(otus-cpp-basic CXX C)

add_executable(test_code
    main.cpp
    lib.cpp
    lib.h
    version.h
)


#add_executable(ex_json ex_json.cpp)
#target_include_directories(ex_json PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/json/include)

#add_executable(ex_gtest ex_gtest.cpp)
#target_include_directories(ex_gtest PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/googletest/googletest/include)
#target_link_directories(ex_gtest PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/googletest/build/lib)
#target_link_libraries(ex_gtest PUBLIC gtest gtest_main)

# add_executable(ex_openssl ex_openssl.cpp)
# target_include_directories(ex_openssl PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/openssl/build/include)
# target_link_directories(ex_openssl PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/openssl/build/lib64)
# target_link_libraries(ex_openssl PUBLIC ssl crypto)


##### find_package examples ######

# find_package(nlohmann_json 3.10.4 REQUIRED)
# target_link_libraries(ex_json nlohmann_json::nlohmann_json)

# set(JSON_BuildTests OFF CACHE INTERNAL "")
# add_subdirectory(json)
# target_link_libraries(ex_json nlohmann_json::nlohmann_json)

##### FetchContent examples ######

# include(FetchContent)

# FetchContent_Declare(json
#   GIT_REPOSITORY https://github.com/nlohmann/json.git
#   GIT_TAG v3.10.4)

# FetchContent_GetProperties(json)
# if(NOT json_POPULATED)
#   FetchContent_Populate(json)
#   add_subdirectory(${json_SOURCE_DIR} ${json_BINARY_DIR} EXCLUDE_FROM_ALL)
# endif()

# target_link_libraries(ex_json PRIVATE nlohmann_json::nlohmann_json)

# FetchContent_Declare(
#   googletest
#   URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
# )
# # For Windows: Prevent overriding the parent project's compiler/linker settings
# set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# FetchContent_MakeAvailable(googletest)
# target_link_libraries(ex_gtest PUBLIC gtest gtest_main)

##### ExternalProject examples ######

# include(ExternalProject)

# ExternalProject_Add(openssl
#     PREFIX openssl
#     GIT_REPOSITORY https://github.com/openssl/openssl.git
#     GIT_TAG openssl-3.0.1
#     CONFIGURE_COMMAND ${CMAKE_BINARY_DIR}/openssl/src/openssl/Configure --prefix=${CMAKE_BINARY_DIR}/openssl/src/openssl-build --openssldir=${CMAKE_BINARY_DIR}/openssl/src/openssl-build
#     BUILD_COMMAND make ${CMAKE_BINARY_DIR}/openssl/src/openssl -j 8
#     INSTALL_COMMAND make ${CMAKE_BINARY_DIR}/openssl/src/openssl install
# )

# add_dependencies(ex_openssl openssl)
# target_link_directories(ex_openssl PUBLIC ${CMAKE_BINARY_DIR}/openssl/src/openssl-build/include/lib64)
# target_include_directories(ex_openssl PUBLIC ${CMAKE_BINARY_DIR}/openssl/src/openssl-build/include)
# target_link_libraries(ex_openssl PUBLIC ssl crypto)
