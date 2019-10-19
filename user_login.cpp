#include<iostream>
#include <zmq.hpp>

#include"database_conn.hpp"

using namespace std;
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

        socket.bind ("tcp://*:5556");
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