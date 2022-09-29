//POP_2021_01_15 _projekt_2_Dębiński_Radosław_AIR_3_184818
//Microsoft Visual Studio 2019 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string.h>
using namespace std;
/***********************************************************************/
struct param
{
	bool quo = false; //czy otwatro cudzysłów
	int coordx = 0; //współrzędna x tablic 3 wymiarowej
	int coordy = 0; //współrzędna y tablic 3 wymiarowej
	int coordz = 0; //współrzędna z tablic 3 wymiarowej
	int lenline = 0; //aktualna długość linii/wiersza
	int indexh = 0; // indeks dla height_table
	int addlines = 0; // liczba dodatkowych linii w komórce
	int num_of_char = 0; //naliczanie znakow w komorce
	int max_n_char = 0;
	//maksymalna liczba znakow dla komorki w wierszu
};
/***********************************************************************/
/******predefined variables*******/
const int max_length = 3000;
const int conditions_num_1 = 4;
const int mode_operator_1 = 1;
const int mode_operator_2 = 2;
const int mode_operator_3 = 3;
const int width_of_cell = 5;
const int width_of_short_cell = 6;
const int n_of_ch_sh_cell = 3;
//number of chars in short cell
const int name_length = 100;
/*********************************/
void introduce_name(char nazwaPliku[]);
void next_introduce(bool new_f, char nazwaPliku[], char name_of_file[]);
void menu(void);
void bad_menu_choise(bool& new_f, char name_of_file[], char nazwaPliku[]);
/**********************function declarations mode 1*********************/
void mode_1(char nazwaPliku[]);
void get_info_table1(char** table1, int* line_table, int num_of_lin,
	int max_num_of_char, int& n, int& m, int& k);
void width_of_kolumns(int* width_table, char** table1, int num_of_lin,
	int* line_table, int m, int n);
void height_of_lines(int* height_table, char** table1, int num_of_lin,
	int* line_table, int k);
bool conditions_for_cell(char** table1, int i, int j, int k, int q);
void width_line_end(int* number_of_widths, int i, int& q, int& b);
void allocate_table2(char*** table2, int n, int m, int* width_table);
void fill_in_table2(char*** table2, int n, int m, int* width_table,
	int* height_table, int k, char** table1, int* line_table,
	int num_of_lin, int max_num_of_char);
void next_cell_v_line(param& set, bool b);
void end_of_line(param& set, int* height_table);
void show_table2(char*** table2, int n, int m, int* width_table,
	int* height_table, int k);
void show_horizontal_line(int* width_table, int m);
void destroy_table2(char*** table2, int n, int m, int* width_table);
void destroy_tables(char** table1, int num_of_lin, int* line_table,
	int* width_table, int* height_table);
/***********************************************************************/
/**********************function declarations mode 2*********************/
void mode_2(char nazwaPliku[]);
void get_info_table1_2(char** table1, int* line_table, int num_of_lin,
	int max_num_of_char, int* height_table, int m);
void broaden_a_line(int* bonus_table, param& set, int& d);
void end_of_line_1(int* bonus_table, param& set, int& d,
	int* height_table);
void cut_a_height_table(int* height_table, int k);
void allocate_table3(char*** table3, int n, int m);
void fill_in_table3(int* line_table, int num_of_lin, char** table1,
	int* height_table, char*** table3);
void next_bottom_cell_mode_2(param& set);
void next_right_cell_mode_2(param& set);
void end_of_line_2(param& set, int* height_table);
void show_table3(char*** table3, int n, int m, int* height_table);
void show_horizontal_line_mode_2(int m);
void destroy_tables_mode_2(char** table1, int num_of_lin,
	int* height_table, char*** table3, int n, int m);
/***********************************************************************/
/**********************function declarations mode 3*********************/
void mode_3(char nazwaPliku[]);
void allocate_table4(char*** table4, int n, int m);
void fill_in_table4(int* line_table, int num_of_lin,
	char** table1, char*** table4);
