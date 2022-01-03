#include "standard.h"

class big_number_algo
{
public: 
    big_number_algo();  //初始化
    void input();     //输入函数
    void calculate();   //计算函数
    void print();   //打印结果
    void cleaner(); //打扫战场准备下一次计算
private:
    vector<string> nums;                //乘数
    vector<string> emblems;              //符号
    string result;      //计算结果
    int eml=0;      //符号位置
};