# Create Project
project(TCPApplication LANGUAGES CXX)

# C++ Standards
cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

# Find Qt5 Packages
find_package(Qt5 REQUIRED COMPONENTS Core Network Test)

# Create main application executable
add_executable(TCPApplication
    tcpapplication.cpp
    tcpServer.cpp
    tcpClient.cpp
    tcpServer.h
    tcpClient.h
)

# Enable Testing
enable_testing(true)

# Create Test Executable
add_executable(TCPServerTest
    tcpServerTest.cpp
    tcpServer.cpp
)

# Link Qt Libraries
target_link_libraries(TCPApplication Qt5::Core Qt5::Network)
target_link_libraries(TCPServerTest Qt5::Core Qt5::Network Qt5::Test)

# Add Tests
add_test(NAME testTCPServer COMMAND TCPServerTest)