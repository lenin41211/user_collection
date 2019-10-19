#include<iostream>
#include<pqxx/pqxx>

using namespace std;
using namespace pqxx;

namespace db_conn
{
    connection Con("dbname = test user = postgres password = Ctpl@789 \
                hostaddr = 127.0.0.1 port = 5432");
    
}