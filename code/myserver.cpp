#include "myserver.hpp"

MyServer::MyServer(int port) : Server(port) {}

void MyServer::run()
{
    setNotFoundErrPage("static/html_files/404.html");
    get("/signup", new ShowPage("static/html_files/signup.html"));
}