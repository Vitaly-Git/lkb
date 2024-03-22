#include <iostream>
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
            os << "{" <<
                    "\"title\":\"" << dr.title << "\"" << ", " << 
                    "\"content\":\"" << dr.content << "\"" << ", " << 
                    "\"guid\":\"" << boost::lexical_cast<std::string>(dr.guid) << "\"" <<
                    "}";
            return os;
        }
    private:
        std::string title = "";
        std::string content = "";
        boost::uuids::uuid guid;
};