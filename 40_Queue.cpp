/*
 40 用栈实现队列

正如标题所述，你需要使用两个栈来实现队列的一些操作。

队列应支持push(element)，pop() 和 top()，其中pop是弹出队列中的第一个(最前面的)元素。

pop和top方法都应该返回第一个元素的值。

样例
比如push(1), pop(), push(2), push(3), top(), pop()，你应该返回1，2和2

挑战
仅使用两个栈来实现它，不使用任何其他数据结构，push，pop 和 top的复杂度都应该是均摊O(1)的
*/

class Queue {
public:
	stack<int> stack1;
	stack<int> stack2;

	Queue() {
		// do intialization if necessary
	}

	void push(int element) {
		// write your code here
		stack1.push(element);
	}

	int pop() {
		// write your code here
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}//while
		}
		
		int ret = stack2.top();
		stack2.pop();
		return ret;
		
	}

	int top() {
		// write your code here
		// write your code here
		if (stack2.empty())
		{
			while (!stack1.empty())
			{
				stack2.push(stack1.top());
				stack1.pop();
			}//while
		}
		return stack2.top();
	}
};
