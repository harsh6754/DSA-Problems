#include <bits/stdc++.h>
#include <mysql/mysql.h>
using namespace std;

int main() {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    const char *server = "localhost";
    const char *user = "root";
    const char *password = "password"; /* set your database password */
    const char *database = "your_database"; /* set your database name */

    conn = mysql_init(NULL);

    if (!mysql_real_connect(conn, server, user, password, database, 0, NULL, 0)) {
        std::cerr << "mysql_real_connect() failed\n";
        return EXIT_FAILURE;
    }

    string query;
    cout << "Enter the SQL query: ";
    getline(cin, query);

    if (mysql_query(conn, query.c_str())) {
        std::cerr << "Query failed. Error: " << mysql_error(conn) << std::endl;
        return EXIT_FAILURE;
    }

    res = mysql_store_result(conn);

    if (res == NULL) {
        std::cerr << "mysql_store_result() failed. Error: " << mysql_error(conn) << std::endl;
        return EXIT_FAILURE;
    }

    int num_fields = mysql_num_fields(res);
    while ((row = mysql_fetch_row(res)) != NULL) {
        for(int i = 0; i < num_fields; i++) {
            cout << (row[i] ? row[i] : "NULL") << " ";
        }
        cout << endl;
    }

    mysql_free_result(res);
    mysql_close(conn);

    return EXIT_SUCCESS;
}
