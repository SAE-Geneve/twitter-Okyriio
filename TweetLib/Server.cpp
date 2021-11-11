#include "Server.h"

namespace tweet {

	grpc::Status Server::Tweet(
		grpc::ServerContext* context, 
		const proto::TweetIn* request, 
		proto::TweetOut* response)
	{
		
		if (storage_->Tweet(context->peer(), request->content())) {
			response->set_error(false);
		
		}
		else
			response->set_error(true);
		
		return grpc::Status::OK;
	}

	grpc::Status Server::Follow(
		grpc::ServerContext* context, 
		const proto::FollowIn* request, 
		proto::FollowOut* response)
	{
		if (storage_->Follow(context->peer(), request->name()))
		{
			response->set_error(false);
		}
		else
			response->set_error(true);
		return {};
	}

	grpc::Status Server::Show(
		grpc::ServerContext* context, 
		const proto::ShowIn* request, 
		proto::ShowOut* response)
	{
		auto list = storage_->Show(context->peer(), request->user());
		for (const auto& element : list)
		{
			std::cout << element.text;
			proto::TweetIn tweetin;
			tweetin.set_user(element.name);
			tweetin.set_time(element.time);
			tweetin.set_content(element.text);
			*response->add_tweets() = tweetin;
		}
		
			response->set_error(false);
		
		return grpc::Status::OK;
	}

	grpc::Status Server::Login(
		grpc::ServerContext* context, 
		const proto::LoginIn* request, 
		proto::LoginOut* response)
	{
		if (storage_->Login(context->peer(), request->user(), request->pass()))
		{
			response->set_error(false);
		}
		else
			response->set_error(true);
		return grpc::Status::OK;
	}

	grpc::Status Server::Logout(
		grpc::ServerContext* context, 
		const proto::LogoutIn* request, 
		proto::LogoutOut* response)
	{
		if (storage_->Logout(context->peer()))
		{
			response->set_error(false);
		}
		else
			response->set_error(true);
		return grpc::Status::OK;
	}

	grpc::Status Server::Register(
		grpc::ServerContext* context, 
		const proto::RegisterIn* request, 
		proto::RegisterOut* response)
	{
		
		if (storage_->Register(context->peer(), request->name(), request->pass())) {
			response->set_error(false);
		}
		else
			response->set_error(true);
		return grpc::Status::OK;
	}

} // End namespace tweet.