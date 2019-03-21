#include<bits/stdc++.h>
using namespace std;

int main(){
    long long light[3];
	long long N,a,b,tim=0;
    cin>>light[0]>>light[2]>>light[1];//下标 0红 2黄 1绿 
    cin>>N;
    long long sum=light[0]+light[1]+light[2];//sum为红绿灯变换一周的总时长
    while(N--){
    	cin>>a>>b;
        if(a==0)//是道路
            tim+=b;//时长直接递增
        else{//是红绿灯
            if(a==1)//将红绿灯标号变为light数组的下标
                a=0;
            else if(a==3)
                a=1;
            b=(light[a]-b+tim)%sum;//该红绿灯变换的最后一周的时长
            while(b>light[a]){//若b比当前红绿灯时长长
                b-=light[a];//减去当前的红绿灯时长
                a=(a+1)%3;//转向下一个红绿灯
            }
            if(a==0)//是红灯
                tim+=light[a]-b;//加上红灯剩余时长
            else if(a==2)//是黄灯
                tim+=light[a]-b+light[0];//加上黄灯剩余时长以及一个红灯时长
        }
    }
    cout<<tim;
    return 0;
}
