#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define MAXSIZE 100

//������������
//
//����ƤƤǿ��Ѫ�������һ���ݳ��ᣬ������֪�ݳ�����Ҫһ��ƽ̹�������γ��ء���ƤƤǿֻ�ҵ���һ�鰼͹��ƽ�ĳ��أ�����ȥ�ĵط������ǲ����õġ�����ƤƤǿ�������æ��������ĳ�������Ƕ���
//
//
//
//��������ʽ��
//
//��������������������
//
//ÿ�����������һ�а���2������n��m��1 <= n, m <= 100����ʾ���ع�ģ�����ر�����Ϊn * m��������С����ÿ��С�����α߳�Ϊ1��ÿ��������0��1���ֱ�����ʽ�ֱ�����»�͹��
//
//������n��ÿ����m���ַ���ɣ��ַ�ֻ����0��1�������������
//
//
//
//�������ʽ��
//
//��ÿ��������������һ����������������ȫ����͹����ɵ������ε���������
//
//
//
//���������롿
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
	int n, m;//���Ϳ�
	cin >> n >> m;
	int arr[MAXSIZE][MAXSIZE] = { 0 };   //������ά����
	int max[MAXSIZE] = { 0 };        //����һ��max���鴢���������������
	for (int i = 0; i < n; i++)		//�����ά����
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}
	int min;
	if (n > m) //��������ε����߳�
	{
		min = m;
	}
	else
		min = n;
	int l = 0;
	for (int i = 0; i < n; i++)//��������
	{
		for (int j = 0; j < m; j++)//��������
		{
			if (arr[i][j] == 1) //���Ϊ1
			{
				for (int k = 1; k <= min - i; k++) //kΪ��i-min����Ϊ�����εı߳�
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
	for (int i = 1; i < l; i++)   //����������
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



