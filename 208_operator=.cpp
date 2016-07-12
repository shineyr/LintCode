/*
208 赋值运算符重载

实现赋值运算符重载函数，确保：

新的数据可准确地被复制
旧的数据可准确地删除/释放
可进行 A = B = C 赋值

说明
本题只适用于C++，因为 Java 和 Python 没有对赋值运算符的重载机制。

样例
如果进行 A = B 赋值，则 A 中的数据被删除，取而代之的是 B 中的数据。

如果进行 A = B = C 赋值，则 A 和 B 都复制了 C 中的数据。
*/
class Solution {
public:
    char *m_pData;
    Solution() {
        this->m_pData = NULL;
    }
    Solution(char *pData) {
        this->m_pData = pData;
    }

    // Implement an assignment operator
    Solution operator=(const Solution &object) {
        // write your code here
        
        if(this!=&object)  
        {  
            delete this->m_pData;  
            if(object.m_pData != nullptr)  
            {  
                this->m_pData = new char[strlen(object.m_pData)+1];  
                strcpy(this->m_pData,object.m_pData);  
            }  
        }  
        return *this;  
    }
};