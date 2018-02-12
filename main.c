/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: poem
 *
 * Created on 2018年2月10日, 上午11:00
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdlib.h>
#include "Slink.h"
#include "Dlink.h"

#define TEST_WHAT 0//1是单链表 0 是双链表

#if TEST_WHAT ==1
//测试的下标
#define TEST1_VISIT 1
#define TEST1_DEL 2

#define TEST2_VISIT 3
#define TEST2_DEL 4

//测试用例

void test(int * arr, int size, WAYS methods, int visit, int del)
{
    printf("TEST START\n");
    pNODE root = generaterList(arr, size, methods); //生成链表
    getPrint(root); //打印链表
    getSize(root); //打印大小
    getItem(root, visit); //索引访问
    deleteItem(root, del); //索引删除
    deleteList(root); //销毁链表
    getSize(root); //确定删掉了
    free(root); //释放掉链表头
    printf("TEST FINISH\n\n");
}
#endif


#if TEST_WHAT ==0
//测试的下标
#define TEST1_VISIT 1
#define TEST1_DEL 100
#define TEST1_INSERT 100

void test(int * arr, int size, int visit, int del, int insert)
{
    printf("TEST START\n");
    pNode root = generaterDList(arr, size); //生成链表
    printf("Size = %d\n", getSizeDList(root));
    getPrintDList(root);
    printf("\n");

    int tmp = getItemDList(root, visit);
    if (tmp != -1)
        printf("#%d item is= %d\n", visit, tmp);
    else
        printf("#%d's item is not found\n", visit);

    pNode res = insertItemDList(root, insert);
    if (res != NULL)
    {
        printf("Insert %d success! Here is the new list:\n",insert);
        getPrintDList(root);
    }
    else
    {
        printf("Insert %d fail\n",insert);
    }
    printf("\n");
    int res2 = deleteValueDList(root, del);
    if (res2 != 1)
    {
        printf("Delete %d fail\n",del);
    }
    else
    {
        printf("Delete %d success! Here is the new list:\n",TEST1_DEL);
        getPrintDList(root);
    }
    printf("\nDelete All\n");
    deleteListDList(&root);
    printf("\nSize = %d\n", getSizeDList(root));



}
#endif

int main(void)
{
    int arr[] = {9, 2, 5, 3, 1, 10};
    int sz = sizeof (arr) / sizeof (arr[0]);
#if TEST_WHAT ==1
    test(arr, sz, LARGE2SMALL, TEST1_VISIT, TEST1_DEL); //从大到小
    test(arr, sz, SMALL2LARGE, TEST2_VISIT, TEST2_DEL); //从小到大
#endif

#if TEST_WHAT ==0
    test(arr, sz, TEST1_VISIT, TEST1_DEL, TEST1_INSERT);
#endif
    return (EXIT_SUCCESS);
}

