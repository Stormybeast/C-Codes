#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


using namespace std;


class expense
{
 private: 
        float cred, deb, rem, start,stf;
        char description[40],c_num[7];
        
  public:
        FILE *fp;
   
    expense()
    {
        cred=0.00;
        deb=0.00;
        rem=0.00;
        start=0.0;
    }
    
    void remaining()
    {
        int i=0;
        char ch;
        fseek(fp,-9,SEEK_END);
        
        for(i=0;i<7;i++)
        {
            c_num[i]=NULL;
        }
        
        i=0;
        
        ch=fgetc(fp);
        
        while(ch != EOF)
        {
            if(isdigit(ch))
            {
                c_num[i]=ch;
                i++;
            }
            else if(ch=='.')
            {
                c_num[i]=ch;
                i++;
            }
            ch=fgetc(fp);
        }
       
       fseek(fp,0,SEEK_END);
       rem = stof();
       
       cout<<"The reamining Balance is: "<<rem<<endl;
    }
    
    void new_account()
        {
            char month[10],upper_month[10];
            int i=0;
            
            fseek(fp,0,SEEK_END);
            
            for(i=0;i<10;i++)
            {
                month[i]=NULL;
                upper_month[i]=NULL;
            }
            
            cout<<"Enter the name of the month for which you want to initiate account. ";
            gets(month);
            month[strlen(month)]=NULL;
    
            for(i=0;i<strlen(month);i++)
            {
                upper_month[i]=toupper(month[i]);
            }
    
            for(i=0;i<25;i++)
            {
                fputc('<',fp);
            }
    
            for(i=0;i<4;i++)
            {
                fputc(' ',fp);
            }
            
            char heading[32]="ACCOUNT FOR THE MONTH OF ";
            fputs(strcat(heading,upper_month),fp);
    
            for(i=0;i<4;i++)
            {
                fputc(' ',fp);
            }
    
            for(i=0;i<25;i++)
            {
                fputc('>',fp);
            }
    
            fputs("\n",fp);
    
            for(i=0;i<29;i++)
            {
                fputc(' ',fp);
            }
    
            int length=strlen(month);
            char date[10];
    
            length=length+25;
    
            for(i=0;i<length;i++)
            {
                fputc('-',fp);
            }
    
            fputs("\n",fp);
    
            fputs("\n",fp);
            
            for(i=0;i<36;i++)
            {
                fputc('-',fp);
            }
    
            fputc(' ',fp);
    
            cout<<"Enter the starting date: ";
            gets(date);
    
            fputs(date,fp);
    
            fputc(' ',fp);
    
            for(i=0;i<36;i++)
            {
                fputc('-',fp);
            }
    
            fputs("\n",fp);
            fputs("\n",fp);
            
            for(i=0;i<8;i++)
            {
                fputc(' ',fp);
            }
            
            fputs("DESCRIPTION",fp);
            
            for(i=0;i<23;i++)
            {
                fputc(' ',fp);
            }
            
            fputs("CREDIT",fp);
            
            for(i=0;i<10;i++)
            {
                fputc(' ',fp);
            }
            
            fputs("DEBIT",fp);
            
            for(i=0;i<10;i++)
            {
                fputc(' ',fp);
            }
            
            fputs("REMAINING",fp);
            
            fputs("\n",fp);
            fputs("\n",fp);
        
            for(i=0;i<2;i++)
            {
                fputc(' ',fp);
            }
            
            fputs("Opening Balance",fp);
            
            for(i=0;i<(42-strlen("Opening Balance")-2);i++)
            {
                fputc(' ',fp);
            }
            
            cout<<"Please enter the Opening Balance: ";
            cin>>start;
            
            ftos(start);
            
            fputs(c_num,fp);
            
            for(i=0;i<(31-strlen(c_num));i++)
            {
                fputc(' ',fp);
            }
            
            fputs(c_num,fp);
            
            fputs("\n",fp);
            
            for(i=0;i<7;i++)
            {
                c_num[i]=NULL;
            }
            
        }
        
