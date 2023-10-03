#include <iostream>
#include <utility>
#include <memory>

/**
 * NOTE:
 *	The utility library provides the std::swap
 *	The memory library provides the std::shared_ptr
 */
template <typename Type>
class LinkedList
{
	struct Node
	{
		Type data;
		std::shared_ptr<Node> next;

		Node(const Type& item) : data(item), next(nullptr)
		{
			std::cout << "Creating Node " << data
				<< "(" << reinterpret_cast<uintptr_t>(this)
				<< ")" << std::endl;
		}

		~Node()
		{
			std::cout << "Destroying Node " << data
				<< "(" << reinterpret_cast<uintptr_t>(this)
				<< ")" << std::endl;
		}

		// Function to copy constructor
		Node(const Node&) = default;

		// Function to move constructor
		Node(Node&&) = default;

		// Function to copy assignment
		Node& operator= (const Node&) = default;

		// Function to move assignment
		Node& operator= (Node&&) = default;
	};

	// Points to the first item in the list
	std::shared_ptr<Node> head;

	// Points to the last item in the list
	std::shared_ptr<Node> tail;

	// Number of items in the list
	int length;

	public:
	/**
	 * The constructor makes an initially empty list
	 * The list is empty when the head and tail are null
	 */
	LinkedList() : head(nullptr), tail(nullptr), length(0) {}

	/**
	 * Copy constructor makes a copy of the other object's list
	 */
	LinkedList(const LinkedList& other) : LinkedList()
	{
		// Walk through other's list inserting each of its elements
		// into the list
		for (auto cursor = other.head; cursor; cursor = cursor->next)
		{
			insert(cursor->data);
		}
	}

	/**
	 * Move constructor takes possession of the temporary list
	 */
	LinkedList(LinkedList&& temp) : LinkedList()
	{
		std::swap(head, temp.head);
		std::swap(tail, temp.tail);
		std::swap(length, temp.length);
	}

	/**
	 * Assignment operator
	 */
	LinkedList& operator=(const LinkedList& other)
	{
		// Make a local, temporary copy of the other
		LinkedList temp {other};
		std::swap(head, temp.head);
		std::swap(tail, temp.tail);
		std::swap(length, temp.length);

		return *this;
	}

	~LinkedList()
	{
		clear();
	}

	void insert(const Type& item)
	{
		auto new_node = std::make_shared<LinkedList::Node>(item);

		// If we have a tail
		if (tail)
		{
			tail->next = new_node;
			tail = new_node;
		}
		else
		{
			// List is empty, so we make head and tail point to the
			// new node
			head = tail = new_node;
		}
		length++;
	}

	bool remove(const Type& item)
	{
		auto cursor = head, previous = head;
		while (cursor && cursor->data != item)
		{
			previous = cursor;
			cursor = cursor->next;
		}

		if (!cursor)
		{
			return false;
		}

		if (head == tail)
		{
			head = tail = nullptr;
		}
		else if (cursor == head)
		{
			head = head->next;
		}
		else
		{
			previous->next = cursor->next;
		}

		if (cursor == tail)
		{
			tail = previous;
		}

		length--;
		return true;
	}

	void print() const
	{
		for (auto cursor = head; cursor; cursor = cursor->next)
		{
			std::cout << cursor->data << " ";
		}
		std::cout << std::endl;
	}

	int getLength() const
	{
		return length;
	}

	void clear()
	{
		auto cursor = head;
		while (cursor)
		{
			// Remember where we are
			auto temp = cursor;
			// cursor = head, therefore we move our head to the next node
			cursor = cursor->next;
			// Severe the link between current head and previous head
			temp->next = nullptr;
		}
		head = tail = nullptr;
		length = 0;
	}

	/**
	 * Provide a convenient way to print a linked list
	 */
	template <typename Vype>
		friend std::ostream& operator<<(std::ostream& os,
				const LinkedList<Vype>& list);
};

/**
 * Prints a linked list object to an output stream
 */
	template <typename Type>
std::ostream& operator<<(std::ostream& os, const LinkedList<Type>& list)
{
	os << "{ ";
	if (list.getLength() > 0)
	{
		auto cursor = list.head;

		// Print first data item
		os << cursor->data;
		cursor = cursor->next;

		// Print rest of data items
		while (cursor)
		{
			os << ", " << cursor->data;
			cursor = cursor->next;
		}
	}
	os << " }";
	return os;
}

void print_separator()
{
	std::cout << "--------------------------------"<< std::endl;
}
