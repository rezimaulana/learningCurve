#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Person
{
    private:
        std::string name_;
        int age_;
        static int idp_;
        static int ids_;
    public:
        Person(){}
        virtual ~Person(){}
        
        virtual void getdata() = 0;
        virtual void putdata() = 0;
        
        void set_name(std::string const &name)
        {
            this->name_ = name;
        }
        void set_age(int const &age)
        {
            this->age_ = age;
        }
        void set_idp()
        {
            idp_++;
        }
        void set_ids()
        {
            ids_++;
        }
        
        std::string get_name()
        {
            return this->name_;
        }
        int get_age()
        {
            return this->age_;
        }
        int get_idp()
        {
            return this->idp_;
        }
        int get_ids()
        {
            return this->ids_;
        }
};

int Person::idp_ = 0;
int Person::ids_ = 0;

class Professor : public Person
{
    private:
        int publications_;
        int cur_id_;
        
    public:
        Professor()
        { 
            set_idp(); 
            cur_id_ = get_idp();
        }
        ~Professor(){}
        void getdata()
        {
            // cin name, age, publications
            std::string name;
            int age;
            
            std::cin >> name >> age >> publications_;
            set_name(name);
            set_age(age);
        }
        void putdata()
        {
            //cout name age publications cur_id
            std::cout << get_name() << " " << get_age() << " " << publications_ << " " << cur_id_ << std::endl;
        }
        
};

class Student : public Person
{
    private:
        int marks_[6];
        int cur_id_;
        
    public:
        Student()
        {
            set_ids();
            cur_id_ = get_ids();
        }
        ~Student(){}
        void getdata()
        {
            // cin name, age, marks
            std::string name;
            int age;
            
            std::cin >> name >> age;
            set_name(name);
            set_age(age);
            
            for (int i = 0; i < 6; i++)
                std::cin >> marks_[i];
        }
        void putdata()
        {
            int sum = 0;
            
            for (int i = 0; i < 6; i++)
                sum += marks_[i];
                
            //cout name, age, sum of marks, cur_id
            std::cout << get_name() << " " << get_age() << " " << sum << " " << cur_id_ << std::endl;
        }
};

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}
