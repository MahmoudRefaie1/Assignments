#include <iostream>
#include <string>
using namespace std;

class Person{
    private:
    string name;
    string ID;
    int age;
    public:
    Person(){
        
    }
    void setname(string name_inpt){
        name = name_inpt;
    }
    void setID(string ID_inpt){
        ID = ID_inpt;
    }
    void setAge(int age_inpt){
        age=age_inpt;
    }
    string getname(){
        return name;
    }
    string getID(){
        return ID;
    }
    int getAge(){
        return age;
    }
    void Printinfo(){
        cout<< "Name: " << name << endl;
        cout<<"Age: " << age << endl;
        cout<<"ID: " <<ID <<endl;
    }

    struct appointment{
       int hours, mins;
    };
    appointment app;


};

class Customer: public Person{
    private:
    int MechanicID;
    appointment appointmentwMech;
    public:
    void setMechanicID(int Input_id){
        MechanicID=Input_id;
    }
    int getMechanicID(){
        return MechanicID;
    }
    //Overloading >,<,==.
    bool operator > (const Customer& f){
       //converting from hours to mins
       int min_c1 = appointmentwMech.hours*60;
       int min_c2 = f.appointmentwMech.hours*60;
       int sumTime1 = min_c1+ this->appointmentwMech.mins;
       int sumTime2 = min_c2+ f.appointmentwMech.mins;
       //I converted into mins and added to get the sum of mins so I can easily conmpare
       return (sumTime1>sumTime2);

    }
    bool operator < (const Customer& f){
        //converting from hours to mins
       int min_c1 = appointmentwMech.hours*60;
       int min_c2 = f.appointmentwMech.hours*60;
       int sumTime1 = min_c1+ this->appointmentwMech.mins;
       int sumTime2 = min_c2+ f.appointmentwMech.mins;
       return (sumTime1<sumTime2);
       
    }
    bool operator == (const Customer& f){
        //converting from hours to mins
       int min_c1 = appointmentwMech.hours*60;
       int min_c2 = f.appointmentwMech.hours*60;
       int sumTime1 = min_c1+ this->appointmentwMech.mins;
       int sumTime2 = min_c2+ f.appointmentwMech.mins;
       return (sumTime1==sumTime2);
    }
};

class mechanic: public Person{
    private:
    int counter=0;
   
    appointment arrOfApp[10]; //assuming only 10 appointments per mechanic.
    public:
    bool isAvailable(int hours, int mins){
        bool b;
       for (int i=0;i<10;i++){
       if(hours == arrOfApp[i].hours && mins == arrOfApp[i].mins) //if there are two booked slots the loop is expected to return false and end.
       {b= false;
       break;
       }
       else
       b= true;
       }
       return b ;
    }
    void setCounter(int c){
        counter=c;
        return;
    }
    int getcounter(){
        return counter;
    }
    void setapps(int h, int m){
           
           if(isAvailable(h, m)){
            arrOfApp[counter].hours=h;
            arrOfApp[counter].mins=m;
            counter++;
                }
            else
            cout <<"Error: This slot has been taken";
           }
        

    void getapps(){
        for(int i=0; i<counter; i++){
            cout<< arrOfApp[i].hours << ":"<< arrOfApp[i].mins <<endl;
    }
    }
};

template <typename T>
class Queue {
public:
    Queue(int size) {
        m_size=size;
        m_front=0;
        m_rear=0;
        m_count=0; 
        m_array = new T[m_size];
    }

    ~Queue() {
        delete[] m_array;
    }

    bool Push(T element) {
        if (m_count == m_size) {
            cout << "Queue is full" << endl;
            return false;
        }
        m_array[m_rear] = element;
        m_rear = (m_rear + 1) % m_size;
        m_count++;
        return true;
    }

    bool Pop(T& element) {
        if (m_count == 0) {
            cout << "Queue is empty" << endl;
            return false;
        }
        element = m_array[m_front];
        m_front = (m_front + 1) % m_size;
        m_count--;
        return true;
    }

private:
    int m_size;
    int m_front;
    int m_rear;
    int m_count;
    T* m_array;
};

