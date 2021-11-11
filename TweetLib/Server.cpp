#include "Server.h"

namespace tweet {

    grpc::Status Server::Tweet(
        grpc::ServerContext* context, 
        const proto::TweetIn* request, 
        proto::TweetOut* response)
    {
        std::string context_string = request->user();
        if (storage_->Tweet( context_string, request->content())) {
            response->set_error(false);
        }
        else response->set_error(true);
        return grpc::Status::OK;
    }

    grpc::Status Server::Follow(
        grpc::ServerContext* context, 
        const proto::FollowIn* request, 
        proto::FollowOut* response)
    {
        std::string context_string = request->name();
        if (storage_->Follow(context_string, request->name())) {
            response->set_error(false);
        }
        else {
            response->set_error(true);
        }
        return grpc::Status::OK;
    }

    grpc::Status Server::Show(
        grpc::ServerContext* context, 
        const proto::ShowIn* request, 
        proto::ShowOut* response)
    {
        std::string context_string = request->user();
        if (storage_->Show(context_string, request->user()).data()) {
            response->set_error(false);
        }
        else {
            response->set_error(true);
        }
        return grpc::Status::OK;
    }

    grpc::Status Server::Login(
        grpc::ServerContext* context, 
        const proto::LoginIn* request, 
        proto::LoginOut* response)
    {
        std::string context_string = request->user();
        if (storage_->Login(context_string, request->user(), request->pass())) {
            response->set_error(false);
        }
        else {
            response->set_error(true);
        }
        return grpc::Status::OK;
    }

    grpc::Status Server::Logout(
        grpc::ServerContext* context, 
        const proto::LogoutIn* request, 
        proto::LogoutOut* response)
    {
        std::string context_string = request->user();
        if (storage_->Logout(request->user())) {
            response->set_error(false);
        }
        else {
            response->set_error(true);
        }
        return grpc::Status::OK;
    }

    grpc::Status Server::Register(
        grpc::ServerContext* context, 
        const proto::RegisterIn* request, 
        proto::RegisterOut* response)
    {
        std::string context_string = request->name();
        if (storage_->Register(context_string, request->name(), request->pass())){
            response->set_error(false);
        }
        else{
            response->set_error(true);
        }
        return grpc::Status::OK;
    }

} // End namespace tweet.