#include <stdio.h>

void test1()
{
    printf("====%s=====\n", __func__);
}

void test2()
{
    printf("====%s=====\n", __func__);
}

void test3()
{
    printf("====%s=====\n", __func__);
}
//����һ������ָ����
typedef void(*FUNC)(void);
//����һ�����飬����ĳ�Ա��ָ��
//�Ǻ���ָ��
FUNC arr[] = {
    //�Ѻ���ע�ᵽ����
    test1,
    //test3
    test2,
};

//
void kill(int id)
{
    if(id >=(int)(sizeof(arr)/sizeof(arr[0])) ){
        printf("no function.\n");
        return;
    }

    arr[id]();
}
int main()
{
#if 0
    for(int i = 0; i < (int)(sizeof(arr)/sizeof(arr[0])); i++){
        if(arr[i]){
            arr[i]();  //�ص�����
        }
    }
#else
    kill(5);
#endif

    return 0;
}

