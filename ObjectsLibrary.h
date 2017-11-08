#pragma once

#ifdef OBJECTSLIBRARY_EXPORTS   
#define OBJECTSLIBRARY_API __declspec(dllexport)    
#else   
#define OBJECTSLIBRARY_API __declspec(dllimport)    
#endif   



namespace ObjectsLibrary
{

	template <typename T>
	class Array
	{
	private:
		T* mas;
		int size;
	public:
		Array()
		{
			size = 0;
			mas = new T[0];
		}

		Array(int _size)
		{
			size = _size;
			mas = new T[size];
			for (int i = 0; i < size; i++)
			{
				mas[i] = T();
			}
		}

		~Array()
		{
			delete[] mas;
		}

		void  push_back(T _data)
		{
			if (size != 0)
			{
				int flag = 0;
				while (flag < size && mas[flag] != T())
				{
					flag++;
				}

				if (flag == size)
				{
					flag--;
					for (int i = 0; i < size; i++)
					{
						mas[i] = mas[i + 1];
					}
					mas[size - 1] = _data;
				}

				else {
					mas[flag] = _data;
				}
			}

		}

		void  push_neck(T _data)
		{
			if (size != 0)
			{
				int flag = 0;
				while (flag < size && mas[flag++] != T())
				{
				}

				if (flag == size)
				{
					flag--;
				}

				for (int i = flag; i > 0; i--)
				{
					mas[i] = mas[i - 1];
				}
				mas[0] = _data;
			}

		}

		void  pop_back()
		{
			if (size != 0 && mas[0] != T())
			{
				int flag = 0;
				while (flag < size && mas[flag] != T())
				{
					flag++;
				}

				mas[flag - 1] = T();
			}
		}

		void  pop_neck()
		{
			if (size != 0 && mas[0] != T())
			{
				int i = 0;

				for (; i < size - 1; i++)
				{
					if (mas[i + 1] != T())
					{
						mas[i] = mas[i + 1];
					}
					else
					{
						mas[i] = T();
					}
				}

				if (mas[i] != T())
				{
					mas[i] = T();
				}
			}
		}

		void  push(int position, T _data)
		{
			if (size != 0 && position < size && position >= 0)
			{
				for (int i = size - 1; i > position; i--)
				{
					mas[i] = mas[i - 1];
				}
				mas[position] = _data;
			}

		}

		void  pop(int position)
		{
			if (size != 0 && position < size && position >= 0)
			{
				for (int i = position; i < size - 1; i ++ )
				{
					mas[i] = mas[i + 1];
				}
				mas[size - 1] = T();
			}

		}

		void push_array(const Array<T>& object)
		{
			if (size != 0)
			{
				int flag = 0;

				while (flag < size && mas[flag] != T())
				{
					flag++;
				}

				for (int i = 0; i < object.size; i++)
				{
					if (flag + i < size)
					{
						mas[flag + i] = object.mas[i];
					}
					else
					{
						break;
					}
				}

			}
		}

		void reverse()
		{
			if (size > 1)
			{
				int flag = 0;
				while (flag < size && mas[flag] != T())
				{
					flag++;
				}

				for (int i = 0; i < flag / 2; i++)
				{
					swap(mas[i], mas[flag - 1 - i]);
				}
			}
		}

		void sort()
		{
			if (size > 1)
			{

				int flag = 0;
				while (flag < size && mas[flag] != T())
				{
					flag++;
				}

				for (int i = 0; i < flag; i++) 
				{
					for (int j = 0; j < flag-1-i; j++)
					{
						if (mas[j] > mas[j + 1])
						{
							swap(mas[j], mas[j + 1]);
						}

					}
				}

			}
		}

		int find(T _data)
		{
			if (size != 0)
			{
				for (int i = 0; i < size; i++)
				{
					if (mas[i] == _data)
					{
						return i;
					}
				}
			}

			return -1;

		}

		void  print()const
		{
			if (size == 0)
			{
				cout << endl;
				return;
			}

			int flag = 0;
			while (flag < size && mas[flag] != T())
			{
				cout << mas[flag++] << ' ';
			}
			cout << endl;
		}

	};

	template <typename T>
	struct Node_1
	{
		T data;
		Node_1 *next;
		void print()
		{
			cout << data << endl;
		}
		Node_1(T _data)
		{
			data = _data;
			next = NULL;
		}
	};

	template <typename T>
	class List_1
	{
	private:
		Node_1<T>* head;
		Node_1<T>* tail;
	public:
		List_1()
		{
			head = NULL;
			tail = NULL;
		}

		~List_1()
		{
			if (head == NULL)
			{
				return;
			}

			Node_1<T>* ptr = head;
			while (ptr != NULL)
			{
				head = head->next;
				delete ptr;
				ptr = head;
			}
		}

