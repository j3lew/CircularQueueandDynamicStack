#include "DynamicStack.hpp"
#include <iostream>
#include <math.h>


using namespace std;

typedef DynamicStack::StackItem StackItem;  // for simplicity
const StackItem DynamicStack::EMPTY_STACK = -999;

DynamicStack::DynamicStack()
{
    init_capacity_ = 16; //wondering if this should be included in the first constructor or just the second
    capacity_ = 16;
    items_ = new StackItem[capacity_];
    size_=0;

}

DynamicStack::DynamicStack(unsigned int capacity)
{
    if(capacity == 0)
    {
        init_capacity_ = 16;
        capacity_= 16;
    }
    else
    {
        capacity_=capacity;
        init_capacity_ = capacity;
    }
    items_ = new StackItem[init_capacity_];
    size_=0;
}

DynamicStack::~DynamicStack()
{
    delete [] items_;
}

bool DynamicStack::empty() const
{
    if (size_ == 0) return true;
    else return false;
}

int DynamicStack::size() const
{
    return size_;
}

void DynamicStack::push(StackItem value) //put on
{
   if(size_ == capacity_)
   {
       capacity_ = 2*capacity_;
       StackItem* items2_ = new StackItem [capacity_];
       for(int i = 0; i<size_; i++)
       {
           items2_[i] = items_[i];
       }
       delete[] items_;
       items_ = items2_;
       items_[size_] = value;
       size_ ++;

   }
   else{
       items_[size_] = value;
       size_ ++;
   }


}

StackItem DynamicStack::pop() //take off top
{
    if(empty()) return EMPTY_STACK;
    else
    {
        StackItem x = items_[size_ -1];
        size_--;
        if(size_<=(0.25*capacity_) && (0.5*capacity_)>=init_capacity_)
        {
            capacity_ = 0.5*capacity_;
            StackItem* items2_ = new StackItem [capacity_];
            for(int i = 0; i<size_; i++)
            {
                items2_[i] = items_[i];
            }
            delete[] items_;
            items_ = items2_;

        }
        return x;
    }


}

StackItem DynamicStack::peek() const
{
    if(empty()) return EMPTY_STACK;
    else return items_[size_ -1];
}

void DynamicStack::print() const
{
    cout<<"Dynamic Stack = ";
    for(int i = 0; i<size_; i++)
    {
        cout<<items_[i];
    }

}
