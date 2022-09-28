#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<stdlib.h>
using namespace std;
class customer
{
  protected:
  string cus_id,cus_name,item_name;
  int qty;
  float item_price,tot_cost;
  public:
    void set_customer(string,string,string,int,float);
    void calculate_cost();
    void cus_details_show();
    void store_customer_details();
    void search_customer_data();


};
class silver_customer:public customer
{
    float dis_rate,dis_amount,final_cost;
public:
    void set_dis_rate(string,string,string,int,float);
    void calculate_discount();
    void discount_show();
    void store_silver_customer_details();
    void search_silver_customer_details();
};

class worker
{
protected:
    string emp_id,emp_name;
    float b_salary,net_salary,allowance;
public:
    void set_worker(string,string,float,float);
    void worker_sal_calculate();
    void worker_sal_show();
    void store_worker_details();
    void search_worker_details();



};
class hourly_pay_worker:public worker
{
    float hours;
   static float hourly_charge;
    public:
    void set_worker(string,string,float);
    void hourly_sal_calculate();
    void show_hourly_pay_worker();
    void store_hourly_pay_worker_details();
    void search_hourly_pay_worker_details();
};
class product
{
    string pro_id,pro_name;
    int qty_out,sold_qty,manu_qty;
public:
    void set_product_value();
    void qty_out_calculate();
    void show_product_qty();
    void store_product_details();
    void search_product_data();



};

class login
{
    string user_name;
    string password;
public:
    void enter_data();
};


void customer::set_customer(string cus_id,string cus_name,
string item_name,int qty,float item_price)
{
    this->cus_id=cus_id;
    this->cus_name=cus_name;
    this->item_name=item_name;
    this->qty=qty;
    this->item_price=item_price;
}
void customer::calculate_cost()
{
    tot_cost=item_price*qty;
}
void customer::cus_details_show()
{   //cout<<"Customer ID :- "<<cus_id<<endl;
   // cout<<"Customer name:-"<<cus_name<<endl;
   // cout<<"Item name   :- "<<item_name<<endl;
    //cout<<"Quantity    :- "<<qty<<endl;
    //cout<<"Item Price  :- "<<item_price<<endl;
    cout<<"Total Cost  :- "<<tot_cost<<endl<<endl;
}
void customer::store_customer_details()
{
    fstream customer_details;
    customer_details.open("Customer_details.txt",ios::app);
    customer_details<<setw(10)<<cus_id<<setw(20)<<cus_name<<setw(30)<<item_name<<setw(30)<<qty<<setw(30)<<item_price<<setw(30)<<tot_cost<<endl;
}

