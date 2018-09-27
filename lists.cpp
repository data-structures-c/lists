#include <iostream> 
using namespace std;


template<class T>
class LinearList
{
private:
    int length;
    int MaxSize;
    T *element;
public:
    LinearList(int MaxLinearSize=10);
    ~LinearList(){delete[]element;}
    int isEmpty()const{return length==0;}
    int Length()const{return length;}
    int Find(int k,T&x)const;
    int Search(const T&x)const;
    void Delete(int k,T&x);
    void Insert(int k,const T&x);
    void Output()const;
};
template<class T>
LinearList<T>::LinearList(int MaxListSize)
{
    MaxSize=MaxListSize;
    element=new T[MaxSize];
    length=0;
}
template<class T>
int LinearList<T>::Find(int k,T&x)const
{
    if(k<1||k>length)
        return 0;
    x=element[k-1];
    return 1;
}
template<class T>
int LinearList<T>::Search(const T&x)const
{
    for(int i=0;i<length;i++)
        if(element[i]==x)
            return ++i;
    return 0;
}
template<class T>
void LinearList<T>::Delete(int k,T&x)
{
    if(Find(k,x))
    {
        for(int i=k;i<length;i++)
            element[i-1]=element[i];
        length--;
    }
    else
        cout<<"out of bounds\n";
}
template<class T>
void LinearList<T>::Insert(int k,const T&x)
{
    if(k<0||k>length)
        cout<<"out of bounds\n";
    if(length==MaxSize)
        cout<<"no memory\n";
    for(int i=length-1;i>=k;i--)
        element[i+1]=element[i];
    element[k]=x;
    length++;
}
template<class T>
void LinearList<T>::Output()const
{
    if(isEmpty())
        cout<<"list is empty\n";
    else
        for(int i=0;i<length;i++)
            cout<<element[i]<<"\t";
}
void menu()
{
    cout<<"\n MENU\n" ;
    cout<<"-----------\n";
    cout<<"1.Length\n";
    cout<<"2.Find\n";
    cout<<"3.Search\n";
    cout<<"4.Delete\n";
    cout<<"5.Insert\n";
    cout<<"6.Output\n";
    cout<<"-------------\n";
}
int main()
{
    int ch;
    int k,x,len,p;
    LinearList <int> obj;
    
    obj.Insert(0,10);
    obj.Insert(1,7);
    obj.Insert(2,5);
    
    obj.Output();
    cout<<endl;
    
    
    int temp=7;
    obj.Delete(1,temp);
    
    obj.Output();
    cout<<endl;
    
    obj.Insert(1,21);
    
    obj.Output();
    cout<<endl;
    
    
    
    
    
    return 0;
}
