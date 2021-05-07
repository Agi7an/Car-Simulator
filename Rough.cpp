#include <iostream>
#include <thread>

using namespace std;

bool con = true;

void f1(int n)
{
    while(con)
    {
        cout<<n<<endl;
    }
}

void f2()
{
    int n;
    cout<<"Enter value: ";
    cin>>n;
    if(n % 2 == 0)
    {
        con = false;
    }
}

int main()
{
    thread func1(f1, 7);
    con = false;
    func1.join();
}