void customer::search_customer_data()
{   int snumber;
    string custo_id;
    fstream search_customer;
    search_customer.open("Customer_details.txt",ios::in);
    cout<<endl<<endl<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t"<<"Enter the customer ID to search : ";
    cin>>custo_id;
    while(search_customer)
    {   search_customer>>cus_id>>cus_name>>item_name>>qty>>item_price>>tot_cost;
        if(custo_id==cus_id)
        {
        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
        cout<<"\t\t\t\t\t"<<"customer ID"<<"\t"<<"customer name"<<"\t"<<"item name"<<"\t"<<"quantity"<<"\t"<<"item price"<<"\t"<<"total cost"<<endl;
        cout<<"\t\t\t\t\t"<<"  "<<cus_id<<"\t\t"<<cus_name<<"\t\t"<<item_name<<"\t\t"<<qty<<"\t\t"<<item_price<<"\t\t"<<tot_cost<<endl<<endl;
        break;
        } else
        {
            cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
            cout<<"\t\t\t\t\t\t\t"<<"NO Customer like this !"<<endl;
            break;
        }
    }

}
void silver_customer::set_dis_rate(string cus_id,string cus_name,string item_name,int qty,float item_price)
{
    this->cus_id=cus_id;
    this->cus_name=cus_name;
    this->item_name=item_name;
    this->qty=qty;
    this->item_price=item_price;
    cout<<"Enter the Discount rate : ";
    cin>>dis_rate;
}
void silver_customer::calculate_discount()
{
    tot_cost=qty*item_price;
    dis_amount=tot_cost*dis_rate/100;
    final_cost=tot_cost-dis_amount;
}
void silver_customer::discount_show()
{

    //cout<<"Customer ID :- "<<cus_id<<endl;
    //cout<<"Customer name:-"<<cus_name<<endl;
    //cout<<"Item name   :- "<<item_name<<endl;
    //cout<<"Quantity    :- "<<qty<<endl;
    //cout<<"Item Price  :- "<<item_price<<endl;
    cout<<"---You have a special discount--- :- "<<dis_amount<<endl;
    cout<<"Final Cost  :- "<<final_cost<<endl;


}
void silver_customer::store_silver_customer_details()
{   string silver_custo_id;
    fstream search_silver_customer;
    fstream silver_customer_details;
    silver_customer_details.open("Silver_customer_details.txt",ios::app);
    silver_customer_details<<setw(10)<< cus_id<<setw(20)<< cus_name<<setw(30)<< item_name<<setw(30)<< qty<<setw(30)<< item_price<<setw(30)<< dis_rate<<setw(30)<<dis_amount<<setw(30)<< final_cost<<endl;
}
void silver_customer::search_silver_customer_details()
{
     int snumber;
    fstream search_silver_customer;
    string silver_custo_id;
    search_silver_customer.open("Silver_customer_details.txt",ios::in);
    cout<<endl<<endl<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t"<<"Enter the customer ID to search : ";
    cin>>silver_custo_id;
    while(search_silver_customer)
    {   search_silver_customer>>cus_id>>cus_name>>item_name>>qty>>item_price>>dis_rate>>dis_amount>>final_cost;
        if(silver_custo_id==cus_id)
        {
        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
        cout<<"customer ID"<<"\t"<<"customer name"<<"\t"<<"item name"<<"\t"<<"quantity"<<"\t"<<"item price"<<"\t\t"<<"discount rate(%)"<<"\t\t"<<"discount amount(LKR)"<<"\t\t"<<"Final cost(LKR)"<<endl;
        cout<<cus_id<<"\t\t"<<cus_name<<"\t\t"<<item_name<<"\t\t"<<qty<<"\t\t"<<item_price<<"\t\t\t"<<dis_rate<<"\t\t\t\t"<<dis_amount<<"\t\t\t\t"<<final_cost<<endl<<endl;
        break;
        }else
        {   cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
            cout<<"\t\t\t\t\t\t\t"<<"NO Silver Customer like this !"<<endl;
            break;
        }
    }
}

void worker::set_worker(string emp_id,string emp_name,float b_salary,float allowance)
{

    this -> emp_id=emp_id;
    this -> emp_name=emp_name;
    this -> b_salary=b_salary;
    this -> allowance=allowance;

}

void worker::worker_sal_calculate()
{
    net_salary=b_salary+allowance;
}
void worker::worker_sal_show()
{
    cout<<"net salary : "<<net_salary<<endl;
}
void worker::store_worker_details()
{
    fstream worker_details;
    worker_details.open("worker_details.txt",ios::app);
    worker_details<<setw(10)<<emp_id<<setw(20)<< emp_name <<setw(20)<<b_salary<<setw(20)<< allowance<<setw(20)<<net_salary<<endl;
}
void worker::search_worker_details()
{
    fstream search_workers_details;
    string worker_emp_id;
    search_workers_details.open("worker_details.txt",ios::in);
    cout<<endl<<endl<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t"<<"Enter the Employee ID to search : ";
    cin>>worker_emp_id;
    while(search_workers_details)
    {   search_workers_details>>emp_id>>emp_name>>b_salary>>allowance>>net_salary;
        if(worker_emp_id==emp_id)
        {
        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
        cout<<"\t\t\t\t\t"<<"employee ID"<<"\t"<<"employee name"<<"\t"<<"B_Salary"<<"\t"<<"allowance"<<"\t"<<"Net Salary"<<endl;
        cout<<"\t\t\t\t\t"<<"  "<<emp_id<<"\t\t"<<emp_name<<"\t\t"<<b_salary<<"\t\t"<<allowance<<"\t\t"<<net_salary<<endl<<endl;
        break;
        }else
        {
            cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
            cout<<"\t\t\t\t\t\t\t"<<"NO worker like this !"<<endl;
            break;
        }
    }
}

