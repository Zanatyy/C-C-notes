//Vector Data Strcuture.
//Technically a dynamic array.
#include <iostream>
#include <assert.h>

using namespace std;
class Vector{
private:
    //Vector consists of: -Array -Size and Capacity variables.
    //Size represents number of elements exist inside the Array.
    //Capacity Represents maximum n of elements can be fit in side the array.
    int *arr=nullptr;
    int size=0;
    int capacity;
public:
    Vector(int size):size(size){
        //Constructor will allocate memory for an array, the size will be given by user.
        //If condition to solve invalid inputs.
        if (size<=0) size=1;
        capacity=size+20;
        arr=new int[capacity]{};
    }

    ~Vector(){
        //Deconstructor
    delete [] arr;
    arr=nullptr;
    }

    void set(int p,int x){
        //Sets an element based on index (index,value).
        //Can be used to edit elements.
    assert(p>=0&&p<size);
    arr[p]=x;
    }

    int get(int p){
        //Getting an element based on index.
    assert(p>=0&&p<size);
    return arr[p];
    }

    void expand_capacity(){
        //To expand the capacity of the array if there's no empty space for a new variable.
        //Expanding is done by allocating a new array with more capacity and deallocating the old one.
    capacity+=20;
    int *new_arr = new int [capacity]{};
    for(int i=0;i<size;i++){
        new_arr[i]=arr[i];
    }
    swap(arr,new_arr);
    delete [] new_arr;
    new_arr=nullptr;
    }

    void push_back(int x){
        //Adds a new element at the end of the array.
        //If the array is full, the array is expanded.
    if(size==capacity) expand_capacity();
    arr[size++]=x;
    }

    int get_size(){
        //Returns the size.
    return size;
    }

    void printv(){
        //Prints all elements of the array.
    cout<<"Vector elements:"<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<endl;
    }
    }
    void insertion(int x,int p){
        //Adds a new element based on index without changing the rest of the Array.
        //Shifts all elements to make a room for the new element.
        //If there's no room, we use expand_capacity().
    if(capacity==size) expand_capacity();
    for(int i=size;i>=p;i--){
        arr[i+1]=arr[i];
    }
    size++;
    arr[p]=x;
    cout<<"Capacity check: ";
    }

};
int main()
{
    /*
    Vector v(3);
    v.set(0,96);
    v.set(1,2);
    v.set(2,5);
    v.push_back(420);                        For testing the data structure
    v.push_back(285879);
    v.insertion(585858,3);
    v.printv();
    cout<<"SIZE: "<<v.get_size()<<endl;
    */
    return 0;
}
