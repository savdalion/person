#include "../include/StdAfx.h"
#include "../include/configure.h"
#include <Person.h>
#include <json-type.h>


/**
* ���������� ������������ ��� ������� 'Person'.
*/
int main( int argc, char** argv ) {

    using namespace person;


    // ��������� ���������� ������ ���-�����
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
    // ��� ����������� '.' ������ ','
    setlocale( LC_NUMERIC, "C" );





    // �������� "�����"
    // @source http://ru.wikipedia.org/wiki/%D0%9F%D1%87%D1%91%D0%BB%D1%8B
    Person bee;
    // ������������ � ���������
    bee << Info( "�� ��� - �����" );

    //std::cout << "����� �������������:\n" << bee() << "\n";
    std::cout << "�������� ����� �������������:\n";  typelib::print( std::cout, bee() );  std::cout << "\n";




    EZLOGGERVLSTREAM( axter::log_always ) << "Person -> END" << std::endl;

    std::cout << std::endl << "^" << std::endl;
    std::cin.ignore();

    return 0;

} // main()
