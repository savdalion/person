#pragma once

#include "configure.h"
#include <typelib/typelib.h>
#include <memory>
#include <ostream>


namespace person {

class Concept;
typedef std::shared_ptr< Concept >  ConceptPtr;
typedef std::unique_ptr< Concept >  ConceptUPtr;

}



namespace boost {

// Для работы коллекций boost::unordered_set и пр.
size_t hash_value( const person::Concept& );

} // boost





namespace person {


/**
* Понятие.
* Всё, о чём может быть сложено мнение.
*/
class Concept {
public:
    explicit inline Concept(
        const std::string& name,
        const typelib::lang_t& lang = typelib::LANG_DEFAULT
    ) :
        mName( name, lang )
    {
    }



    virtual inline ~Concept() {
    }



    inline typelib::Name const& operator()() const {
        return mName;
    }



    inline typelib::Name& operator()() {
        return mName;
    }



    /**
    * @return Число, однозначно соотв. данному понятию.
    */
    inline size_t hash() const {
        return boost::hash_value( *this );
    }






private:
    /**
    * Название понятия.
    */
    typelib::Name mName;
};




} // person







namespace boost {

inline size_t hash_value( const person::Concept& a ) {
    return boost::hash_value( a() );
}

} // boost







namespace std {



/**
* (!) Сравнене проходит по operator<( Name ).
*/
inline bool operator<( const person::Concept& a, const person::Concept& b ) {
    return (a() < b());
}




inline std::ostream& operator<<( std::ostream& out, const person::Concept& c ) {
    out << "{ \"name\": " << c() << " }";
    return out;
}


} // std
