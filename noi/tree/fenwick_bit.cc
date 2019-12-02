/*
Fenwick tree, i.e. binary indexed tree, is used to solve problems of prefix sum and range sum in the complexity O(log(N)) time (N: array length), rather than naive implementation in O(N) time.

Problem description:
    - Given an array a[], and two types of operations are to be performed on it.

    - Change the value stored at an index i. (This is called a point update operation)
    - Find the sum of a prefix of length k. (This is called a range sum query)

Reference:
1. https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/tutorial/

Author: Gao Sheng
*/

#include <iostream>
#include <map>
#include <vector>
#include <fstream>

#define MAX_ARRAY_SIZE 100001

using namespace std;

//declare global arrary to store nodes of binary indexed tree
int BIT[MAX_ARRAY_SIZE];
int nArraySize;
map<int, vector<int>> segment_idx; 

fstream fsGraph;

void updateBinaryIndexTree(int x, int val) {
    //parameters:
    //x: the position index to be updated
    //val: value to be added to x 

    //log current input index &value
    fsGraph<<x<<":"<<val;
    //
    int tmpx = x;
    for(; x <= nArraySize; x += x & -x) {
        BIT[x] += val;
        //log updated tree node id and value up to now
        fsGraph<<","<<x<<":"<<BIT[x];
        //
        map<int, vector<int>>::iterator it = segment_idx.find(x);
        if (it != segment_idx.end())
            it->second.push_back(tmpx);
        else
        {
            segment_idx[x].push_back(tmpx);
        }        
    }
    //new line, each line is an image to show how input value update value
    fsGraph<<endl;

}

int queryPoint(int pos) {
    //parameters:
    //pos: position in array
    //return prefix sum untill pos, i.e. a[1]+a[2]+...+a[pos]

    int sv = 0;
    for(; pos > 0; pos -= (pos & -pos)) {
        sv += BIT[pos];
    }
    return sv;
}

int queryRange(int first, int last) {
    //parameters:
    //first: first position in array
    //last: last position in array
    //return: range sum between pos1 and pos2, i.e. a[first] + a[first+1] + ... + a[last]

    return queryPoint(last) - (first > 1 ? queryPoint(first-1):0);
}

int main()
{
    //prompt message
    cout<<"Please input array size\n";
    //read array size from standard input device, i.e. keyboard
    cin>>nArraySize;
    if(nArraySize >= MAX_ARRAY_SIZE) {
        cout<<"input array size must be less than "<<MAX_ARRAY_SIZE<<endl;
        return 1;
    }
    //
    fsGraph.open ("fenwickTree.txt", fstream::out);
    for(int i = 1; i <= nArraySize; i++) 
        fsGraph<<i<<","; //first line is node id
    fsGraph<<endl;

    cout << "Please input your array values\n";
    //build binary indexed tree frm input array
    for(int i = 1; i <= nArraySize; i++) {
        int v;
        //cin>>v;
        v = i; //generate test data
         
        updateBinaryIndexTree(i, v);

        /*/write latest graph to file
        fsGraph<<i<<":"<<v<<"img";
        for(int k = 1; k <= nArraySize; k++){
            fsGraph<<"*"<<k<<":"<<BIT[k];
            for(vector<int>::iterator it = segment_idx[k].begin(); it != segment_idx[k].end(); it++){
                fsGraph<<","<<k<<":"<<*it;
                //if(it != segment_idx[k].end()-1)
                //    fsGraph<<",";
            }
        }
        fsGraph<<endl;*/
    }
    //print arrray and BIT
    for(int i = 1; i <= nArraySize; i++){
        cout<<"Node id: "<<i<<", BIT value: "<<BIT[i]<<endl;
        cout<<"Array id in the node: ";
        for(vector<int>::iterator it = segment_idx[i].begin(); it != segment_idx[i].end(); it++){
            cout<<*it<<", ";
        }
        cout<<endl<<endl;
    }
    cout<<endl;
    
    //test 
    //get prefix sum untill a position
    int firstPos, lastPos; 
    cout<<"Please input query range (first, last): ";
    cin>>firstPos>>lastPos;
    cout<<"Sum of range element: "<<firstPos<<" - "<<lastPos<<" = "<<queryRange(firstPos, lastPos)<<endl;
    cout<<"Sum of first "<<lastPos<< " elements = "<<queryPoint(lastPos)<<endl;

    fsGraph.close();

    //printf(“sum of all elements in range [2, 7] is %d\n”, query(7) – query(2-1));
    return 0;
}