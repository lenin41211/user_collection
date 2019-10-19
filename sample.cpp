#include<iostream>
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
    }acc_struct;

    account get_details_by_id()
    {
        user_account acc_obj;
        struct account acc;
    }
    
    void add()
    {
        user_account usr_acc[10];    
        usr_acc[count].acc_struct.account_id = 12345;
        usr_acc[count].acc_struct.account_type_id = 541321;
        count++; 
    }
    void view()
    {

    }
};
int main()
{
    return 0;
}