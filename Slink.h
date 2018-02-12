/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Slink.h
 * Author: poem
 *
 * Created on 2018年2月10日, 下午3:54
 */

#ifndef SLINK_H
#define SLINK_H

#ifdef __cplusplus
extern "C"
{
#endif

    typedef struct NODE
    {
        struct NODE * link;
        int value;
    } NODE;

    typedef NODE * pNODE;

    //S2L small -> larget
    //L2S large -> small

    typedef enum WAYS
    {
        SMALL2LARGE,
        LARGE2SMALL,
    } WAYS;

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdlib.h>
    
pNODE generaterList(int * arr, int size, WAYS methods);////数组转链表
int getSize(pNODE list);//返回大小接口
void getPrint(pNODE root);//打印链表接口
int getItem(pNODE root, int index);//返回指定节点接口
int deleteItem(pNODE root, int index);//删除指定节点接口
void deleteList(pNODE root);//删除整个列表
pNODE insertNodeS2L(pNODE list, int value);
pNODE insertNodeL2S(pNODE list, int value);

#ifdef __cplusplus
}
#endif

#endif /* SLINK_H */

