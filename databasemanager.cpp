#include "Databasemanager.h"

DatabaseManager::DatabaseManager(QString path)
{
    DB = new Database(path);
    DB->DatabaseToRestaurants();
}
