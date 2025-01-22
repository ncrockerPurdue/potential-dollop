#include <iostream>
#include <string>
#include <list>
#include <ctime>

using namespace std;

class TodoItem {
	private:
		int id;
		string description;
		bool completed;

	public:
		TodoItem() : id(0), description(""), completed(false) {}
		~TodoItem() = default;

		bool create(string new_description) {
			id = rand() % 100 + 1;
			description = new_description;
			return true;
		}

		int getId() { return id; }
		string getDescription() { return description; }
		bool isCompleted() { return completed; }
};


int main() {
	string version = "v0.1";
	list<TodoItem> todoItems;
	list<TodoItem>::iterator it;
	todoItems.clear();

	srand(time(NULL));

	TodoItem test;
	test.create("this is a test");
	todoItems.push_back(test);

	while (1) {
		system("clear"); //TODO change to cls for windows
		cout << "Todo List - " << version << endl;
		cout << endl;

		for (it = todoItems.begin(); it != todoItems.end(); it++) {
			cout << it->getId() << " | " << it->getDescription() << " | "
				<< it->isCompleted() << endl;
		}
        	break;
	}
	return(0);
}
