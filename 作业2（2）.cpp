#include <stdio.h>
#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main()
{
    deque<int> a;
    a.pop_front();
    a.push_front(1);
    a.push_front(1);
    for (int i = 0; i < a.size(); i++){
        cout << a[i] << ' ';
    }
    return 0;
}