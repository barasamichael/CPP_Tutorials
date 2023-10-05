#include <iostream> 
#include <queue>
#include <string>

struct Message
{
	int rank; // Lower number = Higher Priority
	std::string text;

	Message(const std::string& text, int rank) : text(text), rank(rank){}
};

struct Comparer
{
	bool operator()(Message messageOne, Message messageTwo)
	{
		return messageTwo.rank < messageOne.rank;
	}
};

int main()
{
	std::priority_queue <Message, std::vector<Message>, Comparer> queue;

	queue.push({"Be there soon", 2});
	queue.push({"Gimme a few minutes", 3});
	queue.push({"Will be late!", 1});
	queue.push({"How to work next week", 7});

	while (!queue.empty())
	{
		Message message = queue.top();
		std::cout << message.text << " : " << message.rank << "\n";
		queue.pop();
	}
	std::cout << "\n";
}