void points_condition(char*** table4, param& set);
void show_table4(char*** table4, int n, int m);
void show_horizontal_line_mode_3(int m);
void destroy_table4(char*** table4, int n, int m);
/***********************************************************************/
/**********************common function declarations*********************/
int get_length(char* line);
void get_info(int& num_of_lin, int& max_num_of_char, char nazwaPliku[]);
void fill_in_table1(char** table1, int* line_table,
	int num_of_lin, int max_num_of_char, char nazwaPliku[]);
void allocate_table1(char** table1, int num_of_lin, int max_num_of_char);
int conditions_for_lines(char** table1, int* line_table,
	int num_of_lin, int max_num_of_char, int& k);
void fill_in_bonus_table(int& b, int& d, param& set, int* bonus_table);
void increase_c_v_k(int& c, param& set, int& k);
int max_bonus_table(int* bonus_table, int d);
int conditions_for_columns(char** table1, int* line_table,
	int num_of_lin, int max_num_of_char);
void between_tables(char*** table2, char** table1, param& set, int i, int j);
void go_out(int ch, char nazwaPliku[]);
void go_out_option_1(bool& new_file);
/***********************************************************************/
int main(char second_file_id[], bool new_f)
{
	static bool f = false; //czy mamy pierwszy plik
	char first_file_id[name_length];
	if (f == false)
	{
		introduce_name(first_file_id);
		f = true;
	}
	else
		next_introduce(new_f, first_file_id, second_file_id);

	char m;
	menu();
	cin >> m;
	switch (m)
	{
	case '1':
		system("cls");
		mode_1(first_file_id);
		break;

	case '2':
		system("cls");
		mode_2(first_file_id);
		break;

	case '3':
		system("cls");
		mode_3(first_file_id);
		break;

	default:
		bad_menu_choise(new_f, second_file_id, first_file_id);
		main(first_file_id, new_f);
		break;
	}
	return 0;
}
/***********************************************************************/
void introduce_name(char first_file_id[])
{
	cout << "---Program do generacji tabeli na ";
	cout << "podstawie pliku formatu CSV---" << endl << endl;
	cout << "Prosze podac nazwe pliku: ";
	cin >> first_file_id;
	system("cls");
}
/***********************************************************************/
void next_introduce(bool new_f, char first_file_id[], char second_file_id[])
{
	if (new_f == true) introduce_name(first_file_id);
	else strcpy(first_file_id, second_file_id);
}
/***********************************************************************/
void menu(void)
{
	cout << "---------MENU---------" << endl;
	cout << "W jakim trybie wyswietlania dlugich tekstow";
	cout << " otworzyc plik w formacie csv?:" << endl;
	cout << "1.Wyswietlanie tekstu w jednej linii." << endl;
	cout << "2.Wyswietlanie tekstu w jednej komorce w wielu liniach." << endl;
	cout << "3.Wyswietlanie tylko poczatku tekstu w komorce." << endl;
	cout << "Podaj opcje:";
}
/***********************************************************************/
void bad_menu_choise(bool& new_f, char name_of_file[], char first_file_id[])
{
	system("cls");
	cout << "Nie posiadam takiej opcji w MENU :(" << endl;
	new_f = false;
	strcpy(name_of_file, first_file_id);
}
/***********************************************************************/
void mode_1(char first_file_id[])
{
	int num_of_lin = 0; //liczba wierszy dla tabeli 1
	int max_num_of_char = 0;  //maksymalna liczba znaków tabela 1
	get_info(num_of_lin, max_num_of_char, first_file_id);
	char** table1 = new char* [num_of_lin];
	allocate_table1(table1, num_of_lin, max_num_of_char);
	int* line_table = new int[num_of_lin];  // tablica dlugosci wierszy
	fill_in_table1(table1, line_table, num_of_lin, max_num_of_char, first_file_id);
	//pobranie zawartosci do tabel1 i pobranie informacji o długosci linii do tabeli
	int n; //liczba wierszy dla tabeli 2 
	int m; //liczba kolumn dla tabeli 2
	int k = 0; //końcowa liczba wierszy
	get_info_table1(table1, line_table, num_of_lin, max_num_of_char, n, m, k);
	int* width_table = new int[m];
	width_of_kolumns(width_table, table1, num_of_lin, line_table, m, n);
	int* height_table = new int[k];
	height_of_lines(height_table, table1, num_of_lin, line_table, k);
	char*** table2 = new char** [n];
	allocate_table2(table2, n, m, width_table);
	fill_in_table2(table2, n, m, width_table, height_table,
		k, table1, line_table, num_of_lin, max_num_of_char);
	show_table2(table2, n, m, width_table, height_table, k);
	destroy_table2(table2, n, m, width_table);
	destroy_tables(table1, num_of_lin, line_table, width_table, height_table);
	go_out(mode_operator_1, first_file_id);
}
/***********************************************************************/
void get_info_table1(char** table1, int* line_table, int num_of_lin,
	int max_num_of_char, int& n, int& m, int& k)
{
	n = conditions_for_lines(table1, line_table, num_of_lin,
		max_num_of_char, k);
	m = conditions_for_columns(table1, line_table, num_of_lin,
		max_num_of_char);
}
/***********************************************************************/
void width_of_kolumns(int* width_table, char** table1, int num_of_lin,
	int* line_table, int m, int n)
{
	param set;
	int n_ch = 0; // licznik znaków w komórce
	int whi_cel = 0; // która komórka
	int* number_of_widths = new int[n];
	for (int i = 0; i < n; i++) number_of_widths[i] = 0;
	for (int k = 0; k < m; k++)
	{
		for (int i = 0; i < num_of_lin; i++)
		{
			set.lenline = line_table[i] + 1; // +NULL
			for (int j = 0; j < set.lenline; j++)
			{
				if (table1[i][j] == '\"' && set.quo == false)
				{
					set.quo = true;
					continue;
				}
				if (table1[i][j] == '\"' && set.quo == true)
				{
					set.quo = false;
					continue;
				}
				if (conditions_for_cell(table1, i, j, k, whi_cel))
					n_ch++;

				if (table1[i][j] == ',' && set.quo == false)
					whi_cel++;

				if (table1[i][j] == '\0' && set.quo == false)
					width_line_end(number_of_widths, i, whi_cel, n_ch);
			}
		}
		width_table[k] = max_bonus_table(number_of_widths, n);
		for (int i = 0; i < n; i++) number_of_widths[i] = 0;
	}
	delete[] number_of_widths;
}
/***********************************************************************/
void height_of_lines(int* height_table, char** table1, int num_of_lin,
	int* line_table, int k)
{
	param set;
	int height_line = 0; // wysokosć wiersza
	int num_line = 0; // który wiersz
	for (int i = 0; i < k; i++) height_table[i] = 0;
	for (int i = 0; i < num_of_lin; i++)
	{
		set.lenline = line_table[i] + 1; // +NULL
		for (int j = 0; j < set.lenline; j++)
		{
			if (table1[i][j] == '\"' && set.quo == false)
			{
				set.quo = true;
				continue;
			}
			if (table1[i][j] == '\"' && set.quo == true)
			{
				set.quo = false;
				continue;
			}
			if (table1[i][j] == '\0' && set.quo == false)
			{
				if (height_line != 0)
				{
					height_table[num_line] = height_line;
					height_line = 0;
				}
				num_line++;
			}
			if (table1[i][j] == '\0' && set.quo == true)
				height_line++;
		}
	}
}
/***********************************************************************/
bool conditions_for_cell(char** table1, int i, int j, int k, int whi_cel)
{
	int p = 0;
	if (whi_cel == k) p++;
	if (table1[i][j] != ',') p++;
	if (table1[i][j] != '\"') p++;
	if (table1[i][j] != '\0') p++;
	if (p == conditions_num_1) return true;
	else return false;
}
/***********************************************************************/
void width_line_end(int* number_of_widths, int i, int& whi_cel, int& n_ch)
{
	number_of_widths[i] = n_ch;
	n_ch = 0;
	whi_cel = 0;
}
/***********************************************************************/
void allocate_table2(char*** table2, int n, int m, int* width_table)
{
	for (int i = 0; i < n; i++)
		table2[i] = new char* [m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			table2[i][j] = new char[width_table[j]];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < width_table[j]; k++)
				table2[i][j][k] = '\0';
}
/***********************************************************************/
void fill_in_table2(char*** table2, int n, int m, int* width_table,
	int* height_table, int k, char** table1, int* line_table,
	int num_of_lin, int max_num_of_char)
{
	param set;
	bool b = false; //zmienna dla next_cell_v_line
	for (int i = 0; i < num_of_lin; i++)
	{
		set.lenline = line_table[i] + 1; // +NULL
		for (int j = 0; j < set.lenline; j++)
		{
			if (table1[i][j] == '\"' && set.quo == false)
			{
				set.quo = true;
				continue;
			}
			else if (table1[i][j] == '\"' && set.quo == true)
			{
				set.quo = false;
				set.coordx -= height_table[set.indexh];
				continue;
			}
			else if (table1[i][j] == ',' && set.quo == false)
			{
				b = false;
				next_cell_v_line(set, b);
			}
			else if (table1[i][j] == '\0' && set.quo == true)
			{
				b = true;
				next_cell_v_line(set, b);
			}
			else if (table1[i][j] == '\0' && set.quo == false)
			{
				end_of_line(set, height_table);
			}
			else
			{
				between_tables(table2, table1, set, i, j);
			}
		}
	}
}
/***********************************************************************/
void next_cell_v_line(param& set, bool b)
{
	if (b == true) set.coordx++;
	else set.coordy++;
	set.coordz = 0;
}
/***********************************************************************/
void end_of_line(param& set, int* height_table)
{
	set.coordy = 0;
	set.coordx += height_table[set.indexh] + 1;
	set.indexh++;
}
/***********************************************************************/
void show_table2(char*** table2, int n, int m, int* width_table,
	int* height_table, int k)
{
	int p = 0, g = 0;
	// zmienne kontrolujące wysokość komórki
	show_horizontal_line(width_table, m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "|";
			for (int q = 0; q < width_table[j]; q++)
			{
				cout << table2[i][j][q];
				if (table2[i][j][q] == '\0')
					cout << " ";
			}
			cout << " ";
		}
		cout << "|" << endl;
		if (g < height_table[p])
		{
			g++;
			continue;
		}
		else
		{
			g = 0;
			show_horizontal_line(width_table, m);
			p++;
		}
	}
}
/***********************************************************************/
void show_horizontal_line(int* width_table, int m)
{
	for (int i = 0; i < m; i++)
	{
		cout << "+";
		for (int j = 0; j <= width_table[i]; j++)
			cout << "-";
	}
	cout << "+" << endl;
}
/***********************************************************************/
void destroy_table2(char*** table2, int n, int m, int* width_table)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			delete table2[i][j];

	for (int i = 0; i < n; i++)
		delete table2[i];

	delete[]  table2;
	table2 = NULL;
}
/***********************************************************************/
void destroy_tables(char** table1, int num_of_lin, int* line_table,
	int* width_table, int* height_table)
{
	for (int i = 0; i < num_of_lin; ++i)
		delete[] table1[i];
	delete[] table1;
	table1 = NULL;
	delete[] width_table;
	width_table = NULL;
	delete[] line_table;
	line_table = NULL;
	delete[] height_table;
	height_table = NULL;
}
/***********************************************************************/
void mode_2(char first_file_id[])
{
	int num_of_lin = 0; //liczba wierszy dla tabeli 1
	int max_num_of_char = 0;  //maksymalna liczba znaków tabela 1
	get_info(num_of_lin, max_num_of_char, first_file_id);
	char** table1 = new char* [num_of_lin];
	allocate_table1(table1, num_of_lin, max_num_of_char);
	int* line_table = new int[num_of_lin];  // tablica dlugosci wierszy
	fill_in_table1(table1, line_table, num_of_lin, max_num_of_char, first_file_id);
	int k = 0; //końcowa liczba wierszy
	int m; //końcowa liczba kolumn
	int n = 0; //liczba wierszy
	conditions_for_lines(table1, line_table, num_of_lin, max_num_of_char, k);
	m = conditions_for_columns(table1, line_table, num_of_lin, max_num_of_char);
	int* height_table = new int[k];
	get_info_table1_2(table1, line_table, num_of_lin,
		max_num_of_char, height_table, m);
	cut_a_height_table(height_table, k);
	for (int i = 0; i < k; i++) n += height_table[i];
	char*** table3 = new char** [n];
	allocate_table3(table3, n, m);
	fill_in_table3(line_table, num_of_lin, table1, height_table, table3);
	show_table3(table3, n, m, height_table);
	destroy_tables_mode_2(table1, num_of_lin, height_table, table3, n, m);
	go_out(mode_operator_2, first_file_id);
}
/***********************************************************************/
void get_info_table1_2(char** table1, int* line_table, int num_of_lin,
	int max_num_of_char, int* height_table, int m)
{
	param set;
	int d = 0; //indeks komorki w wierszu
	int* bonus_table = new int[max_length];
	for (int i = 0; i < max_length; i++) bonus_table[i] = 0;
	for (int i = 0; i < num_of_lin; i++)
	{
		set.lenline = line_table[i] + 1; // +NULL
		for (int j = 0; j < set.lenline; j++)
		{
			if (table1[i][j] == '\"' && set.quo == false)
			{
				set.quo = true;
				continue;
			}
			else if (table1[i][j] == '\"' && set.quo == true)
			{
				set.quo = false;
				continue;
			}
			else if (table1[i][j] == '\0' && set.quo == 1) continue;
			else if (table1[i][j] == ',' && set.quo == 0)
			{
				broaden_a_line(bonus_table, set, d);
				continue;
			}
			else if (table1[i][j] == '\0' && set.quo == 0)
			{
				broaden_a_line(bonus_table, set, d);
				end_of_line_1(bonus_table, set, d, height_table);
			}
			else set.num_of_char++;
		}
	}
	delete[] bonus_table;
	bonus_table = NULL;
}
/***********************************************************************/
void broaden_a_line(int* bonus_table, param& set, int& d)
{
	bonus_table[d] = set.num_of_char;
	d++;
	set.num_of_char = 0;
}
/***********************************************************************/
void end_of_line_1(int* bonus_table, param& set, int& d, int* height_table)
{
	set.max_n_char = max_bonus_table(bonus_table, d);
	for (int i = 0; i < d; i++) bonus_table[i] = 0;
	height_table[set.indexh] = set.max_n_char;
	set.indexh++;
	set.max_n_char = 0;
	d = 0;
}
/***********************************************************************/
void cut_a_height_table(int* height_table, int k)
{
	int n;
	int j = 1;
	for (int i = 0; i < k; i++)
	{
		n = height_table[i];
		while (n > width_of_cell)
		{
			n -= width_of_cell;
			j++;
		}
		height_table[i] = j;
		j = 1;
	}
}
/***********************************************************************/
void allocate_table3(char*** table3, int n, int m)
{
	for (int i = 0; i < n; i++)
		table3[i] = new char* [m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			table3[i][j] = new char[width_of_cell];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < width_of_cell; k++)
				table3[i][j][k] = '\0';
}
/***********************************************************************/
void fill_in_table3(int* line_table, int num_of_lin, char** table1,
	int* height_table, char*** table3)
{
	param set;
	for (int i = 0; i < num_of_lin; i++)
	{
		set.lenline = line_table[i] + 1; // +NULL
		for (int j = 0; j < set.lenline; j++)
		{
			if (set.coordz == width_of_cell)
			{
				next_bottom_cell_mode_2(set);
			}
			if (table1[i][j] == '\"' && set.quo == false)
			{
				set.quo = true;
				continue;
			}
			else if (table1[i][j] == '\"' && set.quo == true)
			{
				set.quo = false;
				continue;
			}
			else if (table1[i][j] == ',' && set.quo == false)
			{
				next_right_cell_mode_2(set);
			}
			else if (table1[i][j] == '\0' && set.quo == true)
				continue;

			else if (table1[i][j] == '\0' && set.quo == false)
			{
				end_of_line_2(set, height_table);
			}
			else
			{
				between_tables(table3, table1, set, i, j);
			}
		}
	}

}
/***********************************************************************/
void next_bottom_cell_mode_2(param& set)
{
	set.coordx++;
	set.coordz = 0;
	set.addlines++;
}
/***********************************************************************/
void next_right_cell_mode_2(param& set)
{
	set.coordz = 0;
	set.coordx -= set.addlines;
	set.addlines = 0;
	set.coordy++;
}
/***********************************************************************/
void end_of_line_2(param& set, int* height_table)
{
	set.coordx -= set.addlines;
	set.addlines = 0;
	set.coordx += height_table[set.indexh];
	set.coordy = 0;
	set.coordz = 0;
	set.indexh++;
}
/***********************************************************************/
void show_table3(char*** table3, int n, int m, int* height_table)
{
	int p = 0, g = 0;
	// zmienne kontrolujące wysokość komórki
	show_horizontal_line_mode_2(m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "|";
			for (int q = 0; q < width_of_cell; q++)
			{
				cout << table3[i][j][q];
				if (table3[i][j][q] == '\0')
					cout << " ";
			}
			cout << " ";
		}
		cout << "|" << endl;
		if (g < height_table[p] - 1)
		{
			g++;
			continue;
		}
		else
		{
			g = 0;
			show_horizontal_line_mode_2(m);
			p++;
		}
	}
}
/***********************************************************************/
void show_horizontal_line_mode_2(int m)
{
	for (int i = 0; i < m; i++)
	{
		cout << "+";
		for (int j = 0; j <= width_of_cell; j++)
			cout << "-";
	}
	cout << "+" << endl;
}
/***********************************************************************/
void destroy_tables_mode_2(char** table1, int num_of_lin,
	int* height_table, char*** table3, int n, int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			delete table3[i][j];

	for (int i = 0; i < n; i++)
		delete table3[i];

	delete[]  table3;
	table3 = NULL;

	for (int i = 0; i < num_of_lin; ++i)
		delete[] table1[i];
	delete[] table1;
	table1 = NULL;
	delete[] height_table;
	height_table = NULL;
}
/***********************************************************************/
void mode_3(char first_file_id[])
{
	int num_of_lin = 0; //liczba wierszy dla tabeli 1
	int max_num_of_char = 0;  //maksymalna liczba znaków tabela 1
	get_info(num_of_lin, max_num_of_char, first_file_id);
	char** table1 = new char* [num_of_lin];
	allocate_table1(table1, num_of_lin, max_num_of_char);
	int* line_table = new int[num_of_lin];  // tablica dlugosci wierszy
	fill_in_table1(table1, line_table, num_of_lin, max_num_of_char, first_file_id);
	int n = 0; //końcowa liczba wierszy
	int m; //końcowa liczba kolumn
	conditions_for_lines(table1, line_table, num_of_lin, max_num_of_char, n);
	m = conditions_for_columns(table1, line_table, num_of_lin, max_num_of_char);
	char*** table4 = new char** [n];
	allocate_table4(table4, n, m);
	fill_in_table4(line_table, num_of_lin, table1, table4);
	show_table4(table4, n, m);
	destroy_table4(table4, n, m);
	go_out(mode_operator_3, first_file_id);
}
/***********************************************************************/
void allocate_table4(char*** table4, int n, int m)
{
	for (int i = 0; i < n; i++)
		table4[i] = new char* [m];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			table4[i][j] = new char[width_of_short_cell];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			for (int k = 0; k < width_of_short_cell; k++)
				table4[i][j][k] = '\0';
}
/***********************************************************************/
void fill_in_table4(int* line_table, int num_of_lin, char** table1, char*** table4)
{
	param set;
	for (int i = 0; i < num_of_lin; i++)
	{
		set.lenline = line_table[i] + 1; // +NULL
		for (int j = 0; j < set.lenline; j++)
		{
			if (table1[i][j] == '\"' && set.quo == false)
			{
				set.quo = true;
				continue;
			}
			else if (table1[i][j] == '\"' && set.quo == true)
			{
				set.quo = false;
				continue;
			}
			else if (table1[i][j] == ',' && set.quo == false)
			{
				points_condition(table4, set);
				set.coordz = 0;
				set.coordy++;
			}
			else if (table1[i][j] == '\0' && set.quo == true)
				continue;

			else if (table1[i][j] == '\0' && set.quo == false)
			{
				points_condition(table4, set);
				set.coordx++;
				set.coordy = 0;
				set.coordz = 0;
			}
			else if (set.coordz < width_of_short_cell)
			{
				between_tables(table4, table1, set, i, j);
			}
		}
	}
}
/***********************************************************************/
void points_condition(char*** table4, param& set)
{
	if (table4[set.coordx][set.coordy][n_of_ch_sh_cell] != '\0')
		for (int x = 0; x < n_of_ch_sh_cell; x++)
		{
			table4[set.coordx][set.coordy][n_of_ch_sh_cell + x] = '.';
		}
}
/***********************************************************************/
void show_table4(char*** table4, int n, int m)
{
	show_horizontal_line_mode_3(m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << "|";
			for (int q = 0; q < width_of_short_cell; q++)
			{
				cout << table4[i][j][q];
				if (table4[i][j][q] == '\0')
					cout << " ";

			}
			cout << " ";
		}
		cout << "|" << endl;
		show_horizontal_line_mode_3(m);
	}
}
/***********************************************************************/
void show_horizontal_line_mode_3(int m)
{
	for (int i = 0; i < m; i++)
	{
		cout << "+";
		for (int j = 0; j <= width_of_short_cell; j++)
			cout << "-";
	}
	cout << "+" << endl;
}
/***********************************************************************/
void destroy_table4(char*** table4, int n, int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			delete table4[i][j];

	for (int i = 0; i < n; i++)
		delete table4[i];

	delete[]  table4;
	table4 = NULL;
}
/***********************************************************************/
/**********************common function declarations*********************/
int get_length(char* line)
{
	int p = 0;

	while (line[p] != '\0') p++;

	return p;
}
/***********************************************************************/
void get_info(int& num_of_lin, int& max_num_of_char, char first_file_id[])
{
	fstream p1;

	p1.open(first_file_id, ios::in);
	if (!p1)
	{
		cerr << "Nieudane otwarcie pliku " << first_file_id << " do odczytu " << endl;
		exit(1);
	}
	char* line = new char[max_length];
	int l;

	while (p1.good() == true)
	{
		p1.getline(line, max_length);
		l = get_length(line);
		if (l > max_num_of_char)
			max_num_of_char = l;

		num_of_lin++;
	}
	max_num_of_char++;
	delete[] line;
	line = NULL;
	p1.close();
}
/***********************************************************************/
void fill_in_table1(char** table1, int* line_table, int num_of_lin,
	int max_num_of_char, char first_file_id[])
{
	fstream p1;

	p1.open(first_file_id, ios::in);
	if (!p1)
	{
		cerr << "Nieudane otwarcie pliku " << first_file_id << " do odczytu " << endl;
		exit(1);
	}
	char* line = new char[max_num_of_char];
	int l;

	for (int i = 0; i < num_of_lin; i++)
	{
		p1.getline(line, max_length);
		l = get_length(line);
		line_table[i] = l;
		for (int j = 0; j < l; j++)
			table1[i][j] = line[j];
	}

	delete[] line;
	line = NULL;
	p1.close();
}
/***********************************************************************/
void allocate_table1(char** table1, int num_of_lin, int max_num_of_char)
{
	for (int i = 0; i < num_of_lin; ++i)
	{
		table1[i] = new char[max_num_of_char];
		for (int j = 0; j < max_num_of_char; ++j)
			table1[i][j] = '\0';
	}
}
/***********************************************************************/
int conditions_for_lines(char** table1, int* line_table, int num_of_lin,
	int max_num_of_char, int& k)
{
	param set;
	int b = 0; //aktualna liczba dodatkowych linii
	int c = 0; //liczba linii po obróbce
	int d = 0; //liczba kolumn z dodatkowymi liniami
	int* bonus_table = new int[max_length];
	for (int i = 0; i < max_length; i++) bonus_table[i] = 0;
	for (int i = 0; i < num_of_lin; i++)
	{
		set.lenline = line_table[i] + 1; // +NULL
		for (int j = 0; j < set.lenline; j++)
		{
			if (table1[i][j] == '\"' && set.quo == false)
			{
				set.quo = true;
				continue;
			}
			if (table1[i][j] == '\"' && set.quo == true)
			{
				fill_in_bonus_table(b, d, set, bonus_table);
				continue;
			}
			if (table1[i][j] == '\0' && set.quo == 1)
			{
				b++;
				continue;
			}
			if (table1[i][j] == '\0' && set.quo == 0)
			{
				set.max_n_char = max_bonus_table(bonus_table, d) + 1;
				for (int i = 0; i < d; i++) bonus_table[i] = 0;
				increase_c_v_k(c, set, k);
				d = 0;
				continue;
			}
		}
	}
	delete[] bonus_table;
	bonus_table = NULL;
	return c;
}
/***********************************************************************/
void increase_c_v_k(int& c, param& set, int& k)
{
	if (set.max_n_char != 0)
	{
		c += set.max_n_char;
		k++;
	}
	else
	{
		c++;
		k++;
	}
}
/***********************************************************************/
void fill_in_bonus_table(int& b, int& d, param& set, int* bonus_table)
{
	if (b != 0)
	{
		bonus_table[d] = b;
		b = 0;
		d++;
	}
	set.quo = false;
}
/***********************************************************************/
int max_bonus_table(int* bonus_table, int d)
{
	int max = 0;
	for (int i = 0; i < d; i++)
		if (bonus_table[i] > max) max = bonus_table[i];

	return max;
}
/***********************************************************************/
int conditions_for_columns(char** table1, int* line_table,
	int num_of_lin, int max_num_of_char)
{
	int m = 0;
	bool a = false; //czy otwatro cudzysłów
	int b = 0;
	int l = 0; //aktualna długość linii/wiersza

	for (int i = 0; i < num_of_lin; i++)
	{
		l = line_table[i] + 1; // +NULL
		for (int j = 0; j < l; j++)
		{
			if (table1[i][j] == '\"' && a == false)
			{
				a = true;
				continue;
			}
			if (table1[i][j] == '\"' && a == true)
			{
				a = false;
				continue;
			}
			if (table1[i][j] == ',' && a == false)
				b++;

			if (table1[i][j] == '\0' && a == false)
			{
				if (b > m) m = b;
				b = 0;
			}
		}
	}
	m++;
	return m;
}
/***********************************************************************/
void go_out(int ch, char first_file_id[])
{
	bool new_f = false;
	cout << endl << "By powrocic do menu wprowadz \"1\"";
	cout << endl << "Natomiast, by opuscic program wybierz \"2\"" << endl;
	char o;
	cin >> o;
	switch (o)
	{
	case '1':
		system("cls");
		go_out_option_1(new_f);
		main(first_file_id, new_f);
		break;

	case '2':
		exit(0);
		break;
	default:
		system("cls");
		cout << "Nie posiadam takiej opcji :(" << endl;
		if (ch == 1) mode_1(first_file_id);
		else if (ch == 2) mode_2(first_file_id);
		else if (ch == 3) mode_3(first_file_id);
		break;
	}
}
/***********************************************************************/
void go_out_option_1(bool& new_f)
{
	char choise;
	cout << "Czy zalaczyc nowy plik" << endl;
	cout << "1 = TAK" << endl << "2 = NIE" << endl;
	cin >> choise;
	system("cls");
	switch (choise)
	{
	case '1':
		new_f = true;
		break;

	case '2':
		new_f = false;
		break;
	default:
		system("cls");
		cout << "Nie posiadam takiej opcji :(" << endl;
		go_out_option_1(new_f);
		break;
	}

}
/***********************************************************************/
void between_tables(char*** table2, char** table1, param& set, int i, int j)
{
	table2[set.coordx][set.coordy][set.coordz] = table1[i][j];
	set.coordz++;
}
/***********************************************************************/