    void close_month()
    {
        fseek(fp,-9,SEEK_END);
        char ch;
        int i=0;
        
        for(i=0;i<7;i++)
        {
            c_num[i]=NULL;
        }
        
        fseek(fp,-9,SEEK_END);
        
        i=0;
        
        ch=fgetc(fp);
        
        while(ch != EOF)
        {
            if(isdigit(ch))
            {
                c_num[i]=ch;
                i++;
            }
            else if(ch=='.')
            {
                c_num[i]=ch;
                i++;
            }
            ch=fgetc(fp);
        }
        
        fseek(fp,0,SEEK_END);
        
        for(i=0;i<25;i++)
        {
            fputc('=',fp);
        }
        
        fputc(' ',fp);
        fputc(' ',fp);
        fputc(' ',fp);
        fputc(' ',fp);
        
        fputs("REMAINING BALANCE: ",fp);
        fputs(c_num,fp);
        
        fputc(' ',fp);
        fputc(' ',fp);
        fputc(' ',fp);
        fputc(' ',fp);
        
        for(i=0;i<25;i++)
        {
            fputc('=',fp);
        }
        
        fputs("\n",fp);
        fputs("\n",fp);
        fputs("\n",fp);
    }
    
    void close_day()
    {
        char ch,date[10];
        int i;
        
        for(i=0;i<7;i++)
        {
            c_num[i]=NULL;
        }
        
        fseek(fp,-9,SEEK_END);
        
        i=0;
        
        ch=fgetc(fp);
        
        while(ch != EOF)
        {
            if(isdigit(ch))
            {
                c_num[i]=ch;
                i++;
            }
            else if(ch=='.')
            {
                c_num[i]=ch;
                i++;
            }
            ch=fgetc(fp);
        }
        
        fputs("\n",fp);
        
        for(i=0;i<25;i++)
        {
            fputc('x',fp);
        }
        
        fputc(' ',fp);
        fputc(' ',fp);
        fputc(' ',fp);
        fputc(' ',fp);
        
        fputs("CARRY FORWARD: ",fp);
        fputs(c_num,fp);
        
        fputc(' ',fp);
        fputc(' ',fp);
        fputc(' ',fp);
        fputc(' ',fp);
        
        for(i=0;i<25;i++)
        {
            fputc('x',fp);
        }
        
        fputs("\n",fp);
        fputs("\n",fp);
        
        cout<<"Enter new date: ";
        gets(date);
        
        for(i=0;i<36;i++)
            {
                fputc('-',fp);
            }
    
        fputc(' ',fp);
        
        fputs(date,fp);
        
        fputc(' ',fp);
    
        for(i=0;i<36;i++)
        {
            fputc('-',fp);
        }
        
        fputs("\n",fp);
        
        for(i=0;i<8;i++)
            {
                fputc(' ',fp);
            }
            
            fputs("DESCRIPTION",fp);
            
            for(i=0;i<23;i++)
            {
                fputc(' ',fp);
            }
            
            fputs("CREDIT",fp);
            
            for(i=0;i<10;i++)
            {
                fputc(' ',fp);
            }
            
            fputs("DEBIT",fp);
            
            for(i=0;i<10;i++)
            {
                fputc(' ',fp);
            }
            
            fputs("REMAINING",fp);
            
            fputs("\n",fp);
            fputs("\n",fp);
        
            for(i=0;i<2;i++)
            {
                fputc(' ',fp);
            }
            
            fputs("Opening Balance",fp);
            
            for(i=0;i<(42-strlen("Opening Balance")-2);i++)
            {
                fputc(' ',fp);
            }
            
            fputs(c_num,fp);
            
            for(i=0;i<(31-strlen(c_num));i++)
            {
                fputc(' ',fp);
            }
            
            fputs(c_num,fp);
            
            fputs("\n",fp);
    }
    
    void credit()
    {
        int i=0;
        char ch=NULL;
        
        for(i=0;i<7;i++)
        {
            c_num[i]=NULL;
        }
        
        for(i=0;i<40;i++)
        {
            description[i]=NULL;
        }
        
        cout<<"Credit Description: ";
        gets(description);
        
        cout<<"Enter the amount: ";
        cin>>cred;
        
        fseek(fp,-9,SEEK_END);
        
        ch=fgetc(fp);
        i=0;
        
        while(ch != EOF)
        {
            if(isdigit(ch))
            {
                c_num[i]=ch;
                i++;
            }
            else if(ch=='.')
            {
                c_num[i]=ch;
                i++;
            }
            ch=fgetc(fp);
        }
        
        rem=stof();
        
        rem =rem + cred;

        fseek(fp,0,SEEK_END);
        
        fputc(' ',fp);
        fputc(' ',fp);
        
        fputs(description,fp);
        
        for(i=0;i<(42-strlen(description)-2);i++)
            {
                fputc(' ',fp);
            }
            
        ftos(cred);
        
        fputs(c_num,fp);
        
        for(i=0;i<(31-strlen(c_num));i++)
            {
                fputc(' ',fp);
            }
        
        ftos(rem);
        
        fputs(c_num,fp);
        
        fputs("\n",fp);
        
    }
    
