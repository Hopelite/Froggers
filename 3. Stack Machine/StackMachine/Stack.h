#pragma once
#include "StackElement.h"
#include "ISubject.h"

class Stack : public ISubject
{
public:
	Stack();
	~Stack();

	int getCount();

	void push(int value);
	int pop();
	int peek();
	void duplicate();

	void attach(IObserver* observer) override;
	void detach() override;

protected:
	void notify(const std::string& message) override;

private:
	int count;
	StackElement* top;
	IObserver* observer;
};

