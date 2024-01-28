#include <iostream>
using namespace std;

// This is a generic class. It can be used for any data type.
template <class T>
class Arithametic{
    private:
    T a;
    T b;
    
    public:
    Arithametic(T a, T b);
    T add();
    T sub();
};

template <class T>
Arithametic<T>::Arithametic(T a, T b) // Since this is outside the class, we need to
{              // specify the template also use the scope resolution operator (::).

    this->a=a; // this->a is the data member of the class, a is the parameter.
    this->b=b; // since the name of parameter and data member is same,
}              // we use this-> to refer to the data member.

template <class T>
T Arithametic<T>::add(){
    return a+b;
}

template <class T>
T Arithametic<T>::sub(){
    return a-b;
}

int main(){
    Arithametic<int> ar(10,5);
    cout<<"\n"<<ar.add()<<endl;
    cout<<"\n"<<ar.sub()<<endl;
    
    Arithametic<float> ar1(10.5,5.5);
    cout<<"\n"<<ar1.add()<<endl;
    cout<<"\n"<<ar1.sub()<<endl;
    return 0;
}
