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

	// Adds observer to this stack.
	void attach(IObserver* observer) override;
	// Detaches observer from this stack.
	void detach() override;

protected:
	// Method, that is invoked when changes in stack occur.
	void notify(const std::string& message) override;

private:
	int count;
	StackElement* top;
	IObserver* observer;
};

