#include "Assignment3.h"


int main(){
    string name;
   
    mechanic Ahmed, Khaled, Mai, z;
    
    Customer* customer;
    Customer x;
    customer= new Customer[4]; //assumption
     Queue<Customer> Cus_q(3);
     Queue<mechanic> Mech_q(4);
// assuming there are 3 mechanics as mentioned in the pdf
    Mech_q.Push(Ahmed);
    Mech_q.Push(Mai);
    Mech_q.Push(Khaled);
   
   Ahmed.setname("Ahmed");
   Khaled.setname("Khaled");
   Mai.setname("Mai");
    


 

    cout<< "Please enter the info of every customer "<<endl;
    for (int i=0; i<3; i++){
        cout<<"Enter name "<<endl;
        cin>> name;
        customer[i].setname(name);
        cout <<"Enter the wanted time for the appointment h then m. "<<endl;
        cin>>customer->app.hours;
        cin>> customer->app.mins;
        z.setapps(customer->app.hours, customer->app.mins);
        
        if(customer[i]>customer[i+1])
        Cus_q.Push(customer[i+1]); //this is to compare who has less mins so he will enter the queue first.
        else if (customer[i]<customer[i+1])
        Cus_q.Push(customer[i]);
        
    }
    
    for(int y=0;y<4;y++){
        Cus_q.Pop(x);
        Mech_q.Pop(z);
        
        
        //display their info
       cout <<" Mr" << x.getname() << "has an appointment at " << x.app.hours << ":" << x.app.mins << " with " << z.getname();

    }

    


}
