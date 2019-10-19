#include<iostream>
#include<vector>
#include <zmq.hpp>
#include <pqxx/pqxx>


using namespace std;
using namespace pqxx;

namespace db_conn
{
    connection Con("dbname = test user = postgres password = Ctpl@789 \
                hostaddr = 127.0.0.1 port = 5432");
    
}

//using namespace db_conn;

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

class user_login
{
    public:
        // unsigned long int user_id,user_type_id,created_time;
        // string username,password,transaction_password,user_type;
        // bool user_enabled;
        long int count=0;

    struct login
    {
        unsigned long int user_id,user_type_id;
        std::string username,password,transaction_password,user_type,created_time;
        bool user_enabled;
    
    }lgn_coll[100];
    
    void load_user()
    {
                string select_user = "SELECT * from user_login"; //select_user();
                        
                        
                nontransaction N(db_conn::Con);

                result A( N.exec( select_user ));

                /* List down all the records */
                for (result::const_iterator c = A.begin(); c != A.end(); ++c) 
                {

                    lgn_coll[c[0].as<int>()].user_id = c[0].as<long int>();
                    lgn_coll[c[0].as<int>()].username = c[1].as<string>();
                    lgn_coll[c[0].as<int>()].password = c[2].as<string>();
                    lgn_coll[c[0].as<int>()].transaction_password = c[3].as<string>();
                    lgn_coll[c[0].as<int>()].user_enabled = c[4].as<bool>();
                    lgn_coll[c[0].as<int>()].created_time = c[5].as<string>();
                    lgn_coll[c[0].as<int>()].user_type_id = c[6].as<long int>();
                    
                    cout<< lgn_coll[c[0].as<int>()].user_id <<endl;
                    cout<< lgn_coll[c[0].as<int>()].username <<endl;
                    cout<< lgn_coll[c[0].as<int>()].password <<endl;
                    cout<<lgn_coll[c[0].as<int>()].transaction_password <<endl;
                    cout<< lgn_coll[c[0].as<int>()].user_enabled <<endl;
                    cout<< lgn_coll[c[0].as<int>()].created_time <<endl;
                    cout<< lgn_coll[c[0].as<int>()].user_type_id <<endl;

                    count++;
                }
    }

    void login()
    {
        string word,data,user_name,pwd,socket_id;
        vector<std::string> login_vector;
        std::stringstream data_ss;
        std::stringstream reply_ss;
        
        zmq::context_t context (1);
        zmq::socket_t socket (context, ZMQ_REP);
        zmq::message_t request;

        socket.bind ("tcp://*:5555");
        cout<<"Login Socket Listening at port : 5555"<<endl;
        while (true) {
            
            //  Wait for next request from client
            socket.recv (&request);
            data = (char *) request.data();
            cout<<data<<endl;
            data_ss.str("");
            data_ss<<data;

            while (getline(data_ss, word, ',')) {

				login_vector.push_back(word);
			}
            data_ss.clear();
            socket_id = login_vector[0];
            user_name = login_vector[1];
            pwd = login_vector[2]; 
            login_vector.clear();
            try{

                //string login_func = "SELECT cout(*) from user_login where usernmae = '"+user_name+"' AND password = '"+pwd+"'"; //select_user();
                  string login_func = "select exists(select 1 from user_login where username = '"+user_name+"' and password  = '"+pwd+"')";
                /* Create a non-transactional object. */
                        
                nontransaction N(db_conn::Con);
                result A( N.exec( login_func ));
                reply_ss.str("");
                /* List down all the records */
                for (result::const_iterator c = A.begin(); c != A.end(); ++c) 
                {
                    cout<<c[0].as<bool>()<<endl;
                    if(c[0].as<bool>() == true )
                    {
                        cout<<"login sucess"<<endl;
                        reply_ss<<socket_id<<","<<true;
                        break;
                    }
                    else
                    {
                        cout<<"login failed"<<endl;
                        reply_ss<<socket_id<<","<<false;
                        break;
                    }
                }
            }
            catch (const std::exception &e)
            {
                cerr << "ERROR :: " <<e.what() << std::endl;
            }
            cout<<reply_ss.str().c_str()<<endl;
            zmq::message_t reply ((void*)reply_ss.str().c_str(), reply_ss.str().size());
            socket.send (reply);
            
        }
    }
};


class main_class
{
    public:
        user_login usr_lgn;
        user_profile usr_pro;
        user_account usr_acc;
        
    main_class()
    {
        
        if(db_conn::Con.is_open())
        {
            cout << "Opened database successfully: " << db_conn::Con.dbname() << endl;
        }
        else 
        {
            cout << "Can't open database" << endl;
        }
    }
    
    void onStart()
    {    
        usr_lgn.load_user();
        usr_acc.load_account();
        usr_pro.load_profile();
        usr_lgn.login();        
    
     }
    
};

int main()
{
    main_class m;
    m.onStart();
    //m.login();

    return 0;
}