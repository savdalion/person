#pragma once

#include "TraitCharacter.h"
#include <other-type.h>
#include <memory>
#include <tuple>
#include <ostream>


namespace person {

class Character;
typedef std::shared_ptr< Character >  CharacterPtr;
typedef std::unique_ptr< Character >  CharacterUPtr;

}




namespace person {


/**
* Характер персонажа.
*
* За основу взята работа О. Н. Маноловой "Количественные характеристики черт характера"
* @source http://ria-stk.ru/mi/adetail.php?ID=8859
*
* Характер строится из 10-ти базовых черт:
     0	Гипертимность	    Гип	    hypering	    hyp
     1	Застревание	        Зас	    seizing	        sei
     2	Эмотивность	        Эмо	    emoting	        emo
     3	Педантичность	    Пед	    pedantic	    ped
     4	Тревожность	        Тре	    anxiety	        anx
     5	Циклотимность	    Цик	    cycloiding	    cyc
     6	Демонстративность	Дем	    demonstrativing	dem
     7	Возбудимость	    Воз	    excitability	exc
     8	Дистимность	        Дис	    dysthyming	    dys
     9	Экзальтированность	Экз	    ecstatic	    ecs
*
* Все другие черты характера являются производными от базовых черт.
*/
class Character {
public:
    /**
    * Топология характера, базовые черты.
    * (!) Порядок элементов должен совпадать с порядком в матрице корреляции 'MC'.
    */
    typedef std::tuple<
        hyp, sei, emo, ped, anx, cyc, dem, exc, dys, ecs
    >  topology_t;



public:

    inline Character() {
        std::get< 0 >( mTopology ) =
            std::get< 1 >( mTopology ) =
            std::get< 2 >( mTopology ) =
            std::get< 3 >( mTopology ) =
            std::get< 4 >( mTopology ) =
            std::get< 5 >( mTopology ) =
            std::get< 6 >( mTopology ) =
            std::get< 7 >( mTopology ) =
            std::get< 8 >( mTopology ) =
            std::get< 9 >( mTopology ) =
        0.0f;
    }




    inline virtual ~Character() {
    }




    inline topology_t const& topology() const {
        return mTopology;
    }




