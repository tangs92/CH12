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

//测试的下标
#define TEST1_VISIT 1
#define TEST1_DEL 2

#define TEST2_VISIT 3
#define TEST2_DEL 4

//测试用例
void test(int * arr, int size, WAYS methods, int visit, int del)
{
    printf("TEST START\n");
    pNODE root = generaterList(arr, size, methods);//生成链表
    getPrint(root);//打印链表
    getSize(root);//打印大小
    getItem(root, visit);//索引访问
    deleteItem(root, del);//索引删除
    deleteList(root);//销毁链表
    getSize(root);//确定删掉了
    free(root);//释放掉链表头
    printf("TEST FINISH\n\n");

}

int main(void)
{
    int arr[] = {123,456,12,45,8,4564,222};
    int sz = sizeof (arr) / sizeof (arr[0]);
    test(arr, sz, LARGE2SMALL, TEST1_VISIT, TEST1_DEL);//从大到小
    test(arr, sz, SMALL2LARGE, TEST2_VISIT, TEST2_DEL);//从小到大
    return (EXIT_SUCCESS);
}

