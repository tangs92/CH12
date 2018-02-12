/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Dlink.h
 * Author: poem
 *
 * Created on 2018年2月11日, 上午9:07
 */
#ifndef DLINK_H
#define DLINK_H
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdlib.h>
typedef struct Node 
{
    struct Node * fwd;
    struct Node * bwd;
    int value;
}Node;
typedef Node * pNode;
pNode generaterDList(int * arr,int size);//数组转链表
int getSizeDList(pNode list);//返回大小接口
void getPrintDList(pNode root);//打印链表接口
int getItemDList(pNode root, int index);//返回指定节点接口
pNode insertItemDList(pNode root, int index);//插入值到链表
int deleteItemDList(pNode root, int index);//删除指定节点接口
int deleteValueDList(pNode root, int index);//删除指定值接口
void deleteListDList(pNode *root);//删除整个列表
#endif /* DLINK_H */