		void  push_back(T _data)
		{
			if (head != NULL)
			{
				tail->next = new Node_1<T>(_data);
				tail = tail->next;
			}
			else
			{
				head = new Node_1<T>(_data);
				tail = head;
			}
		}

		void  push_neck(T _data)
		{
			if (head != NULL)
			{
				Node_1<T> *ptr = new Node_1<T>(_data);
				ptr->next = head;
				head = ptr;
			}
			else
			{
				head = new Node_1<T>(_data);
				tail = head;
			}
		}

		void  pop_back()
		{
			if (tail != NULL)
			{
				if (tail == head)
				{
					delete head;
					head = NULL;
					tail = NULL;
				}
				else
				{
					Node_1<T>*ptr = head;
					while (ptr->next != tail)
					{
						ptr = ptr->next;
					}

					delete tail;
					ptr->next = NULL;
					tail = ptr;
				}
			}
		}

		void  pop_neck()
		{
			if (head != NULL)
			{
				if (head == tail)
				{
					delete head;
					head = NULL;
					tail = NULL;
				}
				else
				{
					Node_1<T>*ptr = head->next;
					delete head;
					head = ptr;
				}
			}
		}

		void  push(int position, T _data)
		{
			if (head != NULL)
			{
				int count = 0;
				Node_1<T>* ptr = head;

				for (; count < position - 1; count++)
				{
					if (ptr->next == NULL)
					{
						break;
					}
					else
					{
						ptr = ptr->next;
					}
				}

				if (count >= position)
				{
					push_neck(_data);
				}
				else if (ptr->next == NULL && count <= position - 1)
				{
					push_back(_data);
				}
				else
				{
					Node_1<T>* ptr2 = new Node_1<T>(_data);
					ptr2->next = ptr->next;
					ptr->next = ptr2;
				}
			}
			else
			{
				push_back(_data);
			}
		}

		void  pop(int position)
		{
			if (head != NULL)
			{
				int count = 0;
				Node_1<T>* ptr = head;

				for (; count < position - 1; count++)
				{
					if (ptr->next == NULL)
					{
						break;
					}
					else
					{
						ptr = ptr->next;
					}
				}

				if (count >= position)
				{
					pop_neck();
				}
				else if (ptr->next == NULL && count <= position - 1)
				{
					pop_back();
				}
				else if (ptr->next->next == NULL)
				{
					pop_back();
				}
				else
				{
					Node_1<T>* ptr2 = ptr->next;
					ptr->next = ptr2->next;
					delete ptr2;
				}
			}
		}

		void push_list(const List_1<T>& object)
		{
			if (object.head != NULL)
			{
				Node_1<T>* ptr = object.head;
				do
				{
					push_back(ptr->data);
					ptr = ptr->next;
				} while (ptr != NULL);
			}
		}

		void reverse()
		{
			if (head != tail)
			{
				Node_1<T>* ptr = head;
				int count = 0;

				while (ptr != NULL)
				{
					ptr = ptr->next;
					count++;
				}

				Node_1<T>* ptr2 = tail;
				ptr = head;

				while (ptr != ptr2)
				{
					push(count--, ptr->data);
					ptr = ptr->next;
					pop_neck();
				}

			}
		}

		void sort()
		{
			if (head != tail)
			{
				int length = 0;
				Node_1<T>* ptr = head;

				while (ptr != NULL)
				{
					length++;
					ptr = ptr->next;
				}
				for (int i = 0; i < length; i++)
				{
					ptr = head;
					for (int j = 0; j < length - i - 1; j++)
					{
						if (ptr->data < ptr->next->data)
						{
							T temp = ptr->data;
							ptr->data = ptr->next->data;
							ptr->next->data = temp;
						}
						ptr = ptr->next;
					}
				}

			}
		}

		int find(T _data)
		{
			int count = 0;
			Node_1<T>* ptr = head;
			while (ptr != NULL)
			{
				if (ptr->data == _data)
				{
					return count;
				}
				count++;
				ptr = ptr->next;
			}

			return -1;

		}

		void  print()const
		{
			if (head == NULL)
			{
				cout << endl;
				return;
			}

			Node_1<T>* ptr = head;
			while (ptr != NULL)
			{
				cout << ptr->data << ' ';
				ptr = ptr->next;
			}
			cout << endl;
		}
	};

	template <typename T>
	struct Node_2
	{
		T data;
		Node_2 *next;
		Node_2 *previous;
		void print()
		{
			cout << data << endl;
		}
		Node_2(T _data)
		{
			data = _data;
			next = NULL;
			previous = NULL;
		}
	};

