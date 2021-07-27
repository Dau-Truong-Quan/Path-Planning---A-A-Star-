#pragma once
#pragma once
#include<iostream>
#include "value.h"
using namespace std;


struct bien
{
	NODE data; // queue đang chứa các số nguyên
	struct bien* pNext; // con trỏ liên kết giữa các DATA với nhau
};
typedef struct bien DATA;

// khai báo cấu trúc của queue
struct queue
{
	DATA* pHead; //  con trỏ đầu
	DATA* pTail; // con trỏ cuối 
};
typedef struct queue QUEUE;

// hàm khởi tạo queue
void KhoiTaoQueue(QUEUE& q)
{
	q.pHead = NULL;
	q.pTail = NULL;
}

// hàm khởi tạo 1 cái DATA
DATA* KhoiTaoNode(NODE x)
{
	DATA* p = new DATA();
	if (p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !!!";
		return NULL;
	}
	p->data = x; // thêm giá trị của biến x vào trong data của cái DATA
	p->pNext = NULL;
	return p;
}

// =============== KIỂM TRA QUEUE CÓ RỖNG HAY KHÔNG ===============
bool IsEmpty(QUEUE q)
{
	// nếu danh sách rỗng
	if (q.pHead == NULL)
	{
		return true;
	}
	return false;// danh sách có phần tử
}

// =============== THÊM 1 PHẦN TỬ VÀO CUỐI QUEUE- FIFO ===============
bool Push(QUEUE& q, DATA* p)
{
	if (p == NULL)
	{
		return false;
	}

	// nếu danh sách rỗng
	if (IsEmpty(q) == true)
	{
		q.pHead = q.pTail = p; // DATA p chính là DATA đầu và DATA cuối
	}
	else // danh sách đã có phần tử
	{
		q.pTail->pNext = p; // liên kết con trỏ cuối của danh sách với phần tử p cần thêm vào
		q.pTail = p; // cập nhật lại con trỏ cuối là DATA p
	}
	return true;
}

// =============== LẤY PHẦN TỬ ĐẦU QUEUE VÀ HỦY NÓ ĐI - FIFO ===============
bool Pop(QUEUE& q, NODE& x) // x chính là giá trị cần lấy trong DATA
{
	// nếu danh sách rỗng
	if (IsEmpty(q) == true)
	{
		return false;
	}
	else
	{
		DATA* p = q.pHead; // DATA p chính là DATA thế mạng để tí nữa chúng ta xóa nó đi
		x = p->data; // gán giá trị của DATA đầu stack vào biến x	
		q.pHead = q.pHead->pNext; // cập nhật DATA đầu queue là DATA tiếp theo	
		delete p; // xóa DATA đầu queue vừa lấy 

	}
	return true;// lấy phần tử đầu queue thành công
}
// hàm xuất danh sách queue
void XuatQueue(QUEUE q)
{
	while (IsEmpty(q) == false)
	{
		NODE x;
		Pop(q, x);
		cout << x << " ";
	}

	if (IsEmpty(q) == true)
	{
		cout << "\nDANH SACH DANG RONG KIA";
	}
	else
	{
		cout << "\nDANH SACH DANG TON TAI PHAN TU";
	}
}
void insert(QUEUE& q, DATA* p)
{
	if (IsEmpty(q) == true)
	{
		q.pHead = q.pTail = p; // DATA p chính là DATA đầu và DATA cuối

	}
	else // danh sách đã có phần tử
	{
		if (q.pHead->data->finalCost > p->data->finalCost) {
			p->pNext = q.pHead;
			q.pHead = p;
			return;
		}
		else if (q.pTail->data->finalCost < p->data->finalCost) {
			q.pTail->pNext = p;
			q.pTail = p;
			return;
		}
		else {
			for (DATA* a = q.pHead; a != NULL; a = a->pNext)
			{
				DATA* b = a->pNext;
				if (b->data->finalCost > p->data->finalCost)
				{
					p->pNext = b;
					a->pNext = p;
					return;
				}
			}
		}
	}
	
}
