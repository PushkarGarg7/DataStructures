#include <bits/stdc++.h>
using namespace std;

class MaxHeap{

    private :
    vector<int>heap;
    

    int parent(int i){
        return (i-1)/2;
    }
    int leftC(int i){
        return 2*i+1;
    }
    int rightC(int i){
        return 2*i+2;
    }
    void heapifyUp(int i){
        while (i>0 && heap[i]>heap[parent(i)]){
            swap(heap[parent(i)],heap[i]);
            i=parent(i);
        }
    }

    void heapifyDown(int i){
        int maxIndex=i;

        int l=leftC(i);

        if(l<heap.size() && heap[l]>heap[maxIndex]){
            maxIndex=l;
        }
        int r=rightC(i);

        if(r<heap.size() && heap[r]>heap[maxIndex]){
            maxIndex=r;

        }
        if(maxIndex!=i) {
            swap(heap[i],heap[maxIndex]);
            heapifyDown(maxIndex);

        }

    }

    public :

    void insert(int el){
        heap.push_back(el);
        heapifyUp(heap.size()-1);

    }
    int extractMax(){
        if(heap.size()==0) throw runtime_error("empty");

        int ans=heap[0];
        swap(heap[0],heap[heap.size()-1]);
        heap.pop_back();
        if(heap.size()!=0){
            heapifyDown(0);
        }
        return ans;
    }
    int getMax(){
        if(heap.size()==0) throw runtime_error("empty");
        return heap[0];
    }



};


int main (){
    return 0;

}