#include <iostream>
using namespace std;

#define nl endl
void cppTypeConvertion();
class cppOops{
	public:
	cppOops(){
		// cppEncapsulation();
		cppInheritance();
	}
	void cppEncapsulation();
	void cppInheritance();
	void cppPolymorphism();
};

int main(){	
	// cppTypeConvertion();
	cppOops();
	return 0;
}

// TYPE CONVERTION
	void cppTypeConvertion(){
		// syntax : (data_type)expression 

		char c = (char)(97);

		cout<<int('a')<<" "<<c<<nl;
	}

// OOPS 
	void cppOops:: cppEncapsulation(){
		// programming technique to wrapping up data into single unit class is called encapsulation 				
		class Student{
			private:    										// access specifier
				int id;   										// attribute 

			protected:
				string tutor;

			public:
				string name = "undefined";
				
				Student(string msg){				// method 
					cout<<"msg: "<<msg<<nl;
				}

				void getter(){
					cout<<this->name<<" "<<this->id<<" "<<this->tutor<<nl;
				}

				void publicSetter(int id){
					this->id = id;
				}

				void operator ++(){
					this->id+=1;
				}

				int operator +(Student obj){
					return this->id + obj.id;
				}
			
		};

		Student *dheeraj = new Student("new addmission");
		dheeraj->name = "dheeraj poonia";
		// dheeraj->id = 035;   // error: private member on class can access 
		// dheeraj->tutor = "ajaj sir";  // error: protected only class or derived class can acess
		// dheeraj->publicSetter(035); // logical error : 035 convert to octal -> 29 
		dheeraj->publicSetter(35);
		// ++dheeraj; 	here not work
		dheeraj->getter();

		Student t("student t");
		t.publicSetter(1);
		++t;
		t.getter();

		Student p("student p"), q("student q");
		p.publicSetter(10); q.publicSetter(20);
		cout<<p+q;
	}

	void cppOops:: cppInheritance(){
		// Inheritance is the ability of one class to inherit properties of another class
		class Base{
			private:
			string pri = "+ base-private-attribute";

			protected:
			string pro = "base-protected-attribute";

			public:
			string pub = "base-public-attribute";	

			void getPrivate(){
				cout<<pri<<"-method"<<nl;
			}		
		};
		
		Base obj;
		cout<<"1) ACCESS THOUGH OBJECT"<<nl;		
		// cout<<"access: "<<obj.pri<<nl;
		// cout<<"access: "<<obj.pro<<nl;
		cout<<"access: "<<obj.pub<<nl;

		class privateDerived: private Base{
			public:
				privateDerived(){
					cout<<"\n3) ACCESS THOUGH private_DERIVED"<<nl;		
					// cout<<"access: "<<pri<<nl;
					cout<<pro<<" im here private"<<nl;
					cout<<pub<<" im here private"<<nl;
					getPrivate();
				}
		};
		privateDerived();

		class protectedDerived: protected Base{
			public:
				protectedDerived(){
					cout<<"\n2) ACCESS THOUGH protected_DERIVED"<<nl;		
					// cout<<"access: "<<pri<<nl;
					cout<<"access: "<<pro<<nl;
					cout<<"access: "<<pub<<nl;
				}
		};
		protectedDerived obj3;

		class publicDerived: public Base{
			public:
				publicDerived(){
					cout<<"\n1) ACCESS THOUGH public_DERIVED"<<nl;		
					// cout<<"access: "<<pri<<nl;
					cout<<"access: "<<pro<<nl;
					cout<<"access: "<<pub<<nl;
				}
		};
		publicDerived obj2;

			
	}

	void cppOops:: cppPolymorphism(){
		
	}