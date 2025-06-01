qt_add_library(common_lib STATIC
    database/DatabaseManager.h
    database/DatabaseManager.cpp
    models/CurrencyModel.h
    models/CurrencyModel.cpp
    services/AuthService.h
    services/AuthService.cpp
)

target_link_libraries(common_lib
    Qt6::Core
    Qt6::Sql
)



set(HEADERS
    database/DatabaseManager.h
    services/AuthService.h
)

source_group("Database Headers" FILES ${HEADERS})

target_include_directories(common_lib PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)
