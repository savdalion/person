#pragma once

#include "Concept.h"
#include "Like.h"
#include <map>
#include <memory>
#include <ostream>


namespace person {

class LikeMemory;
typedef std::shared_ptr< LikeMemory >  LikeMemoryPtr;
typedef std::unique_ptr< LikeMemory >  LikeMemoryUPtr;

}



namespace person {


/**
* Память, хранящая информацию об *отношении* к понятиям (нравится / нет).
*/
class LikeMemory {
public:
    /**
    * Понятие и *личное* мнение к этому понятию.
    */
    typedef std::pair< Concept, Like >  conceptLike_t;

    /**
    * Топология памяти LikeMemory.
    */
    typedef std::map< conceptLike_t::first_type, conceptLike_t::second_type >  topology_t;



public:
    inline LikeMemory() {
    }


    virtual inline ~LikeMemory() {
    }




    inline LikeMemory& operator<<( const conceptLike_t& cl ) {
        ( *this ) = cl;
        return *this;
    }



    inline LikeMemory& operator=( const conceptLike_t& cl ) {
        mTopology[ cl.first ] = cl.second;
        return *this;
    }



    /**
    * @return Количество элементов в этой памяти.
    */
    inline size_t count() const {
        return mTopology.size();
    }



    inline topology_t const& topology() const {
        return mTopology;
    }





private:
    topology_t mTopology;
};




} // person








namespace std {


inline std::ostream& operator<<( std::ostream& out, const person::LikeMemory& lm ) {
    out << "{ \"count\": " << lm.count() << ", \"topology\": ";
    typelib::printPair( out, lm.topology() );
    out << " }";
    return out;
}


} // std
