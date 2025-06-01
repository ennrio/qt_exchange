add_executable(client_app
    main.cpp
    ui/MainWindow.cpp
    widgets/ExchangeWidget.cpp
    widgets/RequestsWidget.cpp
    widgets/ProfileWidget.cpp
    ui/LoginDialog.cpp
    ../resources/icons.qrc
)

target_link_libraries(client_app
    common_lib
    Qt6::Widgets
    Qt6::Network
    Qt6::Sql
    pthread
)

target_include_directories(client_app PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/ui
    ${CMAKE_CURRENT_SOURCE_DIR}/widgets
)
