#include<cstring>
#include<iostream>
using namespace std;
#include "CircularQueue.hpp"

typedef CircularQueue::QueueItem QueueItem;
const QueueItem CircularQueue::EMPTY_QUEUE = -999;

CircularQueue::CircularQueue()
{
    items_ = new QueueItem [capacity_];
    head_ = 0;
    tail_ = 0;
    capacity_ = 16;
    size_ = 0;
}

CircularQueue::CircularQueue(unsigned int capacity)
{
   if (capacity == 0){
       capacity_ = 16;
   }
    else capacity_ = capacity;
    head_ = 0;
    tail_ = 0;
    size_ = 0;
    
}

CircularQueue::~CircularQueue()
{
    delete [] items_;
}

bool CircularQueue::empty() const
{
    if (size_ == 0) return true;
    else return false;
}

bool CircularQueue::full() const
{
    if (size_ == capacity_) return true;
    else return false;
}

int CircularQueue::size() const
{
    return size_;
}

bool CircularQueue::enqueue(QueueItem value)
{
    if (full ()) return false;
    else
    {
        items_ [tail_] = value;
        tail_ = (tail_+1)%capacity_;
        size_++;
        return true;
    }
}

QueueItem CircularQueue::dequeue()
{
    if(empty()) return EMPTY_QUEUE;
    else{
        QueueItem x = items_[head_];
        head_ = (head_+1)%capacity_;
        size_--;
        return x;
    }
    
}

QueueItem CircularQueue::peek() const
{
    if (size_ == 0) return EMPTY_QUEUE;
    else return items_[head_];
}

void CircularQueue::print() const
{
    cout <<"Circular Queue = ";
    for (int i = 0; i<size_; i++)
    {
        cout<<items_[i];
    }
}
