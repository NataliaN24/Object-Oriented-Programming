#include "RadioButton.h"

void RadioButton::copyFrom(const RadioButton& other)
{
    options = new MyString[other.numberOfOptions];
    for (size_t i = 0; i < other.numberOfOptions; ++i) {
        options[i] = other.options[i];
    }
    numberOfOptions = other.numberOfOptions;
    selectedOption = other.selectedOption;
}

void RadioButton::moveFrom(RadioButton&& other)
{
    
        options= other.options;
    numberOfOptions = other.numberOfOptions;
    selectedOption = other.selectedOption;

    other.options = nullptr;
    other.numberOfOptions = other.selectedOption = 0;

}

void RadioButton::free()
{
    if (options != nullptr)
    {
        delete[]options;
    }
}

RadioButton::RadioButton()
{
    numberOfOptions = 0;
    options = nullptr;
    selectedOption = 0;
}

RadioButton::RadioButton(const RadioButton& other)
{
    copyFrom(other);
}

RadioButton::RadioButton(RadioButton&& other) noexcept
{
    moveFrom(std::move(other));
}

RadioButton& RadioButton::operator=(const RadioButton& other)
{
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

RadioButton& RadioButton::operator=(RadioButton&& other) noexcept
{
    if (this != &other) {
        Controls::operator=(std::move(other));
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

RadioButton::~RadioButton()
{
    free();
}

RadioButton::RadioButton(unsigned int l, unsigned int w, unsigned int x, unsigned int y, const MyString& name,const MyString* opt, size_t nr, int select)
    :Controls(l, w, x, y, name)
{
    this->options = new MyString[nr];
    for (int i = 0; i < nr; i++)
    {
        options[i] = opt[i];
    }
    numberOfOptions = nr;
    selectedOption = select;
  
}

void RadioButton::display() const
{
        Controls::display();
        std::cout << "Options: " << std::endl;
        for (size_t i = 0; i < numberOfOptions; ++i) {
            std::cout << (i +1== selectedOption ? "[*] " : "[ ] ") << options[i].c_str() << std::endl;
        }
}

void RadioButton::setDataDialog()
{
    std::cout<<"Enter the option you want to select:" << std::endl;
    int nr;
    std::cin >> nr;
    if (nr < 1 || nr > numberOfOptions)
    {
        throw::std::out_of_range("no such option!");
   }
    else
    {
        selectedOption = nr-1;
    }
}

void RadioButton::setNumberOfOptions(size_t nr)
{
    numberOfOptions = nr;
}

MyString RadioButton::getOption() const
{
    return options[selectedOption];
}

Controls* RadioButton::clone() const
{
    return new RadioButton(*this);
}
