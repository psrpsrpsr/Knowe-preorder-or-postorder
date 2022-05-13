#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;
#define MAX 100

string s1 = "abcdef";//先序
string s2 = "cbaedf";//中序
string s3 = "cbefda";//后序

void fun1(int l1, int r1, int l2, int r2)//分别传入先序的前后下标l1、r1和后序的前下标l2、r2
{ 
	if (l1 > r1)//结束条件
	{
		return;
	}
	for (int i = l2; i <= r2; i++)
	{
		if (s2[i] == s1[l1])//找出根节点的下标，前序根节点在l1
		{
			int temp = i - l2;//左树的元素个数
			fun1(l1 + 1, l1 + temp, l2,i-1 );//去查看左子树
			fun1(l1 + temp + 1, r1, i + 1, r2);//右子树
			cout << s1[l1];//后序
		}
	}
}

void fun2(int l1, int r1, int l2, int r2)//后序的l1和r1，中序的l2和r2
{
	if (l1 > r1)//结束递归条件
	{
		return;
	}
	for (int i = l2; i <= r2; i++)
	{
		if (s2[i] == s3[r1])//找出根节点的下标，后序根节点在r1
		{
			int temp = i - l2;//左子树个数
			cout << s3[r1];//先序
			fun2(l1, l1 + temp - 1, l2, i - 1);//左
			fun2(l1 + temp , r1-1, i + 1, r2);//右
		}
	}
}

int main()
{
	cout << "输出后序：" << endl;
	fun1(0, s1.size() - 1, 0, s2.size() - 1);//已知先序中序求后序
	cout << endl << "输出前序：" << endl;
	fun2(0, s1.size() - 1, 0, s2.size() - 1);//已知中后序求前序
}