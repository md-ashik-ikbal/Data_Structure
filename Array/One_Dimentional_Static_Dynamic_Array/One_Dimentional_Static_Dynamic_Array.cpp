#include<iostream>

using namespace std;

class One_Dimentional_Static_Dynamic_Array
{
public:

    int arr_static[5];
    int arr_length_static = sizeof(arr_static) / sizeof(0);

    int *arr_dynamic, arr_length_dynamic;

    One_Dimentional_Static_Dynamic_Array()
    {

    }

    void Array_with_static_length()
    {

        cout << " Enter Five Integer Numbers For Array : " << endl;

        for(int i = 0; i < arr_length_static; i++)
        {
            cout << " Enter Value For Index  " << i << " : ";
            cin >> arr_static[i];
        }

        cout << " Five Integer Numbers That You Entered : " << endl;

        for(int i = 0; i < arr_length_static; i++)
        {
            cout << " Value Of Index  " << i << " : ";
            cout << arr_static[i] << endl;
        }
    }

    void Arry_with_dynamic_length()
    {
        cout << " How Many Size Of your Array Would Be? : " ;
        cin >> arr_length_dynamic;
        cout << " Selected Length " << arr_length_dynamic << endl;
        cout << " Now Enter " << arr_length_dynamic << " Integer Numbers. " << endl;

        arr_dynamic = new int[arr_length_dynamic];

        for(int i = 0; i < arr_length_dynamic; i++)
        {
            cout << " Enter Value For Index  " << i << " : ";
            cin >> arr_dynamic[i];
        }

        for(int i = 0; i < arr_length_dynamic; i++)
        {
            cout << " Value Of Index  " << i << " : ";
            cout << arr_dynamic[i] << endl;
        }
    }
};



int main()
{
    One_Dimentional_Static_Dynamic_Array array1;

    string option;

    while(option != "3")
    {
        cout << " 1. Array With Static Length. " << endl;
        cout << " 2. Array With Dynamic Length. " << endl;
        cout << " 3. Exit The Program. " << endl;
        cout << " What Do You Want To Do? " << endl;
        cin >> option;

        if(option == "1")
        {
            array1.Array_with_static_length();
        }

        else if(option == "2")
        {
            array1.Arry_with_dynamic_length();
        }

        else if(option == "3")
        {
            cout << " SUCCESSFULLY EXITED THE PROGRAM. " << endl;
            break;
        }

        else
        {
            cout << " You Entered Wrong Number " << endl;
        }
    }
}
