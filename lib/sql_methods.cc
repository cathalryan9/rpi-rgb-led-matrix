#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "../include/sqlite-autoconf-3170000/sqlite3.h"
#include <unistd.h>
#include <string>

#include <iostream>
using namespace std;

//#define ENABLE_DB_TRANSACTION
#define BUFFER_SIZE 256


sqlite3 *dbc = NULL;
sqlite3_stmt *stmt     = NULL;
char *zErrMsg = "neeeeeeeh";
std::string sql = "";
char buf[BUFFER_SIZE] = {0};
char *path_to_db = "../../rave.db";

struct states{
    std::string name;
    std::string value;
    }state;


static int callback(void *unused, int count, char **data, char **columns)
{
    int idx;

    printf("There are %d column(s)\n", count);

    for (idx = 0; idx < count; idx++) {
        printf("The data in column \"%s\" is: %s\n", columns[idx], data[idx]);
    }

    printf("\n");

    return 0;
}
////
void sql_update(std::string table, std::string value, std::string where_stmt ){

    /* ===== Connect to DB ===== */
    printf("About to connect\n");
    int ret = sqlite3_open_v2 (path_to_db, &dbc,
    SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE,
    NULL);
    printf("Opened DB\n");
    sql = "UPDATE " + table + " SET " + value + " WHERE " + where_stmt +";\n" ;
    printf(sql.c_str());

    sqlite3_exec(dbc, sql.c_str(), NULL, 0, &zErrMsg);

    if (dbc)
{
    sqlite3_close_v2 (dbc);
    printf("Closed DB\n");

}
    }

std::string sql_select(std::string table, std::string value, std::string where_stmt ){
    printf("About to connect\n");
    int ret = sqlite3_open_v2 (path_to_db, &dbc,
    SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE,
    NULL);
    printf("Opened DB\n");
    sql = "SELECT " + value + " FROM " + table + " WHERE " + where_stmt +";\n" ;
    printf(sql.c_str());

    sqlite3_exec(dbc, sql.c_str(), callback, NULL, NULL);

    if (dbc)
    {
        sqlite3_close_v2 (dbc);
        printf("Closed DB\n");

    }
    //return state.value
    return "returned";

}




