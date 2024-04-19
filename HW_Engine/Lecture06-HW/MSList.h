#pragma once
#include <stdexcept>

template <typename T>
class MSNode
{
public:
	MSNode() : _next(nullptr), _prev(nullptr), _data(T())
	{

	}

    MSNode(const T& value) : _next(nullptr), _prev(nullptr), _data(value)
	{

	}

    MSNode* _next;
    MSNode* _prev;
    T       _data;
};

template <typename T>
class MSList
{
public:
    MSList() : _size(0)
	{
		_head = new MSNode<T>();
		_head->_next = _head;
		_head->_prev = _head;
	}

	~MSList()
	{
		while (_size > 0)
			pop_back();

		delete _head;
	}

	int get_size() { return _size; }

    void push_back(T data)
	{
		MSNode<T>* newNode = new MSNode<T>(data);
		AddNode(_head, newNode);
	}

    void pop_back()
	{
		RemoveNode(_head->_prev);
	}

    MSNode<T>* AddNode(MSNode<T>* before, MSNode<T>* value)
    {
        MSNode<T>* node = value;

        MSNode<T>* prevNode = before->_prev;
        prevNode->_next = node;
        node->_prev = prevNode;

        node->_next = before;
        before->_prev = node;

        _size++;

        return node;
    }

    MSNode<T>* RemoveNode(MSNode<T>* node)
    {
        MSNode<T>* prevNode = node->_prev;
        MSNode<T>* nextNode = node->_next;

        prevNode->_next = nextNode;
        nextNode->_prev = prevNode;

        delete node;

        _size--;

        return nextNode;
    }

    // Operator[] 재정의
	T& operator[](int index)
	{
		if (index < 0 || index >= _size) {
			// 유효하지 않은 인덱스 예외 처리
			throw std::out_of_range("Index out of range");
		}

		MSNode<T>* now = _head->_next;
		for (int a = 0; a < index; a++)
		{
			now = now->_next;
		}

		if (!now) {
			// nullptr인 경우 처리
			throw std::runtime_error("Node pointer is nullptr");
		}

		return now->_data;
	}

private:
    MSNode<T>* _head;
    int _size;
};


