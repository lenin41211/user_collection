#include<iostream>
#include"database_conn.hpp"

using namespace std;

class user_profile
{
    public:
        // long int profile_id,last_update_time;
        // string firstname,lastname,gender,passport_number,other_id,other_id_type,ssn,date_of_birth,address1,address2,city,state,country,phone_number,nationality,zipcode,email_id;
        // bool agree_for_news_letter;
        long int count=0;

    struct profile
    {
        long int profile_id;
        std::string firstname,lastname,gender,passport_number,other_id,other_id_type,ssn,date_of_birth,address1,address2,city,state,country,phone_number,nationality,zipcode,email_id,last_update_time;
        bool agree_for_news_letter;
    }pro_coll[100];

    void load_profile()
    {
        try
        {
                nontransaction N(db_conn::Con);

                string select_profile = "SELECT * from select_profile()";
                
                result B( N.exec( select_profile ));

                /* List down all the records */
                for (result::const_iterator c = B.begin(); c != B.end(); ++c) 
                {
                
                    pro_coll[c[0].as<int>()].profile_id = c[0].as<long int>();
                    pro_coll[c[0].as<int>()].firstname = c[1].as<string>();
                    pro_coll[c[0].as<int>()].lastname = c[2].as<string>();
                    pro_coll[c[0].as<int>()].gender = c[3].as<string>();
                    pro_coll[c[0].as<int>()].passport_number = c[4].as<string>();
                    pro_coll[c[0].as<int>()].other_id = c[5].as<string>();
                    pro_coll[c[0].as<int>()].other_id_type = c[6].as<string>();
                    pro_coll[c[0].as<int>()].ssn = c[0].as<string>();
                    pro_coll[c[0].as<int>()].date_of_birth = c[1].as<string>();
                    pro_coll[c[0].as<int>()].address1 = c[2].as<string>();
                    pro_coll[c[0].as<int>()].address2 = c[3].as<string>();
                    pro_coll[c[0].as<int>()].city = c[4].as<string>();
                    pro_coll[c[0].as<int>()].state = c[5].as<string>();
                    pro_coll[c[0].as<int>()].state = c[5].as<string>();
                    pro_coll[c[0].as<int>()].state = c[5].as<string>();
                    pro_coll[c[0].as<int>()].state = c[5].as<string>();
                    pro_coll[c[0].as<int>()].country = c[6].as<string>();
                    pro_coll[c[0].as<int>()].nationality = c[0].as<string>();
                    pro_coll[c[0].as<int>()].zipcode = c[1].as<string>();
                    pro_coll[c[0].as<int>()].phone_number = c[2].as<string>();
                    pro_coll[c[0].as<int>()].agree_for_news_letter = c[3].as<bool>();
                    pro_coll[c[0].as<int>()].email_id = c[4].as<string>();
                    pro_coll[c[0].as<int>()].last_update_time = c[5].as<long int>();

                    count++;

                }
        }
        catch(const std::exception& e)
        {
            std::cerr << "Error :: in Loading Profile ::" << e.what() << '\n';
        }
        
    }

};