	template <typename T>
	class List_2
	{
	private:
		Node_2<T>* head;
		Node_2<T>* tail;
	public:
		List_2()
		{
			head = NULL;
			tail = NULL;
		}

		~List_2()
		{
			if (head == NULL)
			{
				return;
			}

			Node_2<T>* ptr = head;
			while (ptr != NULL)
			{
				head = head->next;
				delete ptr;
				ptr = head;
			}
		}

		void  push_back(T _data)
		{
			if (head != NULL)
			{
				tail->next = new Node_2<T>(_data);
				tail->next->previous = tail;
				tail = tail->next;
			}
			else
			{
				head = new Node_2<T>(_data);
				tail = head;
			}
		}

		void  push_neck(T _data)
		{
			if (head != NULL)
			{
				Node_2<T> *ptr = new Node_2<T>(_data);
				ptr->next = head;
				head->previous = ptr;
				head = ptr;
			}
			else
			{
				head = new Node_2<T>(_data);
				tail = head;
			}
		}

		void  pop_back()
		{
			if (tail != NULL)
			{
				if (tail == head)
				{
					delete head;
					head = NULL;
					tail = NULL;
				}
				else
				{
					tail = tail->previous;
					delete tail->next;
					tail->next = NULL;
				}
			}
		}

		void  pop_neck()
		{
			if (head != NULL)
			{
				if (head == tail)
				{
					delete head;
					head = NULL;
					tail = NULL;
				}
				else
				{
					head = head->next;
					delete head->previous;
					head->previous = NULL;
				}
			}
		}

		void  push(int position, T _data)
		{
			if (head != NULL)
			{
				int count = 0;
				Node_2<T>* ptr = head;

				for (; count < position - 1; count++)
				{
					if (ptr->next == NULL)
					{
						break;
					}
					else
					{
						ptr = ptr->next;
					}
				}

				if (count >= position)
				{
					push_neck(_data);
				}
				else if (ptr->next == NULL && count <= position - 1)
				{
					push_back(_data);
				}
				else
				{
					Node_2<T>* ptr2 = new Node_2<T>(_data);
					ptr2->next = ptr->next;
					ptr2->previous = ptr;
					ptr->next = ptr2;
					ptr2->next->previous = ptr2;
				}
			}
			else
			{
				push_back(_data);
			}
		}

		void  pop(int position)
		{
			if (head != tail)
			{
				int count = 0;
				Node_2<T>* ptr = head;

				for (; count < position - 1; count++)
				{
					if (ptr->next == NULL)
					{
						break;
					}
					else
					{
						ptr = ptr->next;
					}
				}

				if (count >= position)
				{
					pop_neck();
				}
				else if (ptr->next == NULL && count <= position - 1)
				{
					pop_back();
				}
				else if (ptr->next->next == NULL)
				{
					pop_back();
				}
				else
				{
					Node_2<T>* ptr2 = ptr->next;
					ptr->next = ptr2->next;
					ptr2->next->previous = ptr;
					delete ptr2;
				}
			}
			else
			{
				pop_neck();
			}
		}

		void push_list(const List_2<T>& object)
		{
			if (object.head != NULL)
			{
				Node_2<T>* ptr = object.head;
				do
				{
					push_back(ptr->data);
					ptr = ptr->next;
				} while (ptr != NULL);
			}
		}

		void reverse()
		{
			if (head != tail)
			{
				Node_2<T>* ptr = head;
				int count = 0;

				while (ptr != NULL)
				{
					ptr = ptr->next;
					count++;
				}

				Node_2<T>* ptr2 = tail;
				ptr = head;

				while (ptr != ptr2)
				{
					push(count--, ptr->data);
					ptr = ptr->next;
					pop_neck();
				}

			}
		}

		void sort()
		{
			if (head != tail)
			{
				int length = 0;
				Node_2<T>* ptr = head;

				while (ptr != NULL)
				{
					length++;
					ptr = ptr->next;
				}
				for (int i = 0; i < length; i++)
				{
					ptr = head;
					for (int j = 0; j < length - i - 1; j++)
					{
						if (ptr->data < ptr->next->data)
						{
							T temp = ptr->data;
							ptr->data = ptr->next->data;
							ptr->next->data = temp;
						}
						ptr = ptr->next;
					}
				}

			}
		}

		int find(T _data)
		{
			int count = 0;
			Node_2<T>* ptr = head;
			while (ptr != NULL)
			{
				if (ptr->data == _data)
				{
					return count;
				}
				count++;
				ptr = ptr->next;
			}

			return -1;

		}

