#include <iostream>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/lexical_cast.hpp>

class DataRecord{
    public:
        DataRecord() = delete;
        DataRecord(std::string drTitle, std::string drContent):title(drTitle), content(drContent){
            guid = boost::uuids::random_generator()();
        };
        std::string getTitle();
        std::string getContent();
        std::string getUuid();
        void setTitle(std::string drTitle);
        void setContent(std::string drContent);
        friend std::ostream& operator<<(std::ostream& os, const DataRecord& dr){
            os << "[ [" << dr.title << "] " << "[" << dr.content << "] " << "[" << boost::lexical_cast<std::string>(dr.guid) << "] ]";
            return os;
        }
    private:
        std::string title = "";
        std::string content = "";
        boost::uuids::uuid guid;
};

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

int main(){

    DataRecord dr("Title 1", "Content 11");
    DataRecord dr2("Title 2", "Content 22");

    std::cout << dr << "\n";
    std::cout << dr2 << "\n";

    std::string_view strw(dr.getTitle());
    std::cout << strw << "\n";

    dr.setTitle("Title 1 new");
    std::cout << dr << "\n";
    std::cout << strw << "\n";

    return 0;
}