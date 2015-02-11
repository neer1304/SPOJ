#include<string>
#include<iostream>
#include<string.h>
using namespace std;
string str;int main() { int t;cin>>t>>ws;while(t--){getline(cin,str);int len=str.length();int flag=0;for(int i=0;i<len;i++){if(str[i]==' ')i++;char t0[1]; t0[0]= str[i];if(!strcmp(t0,"I")){for(int j=i+1;j<len;j++){char t1[4];if(str[j]==' ')j++;t1[0] = str[j];t1[1] = str[j+1];t1[2] = str[j+2];t1[3] = str[j+3];if(!strcmp(t1,"LOVEI")){for(int k=j+1;k<len;k++){if(str[k]==' ')k++;char t2[3];t2[0] = str[k];t2[1] = str[k+1];t2[2] = str[k+2];if(!strcmp(t2,"YOULOVEI")){flag=1;break;}}}}}}if(flag) cout<<"I LOVE YOU TOO."<<endl;else cout<<"HARD LUCK PRACHI."<<endl;}return 0;}

#if 0
#include<stdio.h>
#include<string>
#include<string.h>
#include<iostream>
using namespace std;

string str;

int main()
{
    int t;
    cin>>t>>ws;

    while(t--)
    {
       // scanf("%s",&str);
        getline(cin,str);
        int len=str.length();
        printf("len is %d\n",len);
        int flag=0;
        for(int i=0;i<len;i++)
        {
            if(str[i]==' ')
                i++;
            char t0[1]; t0[0]= str[i];
            printf("t0 is %s\n",t0);
            if(!strcmp(t0,"I"))
            {
                printf("inside one\n");
                for(int j=i+1;j<len;j++)
                {
                    char t1[4];
                   // memset(t1,0,4);
                    if(str[j]==' ')
                        j++;
                    t1[0] = str[j];
                    t1[1] = str[j+1];
                    t1[2] = str[j+2];
                    t1[3] = str[j+3];
                     printf("t1 is %s\n",t1);
                    if(!strcmp(t1,"LOVEI"))
                    {
                       //  printf("inside two\n");
                        for(int k=j+1;k<len;k++)
                        {
                            if(str[k]==' ')
                              k++;
                            char t2[3];
                            t2[0] = str[k];t2[1] = str[k+1];t2[2] = str[k+2];
                           // printf("t2 is %s\n",t2);
                            if(!strcmp(t2,"YOULOVEI"))
                            {
                                printf("inside three\n");
                                flag=1;
                                break;
                            }
                        }
                    }
                }
            }
        }

        if(flag)
            printf("I LOVE YOU TOO.\n");
        else
            printf("HARD LUCK PRACHI.\n");

    }
    return 0;
}
#endif