		void  print()const
		{
			if (head == NULL)
			{
				cout << endl;
				return;
			}

			Node_2<T>* ptr = head;
			while (ptr != NULL)
			{
				cout << ptr->data << ' ';
				ptr = ptr->next;
			}
			cout << endl;
		}
	};

	template <typename T>
	class Stack
	{
	private:
		Node_1<T>* head;
	public:
		Stack()
		{
			head = NULL;
		}

		~Stack()
		{
			if (head == NULL)
			{
				return;
			}

			Node_1<T>* ptr = head;
			while (ptr != NULL)
			{
				head = head->next;
				delete ptr;
				ptr = head;
			}
		}

		void push(T _data)
		{
			Node_1<T>* ptr = new Node_1<T>(_data);
			ptr->next = head;
			head = ptr;
		}

		void pop()
		{
			if (head != NULL)
			{
				Node_1<T>* ptr = head;
				head = head->next;
				delete ptr;
			}
		}

		int find(T _data)
		{
			int size_of_stack = 0;
			Node_1<T>* ptr = head;

			while (ptr != NULL)
			{
				size_of_stack++;
				ptr = ptr->next;
			}

			int count = 0;

			ptr = head;
			while (ptr != NULL)
			{
				if (ptr->data == _data)
				{
					return size_of_stack - count - 1;
				}
				count++;
				ptr = ptr->next;
			}

			return -1;

		}

		void push_stack(const Stack<T>& object)
		{
			if (object.head != NULL)
			{
				Node_1<T>* flag = NULL;

				Node_1<T>* ptr = object.head;
				while (ptr != flag)
				{
					while (ptr->next != flag)
					{
						ptr = ptr->next;

					}

					push(ptr->data);
					flag = ptr;
					ptr = object.head;
				}
			}
		}

		void reverse()
		{
			if (head != NULL)
			{
				int size_of_stack = 0;
				Node_1<T>* ptr = head;

				while (ptr != NULL)
				{
					size_of_stack++;
					ptr = ptr->next;
				}

				for (int i = 1; i < size_of_stack; i++)
				{
					ptr = head;
					for (int j = 0; j < size_of_stack - i; j++)
					{
						T temp = ptr->data;
						ptr->data = ptr->next->data;
						ptr->next->data = temp;
						ptr = ptr->next;
					}
				}

			}
		}

		void  print()const
		{
			if (head == NULL)
			{
				cout << endl;
				return;
			}

			Node_1<T>* ptr = head;
			while (ptr != NULL)
			{
				cout << ptr->data << ' ';
				ptr = ptr->next;
			}
			cout << endl;
		}
	};

	template <typename T>
	class Queue
	{
	private:
		Node_1<T>* head;
		Node_1<T>* tail;
	public:
		Queue()
		{
			head = NULL;
			tail = NULL;
		}

		~Queue()
		{
			if (head == NULL)
			{
				return;
			}

			Node_1<T>* ptr = head;
			while (ptr != NULL)
			{
				head = head->next;
				delete ptr;
				ptr = head;
			}
		}

		void push(T _data)
		{

			if (head != NULL)
			{
				tail->next = new Node_1<T>(_data);
				tail = tail->next;
			}
			else
			{
				head = new Node_1<T>(_data);
				tail = head;
			}
		}

		void pop()
		{
			if (head != NULL)
			{
				Node_1<T>* ptr = head;
				head = head->next;
				delete ptr;
			}
		}

		int find(T _data)
		{
			int count = 0;
			Node_1<T>* ptr = head;

			while (ptr != NULL)
			{
				if (ptr->data == _data)
				{
					return count;
				}
				count++;
				ptr = ptr->next;
			}

			return -1;

		}

		void push_queue(const Queue<T>& object)
		{
			if (object.head != NULL)
			{
				Node_1<T>* ptr = object.head;
				do
				{
					push(ptr->data);
					ptr = ptr->next;
				} while (ptr != NULL);
			}
		}

		void reverse()
		{
			if (head != NULL)
			{
				int size_of_queue = 0;
				Node_1<T>* ptr = head;

				while (ptr != NULL)
				{
					size_of_queue++;
					ptr = ptr->next;
				}

				for (int i = 1; i < size_of_queue; i++)
				{
					ptr = head;
					for (int j = 0; j < size_of_queue - i; j++)
					{
						T temp = ptr->data;
						ptr->data = ptr->next->data;
						ptr->next->data = temp;
						ptr = ptr->next;
					}
				}

			}
		}

		void  print()const
		{
			if (head == NULL)
			{
				cout << endl;
				return;
			}

			Node_1<T>* ptr = head;
			while (ptr != NULL)
			{
				cout << ptr->data << ' ';
				ptr = ptr->next;
			}
			cout << endl;
		}
	};

}
