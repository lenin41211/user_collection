#include<iostream>
#include"database_conn.hpp"

using namespace std;

class user_account
{
    public:
        // unsigned long int account_id,account_type_id,account_creation_date;
        // string account_name,currency_id,email_id,remarks;
        // long double balance;
        // bool account_enabled;
        long int count=0;

    struct account
    {
        unsigned long int account_id,account_type_id;
        std::string account_name,currency_id,email_id,remarks,account_creation_date;
        long double balance;
        bool account_enabled;

    }acc_coll[100];

    account get_details_by_id(int id)
    {
        //user_account acc_obj;
        struct account acc;

        acc.account_id = acc_coll[id].account_id;
        acc.account_type_id = acc_coll[id].account_type_id;
        acc.account_name = acc_coll[id].account_name;
        acc.account_enabled = acc_coll[id].account_enabled;
        acc.account_creation_date = acc_coll[id].account_creation_date;
        acc.balance = acc_coll[id].balance;
        acc.remarks = acc_coll[id].remarks;
        acc.currency_id = acc_coll[id].currency_id;
        acc.email_id = acc_coll[id].email_id;

        return acc;
    }

    void load_account()
    {
        try
        {
            nontransaction N(db_conn::Con);

            string select_account = "SELECT * from select_account()";
            
            result C( N.exec( select_account ));
            
            /* List down all the records */
            for (result::const_iterator c = C.begin(); c != C.end(); ++c) 
            {
                   
                acc_coll[c[0].as<int>()].account_id = c[0].as<long int>();
                acc_coll[c[0].as<int>()].account_type_id = c[1].as<long int>();
                acc_coll[c[0].as<int>()].account_name = c[2].as<string>();
                acc_coll[c[0].as<int>()].account_enabled = c[3].as<bool>();
                acc_coll[c[0].as<int>()].account_creation_date = c[4].as<long int>();
                acc_coll[c[0].as<int>()].balance = c[5].as<long double>();
                acc_coll[c[0].as<int>()].remarks = c[6].as<string>();
                acc_coll[c[0].as<int>()].currency_id = c[0].as<string>();
                acc_coll[c[0].as<int>()].email_id = c[0].as<string>();
                   
                count++;
            }
        }
        catch(const std::exception& e)
        {
           std::cerr << "Error :: in Loading Account ::" << e.what() << '\n';
        }                  
    }
    
}; 