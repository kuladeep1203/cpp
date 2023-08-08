/*
#include<iostream>
using namespace std;
template<typename T>
T add(T x,T y)
{
    return(x+y);
}
int main()
{
int b=add<int>(2,3);

cout<<add<float>(2.5,3);
cout<<b;

}

#include<iostream>
using namespace std;
class a
{
  int data;
  public:
  a()
  {
      data=10;
  }
   void display1()
  {
      cout<<"base"<<data<<endl;
  }
};
class b:public a
{
  int data1;
  public:
  b()
  {
      data1=20;
  }
  void display()
  {
      cout<<"derived"<<data1<<endl;
  }
  
};
int main()
{
    a *k=new a;
    k->display1();
    b h;
    k=&h;
    k->display1();
    h.display();
}*/
#include<iostream>
using namespace std;
class abc
{
 
  public:
  static int data;
  abc()
  {
    data=data+10;
  }
virtual void  show()=0;
virtual void  show1()=0;
};
int abc:: data;
class b :public abc
{
public:
b()
{
    data=data-10;
}
virtual void show()
{
    cout<<"hi";
}
};
int main()
{
    //abc d,e,f,g,h;
    // d.show();
    //e.show();
  //  f.show();
   // g.show();
    b k;
    k.show();
   

}