#include<iostream>
#include<string>
#include<fstream>
#include<stdio.h>

using namespace std;
class Customer
{
	
public:
	string name;
	int accno;
	string type;
	float balance;

	string trimfnc(string str) {
const char* typeOfWhitespaces = " \t\n\r\f\v";
str.erase(str.find_last_not_of(typeOfWhitespaces) + 1);
str.erase(0,str.find_first_not_of(typeOfWhitespaces));
return str;
}
	void input()
	{
		
		Customer C;
	  cin.ignore();
		cout<<"Customer Name : ";
		getline(cin,C.name);
		cout<<"Type of Account: ";cin>>C.type;
		cout<<"Balance : ";cin>>C.balance;
		ifstream fin("Account.dat");
		if(!fin)
		{
			ofstream fn("Names.txt",ios::app | ios::binary);
			ofstream fy("Types.txt",ios::app | ios::binary);
			ofstream fb("Balance.txt",ios::app | ios::binary);
			ofstream fout("Account.dat",ios::app);
			int acc=1234567890;
			C.name.resize(50,' ');
			C.accno=acc;
			fout<<C.accno;
			fout<<endl;
			fout.close();
			fin.close();
            fn<<C.name;
            fn<<endl;
		    fy<<C.type;
		    fy<<endl;
		    fb<<C.balance;
		    fb<<endl;
			fn.close();
			fy.close();
			fb.close();
			cout<<"Your Account Number is "<<acc<<endl;
		}
		else
		{
		    ofstream fn("Names.txt",ios::app | ios::binary);
			ofstream fy("Types.txt",ios::app | ios::binary);
			ofstream fb("Balance.txt",ios::app | ios::binary);
			fn.seekp(0,ios::beg);
			fy.seekp(0,ios::beg);
			fb.seekp(0,ios::beg);
			int acc;
			fin.seekg(0);
			short n=1;
			while(!fin.eof())
            {
				fin>>acc;
				if(fin.eof())
				break;
			}
		

			C.accno=acc+1;
			fin.close();
			ofstream fout("Account.dat",ios::app);
			fout.seekp(0,ios::beg);
			fout<<C.accno;
			fout<<endl;
			fout.close();
		    fn<<C.name;
		    fn<<endl;
		    fy<<C.type;
		    fy<<endl;
		    fb<<C.balance;
		    fb<<endl;
		
			fn.close();
			fy.close();
			fb.close();
			cout<<"Your Account Number is "<<C.accno<<endl;
		}
		
	}
	int check(int acc)
	{
		int temp,flag=1,record=0;
		ifstream fin("Account.dat");
		if(!fin)
		{
			
			return -1;
		}
		fin.seekg(0);
		while(flag && !fin.eof())
		{
			fin>>temp;
       record++;
			if(temp==acc)
		 {	
       flag=0;
      }
		}
   
		fin.close();
		if(flag==0)
		return record-1;
		else
		return -1;
	}

};
class Bank 
{
	Customer C;
	public:
		void addAccount()
		{
			C.input();
			cout<<endl;
		}
		void deposit()
		{
			float amt;
			int acc;
			string str,t;
			float b;
			Customer C;
			cout<<"Enter the account Number of Account Holder"<<endl;
      cin>>acc;

			short i=C.check(acc);
			cout<<endl;
      if(i==-1)
      {
        cout<<"*****************Account doesn't Exist******************";
        cout<<endl;
		return;
      }
    
      int j=i;
		fstream fn("Names.txt",ios::in | ios::out | ios::binary);
		fstream fy("Types.txt",ios:: in | ios::out | ios::binary);
		fstream fb("Balance.txt",ios::in | ios::out | ios ::binary);
        if(!fn)
         {
            cout<<"No files";
            return ;
         }
		fn.seekg(0);
		fy.seekg(0);
		fb.seekg(0);
		while(i!=-1)	
		{
		getline(fn,str);
			fy>>t;
			fb>>b;
            if(fn.eof())
                break;
            if(fy.eof())
              break;
            if(fb.eof())
               break;
            i=i-1;
            
			}

   
   fb.seekp(0);
  
   
   fb.seekp(j*sizeof(float),ios::beg);
 str=C.trimfnc(str);
      cout<<"Enter the ammount to be deposited "<<str<<" :";
   cin>>amt;
   b+=amt;
  
   if(j==0)
   {
   	fb<<b;
   }
   else
   {
   fb<<endl;
   fb<<b;}
      fn.close();
      fy.close();
      fb.close();
      cout<<endl;
      cout<<"Your updated balance is : Rs"<<b;
      cout<<endl;
      
		}
	void withdraw()
	{
			float amt;
			int acc;
			string str,t;
			float b;
			Customer C;
			cout<<"Enter the account Number of Account Holder"<<endl;
      cin>>acc;

			short i=C.check(acc);
      if(i==-1)
      {
        cout<<"Account doesn't Exist";
        cout<<endl;
        return;
      }
  
      int j=i;
		fstream fn("Names.txt",ios::in | ios::out | ios::binary);
		fstream fy("Types.txt",ios:: in | ios::out | ios::binary);
		fstream fb("Balance.txt",ios::in | ios::out | ios ::binary);
        if(!fn)
         {
            cout<<"No files";
            return ;
         }
		fn.seekg(0);
		fy.seekg(0);
		fb.seekg(0);
		while(i!=-1)	
		{
		getline(fn,str);
			fy>>t;
			fb>>b;
            if(fn.eof())
                break;
            if(fy.eof())
              break;
            if(fb.eof())
               break;
            i=i-1;
            
			}
   
   
   fb.seekp(0);
  
   fb.seekp(j*sizeof(float),ios::beg);
   str=C.trimfnc(str);
      cout<<"Enter the ammout to be Withdrawn "<<str<<" :";
   cin>>amt;
   b-=amt;
 
   if(j==0)
   {
   	fb<<b;
   }
   else
   {
   fb<<endl;
   fb<<b;
   }
      fn.close();
      fy.close();
      fb.close();
      cout<<endl;
      cout<<"Your updated balance is : Rs."<<b<<endl;
      
 
	}
	void Check()
	{
		Customer C;
		int acc;
		cout<<"Enter the account Number of Account Holder"<<endl;
      cin>>acc;
short i=C.check(acc);
      if(i==-1)
      {
        cout<<"**************Account doesn't Exist****************";
        
      }
      else
      {
      	cout<<"***************User has an account in the Bank!!***************";

	  }
	  cout<<endl;
	}
	void balance()
	{
		float amt;
			int acc;
			string str,t;
			float b;
			Customer C;
			cout<<"Enter the account Number of Account Holder"<<endl;
      cin>>acc;
      cout<<endl;

			short i=C.check(acc);
      if(i==-1)
      {
        cout<<"Account doesn't Exist";
        cout<<endl;
        return;
      }
     
      int j=i;
	
		fstream fb("Balance.txt",ios::in | ios::out | ios ::binary);
        if(!fb)
         {
            cout<<"No files";
            return ;
         }
	
		fb.seekg(0);
		while(i!=-1)	
		{
	
			fb>>b;
     
            if(fb.eof())
               break;
            i=i-1;
            
		}
 
   
   fb.seekp(0);
   
   fb.seekp(j*sizeof(float),ios::beg);
   
   if(j==0)
   {
   	fb<<b;
   }
   else
   {
   fb<<endl;
   fb<<b;
   }
     cout<<"Balance is : Rs."<<b;
      fb.close();
      cout<<endl;
	}
    void displayUser()
    {
    	float amt;
			int acc;
			string str,t;
			float b;
			Customer C;
			cout<<"Enter the account Number of Account Holder"<<endl;
      cin>>acc;

			short i=C.check(acc);
      if(i==-1)
      {
        cout<<"Account doesn't Exist";
        cout<<endl;
        return;
      }
     
      int j=i;
		fstream fn("Names.txt",ios::in | ios::out | ios::binary);
		fstream fy("Types.txt",ios:: in | ios::out | ios::binary);
		fstream fb("Balance.txt",ios::in | ios::out | ios ::binary);
        if(!fn)
         {
            cout<<"No files";
            return ;
         }
		fn.seekg(0);
		fy.seekg(0);
		fb.seekg(0);
		while(i!=-1)	
		{
		getline(fn,str);
			fy>>t;
			fb>>b;
            if(fn.eof())
                break;
            if(fy.eof())
              break;
            if(fb.eof())
               break;
            i=i-1;
            
			}
   
  str=C.trimfnc(str);
cout<<"            Account Holder : "<<str<<endl;
cout<<"            Type of account : "<<t<<endl;
cout<<"            Balance : Rs."<<b<<endl;
      fn.close();
      fy.close();
      fb.close();
      cout<<endl;
	}
	void displayAll()
     {   
	  
		string str,t;
		float b;
			
		fstream fn("Names.txt",ios::in | ios::out | ios::binary);
		fstream fy("Types.txt",ios:: in | ios::out | ios::binary);
		fstream fb("Balance.txt",ios::in | ios::out | ios ::binary);
        if(!fn)
         {
            cout<<"No files";
            return ;
         }
		fn.seekg(0);
		fy.seekg(0);
		fb.seekg(0);
		cout<<"Name             "<<"   Type of Account  "<<"   Balance  "<<endl<<endl;
		int i=1;
		while(!fn.eof())	
		{
		getline(fn,str);
			fy>>t;
			fb>>b;
            if(fn.eof())
                break;
            if(fy.eof())
              break;
            if(fb.eof())
               break;
     str=C.trimfnc(str);
            cout<<str<<"           ";
			cout<<""<<t<<"         Rs."<<b<<endl;
            
            i+=1;
		}

   
   
      fn.close();
      fy.close();
      fb.close();
      cout<<endl;
     }
     void updateName()
     {
     	string name;
			int acc;
			string str,t;
			float b;
			Customer C;
			cout<<"Enter the account Number of Account Holder"<<endl;
      cin>>acc;
cout<<endl;
			short i=C.check(acc);
      if(i==-1)
      {
        cout<<"Account doesn't Exist";
        cout<<endl;
        return;
      }
  
      int j=i;
		fstream fn("Names.txt",ios::in | ios::out | ios::binary);
		fstream fy("Types.txt",ios:: in | ios::out | ios::binary);
		fstream fb("Balance.txt",ios::in | ios::out | ios ::binary);
        if(!fn)
         {
            cout<<"No files";
            return ;
         }
		fn.seekg(0);
		fy.seekg(0);
		fb.seekg(0);
		while(i!=-1)	
		{
		getline(fn,str);
		
            if(fn.eof())
                break;
          
            i=i-1;
            
			}
   
   
   int len=str.length();
  
   fn.seekp(-1,ios::cur);
   fn.seekp(-len,ios::cur);
   cin.ignore();
   str=C.trimfnc(str);
      cout<<"Enter the new name "<<str<<" :";
      getline(cin,name);


 name.resize(50,' ');
fn<<name;
fn<<endl;
   //str.replace()
      fn.close();
      fy.close();
      fb.close();
      cout<<"Updated!!!"<<endl;
      cout<<endl;
       
	 }
};
int main()
{
Bank B;
cout<<"********************************* Welcome to Bank Of Lovely ********************************";
cout<<endl;
cout<<endl;
short flag=0,choice;
char ch;
do
{
cout<<"Choose the option for Banking :";
cout<<endl;
cout<<"1. Add a new account";
cout<<endl;
cout<<"2. Deposit";
cout<<endl;
cout<<"3. Withdraw";
cout<<endl;
cout<<"4. Display Balance";
cout<<endl;
cout<<"5. User details";
cout<<endl;
cout<<"6. Display all user details";
cout<<endl;
cout<<"7. Check if account exists?";
cout<<endl;
cout<<"8. Update name of Account Holdet";
cout<<endl<<endl;
cout<<"Enter your choice"<<endl;
cin>>choice;

switch(choice)
{
	case 1:
		B.addAccount();
		break;
	case 2:
		B.deposit();
		break;
	case 3:
		B.withdraw();
		break;
	case 4:
		B.balance();
		break;
	case 5:
		B.displayUser();
        break;
    case 6:
    	B.displayAll();
    	break;
    case 7:
    	B.Check();
    	break;
    case 8:
    	B.updateName();
    	break;
    default:
	   cout<<"Invalid Choice!! ";
	   	break;
		
}
cout<<endl;

cout<<"Do you want to do some more operations? (y/n)";
cin>>ch;
if(ch=='y')
flag=1;
else
flag=0;
}
while(flag);
cout<<endl;
cout<<"**************************************Thank You For Banking With Us!!!*******************************************";

return 0;
}
