#include<bits/stdc++.h>
using namespace std;
int main(){
    int a=10;
    float b=30.20;
    char c='a';
    int *e=&a;
    float *g=&b;
    char *f=&c;
    cout<<sizeof(a)<<endl; // prints the size of the variable a
    cout<<sizeof(b)<<endl; // prints the size of the variable b
    cout<<sizeof(c)<<endl; // prints the size of the variable c
    cout<<sizeof(e)<<endl; // prints the size of the pointer e
    cout<<sizeof(f)<<endl; // prints the size of the pointer f
    cout<<sizeof(g)<<endl; // prints the size of the pointer g
}