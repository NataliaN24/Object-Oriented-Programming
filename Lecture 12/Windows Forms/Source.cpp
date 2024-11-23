#include <iostream>
#include "Controls.h"
#include "TextBox.h"
#include"CheckBox.h"
#include "RadioButton.h"
#include <iostream>
#include "Form.h"


int main() {
    TextBox textBox1(100, 50, 10, 10, "TextBox1", "Enter Text");
    TextBox textBox2(200, 50, 20, 20, "TextBox2", "Enter More Text");

    CheckBox checkBox1(100, 30, 30, 30, "CheckBox1", "Accept Terms", false);
    CheckBox checkBox2(100, 30, 40, 40, "CheckBox2", "Subscribe to Newsletter", true);

    MyString options[] = { "Option 1", "Option 2", "Option 3" };
    RadioButton radioButton1(120, 30, 50, 50, "RadioButton1", options,3, 1);
    RadioButton radioButton2(120, 30, 60, 60, "RadioButton2", options, 3, 3);

    Controls* controls[] = { &textBox1, &textBox2, &checkBox1, &checkBox2, &radioButton1, &radioButton2 };

    Form form(800, 600, "MyForm", controls, 6, 10);

    form.display();

    form.changeTheDimension(1024, 768);
    form.display(); 

    form.display();  

    form.change(2);  
    form.change(1);  
    form.display();

    return 0;
}
