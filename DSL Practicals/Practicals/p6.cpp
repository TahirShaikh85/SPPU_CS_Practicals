#include <iostream>
#include<stdlib.h>

using namespace std;

// Define the node class to represent a seat in the cinema hall
class node
{ 
public:
    // Pointers to the previous and next nodes in the circular linked list
    node* next;
    node* prev;
    
    // Seat number and booking information
    int seat;
    string id;
    int status;
};

// Define the cinemax class to represent the cinema hall
class cinemax
{
public:
    // Pointers to the head and tail nodes of the circular linked list, and a temp node
    node* head,* tail ,* temp;
    
    // Constructor to initialize the head node
    cinemax()
    {
        head=NULL;
    }
    
    // Member functions to create, display, book, cancel, and display available seats
    void create_list();
    void display();
    void book();
    void cancel();
    void avail();
};

// Function to create the circular linked list
void cinemax::create_list()
{
    // Create the first node
    temp=new node;
    temp->seat=1;
    temp->status=0;
    temp->id="null";
    tail=head=temp;
    
    // Create the remaining nodes and link them in a circular fashion
    for(int i=2;i<=70;i++)
    {
        node *p;
        p= new node;
        p->seat=i;
        p->status=0;
        p->id="null";
        tail->next=p;
        p->prev=tail;
        tail=p;
        tail->next=head;
        head->prev=tail;
    }
}

// Function to display the current status of all the seats
void cinemax::display()
{
    // Initialize variables to keep track of the current row and column
    int r=1;
    node* temp;
    temp=head;
    int count=0;
    
    // Print the column headers
    cout<<"\n------------------------------------------------------------------------------------\n";
    cout<<" Screen this way \n";
    cout<<"------------------------------------------------------------------------------------\n";
    
    // Iterate through the circular linked list and print the seat information
    while(temp->next!=head)
    {
        // Print the seat number
        if(temp->seat/10==0)
            cout<<"S0"<<temp->seat<<" :";
        else
            cout<<"S"<<temp->seat<<" :";
        
        // Print the seat status
        if(temp->status==0)
            cout<<"|___| ";
        else
            cout<<"|_B_| ";
        
        // Increment the column counter and move to the next row if necessary
        count++;
        if(count%7==0)
        {
            cout<<endl;
            r++;
        }
        
        // Move to the next seat
        temp=temp->next;
    }
    
    // Print the information for the last seat
    cout<<"S"<<temp->seat<<" :";

    if(temp->status==0)
        cout<<"|___| ";
    else
        cout<<"|_B_| ";
}
    // Function to book a seat
    void cinemax::book()
    { 
        // Get the seat number and user ID from the user
        int x;
        string y;
        label:
        cout<<"\n\n\nEnter seat number to be booked\n";
        cin>>x;
        cout<<"Enter your ID number\n";
        cin>>y;
        
        // Validate the seat number
        if(x<1||x>70)
        {
            cout<<"Enter correct seat number to book (1-70)\n";
            goto label;
        }
        
        // Search for the seat in the circular linked list
        node *temp;
        temp=new node;
        temp=head;
        while(temp->seat!=x)
        {
            temp=temp->next;
        }
        
        // Check if the seat is already booked
        if(temp->status==1)
            cout<<"Seat already booked!\n";
        
        // If the seat is available, book it
        else{
            temp->status=1;
            temp->id=y;
            cout<<"Seat "<<x<<" booked!\n";
        }
    }
    
    // Function to cancel a booking
    void cinemax::cancel()
    {
        // Get the seat number and user ID from the user
        int x;
        string y;
        label1:
        cout<<"Enter seat number to cancel booking\n";
        cin>>x;
        cout<<"Enter you ID\n";
        cin>>y;
        
        // Validate the seat number
        if(x<1||x>70)
        {
            cout<<"Enter correct seat number to cancel (1-70)\n";
            goto label1;
        }
        
        // Search for the seat in the circular linked list
        node *temp;
        temp=new node;
        temp=head;
        while(temp->seat!=x)
        {
            temp=temp->next;
        }
        
        // Check if the seat is already booked
        if(temp->status==0)
        {
            cout<<"Seat not booked yet!!\n";
        }
        
        // If the seat is booked, check if the user ID matches the ID of the person who booked the seat
        else
        {
            if(temp->id==y)
            {
                temp->status=0;
                cout<<"Seat Cancelled!\n";
            }
        
            // If the user ID doesn't match, don't cancel the booking
            else
                cout<<"Wrong User ID !!! Seat cannot be cancelled!!!\n";
        }
    }
    
    // Function to display the list of available seats
  
    void cinemax::avail()
    {
        // Initialize variables to keep track of the current row and column
        int r=1;
        node* temp;
        temp=head;
        int count=0;
        
        // Print the column headers
        cout<<"\n\n\n\n";
        cout<<"\n------------------------------------------------------------------------------------\n";
        cout<<" Screen this way \n";
        cout<<"------------------------------------------------------------------------------------\n";
        
        // Iterate through the circular linked list and print the seat information
        while(temp->next!=head)
        {
            // Print the seat number
            if(temp->seat/10==0)
                cout<<"S0"<<temp->seat<<" :";
            else
                cout<<"S"<<temp->seat<<" :";
            
            // Print the seat status
            if(temp->status==0)
                cout<<"|___| ";
            else
                cout<<"|_B_| ";
            
            // Increment the column counter and move to the next row if necessary
            count++;
            if(count%7==0)
            {
                cout<<endl;
                r++;
            }
            
            // Move to the next seat
            temp=temp->next;
        }
        
        // Print the information for the last seat
        cout<<"S"<<temp->seat<<" :";
        if(temp->status==0)
            cout<<"|___| ";
        else
            cout<<"|_B_| ";
    }


int main()
{
    // Create an object of the cinemax class
    cinemax c;
    
    // Create the circular linked list of seats
    c.create_list();
    
    int ch;
    do
    {
        cout<<"\nEnter your choice:\n1.Book\n2.Cancel\n3.Check available seats\n4.Check all seats\n5.Exit\n";
        cin>>ch;
        switch(ch)
        {
            case 1:c.book();
            break;
            case 2:c.cancel();
            break;
            case 3:c.avail();
            break;
            case 4:c.display();
            break;
        }
    }while(ch!=5);
    
    return 0;
}
