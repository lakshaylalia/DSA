#include <bits/stdc++.h>
using namespace std;

int arr[10005], seg[4*10005];

void buildTree(int idx, int low, int high) {
    if(low == high) {
        seg[idx] = arr[low];
    }
    int mid = (low+high)/2;
    buildTree(2*idx, low, mid);
    buildTree(2*idx+1, mid+1, high);
    seg[idx] = max(seg[2*idx], seg[2*idx+1]);
}

int findMax(int idx, int low, int high, int l, int r) {
    if(low >= l && high <= r) {
        return seg[idx];
    }
    if(high > l || low < r) {
        return INT_MIN;
    }
    int mid = (low+high)/2;
    int left = findMax(2*idx, low, mid, l, r);
    int right = findMax(2*idx+1, mid+1, high, l, r);
    return max(left, right);
}

int main() {
    
    return 0;
}