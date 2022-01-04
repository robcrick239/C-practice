#include<iostream>
#include<string.h>
#include<fstream>
#include<cmath>

using namespace std;

void menu1(){
	cout << "1. Sign In"<<endl;
	cout << "2. Exit" <<endl;
}//endmenu 1

void menu2(){
	cout << "1. Deposit"<<endl;
	cout << "2. Withdraw"<<endl;
	cout << "3. Enquire Balance"<<endl;
	cout << "4. Sign Out"<<endl;
}//endmenu2




int main(){
	int ans;
	
	do{
		cout << "Welcome to Corruption Inc!\n\n ";
		menu1();
		cout << "What would you like to do?"<<endl;
		cin >> ans;
		if(ans==1){
			string fname;
			int pin;
			int choice;
			int check;
			double balance=0;
			double deposit;
			double withdraw;
			
			fstream pointer;
			pointer.open("Data.txt");
			
		
			cout << "Please enter your name..."<<endl;
			cin >> fname;
	
			cout << "Please enter your pin..."<<endl;
			cin >> pin;
			
			check=trunc(log10(pin)) + 1;
			
			if(check!=4){
				cout<<"Invalid Pin entered, it must be 4 digits"<<endl;
				cout << "Please enter your pin..."<<endl;
				cin >> pin;
			}//endif
			
			cout << "Welcome, " <<fname<<endl;
		
			menu2();
			cout << "What would you like to do?"<<endl;
			cin >> choice;
			
			
		
			
			while(choice!=4){
				
				if(choice==1){
				cout <<"How much would you like to deposit?"<<endl;
				cin >> deposit;
				
				balance=balance + deposit;
			
				cout << "Your new balance is $"<<balance<<endl;
				
				menu2();
				
				cout << "What would you like to do?"<<endl;
			    cin >> choice;
					
			}//endif
			
				if(choice==2){
					cout<<"How much would you like to withdraw?"<<endl;
					cin>>withdraw;
					
					if(withdraw > balance){
						cout << "Insufficient Funds"<<endl;
						cout<<"How much would you like to withdraw?"<<endl;
					    cin>>withdraw;
					}//endif
					
					if(withdraw >= 1000){
						cout<<"You cannot withdraw more than $1000 at once"<<endl;
						cout<<"How much would you like to withdraw?"<<endl;
						cin>>withdraw;
					}//endif
					
					balance=balance-withdraw;
					
					cout << "Your new balance is $"<<balance<<endl;
					
					
					cout << "What would you like to do?"<<endl;
			    	cin >> choice;
				}//endif
				
				if(choice==3){
			    	cout << "Your current balance is $"<<balance<<endl;
			    	cout << "What would you like to do?"<<endl;
			    	cin >> choice;
					}//endif
					
				if(choice==4){
					cout<<"Thank you for banking with us!!"<<endl<<endl;
					menu1();
					cout << "What would you like to do?"<<endl;
					cin >> ans;
				}//endif
				
					
					
			}//endwhile
			
		
				
					pointer <<fname <<"\t"<< balance<<endl;
					pointer.close();
		}//endif
	}while(ans!=2);
	
}//endmain

