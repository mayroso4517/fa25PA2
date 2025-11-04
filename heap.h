//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    int top() {
        if (size == 0)
            return -1;
        return data[0];
    }


    void push(int idx, int weightArr[]) {
        data[size] = idx;
        upheap(size, weightArr);
        size++;
    }

    int pop(int weightArr[]) {
      if (size == 0)
          return -1;

        int smallest = data[0]; // Stores smallest node
        size--;
        if (size > 0) {
            data[0] = data[size];
            downheap(0, weightArr);
        }
        return smallest;
    }

    void upheap(int pos, int weightArr[]) { //Moves the smallest frequency to the top

    while (pos > 0) {
        int parent = (pos -1)/ 2; //Uses heap formula to find parent
        if (weightArr[data[pos]] < weightArr[data[parent]]) {
            int tmp = data[pos];
            data[pos] = data[parent];
            data[parent] = tmp;
            pos = parent;
        } else {

        }
      }

    }

    void downheap(int pos, int weightArr[]) {
        while (true) {
            int left = 2 * pos + 1;
            int right = 2 * pos + 2;
            int smallest = pos;

            //Compares the left and right child
            if (left < size && weightArr[data[left]] < weightArr[data[smallest]]) {
                smallest = left;
            }
            if (right < size && weightArr[data[right]] < weightArr[data[smallest]]) {
                smallest = right;
            } //Will perform a swap
            if (smallest != pos) {
                int tmp = data[pos];
                data[pos] = data[smallest];
                data[smallest] = tmp;
                pos = smallest;
            } else {
                break;
            }
        }
    }
};

#endif