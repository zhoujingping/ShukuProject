#pragma once

#include"Element.h"
#include"Node.h"

//Êý¶ÀÀà
class Shuku
{
public:
	Shuku();
	~Shuku();

	void GenerateShuku();
	void PrintShuku()const;
	void WriteFile(ofstream& out)const;

private:
	void GetNextValue(Element* currentElement);
	bool valueInRow(int value, int x, int y);
	bool valueInCol(int value, int x, int y);
	bool valueInSmallShuku(int value, int x, int y);
	void InitShuku();
	void NextNode(Node& currentNode);
	void PrevNode(Node& currentNode);

	const int MaxSize=9 ;

	Element (*shuku)[9];

};