    /**
    * Устанавливает значение для черты характера 'T'.
    * Остальные черты автоматически подтягиваются к "подходящим",
    * естественным значениям согласно матрице корреляции 'MC'.
    * (!) Меняются все значения за исключением черты 'T'.
    */
    template< typename T, typename V >
    inline void set( V value ) {
        assert( typelib::between( static_cast< float >( value ), 0.0f, 50.0f )
            && "Значение черты характера должно лежать в диапазоне [0; 50]." );

        /* - Не компилируется. Переписано. См. ниже.
        // находим индекс в массиве 'MC' по черте 'T'
        static const size_t k = indexMC< T >();
        std::get< k >( mTopology ) = static_cast< float >( value );
        recount< k >();
        */

        const auto& type = typeid( T );
        const float v = static_cast< float >( value );
        if (type == typeid( hyp )) {
            std::get< 0 >( mTopology ) = v;
            recount< 0 >();
        } else if (type == typeid( sei )) {
            std::get< 1 >( mTopology ) = v;
            recount< 1 >();
        } else if (type == typeid( emo )) {
            std::get< 2 >( mTopology ) = v;
            recount< 2 >();
        } else if (type == typeid( ped )) {
            std::get< 3 >( mTopology ) = v;
            recount< 3 >();
        } else if (type == typeid( anx )) {
            std::get< 4 >( mTopology ) = v;
            recount< 4 >();
        } else if (type == typeid( cyc )) {
            std::get< 5 >( mTopology ) = v;
            recount< 5 >();
        } else if (type == typeid( dem )) {
            std::get< 6 >( mTopology ) = v;
            recount< 6 >();
        } else if (type == typeid( exc )) {
            std::get< 7 >( mTopology ) = v;
            recount< 7 >();
        } else if (type == typeid( dys )) {
            std::get< 8 >( mTopology ) = v;
            recount< 8 >();
        } else if (type == typeid( ecs )) {
            std::get< 9 >( mTopology ) = v;
            recount< 9 >();
        } else {
            const std::string& typeName = type.name();
            std::cerr <<
                "Черта характера должна быть из набора [ hyp, sei, emo, ped, anx, cyc, dem, exc, dys, ecs ]." <<
                " Получено: " << typeName <<
            std::endl;
            throw "@todo fine";
        }
    }






protected:
    /**
    * Устанавливает значения других черт характера согласно матрице
    * корреляции 'MC'.
    * (!) Меняются все значения за исключением черты 'k'.
    *
    * @template k Индекс черты, относительно которой надо пересчитать
    *           другие черты.
    *
    * @see set()
    */
    template< size_t k >
    inline void recount() {
        const float value = std::get< k >( mTopology );
        // и пересчитываем значения других черт
        for (size_t i = 0; i < 10; ++i) {
            if (i != k) {
                const float t = value * (MC[k][i] + 1.0f);
                assert( typelib::between( t, 0.0f, 100.0f )
                    && "Значения черт характера должны лежать в диапазоне [0; 100]." );

                //std::get< i >( mTopology ) = t;
                switch ( i ) {
                    case 0 :
                        std::get< 0 >( mTopology ) = t;
                        break;
                    case 1 :
                        std::get< 1 >( mTopology ) = t;
                        break;
                    case 2 :
                        std::get< 2 >( mTopology ) = t;
                        break;
                    case 3 :
                        std::get< 3 >( mTopology ) = t;
                        break;
                    case 4 :
                        std::get< 4 >( mTopology ) = t;
                        break;
                    case 5 :
                        std::get< 5 >( mTopology ) = t;
                        break;
                    case 6 :
                        std::get< 6 >( mTopology ) = t;
                        break;
                    case 7 :
                        std::get< 7 >( mTopology ) = t;
                        break;
                    case 8 :
                        std::get< 8 >( mTopology ) = t;
                        break;
                    case 9 :
                        std::get< 9 >( mTopology ) = t;
                        break;
                    default:
                        std::cerr <<
                            "Черта характера должна быть из диапазона [0; 9]." <<
                            " Получено: " << i <<
                        std::endl;
                        throw "@todo fine";

                } // switch ( i )

            } // if (i != k)

        } // for (size_t i = 0; i < 10; ++i)

    }





protected:
    /**
    * @return Индекс в массиве 'MC' по черте 'T'.
    */
    template< typename T >
    static inline size_t indexMC() {
        const auto& type = typeid( T );
        if (type == typeid( hyp )) {
            return 0;
        } else if (type == typeid( sei )) {
            return 1;
        } else if (type == typeid( emo )) {
            return 2;
        } else if (type == typeid( ped )) {
            return 3;
        } else if (type == typeid( anx )) {
            return 4;
        } else if (type == typeid( cyc )) {
            return 5;
        } else if (type == typeid( dem )) {
            return 6;
        } else if (type == typeid( exc )) {
            return 7;
        } else if (type == typeid( dys )) {
            return 8;
        } else if (type == typeid( ecs )) {
            return 9;
        } else {
            const std::string& typeName = type.name();
            std::cerr <<
                "Черта характера должна быть из набора [ hyp, sei, emo, ped, anx, cyc, dem, exc, dys, ecs ]." <<
                " Получено: " << typeName <<
            std::endl;
            throw "@todo fine";
        }
        return 0;
    }





protected:
    /**
    * Базовые черты характера (топология).
    */
    topology_t mTopology;





private:
    /**
    * Матрица корреляция между базовыми чертами характера.
    * (!) Порядок коэффициентов должен совпадать с порядком в
    * топологии 'topology'.
    */
    static const float MC[10][10];

};






// @source http://ria-stk.ru/mi/adetail.php?ID=8859
const float Character::MC[10][10] = {
    { 1.00f, 0.04f, 0.11f, 0.00f, -0.03f, -0.11f, 0.51f, 0.03f, -0.62f, 0.05f },
    { 0.04f, 1.00f, 0.06f, 0.39f, 0.22f, 0.28f, 0.16f, 0.23f, 0.00f, 0.18f },
    { 0.11f, 0.06f, 1.00f, 0.26f, 0.48f, 0.20f, 0.03f, 0.26f, -0.06f, 0.30f },
    { 0.00f, 0.39f, 0.26f, 1.00f, 0.23f, 0.22f, 0.12f, 0.06f, 0.16f, 0.13f },
    { -0.03f, 0.22f, 0.48f, 0.23f, 1.00f, 0.33f, 0.01f, 0.02f, 0.18f, 0.26f },
    { -0.11f, 0.28f, 0.20f, 0.22f, 0.33f, 1.00f, -0.11f, 0.42f, 0.27f, 0.70f },
    { 0.51f, 0.16f, 0.03f, 0.12f, 0.01f, -0.11f, 1.00f, 0.27f, -0.30f, 0.22f },
    { 0.03f, 0.23f, 0.26f, 0.06f, 0.02f, 0.42f, 0.27f, 1.00f, 0.10f, 0.29f },
    { -0.62f, 0.00f, -0.06f, 0.16f, 0.18f, 0.27f, -0.30f, 0.10f, 1.00f, 0.16f },
    { 0.05f, 0.30f, 0.30f, 0.13f, 0.26f, 0.70f, 0.22f, 0.29f, 0.16f, 1.00f }
};




} // person








namespace std {


inline std::ostream& operator<<( std::ostream& out, const person::Character& c ) {
    std::ostringstream ss;
    ss << "[ " <<
        std::get< 0 >( c.topology() ) << ", " <<
        std::get< 1 >( c.topology() ) << ", " <<
        std::get< 2 >( c.topology() ) << ", " <<
        std::get< 3 >( c.topology() ) << ", " <<
        std::get< 4 >( c.topology() ) << ", " <<
        std::get< 5 >( c.topology() ) << ", " <<
        std::get< 6 >( c.topology() ) << ", " <<
        std::get< 7 >( c.topology() ) << ", " <<
        std::get< 8 >( c.topology() ) << ", " <<
        std::get< 9 >( c.topology() ) <<
    " ]";
    out << ss.str();

#ifdef _DEBUG
    // @test
    const std::string& s = ss.str();
    //std::cout << std::endl << s << std::endl << std::endl;
#endif

    return out;
}


} // std
