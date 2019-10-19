#include<iostream>
#include<iostream>
#include<vector>
#include<zmq.hpp>
#include <pqxx/pqxx>

using namespace std;
using namespace pqxx;

namespace db_conn
{
    connection Con("dbname = test user = postgres password = Ctpl@789 \
                hostaddr = 127.0.0.1 port = 5432");
    
}


//using namespace db_conn;
unsigned long int account_count=0,login_count=0,profile_count=0;
class user
{
    private:

        struct profile_collection
        {

            unsigned long int profile_id;
            std::string firstname,lastname,gender,passport_number,other_id,other_id_type,ssn,date_of_birth,address1,address2,city,state,country,phone_number,nationality,zipcode,email_id,last_update_time;
            bool agree_for_news_letter;

            void load()
            {

            }

            void add()
            {

            }

        
        }profile_collection;

        struct account_collection
        {
        
            unsigned long int account_id,account_type_id;
            std::string account_name,currency_id,email_id,remarks,account_creation_date;
            long double balance;
            bool account_enabled;

            void load()
            {
                try
                {
                    nontransaction N(db_conn::Con);

                    string select_account = "SELECT * from select_account()";
                    
                    result C( N.exec( select_account ));
                    
                    /* List down all the records */
                    for (result::const_iterator c = C.begin(); c != C.end(); ++c) 
                    {
                        
                        account_id = c[0].as<long int>();
                        account_type_id = c[1].as<long int>();
                        account_name = c[2].as<string>();
                        account_enabled = c[3].as<bool>();
                        account_creation_date = c[4].as<long int>();
                        balance = c[5].as<long double>();
                        remarks = c[6].as<string>();
                        currency_id = c[0].as<string>();
                        email_id = c[0].as<string>();
                        
                        ::account_count++;
                    }
                }
                catch(const std::exception& e)
                {
                std::cerr << "Error :: in Loading Account ::" << e.what() << '\n';
                }               
            }
            
            void add()
            {

            }

        }account_collection;

        struct login_collection
        {

            unsigned long int user_id,user_type_id,login_count=0;
            std::string username,password,transaction_password,user_type,created_time;
            bool user_enabled;
            
            void load()
            {
                try
                {
                    string select_user = "SELECT * from user_login"; //select_user();
                        
                        
                    nontransaction N(db_conn::Con);

                    result A( N.exec( select_user ));

                    /* List down all the records */
                    for (result::const_iterator c = A.begin(); c != A.end(); ++c) 
                    {

                        user_id = c[0].as<long int>();
                        username = c[1].as<string>();
                        password = c[2].as<string>();
                        transaction_password = c[3].as<string>();
                        user_enabled = c[4].as<bool>();
                        created_time = c[5].as<string>();
                        user_type_id = c[6].as<long int>();
                        
                        cout<< user_id <<endl;
                        cout<< username <<endl;
                        cout<< password <<endl;
                        cout<< transaction_password <<endl;
                        cout<< user_enabled <<endl;
                        cout<< created_time <<endl;
                        cout<< user_type_id <<endl;

                        ::login_count++;

                    }
                }
                catch(const std::exception& e)
                {
                    std::cerr << " ERROR :: IN LOADING PROFILE " << e.what() << '\n';
                }
                
            }

            void add()
            {
                
            }
                
        }login_collection;

    public:
        void onStart()
        {
            account_collection.load();
            profile_collection.load();
            login_collection.load();
        }
    
};

int main()
{
   user usr;
   
   usr.onStart();

   return 0;
}