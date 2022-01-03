#include "algo.h"

/*
version history
v0.1 2021/12/31
*/

/*   calculate()
帮助理解的图示
                986
               * 84 
               -----
                   4 <-add =2  num3 =4              

     ++     num_sum[0]           3944           //竖向相加(逆向)
            num_sum[1]          7888(0)
            ..........................

*/


big_number_algo::big_number_algo() //初始化
{
    cout << "大数计算程序 v0.1" << endl    
         << "现在可以运行." << endl; //基本说明
}

void big_number_algo::input() //输入函数
{
    int locate=0;   //分割数字时的寄存变量
    int counter=0;  //统计符号的连续出现次数,防止出现两个连续的符号
    int counter_spot=0;     //统计小数点出现的次数,防止一个数据出现两个小数点
    int end=0;   //结束标记
    bool judge[2] = {true,true}; //循环控制变量,从外向内依次为[0],[1],[2]...
    string input_sentence;  //输入的表达式
    string deliver[5];     //运送变量
    while (judge[0])
    {
        cout << "输入示例:" << endl
             << "(2000乘以3000乘以200):" << endl
             << "2000*3000*200" << endl;
        cout << "输入完成后按回车结束." << endl<<endl;
        cin >> input_sentence;
        if(input_sentence.size()>30000)
        {
            cout<<"输入的表达式过大!请重新输入."<<endl;
            input_sentence.clear();
            continue;
        }
        for (int n = 0; n < input_sentence.size(); n++) //记录最后一个符号出现的位置并打上结束标记
        {
            if (input_sentence[n] == '*')
            {
                end = n;
            }
            if (end == input_sentence.size() - 1)
            {
                cout << "输入的表达式不合规,最后一个字符是符号\"*\".请重新输入." << endl;
                continue;
            }
            if (input_sentence[input_sentence.size() - 1] == '.')
            {
                cout << "输入的表达式不合规,最后一个字符是符号\".\".请重新输入." << endl;
                continue;
            }
        }
        for(int k = 0; k < input_sentence.size()&&k!=-1; k++)
        {
            switch (input_sentence[k])
            {
                case '1':   //如果是数字,略过,遇到符号分割
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                case '0':
                counter=0;
                break;
                case '.':       //一个数字之间不能有2个. 且.和*不能连在一起
                counter_spot++; 
                counter++;
                if(counter==2||counter_spot==2)
                {
                    cout<<"输入的表达式不合规,2个符号连续出现,或者一个数字中含有2个小数点.请重新输入."<<endl;
                    k=-2;
                    counter_spot=0;
                    counter=0;
                    judge[1]=false;
                    break;
                }
                break;

                case '*':
                counter++;
                counter_spot=0;
                 if(k==0)//如果第一个字符就是运算符
                {
                    cout<<"输入的表达式不合规,第一个字符不能为\"*\"."<<endl;
                    k=-2;
                    judge[1]=false;
                    break;
                }
                if(counter==2)//如果有运算符连在一起
                {
                    cout<<"输入的表达式不合规,有多个符号连在一起."<<endl;
                    k=-2;
                    counter=0;
                    judge[1]=false;
                    break;
                }
                for(;locate<k;locate++)//将运算符前的数字和小数点连起来放进nums
                {
                    deliver[0]+=input_sentence[locate];
                }
                nums.push_back(deliver[0]);
                deliver[1]+=input_sentence[locate];//将运算符放进emblems
                emblems.push_back(deliver[1]);
                deliver[0].clear();
                deliver[1].clear();
                locate=k+1;
                break;

                default:
                cout<<"输入的表达式不合规,含有不合规字符,请重新输入."<<endl<<endl;
                k=-2;
                judge[1]=false;
                break;
            }
        }
        if (judge[1] == true)
        {
            //将最后一个运算符后面的数字存入
            for (int n = end + 1; n < input_sentence.size(); n++)
            {
                deliver[0] += input_sentence[n];
            }
            nums.push_back(deliver[0]);
            deliver[0].clear();
            // cout<<judge[1]<<endl;
            judge[0] = false;
        }
        else
        {
            locate=0;
            nums.clear();
            emblems.clear();
            judge[1] = true;
        }
    }
    //以下为调试代码
    /*
        cout<<"nums:";
        for(int k=0;k<nums.size();k++)
        {
            cout<<nums[k]<<",";
        }
        cout<<endl<<endl;
        cout<<"emblems:";
        for(int k=0;k<emblems.size();k++)
        {
            cout<<emblems[k]<<",";
        }
        cout<<endl<<endl;
        //system("pause");
    */
}

