#include "handlers.hpp"


Interface::SignupPageHandler::SignupPageHandler() {};
Response *Interface::SignupPageHandler::callback(Request *req)
{
    Response *res;
    change_error_text("");
    res = Response::redirect("/signup");
    return res;
}

Interface::SignupHandler::SignupHandler(Utaxi *utaxi_) { utaxi = utaxi_; }
Response *Interface::SignupHandler::callback(Request *req)
{
    change_error_text("");
    SignupCredentials new_signup;
    std::string username = req->getBodyParam("username");
    std::string role = req->getBodyParam("role");
    new_signup.username = (username == "" ? EMPTY_ARG : username);
    new_signup.role = req->getBodyParam("role");
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

Interface::ReqTripPageHandler::ReqTripPageHandler() {};
Response *Interface::ReqTripPageHandler::callback(Request *req)
{
    Response *res;
    change_error_text("");
    res = Response::redirect("/reqtrip");
    return res;
}

Interface::ReqTripHandler::ReqTripHandler(Utaxi *utaxi_) { utaxi = utaxi_;}
Response *Interface::ReqTripHandler::callback(Request *req)
{
    change_error_text("");
    TripRequestTokens new_trip;
    std::string username = req->getBodyParam("username");
    std::string origin = req->getBodyParam("origin");
    std::string destination = req->getBodyParam("destination");
    std::string form_req = req->getBodyParam("submit");
    new_trip.username = (username == "" ? EMPTY_ARG : username);
    new_trip.origin_name = (origin == "" ? EMPTY_ARG : origin);
    new_trip.destination_name = (destination == "" ? EMPTY_ARG : destination);
    new_trip.in_hurry = req->getBodyParam("in_hurry");
    Response *res;
    try 
    {
        if(form_req == "Request")
        {
            utaxi->post_trips(new_trip);
            std::string trip_id = std::to_string(utaxi->get_trips_count());
            change_error_text("Trip ID: " + trip_id);
            res = Response::redirect("/reqtrip");
        }
        else if(form_req == "Calculate Cost")
        {
            std::string cost = std::to_string(utaxi->get_cost(new_trip));
            change_error_text("Trip cost: " + cost);
            res = Response::redirect("/reqtrip");
        }
    }
    catch(std::runtime_error &er)
    {
        change_error_text(er.what());
        res = Response::redirect("/reqtrip");
    }

    return res;
}