#include<iostream>
using namespace std;

class Test{
int a;
public:
    Test(int a = 0):a(a){}
    int getA(){return a;}
};
template<typename T>
class my_shared_ptr{
private:
    T* M_ptr;    
    int* count;
public:
    my_shared_ptr(T* M_ptr):M_ptr(M_ptr){
        count = new int(1);
    }
    my_shared_ptr(my_shared_ptr<T> &other_ptr):M_ptr(other_ptr.M_ptr),count(other_ptr.count){
        (*count)++;
    }
    T* get(){
        return M_ptr;
    }
    int countOf(){return *count;}
    T& operator *(){    
        return *M_ptr;
    }
    T* operator->() { return M_ptr; }
    ~my_shared_ptr(){
        *count--;
        if(count == 0){
            delete M_ptr;
        }
    }
};
int main(){
    my_shared_ptr<Test> my(new Test(5));
    cout<<my.countOf()<<endl;
    auto tt = my;
    cout<<my->getA()<<endl;

    cout<<tt.countOf()<<endl;
}