#include <iostream>
using namespace std;

// Create Node

class Node
{
public:
    int data; // Data of the node
    Node *next = NULL; // Pointer for holding address of next node
};

// Linked List

class Singly_Linked_List
{
public:
    Node* i = NULL; // For initializing head
    Node*& head = i; // head of the list

    // Insert node at the beginning

    void insert_At_Beginning (int nodeData)
    {
        Node* newNode = new Node; // Memory allocation

        newNode -> data = nodeData; // Put the nodeData into the newNode
        newNode -> next = head; // Make the newNode's next NULL
        head = newNode; // Declare newNode as head

        cout << nodeData << " has been inserted at the beginning." << endl; // Print which data has been inserted
    }

    //Insert node at the end

    void insert_At_End (int nodeData)
    {
        Node* tempHead = head; // Take a temporary head to keep head safe (it will help to show output of the list)

        Node* newNode = new Node; // Memory allocation

        if (tempHead == NULL) // If list is empty then insert first node without checking anything
        {
            newNode -> data = nodeData; // Put the nodeData into the newNode
            head = newNode; // Declare newNode as head (as there was no head before)
        }

        else if (tempHead != NULL) // Else if head is was declared before (means head in not NULL)
        {
            while (tempHead -> next != NULL) // Then traverse to the last node to insert data after (means the node which next is NULL)
            {
                tempHead = tempHead -> next; // Going to the last node by setting tempHead to next after next
            }

            newNode -> data = nodeData; // Put the nodeData into the newNode
            tempHead -> next = newNode; // Keep last node into newNode
        }

        else // If above tow scenarios do not happen
        {
            cout << "Error."; // Print Error
        }

        cout << nodeData << " has been inserted at the end." << endl; // Print which data has been inserted
    }

    // Delete data from the beginning

    void delete_From_Beginning()
    {
        Node* tempHead = head; // Take a temporary head to keep head safe (it will help to show output of the list)

        if (tempHead == NULL) // If head is NULL
        {
            cout << "List Is Empty. There Is Nothing To Delete From Beginning." << endl; // Print list is empty
        }

        else
        {
            cout << tempHead -> data << " has been deleted" << endl; // Print which data will be deleted
            head = head -> next; // Move head to the next
            delete tempHead; // Delete the head
        }
    }

    // Delete data from the end

    void delete_From_End()
    {
        Node *tempHead = head; // Take a temporary head to keep head safe (it will help to show output of the list)

        if (tempHead == NULL) // If head is NULL
        {
            cout << "List Is Empty. There Is Nothing To Delete From End." << endl; // Print list is empty
        }

        else
        {
            if (tempHead -> next == NULL) // If there is only one node in the list
            {
                cout << head -> data << " has been deleted." << endl; // Print which data will be deleted
                head = NULL; // Make head NULL
                delete head; // Delete the node
            }

            else // While there is more than one node in the list
            {
                while (tempHead -> next -> next != NULL) // Then traverse to the last node to delete
                {
                    tempHead = tempHead -> next; // Going to the last node by setting tempHead to next after next
                }

                cout << tempHead -> next -> data << " has been deleted" << endl; // Print which data will be deleted
                tempHead -> next = NULL; // Set the next of tempHead (last node) to NULL
                delete tempHead -> next; // Delete the last node
            }
        }
    }

    // Print Linked_List

    void print ()
    {
        Node* tempHead = head; // Take a temporary head to keep head safe (it will help to show output of the list)

        int i = 1; // For counting data
        if (tempHead == NULL) // If there is no node in the list
        {
            cout << "List Is Empty." << endl; // Print empty message
        }

        else
        {
            while (tempHead != NULL) // Loop will continue until tempHead gets NULL
            {
                cout << "Data " << i << "-> " << tempHead -> data <<", "; // Print data
                tempHead = tempHead -> next; // Change the head to next node
                i++; // Increment the value of i (data count)
            }
        }

    }
};

// Drive code

int main ()
{
    Singly_Linked_List l1; // Creating object of list

    char option; // Take option as character to avoid error
    int data; // For passing data to the list

    while (true) // Enter loop without checking any condition
    {
        cout << endl << "------------------------------------------"; // For marking changes a session
        cout << endl << "1. Insert Data At The Beginning." << endl;
        cout << "2. Insert Data At The End." << endl;
        cout << "3. Delete Data From Beginning." << endl;
        cout << "4. Delete Data From End." << endl;
        cout << "5. Print The List." << endl;
        cout << "6. Exit The Program." << endl;
        cout << "Select An Option : ";
        cin >> option; // Taking input from user to match what user wants to do

        if (option == '1') // If choose option 1 insert_At_Beginning method will be called
        {
            cout << "Enter Data To Put It At The Beginning : ";
            cin >> data; // Data to be passed as the perimeter of the method
            l1.insert_At_Beginning(data); // Call insert_At_Beginning method and pass data as perimeter
        }

        else if (option == '2') // If choose option 2 insert_At_End method will be called
        {
            cout << "Enter Data To Put It At The End : ";
            cin >> data; // Data to be passed as the perimeter of the method
            l1.insert_At_End(data); // Call insert_At_End method and pass data as perimeter
        }

        else if (option == '3') // If choose option 3 delete_From_Beginning method will be called
        {
            l1.delete_From_Beginning(); // Call delete_From_Beginning method for deleting data from the beginning
        }

        else if (option == '4') // If choose option 4 delete_From_End method will be called
        {
            l1.delete_From_End(); // Call delete_From_End method for deleting data from the end
        }

        else if (option == '5') // If choose option 5 print method will be called
        {
            l1.print(); // Call print method for show the list
        }

        else if (option == '6') // If choose option 6 loop will be broken and program will be finished
        {
            cout << "Exited Successfully.";
            break;
        }

        else // For any other character
        {
            cout << "Wrong Input."; // Print invalid input
        }
    }
}

