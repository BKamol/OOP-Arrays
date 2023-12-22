#pragma once
#include "List.h"

using namespace std;

template <class T>
class SortedList: public List<T>
{
protected:
	void sort() 
	{
		this->to_start();
		this->next();
		bool has_replaced = true;
		while (has_replaced)
		{
			has_replaced = false;
			elem<T>* q = this->p;
			elem<T>* qprev = this->prev;
			while (q != nullptr)
			{
				if (q->data < qprev->data)
				{
					T temp = qprev->data;
					qprev->data = q->data;
					q->data = temp;
					has_replaced = true;
				}
				else
				{
					q = q->next;
					qprev = qprev->next;
				}
			}
		}
		this->to_start();
	}

public:
	SortedList() : List<T>() {};

	SortedList(SortedList& other)
	{
		other.to_start();
		while (other.p)
		{
			T data = other.p->data;
			this->add(data);
			other.next();
		}
		other.to_start();
	}

	SortedList(List<T> other)
	{
		other.to_start();
		while (other.p)
		{
			this->add(other.p->data);
			other.next();
		}
		other.to_start();
	}

	SortedList(SortedList&& moved)
	{
		this->top = moved.List<T>::top;
		this->p = moved.List<T>::p;
		this->prev = moved.List<T>::prev;
		moved.List<T>::prev = nullptr;
		moved.List<T>::p = nullptr;
		moved.List<T>::top = nullptr;
	}

	SortedList(List<T>&& moved)
	{
		this->top = moved.List<T>::top;
		this->p = moved.List<T>::p;
		this->prev = moved.List<T>::prev;
		moved.List<T>::prev = nullptr;
		moved.List<T>::p = nullptr;
		moved.List<T>::top = nullptr;
	}

	void add(T data)
	{
		if (this->top == nullptr)
		{
			this->top = new elem<T>{ data, nullptr };
			this->p = this->top;
		}
		else if (data < this->top->data)
		{
			elem<T>* q = new elem<T>{ data, this->top };
			this->top = q;
		}
		else
		{
			this->to_start();
			while (this->p && this->p->data < data)
				this->next();
			List<T>::add_before_current(data);
		}
	}

	void add_before_current(T data)
	{
		this->add(data);
	}
	void add_after_current(T data)
	{
		this->add(data);
	}

	friend istream& operator>>(istream& in, SortedList& other)
	{
		cout << "Input size of list: " << endl;
		int n;
		in >> n;
		cout << "Input " << n << " elements :" << endl;
		T data;
		for (int i = 0; i < n; i++)
		{
			in >> data;
			other.add(data);
		}
		return in;
	};

	bool contains(T data)
	{
		this->to_start();
		while (this->p)
		{
			if (data == this->p->data)
				return true;
			this->next();
		}
		this->to_start();
		return false;
	}

	
};