void hourly_pay_worker::set_worker(string emp_id,string emp_name,float hours)
{
    this -> emp_id=emp_id;
    this -> emp_name=emp_name;
    this -> hours=hours;
    this ->hourly_charge=hourly_charge;

}
float hourly_pay_worker::hourly_charge=100;

void hourly_pay_worker::hourly_sal_calculate()
{
  net_salary=hourly_charge*hours;
}
void hourly_pay_worker::show_hourly_pay_worker()
{
    cout<<"net salary :"<<net_salary<<endl;
}
void hourly_pay_worker::store_hourly_pay_worker_details()
{
   fstream hourly_pay_worker_details;
   hourly_pay_worker_details.open("hourly_pay_worker_details.txt",ios::app);
   hourly_pay_worker_details<<setw(10)<< emp_id<<setw(20)<<emp_name<<setw(20)<< hours<<setw(20)<<net_salary<<endl;
}
void hourly_pay_worker::search_hourly_pay_worker_details()
{
    string hourly_pay_worker_id;
    fstream search_hourly_pay_worker;
    search_hourly_pay_worker.open("hourly_pay_worker_details.txt",ios::in);
    cout<<endl<<endl<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t"<<"Enter the Employee ID to search : ";
    cin>>hourly_pay_worker_id;
    while(search_hourly_pay_worker)
    {   search_hourly_pay_worker>>emp_id>>emp_name>>hours>>net_salary;
        if(hourly_pay_worker_id==emp_id)
        {
        cout<<endl<<endl<<endl<<endl<<endl<<endl;

        cout<<" "<<"#####:-Default Hourly charge is  "<<"\""<<hourly_charge<<"\""<<"-:#####"<<endl<<endl;
        cout<<"\t\t\t\t\t"<<"employee ID"<<"\t"<<"employee name"<<"\t"<<"No of Hours"<<"\t"<<"\t"<<"Net Salary"<<endl;
        cout<<"\t\t\t\t\t"<<"  "<<emp_id<<"\t\t"<<emp_name<<"\t\t"<<hours<<"\t\t\t"<<net_salary<<endl<<endl;
        break;
        }else
        {
            cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
            cout<<"\t\t\t\t\t\t\t"<<"NO hourly pay worker like this !"<<endl;
            break;
        }
    }

}

void product::set_product_value()
{
    cout<<"Enter the product ID             : ";
    cin>>pro_id;
    cout<<"Enter the product Name           : ";
    cin>>pro_name;
    cout<<"Enter the manufactured quantity  : ";
    cin>>manu_qty;
    cout<<"this is the sold quantity        : ";
    cin>>sold_qty;


}
void product::qty_out_calculate()
{
   qty_out=manu_qty-sold_qty;
}
void product::show_product_qty()
{
    cout<<"quantity outstanding : "<<qty_out<<endl;
}
void product::store_product_details()
{
    fstream product_details;
  product_details.open("product_details.txt",ios::app);
  product_details<<setw(10)<< pro_id<<setw(20)<<pro_name<<setw(20)<< manu_qty<<setw(20)<<sold_qty<<setw(20)<<qty_out<<endl;
}
void product::search_product_data()
{
    string prod_id;
    fstream search_product;
    search_product.open("product_details.txt",ios::in);
    cout<<endl<<endl<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t"<<"Enter the product ID to search : ";
    cin>>prod_id;
    while(search_product)
    {   search_product>>pro_id>>pro_name>>manu_qty>>sold_qty>>qty_out;
        if(prod_id==pro_id)
        {
        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
        cout<<"\t\t\t\t\t"<<"product ID"<<"\t"<<"product name"<<"\t"<<"manufactured qty"<<"\t"<<"sold quantity"<<"\t"<<"quantity outstanding"<<endl;
        cout<<"\t\t\t\t\t"<<"  "<<pro_id<<"\t\t"<<pro_name<<"\t\t"<<manu_qty<<"\t\t\t"<<sold_qty<<"\t\t"<<qty_out<<endl<<endl;
        break;
        }else
        {
            cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
            cout<<"\t\t\t\t\t\t\t"<<"NO product like this !"<<endl;
            break;
        }
    }

}

