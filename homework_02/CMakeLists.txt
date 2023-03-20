cmake_minimum_required(VERSION 3.5)

project(homework_02)

add_executable(ip_filter 
    main.cpp    
    ip_filter.cpp
)

set_target_properties(ip_filter PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)