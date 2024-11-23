#pragma once
#include"Controls.h"

class RadioButton:public Controls
{
	MyString* options;
	size_t numberOfOptions;
	int selectedOption;

	void copyFrom(const RadioButton&other);
	void moveFrom(RadioButton&&other);
	void free();
	
public:
	RadioButton();
	RadioButton(const RadioButton& other);
	RadioButton(RadioButton&& other)noexcept;
	RadioButton& operator=(const RadioButton& other);
	RadioButton& operator=(RadioButton&& other)noexcept;
	~RadioButton();

	RadioButton(unsigned int l, unsigned int w, unsigned int x, unsigned int y, const  MyString& name, const MyString* opt, size_t nr, int select);
	void display()const;
	virtual void setDataDialog() override;
	void setNumberOfOptions(size_t nr);
	MyString getOption()const;
	virtual Controls* clone()const override;
};

