#pragma once
#include <iostream>

using namespace std;

template <class T>
struct elem
{
	T data;
	elem* next;
};

template <class T>
class List
{
public:
	
	elem<T>* top; 
	elem<T>* p; 
	elem<T>* prev;

	void copy(List<T>* other)
	{
		del();
		to_start();
		other.to_start();
		T data;
		while (other->p != nullptr)
		{
			data = other.p->data;
			add(data);
			other.next();
		}
		to_start();
		other.to_start();
	}
	void del()
	{
		while (top != nullptr)
		{
			elem<T>* q = top;
			top = top->next;
			delete q;
		}
		p = nullptr;
		prev = nullptr;
	}

public:
	List()
	{
		top = nullptr;
		p = nullptr;
		prev = nullptr;
	}

	List(List& other)
	{
		other.to_start();
		while (other.p)
		{
			T data = other.p->data;
			add(data);
			other.next();
		}
	}

	List(List&& moved) noexcept
	{
		top = moved.top;
		p = moved.p;
		prev = moved.prev;
		moved.prev = nullptr;
		moved.p = nullptr;
		moved.top = nullptr;
	}

	elem<T>* get_p() { return p; }
	T get_value() { return p->data; }
	void set_value(T _data) { p->data = _data; }

	void next()
	{
		if (p != nullptr)
		{
			prev = p;
			p = p->next;
		}
		else
			cout << "Current element is nullptr" << endl;
	}

	bool is_end()
	{
		return p->next == nullptr;
	}

	void to_start()
	{
		p = top;
		prev = nullptr;
	}

	void add(T _data)
	{
		elem<T>* q = new elem<T>;
		q->data = _data;
		q->next = nullptr;
		if (top == nullptr)
		{
			top = q;
			p = q;
		}
		else
		{
			while (!is_end())
				next();
			p->next = q;
		}
	};

	void delete_current()
	{
		elem<T>* q = p;
		p = p->next;
		prev->next = p;
		delete q;
	}

	void add_after_current(T data)
	{
		elem<T>* q = new elem<T>;
		q->data = data;
		q->next = p->next;
		p->next = q;
	}
	void add_before_current(T data)
	{
		elem<T>* q = new elem<T>;
		q->data = data;
		if (prev != nullptr)
		{
			q->next = prev->next;
			prev->next = q;
		}
		else
		{
			q->next = top;
			top = q;
		}
	}

	List& operator=(List& other)
	{
		if (this == &other)
			return *this;
		if (top != nullptr)
			del();
		other.to_start();
		T data;
		while (other.p)
		{
			data = other.p->data;
			add(data);
			other.next();
		}
		other.to_start();
		return *this;
	}

	bool operator==(List& other)
	{
		to_start();
		other.to_start();
		if (top == nullptr || other.top == nullptr) return false;
		while (p != nullptr && other.p != nullptr)
		{
			if (p->data != other.p->data) return false;
			next();
			other.next();
		}
		if ((p == nullptr && other.p != nullptr) || (p != nullptr && other.p == nullptr))
			return false;
		return true;
	}

	friend istream& operator>>(istream& in, List& other)
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
	
	friend ostream& operator<<(ostream& out, List<T>& other)
	{
		if (other.top == nullptr)
		{
			out << "Empty list" << endl;
			return out;
		}
		other.to_start();
		out << "( ";
		while (other.p)
		{
			out << other.p->data << ' ';
			other.next();
		}
		out << ')' << endl;
		other.to_start();
		return out;
	};

	bool contains(T data)
	{
		to_start();
		while (p)
		{
			if (p->data == data) return true;
			next();
		}
		to_start();
		return false;
	}

	~List()
	{
		del();
	}

};
