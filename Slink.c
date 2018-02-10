/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Slink.h"
//初始化链表头(从小到大)链表头默认不放内容,只是一个最小值

pNODE initListS2L(void)
{
    pNODE root = malloc(sizeof (NODE));
    if (root == NULL)
        return NULL;
    root->link = NULL;
    root->value = INT_MIN;
    return root;
}

//初始化链表头(从大到小)链表头默认不放内容,只是一个最大值

pNODE initListL2S(void)
{
    pNODE root = malloc(sizeof (NODE));
    if (root == NULL)
        return NULL;
    root->link = NULL;
    root->value = INT_MAX;
    return root;
}

//从小到大插入

pNODE insertNodeS2L(pNODE list, int value)
{
    if (list == NULL)
        return NULL;
    pNODE current = list;//当前位置
    pNODE previous = NULL;//前一个位置
    pNODE newNode = malloc(sizeof (NODE));
    if (newNode == NULL)
        return NULL;
    //寻找插入位置
    while (current != NULL && current->value < value)
    {
        previous = current; //记录下前一个节点的地址
        current = current->link; //移到下一个节点
    }
    if (current != NULL)//当前节点为空吗
    {
        //不为空
        previous->link = newNode; //先前驱
        newNode->link = current; //再后继
        newNode->value = value;
    }
    else
    {
        //为空
        previous->link = newNode;
        newNode->link = NULL;//新节点作为尾节点
        newNode->value = value;
    }
    return newNode;
}
//从大到小插入

pNODE insertNodeL2S(pNODE list, int value)
{
    if (list == NULL)
        return NULL;
    pNODE current = list;//当前位置
    pNODE previous = NULL;//前一个位置
    pNODE newNode = malloc(sizeof (NODE));
    if (newNode == NULL)
        return NULL;
    //寻找插入位置
    while (current != NULL && current->value > value)
    {
        previous = current;
        current = current->link;
    }

    if (current != NULL)//当前节点为空
    {
        newNode->value = value;
        newNode->link = current; //先处理新节点的后继
        previous->link = newNode; //再处理新节点的前驱
    }
    else
    {
        newNode->value = value;
        newNode->link = NULL;
        previous->link = newNode;
    }
    return newNode;
}

//打印节点

void printList(int item)
{
    printf("%d ", item);
}
//返回链表大小

int getListSize(pNODE list)
{
    pNODE ptr = list;
    int sz = 0;
    while (ptr != NULL)
    {
        //跳过头节点
        if (ptr->value == INT_MAX || ptr->value == INT_MIN)
        {
            ptr = ptr->link;
            continue;
        }
        else
        {
            sz++;
        }
        ptr = ptr->link;
    }
    return sz;
}

//链表遍历

void visitEachNode(pNODE list, void(*func)(int))
{
    pNODE ptr = list;
    while (ptr != NULL)
    {
        //跳过头节点
        if (ptr->value == INT_MAX || ptr->value == INT_MIN)
        {
            ptr = ptr->link;
            continue;
        }
        else
        {
            func(ptr->value);
        }
        ptr = ptr->link;
    }

        printf("\n");
}

//返回指定节点

int getSelectNode(pNODE root, int index)
{
    pNODE ptr = root;
    pNODE prev = NULL;
    if (root == NULL || index <= 0)
        return -1;//返回参数错误
    int i = 0;
    while (ptr != NULL && i < index)
    {
        //跳过头节点
        if (ptr->value == INT_MAX || ptr->value == INT_MIN)
        {
            prev = ptr;
            ptr = ptr->link;
            continue;
        }
        prev = ptr;
        ptr = ptr->link;
        i++;
    }

    if (i < index)
    {
        return -2;//找不到的情况
    }
    return prev->value;

}

//删除指定节点

int deleteSeletedNode(pNODE root, int index)
{
    pNODE ptr = root;
    pNODE prev = NULL;

    int _index = index - 1;//处理下标

    if (root == NULL || _index < 0)
        return -1;
    if (index == 0)//处理删第一个元素的问题
        index++;

    int i = 0;
    while (ptr != NULL && i < _index)
    {
        //跳过第一个
        if (ptr->value == INT_MAX || ptr->value == INT_MIN)
        {
            prev = ptr;
            ptr = ptr->link;
            continue;
        }
        prev = ptr;
        ptr = ptr->link;
        i++;
    }

    //判断找到了删除的位置吗
    if (ptr != NULL)
    {
        //找到了
        if (prev == NULL)
        {
            //处理删除第一个元素的问题
            //手动把prev指向链表头
            //ptr指向第一个元素
            prev = root;
            ptr = prev->link;
            
            //删除第一个元素
            prev->link = ptr->link;
            ptr->link = NULL;
            ptr->value = 0;
        }
        else
        {
            //正常的删除节点
            prev->link = ptr->link;
            ptr->link = NULL;
            ptr->value = 0;
        }

    }
    else
    {
        //找不到,报错退出
        return -1;
    }
    free(ptr);//释放掉删除的元素
    return 1;
}

//返回大小接口

int getSize(pNODE root)
{
    int sz = 0;
    if (root->link == NULL)//处理空链表
    {
        printf("size = 0\n");
        return 0;
    }
    else
    {
        sz = getListSize(root);//处理正常的情况
        printf("size = %d\n", sz);
    }

    return sz;
}

//返回指定节点接口

int getItem(pNODE root, int index)
{
    int res = getSelectNode(root, index);
    if (res != -1 && res != -2)
    {
        //正常的情况
        printf("#%d's Item is %d\n", index, res);
    }
    else
    {
        //找不到的情况
        printf("#%d's Item is not found\n", index);
    }
}

//删除指定节点接口

int deleteItem(pNODE root, int index)
{
    printf("Delete #%d's Item\n", index);
    if (deleteSeletedNode(root, index) == 1)
    {
        //正常情况
        printf("Delete #%d's Item success. Here is the list now\n", index);
        visitEachNode(root, printList);
    }
    else
    {
        //找不到删除元素的情况
        printf("Delete #%d's Item fail.\n", index);
    }
}

//打印链表接口

void getPrint(pNODE root)
{
    //遍历打印
    visitEachNode(root, printList);
}

//数组转链表

pNODE generaterList(int * arr, int size, WAYS methods)
{
    pNODE root = NULL;
    //根据选择,决定是从小到大,还是从大到小
    if (methods == LARGE2SMALL)
    {
        root = initListL2S();
        for (int i = 0; i < size; i++)
            insertNodeL2S(root, *(arr + i));
    }
    else
    {
        root = initListS2L();
        for (int i = 0; i < size; i++)
            insertNodeS2L(root, *(arr + i));
    }

    return root;
}
//删除整个列表

void deleteList(pNODE root)
{
    printf("Delete All\n");
    int sz = getSize(root);
    //逆序释放每一个元素
    for (; sz > 0; sz--)
    {
        deleteSeletedNode(root, sz);
    }
    printf("Delete Finish\n");

}