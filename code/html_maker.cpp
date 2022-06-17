#include "html_maker.hpp"

std::string req_trip_html(const std::vector<Location*> &locations)
{
    std::string line;
    std::ifstream infile;
    infile.open("static/html_files/reqtrip.html");
    std::string body;
    while(std::getline(infile, line) && line != "<option value=\"\" class=\"loc\">choose origin</option>")
        body += line;

    body += line;
    for(int i = 0; i < locations.size(); i++)
        body += ("<option value=\"" + locations[i]->get_name() + "\" class=\"loc\">" + locations[i]->get_name() + "</option>");
    
    while(std::getline(infile, line) && line != "<option value=\"\" class=\"loc\">choose destination</option>")
        body += line;

    body += line;
    for(int i = 0; i < locations.size(); i++)
        body += ("<option value=\"" + locations[i]->get_name() + "\" class=\"loc\">" + locations[i]->get_name() + "</option>");
    
    while(std::getline(infile, line))
        body += line;
        
    infile.close();
    return body;
}