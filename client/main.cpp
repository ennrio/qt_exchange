#include "ui/MainWindow.h"
#include "../common/database/DatabaseManager.h"
#include <QApplication>
#include "ui/LoginDialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Инициализация БД
    if (!DatabaseManager::instance().initialize()) {
        qCritical() << "Failed to initialize database!";
        return 1;
    }
    LoginDialog loginDialog;
    if (loginDialog.exec() != QDialog::Accepted) {
        return 0; // выход, если не вошли
    }

    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