void big_number_algo::calculate()
{
    //cout<<"cal"<<endl;
    vector<string> num_sum;           //数字集合 相当于乘法竖式中纵向相加的多行数字
    int num1 = 0, num2 = 0, num3 = 0; //用于数学计算的变量
    int add=0;              //进位数字
    string tem_str;//临时储存数字的变量
    string reverse;//倒置后的字符串
    if (emblems[eml] == "*")          //乘法
    {

        for (int n = nums[eml + 1].size() - 1; n >= 0; n--) //符号数永远比数字数量少一个,所以eml+1不会溢出,低位向高位乘
        {
            //cout<<"for 1"<<endl;
            switch (nums[eml + 1][n])
            {
            case '0':
                num2 = 0;
                break;
            case '1':
                num2 = 1;
                break;
            case '2':
                num2 = 2;
                break;
            case '3':
                num2 = 3;
                break;
            case '4':
                num2 = 4;
                break;
            case '5':
                num2 = 5;
                break;
            case '6':
                num2 = 6;
                break;
            case '7':
                num2 = 7;
                break;
            case '8':
                num2 = 8;
                break;
            case '9':
                num2 = 9;
                break;
            default: //说明出bug了

                break;
            }
            for (int k = nums[eml].size()-1; k >=0; k--) //由于设定了表达式长度不超过30000,所以int类型应该不会溢出
            {                                          //这里用第一个数字中的每个数逐个乘以第二个数的每个数(逆向),从低位向高位乘,后一个数乘前一个数
                switch (nums[eml][k])
                {
                case '0':
                    num1 = 0;
                    break;
                case '1':
                    num1 = 1;
                    break;
                case '2':
                    num1 = 2;
                    break;
                case '3':
                    num1 = 3;
                    break;
                case '4':
                    num1 = 4;
                    break;
                case '5':
                    num1 = 5;
                    break;
                case '6':
                    num1 = 6;
                    break;
                case '7':
                    num1 = 7;
                    break;
                case '8':
                    num1 = 8;
                    break;
                case '9':
                    num1 = 9;
                    break;
                default: //说明出bug了

                    break;
                }
               // cout<<"num1:"<<num1<<"  num2:"<<num2<<endl;
                num3=num1*num2+add;//逐个相乘,并算上进位数字
                add=0;
                if(num3>=10)//大于10 说明需要进位
                {
                    add=num3/10;        //获取进位的数字,num3与add都为int型  所以是整除
                    num3=num3-add*10;      //记录除去进位后的个位数
                }
               // cout<<"num3:"<<endl<<num3<<endl;
               // cout<<"add:"<<endl<<add<<endl;
                tem_str+=to_string(num3);//先逆向将数字连起来,然后再反转字符串
                if(k==0)//如果是最后一位数,把add补上
                {
                    tem_str+=to_string(add);
                }
               // cout<<"tem_str:"<<endl<<tem_str<<endl;
               // system("pause");
            }
            //将tem_str反转
            for(int k=tem_str.size()-1;k>=0;k--)//反转字符串
            {
                reverse+=tem_str[k];
            }
           // cout<<"reverse:"<<reverse<<endl;
            num_sum.push_back(reverse);//将一行计算结果存入num_sum
            reverse.clear();//清空变量 
            //tem=0;
            tem_str.clear();
            num1=0,num2=0,num3=0,add=0;//重置变量
        }
        /*
        for(int k=0;k<num_sum.size();k++)
        {
            cout<<num_sum[k]<<endl;
        }
        */
      //  system("pause");
        
        
        for(int k=0;k<num_sum.size();k++)//按位给加数乘10
        {
            //cout<<"for 2"<<endl;
            for(int n=0;n<k;n++)//按位给加数乘10
            {
                //cout<<"for 3"<<endl;
                //cout<<"num_add_10:"<<endl<<num_add_10<<endl;
                num_sum[k]+='0';
            }
        }
        //system("pause");
        for(int k=0;k<num_sum.size()-1;k++)//乘法竖式中的多行数字纵向相加(逆向)
        {
            //cout<<"for 4"<<endl;
            for(int n=num_sum[k].size()-1,j=num_sum[k+1].size()-1;n>=0||j>=0;)//逐个相加
            {                                   
               // cout<<"for 5"<<endl;   
                //cout<<"n:"<<n<<"j:"<<j<<endl;
                if(n>=0)//防止数组越界
                {
                num1=((int)num_sum[k][n]-48);   //将char转为int,用于计算
               // cout<<num_sum[k]<<endl;
                //cout<<"num1: " <<num1<<endl;
                }
                else
                {
                    //cout<<"num1=0"<<endl;
                    num1=0;
                }
                if(j>=0)//防止数组越界
                {
                num2=((int)num_sum[k+1][j]-48);
                //cout<<"num_sum["<<k<<"]"<<endl<<num_sum[k]<<endl;
                //cout<<"num_sum["<<k<<"]"<<"["<<j<<"]"<<": "<<num_sum[k][j]<<endl;
                //cout<<(int)num_sum[k][j]<<endl;
                }
                else
                {
                    num2=0;
                }
              //  cout<<"num1:"<<num1<<"num2:"<<num2<<endl;
                num3=num1+num2+add;
                add=0;
                //cout<<"num1 : "<<num1<<endl<<endl;
                //cout<<endl<<"num3: "<<num3<<endl;
                if(num3>=10)
                {
                    add=num3/10;//整除
                    num3=num3-add*10;//获取个位数
                }
               // cout<<"add: "<<add<<endl<<"num1: "<<num1<<endl<<"num2: "<<num2<<endl<<"num3: "<<num3<<endl;
                //system("pause");
                tem_str+=to_string(num3);//逆向链接,到时候再反转
                if(j==0&&n==0)//如果后一个数是最后一次加法 那么加数等不到下一个加法了,直接补上
                {
                    tem_str+=to_string(add);
                }
               // cout<<"tem_str:"<<endl<<tem_str<<endl;
                //system("pause");
                if(n>=0)
                {
                    n--;
                }
                if(j>=0)
                {
                    j--;
                }
            }

            for(int n=tem_str.size()-1;n>=0;n--)//反转
            {
                reverse+=tem_str[n];
            }
            num_sum[k+1]=reverse;//将算完的结果替换原来的后面的加数,进行下一次加法
          //  cout<<reverse<<endl;
           // cout<<"num_sum"<<endl<<endl;
           /*
            for(int p=0;p<num_sum.size();p++)
            {
                cout<<num_sum[p]<<endl;
            }
            */
            //system("pause");
            tem_str.clear();//清空所有变量
            reverse.clear();
            num1=0,num2=0,num3=0,add=0;
        }
        nums[eml+1]=num_sum[num_sum.size()-1];//获取最终的纵向相加结果,进行下一次乘法
        if(eml<emblems.size()-1)
        {
            eml++;
            //cout<<"eml:"<<eml<<endl;
           // cout<<emblems.size()<<endl;
            //system("pause");
            calculate();//继续计算,递归
        }
        else
        {
            result=nums[nums.size()-1];
            return;
        }
    }
}

void big_number_algo::print()   //打印结果
{
    cout<<"result:"<<endl<<result<<endl;
}