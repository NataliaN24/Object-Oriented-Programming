#include"HtmlTable.h"
#include"Utils.h"

int main() 
{
	//PRINT TABLE FUNCTION:
	std::cout << "Table:" << std::endl;
	HtmlTable html_table;
	std::ifstream file(CONSTANTS::FILE_NAME,std::ios::in);
	if (!file.is_open()) {
		std::cerr << "File could not be opened" << std::endl;
		return 0;
	}
	html_table.parseHtmlTable(html_table,file);
	html_table.print();
	std::cout << std::endl;

	//ADDING A NEW ROW IN THE TABLE
	std::cout << "Table with the added row:" << std::endl;
	const Cell values[] = { "New Value1", "New Value2", "New Value3" };
	bool isHeader[] = { true, false, true,false }; 
	html_table.addNewRow(3, values, isHeader);
	html_table.save_table("table_with_added_row.txt", html_table);//I am using another file just for demostration but it can be saved also on the same file
	html_table.print();
	std::cout << std::endl;

	//REMOVING A ROW FROM THE TABLE;
	std::cout << "Table with removed row:" << std::endl;
	html_table.removeRow(1);
	html_table.save_table("table_removed_row.txt", html_table);
	html_table.print();
	std::cout << std::endl;

	//EDITING A ROW
	std::cout << "Edited row:" << std::endl;
	html_table.editCell(4, 2, "value", true);
	html_table.save_table("table_edited_row.txt", html_table);
	html_table.print();

}