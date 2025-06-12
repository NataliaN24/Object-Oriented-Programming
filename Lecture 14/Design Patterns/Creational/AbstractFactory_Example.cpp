#include <iostream>

class Button
{
public:
	virtual void render() = 0;
	virtual ~Button() = default;
};

class CheckBox {
public:
	virtual void render() = 0;
	virtual ~CheckBox() = default;
};

class WindowsButton :public Button
{
public:
	void render()override
	{
		std::cout << "Rendering Windows Button" << std::endl;
	}
};


class MacButton : public Button {
public:
	void render() override {
		std::cout << "Rendering Mac Button" << std::endl;
	}
};

class WindowsCheckBox :public CheckBox
{
public:
	void render() override {
		std::cout << "Rendering Windows Checkbox" << std::endl;
	}
};

class MacCheckbox : public CheckBox {
public:
	void render() override {
		std::cout << "Rendering Mac Checkbox" << std::endl;
	}
};

class GUI_Factory
{
public:
	virtual Button* createButton() = 0;
	virtual CheckBox* createCheckBox() = 0;
	virtual ~GUI_Factory() = default;
};

class WindowsFactory :public GUI_Factory
{
public:
	virtual Button* createButton() override
	{
		return new WindowsButton();
	}
	virtual CheckBox* createCheckBox() override
	{
		return new WindowsCheckBox();
	}
};


class MacFactory : public GUI_Factory {
public:
	Button* createButton() override {
		return new MacButton();
	}
	CheckBox* createCheckBox() override {
		return new MacCheckbox();
	}
};

void renderUI(GUI_Factory* factory)
{
	Button* btn = factory->createButton();
	CheckBox* chbtn = factory->createCheckBox();

	btn->render();
	chbtn->render();

	delete btn;
	delete chbtn;
}

int main()
{
	GUI_Factory* factory;
	
	bool isWindows = true;
	if (isWindows)
	{
		factory = new WindowsFactory();
	}
	else
	{
		factory = new MacFactory();
	}
	renderUI(factory);
	delete factory;
	return 0;
}
