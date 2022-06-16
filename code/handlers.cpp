#include "handlers.hpp"


Interface::SignupPageHandler::SignupPageHandler() {};
Response *Interface::SignupPageHandler::callback(Request *req)
{
    Response *res;
    change_error_text("");
    res = Response::redirect("/signup");
    return res;
}

Interface::SignupHandler::SignupHandler(Utaxi *utaxi_) {utaxi = utaxi_;}
Response *Interface::SignupHandler::callback(Request *req)
{
        change_error_text("");
    SignupCredentials new_signup;
    std::string username = req->getBodyParam("username");
    std::string role = req->getBodyParam("role");
    new_signup.username = username;
    new_signup.role = role;
    Response *res;
    try 
    {
        utaxi->signup(new_signup);
        change_error_text("");
        res = Response::redirect("/");
    }
    catch(std::runtime_error &er)
    {
        change_error_text(er.what());
        res = Response::redirect("/signup");
    }

    return res;
}