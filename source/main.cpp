#include <iostream>
#include <string>
#include <sstream>
#include "telegram_agent.h"
#include "util.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>

int main() {
    boost::property_tree::ptree read_pt;
    boost::property_tree::ptree write_pt;

    std::string f( "/settings/config.ini" );

    try
    {
        boost::property_tree::ini_parser::read_ini("/settings/config.ini",read_pt);
    }
    catch(boost::property_tree::ini_parser_error& err)
    {
        std::cout<<err.message()<<std::endl;
    }

    std::string apiKey = read_pt.get<std::string>("TELEGRAM.API_KEY");
    std::string chatId = read_pt.get<std::string>("TELEGRAM.CHAT_ID");
    int UPDATE_ID =0;
    try{
        int UPDATE_ID = read_pt.get<int>("TELEGRAM.UPDATE_ID");
    }
    catch(exception e)
    {
        int UPDATE_ID = 0;
    }

    vector<string> vRet;

    if(chatId.find("|")!= string::npos)
    {
        vRet = util::split(chatId, '|');
    }
    else
    {
        vRet.push_back(chatId);
    }
    write_pt.put("TELEGRAM.API_KEY", apiKey);
    write_pt.put("TELEGRAM.CHAT_ID", chatId);
    write_pt.put("TELEGRAM.UPDATE_ID",UPDATE_ID);
    boost::property_tree::write_ini(f, write_pt);

    telegram_agent* tele_agent = new telegram_agent(apiKey, vRet, UPDATE_ID);
    tele_agent->SetCPS(1);
    tele_agent->Start(nullptr);

    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}