#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class PriorityQueue
{
    vector<int> arr;
    int n;
    int index;

private:
    void swim(int k)
    {
        // Insert at end then go upwards through parents at a desired location

        while (k > 1 && arr[k / 2] < arr[k])
        {
            swap(arr[k / 2], arr[k]);
            k = k / 2;
        }
    }

    void sink(int k)
    {
        // bring an element from top to right position through childs
        while (2 * k <= index)
        {
            int j = 2 * k;
            // finding out which should we swap with
            if (j < index && arr[j] < arr[j + 1])
            {
                j++;
            }

            if (arr[k] >= arr[j])
                return;
            swap(arr[k], arr[j]);
        }
    }

public:
    PriorityQueue(int n)
    {
        arr.resize(n);
        this->n = n;
        index = 0;
    }
    void insert(int k)
    {
        if (isFull())
        {
            cout << "The Priority queue is already full" << endl;
            return;
        }
        arr[++index] = k;
        swim(index);
    }
    int delMax()
    {
        if (isEmpty())
        {
            cout << "The Priority queue is Empty" << endl;
            return -1;
        }
        int maxEle = arr[1];
        arr[1] = arr[index--];
        sink(1);
        return maxEle;
    }
    bool isFull()
    {
        return index == n;
    }
    bool isEmpty()
    {
        return index == 0;
    }
    int size()
    {
        return index;
    }
    int top()
    {
        return arr[1];
    }
};

int main()
{
    PriorityQueue pQueue = PriorityQueue(10);
    pQueue.insert(1);
    pQueue.insert(5);
    pQueue.insert(10);
    pQueue.insert(20);
    pQueue.insert(11);
    pQueue.insert(22);
    pQueue.insert(23);
    pQueue.insert(25);
    pQueue.insert(40);
    pQueue.insert(43);
    pQueue.insert(23);
    cout << pQueue.size() << endl;
    assert(pQueue.top() == 43);
    assert(pQueue.size() == 10);
    assert(pQueue.delMax() == 43);
    assert(pQueue.size() == 9);

    return 0;
}