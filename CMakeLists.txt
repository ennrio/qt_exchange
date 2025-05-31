cmake_minimum_required(VERSION 3.16)
project(ExchangeApp VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Sql Widgets Network)

add_subdirectory(common)
add_subdirectory(client)
add_subdirectory(admin)

configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/sql/init_db.sql"
    "${CMAKE_CURRENT_BINARY_DIR}/init_db.sql"
    COPYONLY
)
