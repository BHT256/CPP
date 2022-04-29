#include <iostream>
#include <string>
using namespace std;
int main()
{
    char str[] = "programming charm\0"; //源字符串
    cout << "输入要搜索的某个字符:" << endl;
    fflush(stdin); //重刷新缓存区 确保在下一次输入时不会有额外的字符进入标准输入流中
    char str2[20];              //要查找的字符串
    fgets(str2, 19, stdin);
    char* res;
    res = (char*)memchr(str, str2[0], strlen(str));  //根据要查找的字符串第一个字符，切割源字符串
    if (res == NULL)
    {
        cout << "找不到" << endl;
        return 0;
    }
    int n;
    while (1)
    {
        n = memcmp(res, str2, strlen(str2) - 1); //比较
        if (n != 0)
        {
            if (strlen(res) <= strlen(str2))  //切割出的字符串小于要查找字符串的长度
            {
                cout << "找不到" << endl;
                return 0;
            }
            else
            {
                //根据要查找的第一个字符继续切割
                res = (char*)memchr(res + 1, str2[0], strlen(res));
                if (res == NULL)
                {
                    cout << "找不到" << endl;
                    return 0;
                }
            }
        }
        else
        { //如果n = 0，找到
            cout << "已经找到" <<str2<< endl;
            return 0;
        }
    }
}