    void debit()
    {
        int i=0;
        char ch;
        
        for(i=0;i<7;i++)
        {
            c_num[i]=NULL;
        }
        
        for(i=0;i<40;i++)
        {
            description[i]=NULL;
        }
        i=0;
        cout<<"Debit Description: ";
        gets(description);
        
        cout<<"Enter the amount: ";
        cin>>deb;
        
        fseek(fp,-9,SEEK_END);
        
        ch=fgetc(fp);
        
        while(ch != EOF)
        {
            if(isdigit(ch))
            {
                c_num[i]=ch;
                i++;
            }
            else if(ch=='.')
            {
                c_num[i]=ch;
                i++;
            }
            ch=fgetc(fp);
        }
        
        rem=stof();
        
        rem = rem - deb;
        
        fseek(fp,0,SEEK_END);
        
        fputc(' ',fp);
        fputc(' ',fp);
        
        fputs(description,fp);
        
        for(i=0;i<(58-strlen(description)-2);i++)
            {
                fputc(' ',fp);
            }
            
        ftos(deb);
        
        fputs(c_num,fp);
        
        for(i=0;i<(15-strlen(c_num));i++)
            {
                fputc(' ',fp);
            }
        
        ftos(rem);
        
        fputs(c_num,fp);
        
        fputs("\n",fp);
        
    }
    
    void display()
    {
     fseek(fp,0,SEEK_SET);
     char ch;
     
     ch=fgetc(fp);
     while(ch != EOF)
     {
         cout<<ch;
         ch=fgetc(fp);
     }
    }
    
private:
    
    void ftos(float num)
    {
            int digit,i=0,diff,temp,j,k=0;
    
            temp=(int)num;
            num = num -temp;
            
            for(i=0;i<7;i++)
            {
                c_num[i]=NULL; 
            }

            while(temp!=0)
            {
                digit = temp%10;
                if(digit == 0)
                {
                    c_num[i]='0';
                }
                else if(digit == 1)
                {
                    c_num[i]='1';
                }
                else if(digit == 2)
                {
                    c_num[i]='2';
                }
                else if(digit == 3)
                {
                    c_num[i]='3';
                }
                else if(digit == 4)
                {
                    c_num[i]='4';
                }
                else if(digit == 5)
                {
                    c_num[i]='5';
                }
                else if(digit == 6)
                {
                    c_num[i]='6';
                }
                else if(digit == 7)
                {
                    c_num[i]='7';
                }
                else if(digit == 8)
                {
                    c_num[i]='8';
                }
                else if(digit == 9)
                {
                    c_num[i]='9';
                }
                temp=temp/10;
                i++;
            }
    
            j=0;
            i=i-1;
    
            while(j<i)
            {
                temp=c_num[j];
                c_num[j]=c_num[i];
                c_num[i]=temp;
                j++;i--;
            }

            c_num[strlen(c_num)]='.';
    
            i=0;
            digit=0;
    
            if(num == 0)
            {
                int length=strlen(c_num);
                c_num[length]='0';
                length++;
                c_num[length]='0';
            }
            else
            {   
                while(i<2)
                {
                    num=num*10;
                    temp=num;
                    digit=(digit*10)+temp;
                    num=num-temp;
                    i++;
                }
            }
    
            i=strlen(c_num)+1;
    
            while((i>=strlen(c_num)) && (digit!=0))
            {
                temp=digit%10;
                if(temp == 0)
                {
                    c_num[i]='0';
                }
                else if(temp == 1)
                {
                    c_num[i]='1';
                }
                else if(temp == 2)
                {
                    c_num[i]='2';
                }
                else if(temp == 3)
                {
                    c_num[i]='3';
                }
                else if(temp == 4)
                {  
                    c_num[i]='4';
                }
                else if(temp == 5)
                {
                    c_num[i]='5';
                }   
                else if(temp == 6)
                {
                    c_num[i]='6';
                }
                else if(temp == 7)
                {
                    c_num[i]='7';
                }
                else if(temp == 8)
                {
                    c_num[i]='8';
                }
                else if(temp == 9)
                {
                    c_num[i]='9';
                }
                digit=digit/10;
                i--;
            }
    }
    
