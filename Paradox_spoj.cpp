#include <iostream>
#include<stdio.h>

using namespace std;

#define MX 10000000

int main()
{
	int T;
	while(1)
	{
		int N,i,j,k;
		cin>>N;
		if(N==0)
			return 0;

		int dis[N+1][N+1];

		for(i=0; i<=N ; i++)
			for(j=0 ; j<=N ; j++)
				dis[i][j] = MX;

		for(i=1 ; i<=N ; i++)
		{
			int x;
			string str;
			cin>>x>>str;
			if(str == "true")
				dis[i][x] = 2;
			else
				dis[i][x] = 1;
		}
        printf("dis[i][j] before \n");
        for(i=1;i<=N;i++)
        {
           for(j=1;j<=N;j++)
           {
              cout<<dis[i][j];
            }
            cout<<endl;
        }
		for(k=1;k<=N;k++)
		{
			for(i=1;i<=N;i++)
			{
				for(j=1;j<=N;j++)
				{
					if(dis[i][j]>dis[i][k]+dis[k][j])
					{
					    printf("%d %d %d\n",dis[i][j],dis[i][k],dis[k][j]);
						dis[i][j]=dis[i][k]+dis[k][j];
					}
				}
			}
		}
             printf("dis[i][j] after \n");
             for(i=1;i<=N;i++)
			{
				for(j=1;j<=N;j++)
				{
                    cout<<dis[i][j];
				}
				cout<<endl;
			}


		int temp=0;
		for(i=1 ; i<=N ; i++)
		{
			if(  dis[i][i] % 2 == 1)
			{
				cout<<"PARADOX"<<endl;
				temp = 1;
				break;
			}

		}
		if(temp == 0)
		{
			cout<<"NOT PARADOX"<<endl;
		}
	}
	return 0;
}
