#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};
class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
      unordered_map<int,stack<int>> mp;
      for(int i=0;i<2*e;i+=2){
          mp[A[i]].push(A[i+1]);
      }
       for(int i=0;i<2*e;i+=2){
          if(mp[B[i]].top()!=B[i+1])return 0;
          mp[B[i]].pop();
      }
      return 1;
    }
};