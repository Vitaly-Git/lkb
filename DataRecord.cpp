#include <iostream>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/lexical_cast.hpp>
#include "DataRecord.hpp"

std::string DataRecord::getTitle(){
    return title;
}

std::string DataRecord::getContent(){
    return content;
}

std::string DataRecord::getUuid(){
    return boost::lexical_cast<std::string>(guid);
}

void DataRecord::setTitle(std::string drTitle){
    title = drTitle;
}

void DataRecord::setContent(std::string drContent){
    content = drContent;
}

