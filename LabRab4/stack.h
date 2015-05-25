struct node
{
	float nmb;
	node * next;
};

struct stack
{
	private:
		node * top;
	public:
		stack() : top(nullptr) {}
		void push(float);
		float pop();
		bool isEmpty();
};