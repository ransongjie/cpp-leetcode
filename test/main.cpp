#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

void test1();//cpp 方法头
void test2();

int main(){
    test2();
}
void test2(){
    //vector sum 求和
    vector<int> vec;//创建
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    int sum=accumulate(vec.begin(),vec.end(),0);
    cout<<sum<<endl;
}

void test1(){
    //string 获取字符
    string str="xcrj";
    cout<<str[3]<<endl;
    cout<<str.at(3)<<endl;

    //string长度
    cout<<str.size()<<endl;
}