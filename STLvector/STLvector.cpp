#define _CRT_SECURE__NO_WARNINGS 1
#include<bits/stdc++.h>
using namespace std;

void printVectorInt(vector<int>& v)
{
	vector<int>::iterator it = v.begin();
	for (; it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
void t1()
{
	vector<int>v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	//遍历
	//定义一个迭代器iterator 保存起始迭代器
	vector<int>::iterator it = v1.begin();
	for (; it != v1.end(); it++) {
		//*it == int
		cout << *it << " ";
	}
	cout << endl;
}
void t2()
{
	vector<int>v1;
	v1.reserve(1000);
	cout << "容量:" << v1.capacity() << " 大小:" << v1.size() << endl;

	vector<int>::iterator it;
	int count = 0;
	for (int i = 1; i < 1000; i++) {
		v1.push_back(i);
		if (it != v1.begin()) {
			count++;
			cout << "第" << count << "次开辟空间容量:" << v1.capacity() << endl;
			it = v1.begin();
		}
	}
}
void t3()
{
	vector<int>v1(5, 100);
	printVectorInt(v1);

	vector<int>v2(v1.begin(), v1.end());
	printVectorInt(v2);

	vector<int>v3;
	//v3 = v2;
	//v3.assign(v2.begin(), v2.end());
	v3.assign(10, 10);
	printVectorInt(v3);

	v3.swap(v2);
	printVectorInt(v2);
	printVectorInt(v3);

	vector<int>v4;
	if (v4.empty()) {
		cout << "空" << endl;
	}
	else {
		cout << "非空" << endl;
	}

	vector<int>v5(10,30);
	cout << "容量:" << v5.capacity() << " " << "大小:" << v5.size() << endl;
	printVectorInt(v5);
	//v5.reserve(15);//过大
	//v5.resize(15, 2);
	v5.resize(5);
	printVectorInt(v5);
}
void t4()
{
	vector<int>v1;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);

	cout << "头元素:" << v1.front() << " 尾元素:" << v1.back() << endl;
	//at越界会抛出异常
	cout << v1[1] << " " << v1.at(1) << endl;
	v1.at(1) = 200;
	v1[3] = 300;
	printVectorInt(v1);

	//尾删
	v1.pop_back();
	printVectorInt(v1);

	v1.insert(v1.begin() + 2, 3, 500);
	printVectorInt(v1);

	v1.erase(v1.begin() + 2, v1.begin() + 5);//左闭右开
	printVectorInt(v1);
	
	v1.clear();
	printVectorInt(v1);
	cout << "容量:" << v1.capacity() << " " << "大小:" << v1.size() << endl;
}
void t5()//swap收缩vector空间
{
	vector<int>v1;
	v1.reserve(1000);
	cout << "容量:" << v1.capacity() << " " << "大小:" << v1.size() << endl;
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	//v1[9] = 90;
	cout << "容量:" << v1.capacity() << " " << "大小:" << v1.size() << endl;
	//resize只能修改大小，不能修改容量
	//v1.reserve(4);
	vector<int>(v1).swap(v1);
	cout << "容量:" << v1.capacity() << " " << "大小:" << v1.size() << endl;
}
void t6()//嵌套容器
{
	vector<int>v1(5, 10);
	vector<int>v2(5, 100);
	vector<int>v3(5, 1000);
	
	//需求：定义一个vector容器存放v1，v2，v3
	vector<vector<int>>v;
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

	//遍历
	vector<vector<int>>::iterator it = v.begin();
	for (; it != v.end(); it++) {
		//*it == vector<int>
		vector<int>::iterator mit = (*it).begin();
		for (; mit != (*it).end(); mit++) {
			cout << *mit << " ";
		}
		cout << endl;
	}
}
void t7()//实用STL算法对vector容器排序
{
	vector<int>v1;
	v1.push_back(20);
	v1.push_back(60);
	v1.push_back(50);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(10);
	printVectorInt(v1);

	//排序算法
	sort(v1.begin(), v1.end());
	printVectorInt(v1);

}
class Person
{
	friend void printVectorPerson(vector<Person>& v);
	friend bool cmpPerson(Person ob1, Person ob2);
private:
	int num;
	string name;
	double score;
public:
	Person(){}
	Person(int num, string name, double score)
	{
		this->num = num;
		this->name = name;
		this->score = score;
	}
};
void printVectorPerson(vector<Person>& v)
{
	vector<Person>::iterator it = v.begin();
	for (; it != v.end(); it++) {
		//*it == Person
		cout << (*it).num << " " << (*it).name << " " << (*it).score << endl;
	}
}
bool cmpPerson(Person ob1, Person ob2)
{
	return ob1.num < ob2.num;
}
void t8()
{
	vector<Person>v1;
	v1.push_back(Person(100, "lucy", 77.7f));
	v1.push_back(Person(103, "bob", 77.7f));
	v1.push_back(Person(101, "tom", 77.7f));
	v1.push_back(Person(104, "德玛", 77.7f));
	v1.push_back(Person(105, "小法", 77.7f));

	printVectorPerson(v1);
	sort(v1.begin(), v1.end(), cmpPerson);
	printVectorPerson(v1);
}
int main()
{
	//t1();
	//t2();
	//t3();
	//t4();
	//t5();
	//t6();
	//t7();
	t8();
	return 0;
}

