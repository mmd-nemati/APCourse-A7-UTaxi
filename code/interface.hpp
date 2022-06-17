#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#include "myserver.hpp"
#include "utaxi.hpp"

class Interface 
{
    public:
        void run(char *argv[]);

    private:
        Utaxi *utaxi;
        void server_pages(MyServer &server);
        void server_css(MyServer &server);
        void server_js(MyServer &server);
        void server_images(MyServer &server);
        void server_handlers(MyServer &server);

        class SignupPageHandler : public RequestHandler
        {
            public:
                SignupPageHandler();
                Response *callback(Request *req);
        };

        class SignupHandler : public RequestHandler
        {
            public:
                SignupHandler(Utaxi *utaxi_);
                Response *callback(Request *req);
            private:
                Utaxi *utaxi;
        };

        class ReqTripPageHandler : public RequestHandler
        {
            public:
                ReqTripPageHandler();
                Response *callback(Request *req);
        };

        class ReqTripHandler : public RequestHandler
        {
            public:
                ReqTripHandler(Utaxi *utaxi_);
                Response *callback(Request *req);
            private:
                Utaxi *utaxi;
        };

};

#endif /* __INTERFACE_H__ */