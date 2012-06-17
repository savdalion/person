#include "../include/StdAfx.h"
#include "../include/configure.h"
#include <Person.h>
#include <json-type.h>


/**
* Визуальное тестирование для проекта 'Person'.
*/
int main( int argc, char** argv ) {

    using namespace person;


    // Приоритет определяет размер лог-файла
    axter::ezlogger<>::set_verbosity_level_tolerance( axter::log_rarely );
    //axter::ezlogger<>::set_verbosity_level_tolerance( axter::log_often );

    EZLOGGERVLSTREAM( axter::log_always ) << "Person -> BEGIN" << std::endl;
    #ifdef _MSC_VER
        #ifdef _DEBUG
            EZLOGGERVLSTREAM( axter::log_always ) << "Debug." << std::endl;
        #else
            EZLOGGERVLSTREAM( axter::log_always ) << "Release." << std::endl;
        #endif
    #endif

            
    setlocale( LC_ALL, "Russian" );
    // Для разделителя '.' вместо ','
    setlocale( LC_NUMERIC, "C" );





    // Персонаж "Пчела"
    // @source http://ru.wikipedia.org/wiki/%D0%9F%D1%87%D1%91%D0%BB%D1%8B
    Person bee;
    // Рассказываем о персонаже
    bee << Info( "Моё имя - Пчела" );

    //std::cout << "После инициализации:\n" << bee() << "\n";
    std::cout << "Персонаж после инициализации:\n";  typelib::print( std::cout, bee() );  std::cout << "\n";




    EZLOGGERVLSTREAM( axter::log_always ) << "Person -> END" << std::endl;

    std::cout << std::endl << "^" << std::endl;
    std::cin.ignore();

    return 0;

} // main()
