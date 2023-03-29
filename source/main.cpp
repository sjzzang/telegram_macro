#include <iostream>
#include <string>
#include "telegram_agent.h"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
int main() {
    boost::property_tree::ptree pt;
    try
    {
        boost::property_tree::ini_parser::read_ini("/config.ini",pt);
    }
    catch(boost::property_tree::ini_parser_error& err)
    {
        std::cout<<err.message()<<std::endl;
    }
    std::string apiKey = pt.get<std::string>("TELEGRAM.API_KEY");
    std::string chatId = pt.get<std::string>("TELEGRAM.CHAT_ID");
    cout<<"API_JEY : "+ apiKey + "\n" + "CHAT_ID : " + chatId + "\n";
    telegram_agent tele_agent(apiKey,chatId);

    return 0;
}