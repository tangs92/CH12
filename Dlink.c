/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Dlink.cpp
 * Author: poem
 * 
 * Created on 2018年2月11日, 上午9:07
 */

#include "Dlink.h"

//最后一个节点的后继是NULL
//传入链表的头指针

pNode _insertNode(pNode root, int value)
{
    pNode this;
    pNode next;
    pNode newNode;

    //this指向新节点之前的那一个节点
    //next指向新节点之后的那一个节点

    //先检测value是不是已经在链表中了
    for (this = root; (next = this->fwd) != NULL; this = next)
    {
        if (next->value == value)
            return NULL;
        if (next->value > value)
            break;
    }

    newNode = (pNode) malloc(sizeof (pNode));
    if (newNode == NULL)
        return NULL;
    newNode->value = value;

    //注意!!!
    //空链表下,根节点的fwd和bwd都为NUL
    //第一个节点的bwd=NUL
    //最后一个节点的fwd=NUL

    //root的fwd指第一个节点
    //root的bwd指最后一个节点

    //原始的代码

    //    if (next != NULL)
    //    {
    //        //next != NULL 
    //        newNode->fwd = next;
    //        //并非位于链表的尾部
    //        if (this != root)
    //        {
    //            //并非位于链表的起始位置 非常正常的插在中间的情况情况            
    //            this->fwd = newNode;
    //            newNode->bwd = this;
    //        }
    //        else
    //        {
    //            //位于链表的起始位置 插在第一个元素之前的那种情况
    //            root->fwd = newNode;
    //            newNode->bwd = NULL;
    //
    //        }
    //        next->bwd = newNode;
    //    }
    //    else
    //    {
    //        //next == NULL 
    //        newNode->fwd = next;
    //        //位于链表的尾部
    //        if (this != root)
    //        {
    //            //并非位于链表的起始位置 插在最后一个节点之后的那种情况 先后再前
    //            this->fwd = newNode;
    //            newNode->bwd = this;
    //        }
    //        else
    //        {
    //            //位于链表的起始位置 这是插入第一个节点的情况
    //
    //            root->fwd = newNode;
    //            newNode->bwd = NULL;
    //        }
    //        root->bwd = newNode;
    //    }

    ////以下是逻辑提炼后的代码
    newNode->fwd = next;

    //新节点的前驱不是头结点的情况
    if (this != root)
    {
        this->fwd = newNode;
        newNode->bwd = this;
    }
    else
    {
        root->fwd = newNode;
        newNode->bwd = NULL;
    }

    //新节点的后继不是空的情况
    if (next != NULL)
    {
        next->bwd = newNode;
    }
    else
    {
        root->bwd = newNode;
    }
    return newNode;
}

pNode _initDList(int * arr, int size)
{
    pNode pStart = malloc(sizeof (Node));


    if (pStart == NULL)
        return NULL;

    pStart->bwd = NULL;
    pStart->fwd = NULL;

    pStart->value = 0;

    for (int i = 0; i < size; i++)
    {
        _insertNode(pStart, *(arr + i));
    }
    return pStart;

}

int _delNodeByPtr(pNode root, pNode ptr)
{
    pNode this;
    pNode next;

    if (root->fwd == NULL)//空链表的情况
        return -1;

    for (this = root; (next = this->fwd) != NULL; this = next)
    {
        if (next->value == ptr->value)
            break;
    }
    //    printf("ss");

    if (this != NULL && next == NULL)//找不到这个数
        return -1;

    if (next->fwd != NULL)
    {
        //如果下一个不是结尾
        this->fwd = next->fwd;
        if (this != root)
        {
            //如果当前位置不是头    
            next->fwd->bwd = this;
        }
        else
        {
            //如果当前位置是头
            next->fwd->bwd = NULL;
        }
        next->fwd = next->bwd = NULL;
    }
    else
    {
        //如果下一个是结尾
        if (this != root)
        {
            //如果当前位置不是头
            this->fwd = NULL;
            root->bwd = this;

            next->fwd = next->bwd = NULL;
            //            free(next);
        }
        else
        {
            root->bwd = root->fwd = NULL;

        }
    }


    free(next);


    return 1;
}
//////////////////对外接口///////////////////////////////

pNode generaterDList(int * arr, int size)//数组转链表
{
    pNode start = _initDList(arr, size);
    if (start == NULL)
        return NULL;
    return start;
}

int getSizeDList(pNode root)//返回大小接口
{
    //空链表下,根节点的fwd和bwd都为NUL
    //第一个节点的bwd=NUL
    //最后一个节点的fwd=NUL
    if (root == NULL)
        return 0;
    pNode tmp = root->fwd;
    int sz = 0;
    while (tmp != NULL)
    {
        sz++;
        tmp = tmp->fwd;
    }
    return sz;

}

void getPrintDList(pNode root)//打印链表接口
{
    pNode tmp = root->fwd;
    while (tmp != NULL)
    {
        printf("%d ", tmp->value);
        tmp = tmp->fwd;
    }
}

int getItemDList(pNode root, int index)//返回指定节点接口
{
    int _index = index - 1;
    register pNode tmp = root->fwd;
    int i = 0;
    while (tmp->fwd != NULL && i < _index)
    {
        tmp = tmp->fwd;
        i++;
    }
    if (i < _index)
        return -1;
    else
        return tmp->value;
}

pNode insertItemDList(pNode root, int value)//插入值到链表
{
    if (root == NULL)
        return NULL;
    return _insertNode(root, value);
}

int deleteItemDList(pNode root, int index)//删除指定下标节点接口
{
    pNode this;
    pNode next;
    int _index = index;
    if (root->fwd == NULL)
        return -1;
    int i = 0;
    for (this = root; ((next = this->fwd) != NULL) &&(i < _index); this = next, i++)
    {
        ;
    }

    if (i < _index)
        return -1;
    else
    {
        if (_delNodeByPtr(root, this) == 1)
        {
            return 1;
        }
    }
    return -1;
}

int _delNodeByVal(pNode root, int value)
{
    pNode this;
    pNode next;

    if (root->fwd == NULL)//空链表的情况
        return -1;

    for (this = root; (next = this->fwd) != NULL; this = next)
    {
        if (next->value == value)
            break;
    }

    if (this != NULL && next == NULL)//找不到这个数
        return -1;

    if (next->fwd != NULL)
    {
        //如果下一个不是结尾
        this->fwd = next->fwd;
        if (this != root)
        {
            //如果当前位置不是头    
            next->fwd->bwd = this;
        }
        else
        {
            //如果当前位置是头
            next->fwd->bwd = NULL;
        }
        next->fwd = next->bwd = NULL;
    }
    else
    {
        //如果下一个是结尾
        if (this != root)
        {
            //如果当前位置不是头
            this->fwd = NULL;
            root->bwd = this;

            next->fwd = next->bwd = NULL;
        }
        else
        {
            root->bwd = root->fwd = NULL;

        }
    }
    free(next);
    return 1;
}

int deleteValueDList(pNode root, int val)//删除指定值接口
{
    return _delNodeByVal(root, val);
}

void deleteListDList(pNode * root)//删除整个列表
{
    pNode tmp = NULL;
    //从头往后free,free一个头往前移
    while (*root != NULL)
    {
        tmp = (*root)->fwd;
        free(*root);
        *root = tmp;
    }

}