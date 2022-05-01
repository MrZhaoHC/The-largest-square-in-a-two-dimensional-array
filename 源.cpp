#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define MAXSIZE 100

//【问题描述】
//
//这天皮皮强心血来潮想办一场演唱会，众所周知演唱会需要一个平坦的正方形场地。但皮皮强只找到了一块凹凸不平的场地，凹下去的地方明显是不能用的。所以皮皮强想请你帮忙算出他最大的场地面积是多少
//
//
//
//【输入形式】
//
//输入包含多组测试用例；
//
//每组测试用例第一行包括2个整数n，m（1 <= n, m <= 100）表示场地规模，场地被划分为n * m个正方形小区域，每个小正方形边长为1，每个区域都有0或1两种表现形式分别代表凹下或凸起；
//
//接下来n行每行由m个字符组成（字符只含有0或1）代表场地情况。
//
//
//
//【输出形式】
//
//对每组测试用例请输出一个正整数代表场地中全部由凸起组成的正方形的最大面积。
//
//
//
//【样例输入】
//
//4 4
//0 1 1 1
//1 1 1 0
//0 1 1 0
//1 1 0 1
//1 1
//1



void opeart()
{
	int n, m;//长和宽
	cin >> n >> m;
	int arr[MAXSIZE][MAXSIZE] = { 0 };   //建立二维数组
	int max[MAXSIZE] = { 0 };        //建立一个max数组储存所有正方形面积
	for (int i = 0; i < n; i++)		//输入二维数组
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	int min;
	if (n > m) //最大正方形的最大边长
	{
		min = m;
	}
	else
		min = n;
	int l = 0;
	for (int i = 0; i < n; i++)//遍历数组
	{
		for (int j = 0; j < m; j++)//遍历数组
		{
			if (arr[i][j] == 1) //如果为1
			{
				for (int k = 1; k <= min - i; k++) //k为（i-min）意为正方形的边长
				{
					int flag = 1;
					for (int o = i; o < i + k; o++)
					{
						for (int p = j; p < j + k; p++)
						{
							if (arr[o][p] == 0)
								flag = 0;
						}
					}
					if (flag == 1)
					{
						max[l] = k * k;
						l++;
					}
				}
			}
		}
	}
	int result = max[0];
	for (int i = 1; i < l; i++)   //对数组排序
	{
		if (max[i] > result)
		{
			result = max[i];
		}
	}
	cout << result;
}


int main()
{
	opeart();
	return 0;
}



