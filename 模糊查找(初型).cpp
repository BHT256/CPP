#include <iostream>
#include <string>
using namespace std;
int main()
{
    char str[] = "programming charm\0"; //Դ�ַ���
    printf("����Ҫ������ĳ���ַ�:\n");
    fflush(stdin); //��ˢ�»����� ȷ������һ������ʱ�����ж�����ַ������׼��������
    char str2[20];              //Ҫ���ҵ��ַ���
    fgets(str2, 19, stdin);
    char* res;
    res = (char*)memchr(str, str2[0], strlen(str));  //����Ҫ���ҵ��ַ�����һ���ַ����и�Դ�ַ���
    if (res == NULL)
    {
        printf("�Ҳ���\n");
        return 0;
    }
    int n;
    while (1)
    {
        n = memcmp(res, str2, strlen(str2) - 1); //�Ƚ�
        if (n != 0)
        {
            if (strlen(res) <= strlen(str2))  //�и�����ַ���С��Ҫ�����ַ����ĳ���
            {
                printf("�Ҳ���\n");
                return 0;
            }
            else
            {
                //����Ҫ���ҵĵ�һ���ַ������и�
                res = (char*)memchr(res + 1, str2[0], strlen(res));
                if (res == NULL)
                {
                    printf("�Ҳ���\n");
                    return 0;
                }
            }
        }
        else
        { //���n = 0���ҵ�
            printf("���ҵ�%s\n", str2);
            return 0;
        }
    }
}