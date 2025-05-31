#include "ui/AdminWindow.h"
#include "common/database/DatabaseManager.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Инициализация БД
    if (!DatabaseManager::instance().initialize()) {
        qCritical() << "Failed to initialize database!";
        return 1;
    }

    AdminWindow adminWindow;
    adminWindow.show();

    return app.exec();
}
