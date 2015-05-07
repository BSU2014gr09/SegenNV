struct stack
{
	private:
		float nmb;
		stack * next;
	public:
		stack() : next(nullptr) {}
		void push(float);
		float pop();
		bool empty();
};