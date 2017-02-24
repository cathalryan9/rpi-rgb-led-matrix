#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "../include/bld/sqlite3.h"
#include <unistd.h>
#include <string>

#include <iostream>
using namespace std;

//#define ENABLE_DB_TRANSACTION
#define BUFFER_SIZE 256

//void
//update_callback ( void *user_data, int operation_type,
//char const *database, char const *table, sqlite3_int64 rowid)
//{
//    //printf("bahhhh\n");
//    printf ("\n Operation type – %d \n Database – %s\n Table – %s\n  User-Data – %s \n",
//    operation_type, database, table, (char *)user_data);
//
//
//}
////

sqlite3 *dbc = NULL;
sqlite3_stmt *stmt     = NULL;
char *zErrMsg = "neeeeeeeh";
std::string sql = "";
char buf[BUFFER_SIZE] = {0};
char *path_to_db = "../../rave.db";

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




