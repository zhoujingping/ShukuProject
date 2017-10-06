#include "stdafx.h"
#include "Element.h"


Element::Element(int x,int y):isProcessed(false),value(0)
{
	node.x = x;
	node.y = y;
}


Element::~Element(){}

//检查该位置数值是否已处理过
bool Element::IsProcessed()const 
{
	return isProcessed;
}

//获取该数值行号
int Element::X() const
{
	return node.x;
}

//获取该数值列号
int Element::Y()const
{
	return node.y;
}

//设置该数值的行号
void Element::SetX(int x)
{
	node.x = x;
}

//设置该数值的列号
void Element::SetY(int y)
{
	node.y = y;
}

//检查有效数值列表是否为空
bool Element::IsValueListEmpty()const 
{
	return valueList.empty();
}

//将数字number添加到有效数值列表中
void Element::AddNextValue(int number)
{
	valueList.push_back(number);
}

//选择下一个有效数值
void Element::PickNextValue()
{
	int nextValue = valueList.front();
	valueList.pop_front();
	value = nextValue;
	isProcessed = true;
}

//设置处理标志
void Element::setIsProcessed(bool ip) 
{
	isProcessed = ip;
}

//清空该数值
void Element::Clear()
{
	valueList.clear();
	value = 0;
	isProcessed = false;
}
