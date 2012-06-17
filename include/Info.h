#pragma once

#include <string>
#include <memory>
#include <ostream>


namespace person {

class Info;
typedef std::shared_ptr< Info >  InfoPtr;
typedef std::unique_ptr< Info >  InfoUPtr;

}



namespace boost {

// Для работы коллекций boost::unordered_set и пр.
size_t hash_value( const person::Info& );

} // boost




namespace person {


/**
* Информация о чём-либо.
* Представлена в виде строки символов, из которой впоследствии может быть
* получен набор термов.
* Строка символов может быть *любой*, она не разделена на языки, т.к. Info - это
* просто поток. Мы не называем здесь этот поток "данными", чтобы подчеркнуть:
* поток содержит то, что может быть воспринято персонажем.
*/
class Info {
public:
    explicit inline Info( const std::string& data ) : mData( data ) {
    }



    inline std::string const& operator()() const {
        return mData;
    }


    inline std::string& operator()() {
        return mData;
    }



    inline bool operator==( const Info& b ) const {
        return (mData == b());
    }





private:
    /**
    * Информация в виде набора символов.
    */
    std::string mData;
};




} // person








namespace boost {

inline size_t hash_value( const person::Info& a ) {
    return boost::hash_value( a() );
}

} // boost






namespace std {


inline bool operator<( const person::Info& a, const person::Info& b ) {
    return (a() < b());
}



inline std::ostream& operator<<( std::ostream& out, const person::Info& info ) {
    out << "\"" << info() << "\"";
    return out;
}


} // std
