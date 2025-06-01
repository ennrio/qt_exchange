add_executable(admin_app
    main.cpp
    ui/AdminWindow.cpp
    widgets/UsersWidget.cpp
    widgets/CurrenciesWidget.cpp
    widgets/RequestsAdminWidget.cpp
    ui/LoginDialog.cpp
    ../resources/icons.qrc
    widgets/UsersWidget.h
    widgets/CurrenciesWidget.h
    widgets/RequestsAdminWidget.h
)

set(UI
    ui/AdminWindow.cpp
    ui/AdminWindow.h
    ui/AdminWindow.h
)

source_group("UI" FILES ${UI})

target_link_libraries(admin_app
    common_lib
    Qt6::Widgets
    Qt6::Sql
    pthread
)

target_include_directories(admin_app PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/ui
    ${CMAKE_CURRENT_SOURCE_DIR}/widgets
)
