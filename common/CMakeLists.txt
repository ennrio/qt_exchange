add_library(common_lib STATIC
    database/DatabaseManager.cpp
    models/CurrencyModel.cpp
    services/AuthService.cpp
)

target_link_libraries(common_lib
    Qt6::Core
    Qt6::Sql
    Qt6::Network
    pthread
)

set(HEADERS
    database/DatabaseManager.h
    models/CurrencyModel.cpp
    services/AuthService.cpp
)

source_group("Database Headers" FILES ${HEADERS})

target_include_directories(common_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
