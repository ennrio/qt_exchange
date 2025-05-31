add_executable(admin_app
    main.cpp
    ui/AdminWindow.cpp
    widgets/UsersWidget.cpp
    widgets/CurrenciesWidget.cpp
    widgets/RequestsAdminWidget.cpp
    ../resources/icons.qrc
)

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