void login::enter_data()
{   cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t"<<"User Name : ";
    cin>>user_name;
    system("CLS");
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t"<<"Password : ";
    cin>>password;
    system("CLS");

    if(user_name=="A"&& password=="1")
    {
    int number;
    char text;

    while(text!='y'&&text!='Y')


    {


                cout<<"\t\t\t\t\t\t"<<"********************YASODHANA CONCREET FACTORY********************"<<endl;
                cout<<"\t\t\t\t\t\t"<<"                    NO:546/5, IHALABIYANVILA, KADAWATHA"<<endl;
                cout<<"\t\t\t\t\t\t"<<"                  TEL-:0112345678/MOBILE-:0712345678"<<endl<<endl<<endl<<endl<<endl;
                cout<<"\t\t\t\t\t\t"<<"1  ::-> Customer Details and Transaction Details"<<endl;
                cout<<"\t\t\t\t\t\t"<<"2  ::-> Silver Customer Details and Transaction Details"<<endl;
                cout<<"\t\t\t\t\t\t"<<"3  ::-> Normal Workers Details"<<endl;
                cout<<"\t\t\t\t\t\t"<<"4  ::-> Hourly payment workers Details"<<endl;
                cout<<"\t\t\t\t\t\t"<<"5  ::-> product Details"<<endl;
                cout<<"\t\t\t\t\t\t"<<"6  ::-> Search customer"<<endl;
                cout<<"\t\t\t\t\t\t"<<"7  ::-> Search  silver customer"<<endl;
                cout<<"\t\t\t\t\t\t"<<"8  ::-> Search worker"<<endl;
                cout<<"\t\t\t\t\t\t"<<"9  ::-> Search hourly worker"<<endl;
                cout<<"\t\t\t\t\t\t"<<"10 ::-> Search product"<<endl;
                cout<<"\t\t\t\t\t\t"<<"11 ::-> EXIT"<<endl;
                cout<<"Enter your choice :: ";
                cin>>number;

                system("CLS");
                 if(number==1)
    {
        string a,b,c;
        int d;
        float e;
    cout<<"enter cus_Id      : ";
    cin>>a;
    cout<<"enter cus_name    : ";
    cin>>b;
    cout<<"enter item_name   : ";
    cin>>c;
    cout<<"enter  qty        : ";
    cin>>d;
    cout<<"enter item_price  : ";
    cin>>e;
    customer C1;
    C1.set_customer(a,b,c,d,e);
    C1.calculate_cost();
    C1.cus_details_show();
    C1.store_customer_details();
    }
    else if(number==2)
    {
        string a,b,c;
    int d;
    float e;
    cout<<"enter cus_Id     : ";
    cin>>a;
    cout<<"enter cus_name   : ";
    cin>>b;
    cout<<"enter item_name  : ";
    cin>>c;
    cout<<"enter  qty       : ";
    cin>>d;
    cout<<"enter item_price : ";
    cin>>e;

    silver_customer SC1;
    SC1.set_dis_rate(a,b,c,d,e);
    SC1.calculate_discount();
    SC1.discount_show();
    SC1.store_silver_customer_details();
    }
    else if(number==3)
    {
    string a,b;
    float c,d;
    cout<<"Enter the Employee ID   : ";
    cin>>a;
    cout<<"Enter the Employee Name : ";
    cin>>b;
    cout<<"Enter the Basic Salary  : ";
    cin>>c;
    cout<<"Enter the Allowance     : ";
    cin>>d;
    worker wr1;
    wr1.set_worker(a,b,c,d);
    wr1.worker_sal_calculate();
    wr1.worker_sal_show();
    wr1.store_worker_details();
    }
    else if(number==4)
    {
    string a,b;
    float c;
    cout<<"Enter Employee ID   : ";
    cin>>a;
    cout<<"Enter Employee Name : ";
    cin>>b;
    cout<<"Enter No of Hours   : ";
    cin>>c;
    hourly_pay_worker hpw1;
    hpw1.set_worker(a,b,c);
    hpw1.hourly_sal_calculate();
    hpw1.show_hourly_pay_worker();
    hpw1.store_hourly_pay_worker_details();
    }
    else if(number == 5)
    {
        product p;
        p.set_product_value();
        p.qty_out_calculate();
        p.show_product_qty();
        p.store_product_details();

    }
    else if(number==6)
    {
        customer C1;
        C1.search_customer_data();
    }
    else if(number==7)
    {
        silver_customer SC1;
        SC1.search_silver_customer_details();
    }
    else if(number==8)
    {
        worker wr1;
        wr1.search_worker_details();
    }
    else if(number==9)
    {
        hourly_pay_worker hpw1;
        hpw1.search_hourly_pay_worker_details();
    }
    else if(number==10)
    {
      product p;
      p.search_product_data();
    }
    cout<<"IF you want stop press 'y' otherwise press 'n' : ";
    cin>>text;
    }

}else
while(user_name!="A" || password!="1")
{

    {
        cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t"<<"INVALID USER NAME OR PASSWORD! TRY AGAIN!"<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t"<<"User Name : ";
    cin>>user_name;
    system("CLS");
    cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    cout<<"\t\t\t\t\t\t\t\t\t"<<"Password : ";
    cin>>password;
    system("CLS");

    if(user_name=="A"&& password=="1")
    {
    int number;
    char text;

    while(text!='y'&&text!='Y')


    {


                cout<<"\t\t\t\t\t\t"<<"********************YASODHANA CONCREET WORKTATION********************"<<endl;
                cout<<"\t\t\t\t\t\t"<<"                    NO:546/5, IHALABIYANVILA, KADAWATHA"<<endl;
                cout<<"\t\t\t\t\t\t"<<"                  TEL-:0112345678/MOBILE-:0712345678"<<endl<<endl<<endl<<endl<<endl;
                cout<<"\t\t\t\t\t\t"<<"1  ::-> Customer Details and Transaction Details"<<endl;
                cout<<"\t\t\t\t\t\t"<<"2  ::-> Silver Customer Details and Transaction Details"<<endl;
                cout<<"\t\t\t\t\t\t"<<"3  ::-> Normal Workers Details"<<endl;
                cout<<"\t\t\t\t\t\t"<<"4  ::-> Hourly payment workers Details"<<endl;
                cout<<"\t\t\t\t\t\t"<<"5  ::-> product Details"<<endl;
                cout<<"\t\t\t\t\t\t"<<"6  ::-> Search customer"<<endl;
                cout<<"\t\t\t\t\t\t"<<"7  ::-> Search silver customer"<<endl;
                cout<<"\t\t\t\t\t\t"<<"8  ::-> Search worker"<<endl;
                cout<<"\t\t\t\t\t\t"<<"9  ::-> Search hourly worker"<<endl;
                cout<<"\t\t\t\t\t\t"<<"10 ::-> Search product"<<endl;
                cout<<"\t\t\t\t\t\t"<<"11 ::-> EXIT"<<endl;
                cout<<"Enter your choice :: ";
                cin>>number;

                system("CLS");
                 if(number==1)
    {
        string a,b,c;
        int d;
        float e;
    cout<<"enter cus_Id      : ";
    cin>>a;
    cout<<"enter cus_name    : ";
    cin>>b;
    cout<<"enter item_name   : ";
    cin>>c;
    cout<<"enter  qty        : ";
    cin>>d;
    cout<<"enter item_price  : ";
    cin>>e;
    customer C1;
    C1.set_customer(a,b,c,d,e);
    C1.calculate_cost();
    C1.cus_details_show();
    C1.store_customer_details();
    }
    else if(number==2)
    {
        string a,b,c;
    int d;
    float e;
    cout<<"enter cus_Id     : ";
    cin>>a;
    cout<<"enter cus_name   : ";
    cin>>b;
    cout<<"enter item_name  : ";
    cin>>c;
    cout<<"enter  qty       : ";
    cin>>d;
    cout<<"enter item_price : ";
    cin>>e;

    silver_customer SC1;
    SC1.set_dis_rate(a,b,c,d,e);
    SC1.calculate_discount();
    SC1.discount_show();
    SC1.store_silver_customer_details();
    }
    else if(number==3)
    {
    string a,b;
    float c,d;
    cout<<"Enter the Employee ID   : ";
    cin>>a;
    cout<<"Enter the Employee Name : ";
    cin>>b;
    cout<<"Enter the Basic Salary  : ";
    cin>>c;
    cout<<"Enter the Allowance     : ";
    cin>>d;
    worker wr1;
    wr1.set_worker(a,b,c,d);
    wr1.worker_sal_calculate();
    wr1.worker_sal_show();
    wr1.store_worker_details();
    }
    else if(number==4)
    {
    string a,b;
    float c;
    cout<<"Enter Employee ID   : ";
    cin>>a;
    cout<<"Enter Employee Name : ";
    cin>>b;
    cout<<"Enter No of Hours   : ";
    cin>>c;
    hourly_pay_worker hpw1;
    hpw1.set_worker(a,b,c);
    hpw1.hourly_sal_calculate();
    hpw1.show_hourly_pay_worker();
    hpw1.store_hourly_pay_worker_details();
    }
     else if(number == 5)

    {

        product P;
        P.set_product_value();
        P.qty_out_calculate();
        P.show_product_qty();
        P.store_product_details();

    }
    else if(number==6)
    {
        customer C1;
        C1.search_customer_data();
    }
    else if(number==7)
    {
        silver_customer SC1;
        SC1.search_silver_customer_details();
    }
    else if(number==8)
    {
        worker wr1;
        wr1.search_worker_details();
    }
    else if(number==9)
    {
        hourly_pay_worker hpw1;
        hpw1.search_hourly_pay_worker_details();
    }
    else if (number==10)
    {
        product p;
        p.search_product_data();
    }
    cout<<"IF you want stop press 'y' otherwise press 'n' : ";
    cin>>text;
    }
}
    }
}
}



int main()
{

    login public_login;
    public_login.enter_data();






  /*customer C1;
    C1.set_customer("C002","SUPARA","STATURE",20,200);
    C1.calculate_cost();
    C1.cus_details_show();
    C1.store_customer_details();*/

    /*string a,b,c;
    int d;
    float e;
    cout<<"enter cus_Id : ";
    cin>>a;
    cout<<"enter cus_name : ";
    cin>>b;
    cout<<"enter item_name : ";
    cin>>c;
    cout<<"enter  qty : ";
    cin>>d;
    cout<<"enter item_price : ";
    cin>>e;

    silver_customer SC1;
    SC1.set_dis_rate(a,b,c,d,e);
    SC1.calculate_discount();
    SC1.discount_show();
    SC1.store_silver_customer_details();*/


    /*hourly_pay_worker hpw1;
    hpw1.set_worker("E001","RANI",10);
    hpw1.hourly_sal_calculate();
    hpw1.show_hourly_pay_worker();*/

    /*worker wr1;
    wr1.set_worker("E001","RUWAN",25000,1000);
    wr1.worker_sal_calculate();
    wr1.worker_sal_show();*/

    return 0;
}