    float stof()
    {
        int i,d;
        float num,toadd;
        num=0;
        i=0;
 
        while(c_num[i] != '.')
        {
            if(c_num[i]=='0')
            {
                num = num*10;
            }
            else if(c_num[i]=='1')
            {
                num = (num*10)+1;
            }
            else if(c_num[i]=='2')
            {
                num = (num*10)+2;
            }
            else if(c_num[i]=='3')
            {
                num = (num*10)+3;
            }
            else if(c_num[i]=='4')
            {
                num = (num*10)+4;
            }
            else if(c_num[i]=='5')
            {
                num = (num*10)+5;
            }
            else if(c_num[i]=='6')
            {
                num = (num*10)+6;
            }
            else if(c_num[i]=='7')
            {
                num = (num*10)+7;
            }
            else if(c_num[i]=='8')
            {
                num = (num*10)+8;
            }
            else if(c_num[i]=='9')
            {
                num = (num*10)+9;
            }
            i++;
        }

        i++;
        toadd=0;
        d=0;
 
        while(d<2)
        {
            if(c_num[i]=='0')
            {
                toadd = toadd*10;
            }
            else if(c_num[i]=='1')
            {
                toadd = (toadd*10)+1;
            }
            else if(c_num[i]=='2')
            {
                toadd = (toadd*10)+2;
            }
            else if(c_num[i]=='3')
            {
                toadd = (toadd*10)+3;
            }
            else if(c_num[i]=='4')
            {
                toadd = (toadd*10)+4;
            }
            else if(c_num[i]=='5')
            {
                toadd = (toadd*10)+5;
            }
            else if(c_num[i]=='6')
            {
                toadd = (toadd*10)+6;
            }
            else if(c_num[i]=='7')
            {
                toadd = (toadd*10)+7;
            }
            else if(c_num[i]=='8')
            {
                toadd = (toadd*10)+8;
            }
            else if(c_num[i]=='9')
            {
                toadd = (toadd*10)+9;
            }
    
            d++;
            i++;
        }
        
        toadd = toadd/100;
        
        num=num+toadd;
 
        return num;
    }
    
};

int main()
{
    expense e;
    int n=1,choice;
    char directory[100]="/home/codemaster_sb/Documents/expense.txt";
    
    e.fp = fopen(directory,"r+");
    
    if(e.fp == NULL)
    {
        e.fp = fopen(directory,"w+");
        fclose(e.fp);
        e.fp = fopen(directory,"r+");
        cout<<"File opened and ready to read and write."<<endl;
    }
    else
    {
        cout<<"File opened and ready to read and write."<<endl;
    }
    
    fclose(e.fp);
    
    while(n==1)
    {
        cout<<endl;
        cout<<"What do you want to do?"<<endl;
        cout<<"1) Enquire remaining balance available."<<endl;
        cout<<"2) Start account of new month."<<endl;
        cout<<"3) Close account of current month."<<endl;
        cout<<"4) Close account of current day."<<endl;
        cout<<"5) Enter Credit."<<endl;
        cout<<"6) Enter Debit."<<endl;
        cout<<"7) Exit Program."<<endl;
        cin>>choice;
        
        cin.ignore();
        
        switch(choice)
        {
            case 1:
                   e.fp = fopen(directory,"r+");
                   e.remaining();
                   fclose(e.fp);
            break;
            
            
            case 2:
                   e.fp = fopen(directory,"r+");
                   e.new_account();
                   e.display();
                   fclose(e.fp);
            break;
            
            
            case 3:
                   e.fp = fopen(directory,"r+");
                   e.close_month();
                   e.display();
                   fclose(e.fp);
            break;
            
            
            case 4:
                   e.fp = fopen(directory,"r+");
                   e.close_day();
                   e.display();
                   fclose(e.fp);
            break;
            
            
            case 5:
                   e.fp = fopen(directory,"r+");
                   e.credit();
                   e.display();
                   fclose(e.fp);
            break;
            
            
            case 6:
                   e.fp = fopen(directory,"r+");
                   e.debit();
                   e.display();
                   fclose(e.fp);
            break;
            
            
            case 7:
                   n=0;
            break;
            
            
            default:
                   cout<<"Please enter a valid decision."<<endl;
            break;
        }
    }
    
    return 0;
}
