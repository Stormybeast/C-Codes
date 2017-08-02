#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int prime(int);
int get_nums();
void type_cast(char[80]);
void lcm();

int factors[10000],nums[10000][10000],prob_factors[10000];

int main()
{
    int num,i=0,j=0;

    get_nums();
    
    lcm();
    
    return 0;
}


int prime(int n)
{
    int temp=2,count=0,result;
    
    while(temp<=n)
    {
        result=n%temp;
        if(result==0)
        {
            count=count+1;
        }    
        temp++;
    }
    
    if(count==1)
    {
        return 0;
    }
    else
    {
        return 1; 
    }
}


int get_nums()
{
    char string[80];
    int i,temp=0,j,count;
    
    cout<<"Enter the numbers of which you want to find the lcm: ";
    gets(string);
    string[strlen(string)]=NULL;
    
    
    type_cast(string);
    
    return 0;
}


void type_cast(char string_nums[80])
{
    int i,j,temp,count;
    
    i=0;
    j=0;
    temp=0;

    while(i<=strlen(string_nums))
    {
        if(isdigit(string_nums[i]))
        {
            if(string_nums[i]=='0')
            {
                temp=(temp*10);
            }
            else if(string_nums[i]=='1')
            {
                temp=(temp*10)+1;
            }
            else if(string_nums[i]=='2')
            {
                temp=(temp*10)+2;
            }
            else if(string_nums[i]=='3')
            {
                temp=(temp*10)+3;
            }
            else if(string_nums[i]=='4')
            {
                temp=(temp*10)+4;
            }
            else if(string_nums[i]=='5')
            {
                temp=(temp*10)+5;
            }
            else if(string_nums[i]=='6')
            {
                temp=(temp*10)+6;
            }
            else if(string_nums[i]=='7')
            {
                temp=(temp*10)+7;
            }
            else if(string_nums[i]=='8')
            {
                temp=(temp*10)+8;
            }
            else if(string_nums[i]=='9')
            {
                temp=(temp*10)+9;
            }
            i++;
        }
        else
        {
                nums[j][0]=temp;
                temp=0;
                j++;
                i++;
        }
    }
    
    i=0;
    count=0;
    
    while(nums[i][0]!=NULL)
    {
        count++;
        i++;
    }
    
    cout<<"The entered numbers are: ";
    
    for(i=0;i<count;i++)
    {
        cout<<nums[i][0]<<" ";
    }
    cout<<endl;
}

void lcm()
{
    int max=0,num=2,j=0,i,flag,k,m,result;
    
    for(i=0;i<10;i++)
    {
        if(max<nums[i][0])
        {
            max=nums[i][0];
        }
    }
    
    cout<<"The maximum number is: "<<max<<endl;
    
    for(i=0;num<=max;num++)
    {
        flag=prime(num);
        
        if(flag==0)
        {
            prob_factors[i]=num;
            i++;
        }
    }
    
    prob_factors[i] = NULL;
    
    cout<<"Probable Factors: ";
    for(i=0;prob_factors[i]!=NULL;i++)
    {
        cout<<prob_factors[i]<<" ";
    }
    cout<<endl;
    k=0;
    m=0;
    i=0;
    int count_f=0,f=0;
    while(prob_factors[i] != NULL)
    {
              k=0;
              count_f=0;
              while(nums[k][m] != NULL)
              {
                if(nums[k][m]%prob_factors[i]==0)
                {
                  result=nums[k][m]/prob_factors[i];
                  cout<<"Result: "<<nums[k][m]<<"/"<<prob_factors[i]<<"= "<<result<<endl;
                  nums[k][m+1]=result;
                  count_f++;
                }
                else
                {
                  nums[k][m+1]=nums[k][m];
                }
                k++;
              }
              
              if(count_f>=1)
              {
                cout<<"Storing "<<prob_factors[i]<<endl;
                factors[f]=prob_factors[i];
                cout<<"Stored at index number: "<<f<<endl;
                f++;
              }
              else
              {
                i++;
              }
              m++;
    }
    
    int product=1;
    
    cout<<"Array of factors: "<<endl;
    for(k=0;factors[k]!= NULL;k++)
    {
        cout<<"Factor["<<k<<"]: "<<factors[k]<<endl;
    }
    
    for(k=0;factors[k]!=NULL;k++)
    {
        product=product*factors[k];
    }
    
    cout<<"The lcm is: "<<product<<endl;
    
}    
