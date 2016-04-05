/*
 12 带最小值操作的栈

实现一个带有取最小值min方法的栈，min方法将返回当前栈中的最小值。

你实现的栈将支持push，pop 和 min 操作，所有操作要求都在O(1)时间内完成。
*/

class MinStack {
public:
	MinStack() {
		// do initialization if necessary
	}

	void push(int number) {
		// write your code here
		datas.push(number);
		if (minDatas.empty())
		{
			minDatas.push(number);
		}
		else{
			if (number < minDatas.top())
			{
				minDatas.push(number);
			}
			else{
				minDatas.push(minDatas.top());
			}//else
		}//else
	}

	int pop() {
		// write your code here
		int ret = datas.top();
		datas.pop();
		minDatas.pop();
		return ret;
	}

	int min() {
		// write your code here
		return minDatas.top();
	}

private:
	stack<int> datas;
	stack<int> minDatas;
};
