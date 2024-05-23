#include<iostream>
using namespace std;
/*int BinarySearch(int list[],int n,int key);
int main()
{
    int key,n;
cout<<"how many numbers do you want\n";
cin>>n;
int list[n];
for(int i=0;i<n;i++)
{  cout<<"enter the element "<<i<<"\n";
    cin>>list[i];
}
cout<<"enter key\n";
cin>>key;/*
    int list[]={23,45,28,65,87,10};
    int key=87;*/
   /*int i= BinarySearch(list,n,key);
    if(i==-1)

  cout<<"The Element is Not Found \n";

  else

  cout<<"The Element is  Found at Index "<<i<<"/n";

    return 0;
}
   int BinarySearch(int list[],int n,int key)//fun definition
   {
    int found=0,index=0;
    int top=n-1,bottom=0,middle;
    do
    {
    middle=(top+bottom)/2;

    if(key==list[middle])
        found=1;
    else
    {
        if(key<list[middle])

            top=middle-1;
        else

         bottom=middle+1;


    }

    }while(found==0 && top>=bottom);

    if(found==0)

    index=-1;
    else

    index=middle;

  return index;




       return 0;
   }*/
   int binary_functio(int list[],int b,int key)
   {
       int index=0,found=0;
       int top=5,bottom=0,middle;
       do{ middle=(top+bottom)/2;
       if(key==list[middle])
        found=1;
       else
       {
           if(key<list[middle])
            top=middle-1;
           else
            bottom=middle+1;
       }


       }while(found==0&&top>=bottom);
       if(found==0)
        index=-1;
        else
        index=middle;
        return index;
   }

   int main()
   {
       int list[]={1,2,3,4,5};
       int key=0;
       int b=sizeof (list)/list[0];
       int m=binary_functio(list,b,key);
       if(m==-1)
        cout<<"not foound\n";
       else
        cout<<"the number is found";

   }
