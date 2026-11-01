#include <iostream>
#include <clocale>
using namespace std;

int main()
{
    setlocale(LC_ALL,".65001");
    bool f = false;
    int a,b;
    cin>>a;
    if(a==0){
        cout<<"Последовательность пустая";
    }
    else
    {
        cin>>b;
        while(b!=0)
        {
           if(a>=b)
           {
                f=true;
            }
            a=b;
            cin>>b;
        }
        if(f)
        {
            cout<<"Последовательность не упорядочена по возрастанию";
        }
        else
        {
            cout<<"Последовательность упорядочена";
        }
    }
    return 0;

}