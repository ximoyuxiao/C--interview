#include<iostream>
using namespace std;
class A{
public:
    A(){cout<<"A()"<<endl;}
    virtual int vfunc(int a = 0 ){cout<<"A.vfunc()"<<endl;return a;}
    int func(int a = 0 ){cout<<"A.func()"<<endl;return a;}
    virtual ~A(){cout<<"~A()"<<endl;}
};
class B:public A{
public:
    B(){cout<<"B()"<<endl;}
    virtual int vfunc(int a = 1 ){cout<<"B.vfunc()"<<endl;return a;}
    int func(int a = 1 ){cout<<"B.func()"<<endl;return a;}
    ~B(){cout<<"~B()"<<endl;}
};
int main(){
    A* a = new B();  // A() B()
    cout<<a->vfunc()<<endl; // B.vfunc 0
    cout<<a->func()<<endl;  // A.func 0
    delete a;  // ~B() ~A()
    return 0;
}