/* C++ API */
#include <iostream>
#include"fort.hpp"
#include "fort.c"
int main(void)
{
  int a = 1;
    fort::utf8_table table;
    table.set_border_style(FT_NICE_STYLE);
    table.column(0).set_cell_text_align(fort::text_align::center);
    table.column(1).set_cell_text_align(fort::text_align::center);

    table << fort::header
          << "Ранг" << "Название" << "Год" << "Рейтинг" << fort::endr
          << a << "Побег из Шоушенка" << "1994" << "9.5"<< fort::endr
          << "2" << "12 разгневанных мужчин" << "1957" << "8.8" << fort::endr
          << "3" << "Космическая одиссея 2001 года" << "1968" << "8.5" << fort::endr
          << "4" << "Бегущий по лезвию" << "1982" << "8.1" << fort::endr;
    std::cout << table.to_string() << std::endl;
}