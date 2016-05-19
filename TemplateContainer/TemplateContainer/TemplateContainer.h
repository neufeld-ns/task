#pragma once
#include "TemplateContainer.h"

class EmptyContainerException : public std::exception
{
public:
	explicit EmptyContainerException(const char* message ) :
		msg_(message)
	{
	}
	explicit EmptyContainerException(const std::string& message) :
		msg_(message)
	{}

	virtual ~EmptyContainerException() throw () {}
	virtual const char* what() const throw () {
		return msg_.c_str();
	}

protected:

	std::string msg_;
};
template <typename T>
class Container
{
	struct  Node //Класс node содержит данные списка
	{
		const T *data; 
		struct Node *next; 
	};
private:


	Node *head, *tail; //Указатель на начало списка
	int count; //Количество элементов в списке
public:
	//class CIterator{};
	Container() : head(NULL), tail(NULL), count(0) {}
	//Container(const Container &copy)

	~Container()
	{
		clear(); //Функция освобождает память, используемую для хранения списка
	}
	int getCount() const //Возвращает количество элементов в списке
	{
		return count;
	}
	bool isEmpty()
	{
		return (count == 0);
	}
	int  push_back( const T  *data)
	{
		Node *to_add = new Node{ data,NULL };
		//to_add->next = NULL;
		//to_add->data = data;
		if (head == NULL)
			head = tail = to_add;
		else
		{
			tail->next = to_add;
			tail = to_add;
		}
		count++;
		return count;
	}
	int push_front(T data)
	{
		Node *to_add = new Node;
		to_add->next = head;
		to_add->data = data;
		if (head == NULL)
			head = tail = to_add;
		else
		{
			head = to_add;
		}
		count++;
		return count;
	}

	const T* pop_front() //Удаление элемента из списка. 
	{
		if (!count)
			throw EmptyContainerException("Attempt to pop_front from empty container");
		const T *returnData;
		Node *to_del = head;
		if (count == 1)
		{
			returnData = to_del->data;
			to_del->data = NULL;
			delete to_del;
			head = tail = NULL;
		}
		else
		{
			head = head->next;
			returnData = to_del->data;
			to_del->data = NULL;
			delete to_del;
		}
		count--;
		return returnData;
	}
	const T* pop_back()
	{
		if (!count)
			throw EmptyContainerException("Attempt to pop_back from empty container");
		const T* returnData;
		Node *to_del = head;
		if (count == 1)
		{
			returnData = to_del->data;
			delete head;
			head = tail = NULL;
		}
		else
		{
			for (; to_del->next != tail; to_del = to_del->next);
			tail = to_del;
			to_del = to_del->next;
			returnData = to_del->data;
			to_del->data = NULL;
			delete to_del;
		}
		count--;
		return returnData;
	}
	T fist()
	{
		if (head)
			return head->data;
		return NULL;
	}
	T last()
	{
		if (tail)
			return tail->data;
		return NULL;
	}
	void clear() //Очистка списка
	{
		Node *current = head;
		Node *to_del = head;
		while (to_del != NULL)
		{
			current = current->next;
			delete to_del->data;
			delete to_del;
			to_del = current;
		}
		head= tail = NULL;
		count = 0;
	}
	class CIterator
	{
	private:
		Node* curentNode;
	public:
		CIterator(Node *x = 0) :curentNode(x) {};
		void operator++() 
		{
			if (curentNode)
				curentNode = curentNode->next;
		}
		bool operator!=(CIterator &right) 
		{
			return curentNode != right.curentNode;
		}
		Node& operator->()
		{
			return curentNode;
		}
		const T* operator*() const
		{
			return curentNode->data;
		}
	};
	CIterator begin() const
	{
		CIterator x(head);
		return x;
	}
	CIterator end() const
	{
		return 0;
	}
};

