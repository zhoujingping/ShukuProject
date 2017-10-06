#pragma once
#include"Node.h"
#include<list>
using namespace std;

//数独组成元素类
class Element
{
public:
	Element(int x = 0,int y=0);
	~Element();
	bool IsProcessed() const;
	int X() const;
	int Y() const;
	void SetX(int x);
	void SetY(int y);

	void AddNextValue(int number);
	void PickNextValue();
	void Clear();
	void setIsProcessed(bool ip);

	bool IsValueListEmpty() const;
	int value;

private:
	Node node;
	bool isProcessed;
	list<int> valueList;
};

