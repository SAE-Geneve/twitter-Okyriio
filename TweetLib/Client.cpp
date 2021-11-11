#include "Client.h"

namespace tweet {

	proto::TweetOut Client::Tweet(const proto::TweetIn in)
	{
		grpc::ClientContext client_context;
		proto::TweetOut out;
		auto status = stub_->Tweet(&client_context, in, &out);
		if (!status.ok())
		{
			throw std::runtime_error("tweet error :" + status.error_message());
		}
		return out;
	}

	proto::FollowOut Client::Follow(const proto::FollowIn in)
	{
		grpc::ClientContext client_context;
		proto::FollowOut fout;
		auto status = stub_->Follow(&client_context, in, &fout);
		if (!status.ok())
		{
			throw std::runtime_error("follow error :" + status.error_message());
		}
		return fout;
	}

	proto::ShowOut Client::Show(const proto::ShowIn in)
	{
		grpc::ClientContext client_context;
		proto::ShowOut sout;
		auto status = stub_->Show(&client_context, in, &sout);
		if (!status.ok())
		{
			throw std::runtime_error("Show error :" + status.error_message());
		}
		return sout;
	}

	proto::LoginOut Client::Login(const proto::LoginIn in)
	{
		grpc::ClientContext client_context;
		proto::LoginOut lout;
		auto status = stub_->Login(&client_context, in, &lout);
		if (!status.ok())
		{
			throw std::runtime_error("Login error :" + status.error_message());
		}

		return lout;
	}

	proto::LogoutOut Client::Logout(const proto::LogoutIn in)
	{
		grpc::ClientContext client_context;
		proto::LogoutOut loout;
		auto status = stub_->Logout(&client_context, in, &loout);
		if (!status.ok())
		{
			throw std::runtime_error("logout error :" + status.error_message());
		}
		return loout;
	}

	proto::RegisterOut Client::Register(const proto::RegisterIn in)
	{
		grpc::ClientContext client_context;
		proto::RegisterOut rout;
		auto status = stub_->Register(&client_context, in, &rout);
		if (!status.ok())
		{
			throw std::runtime_error("register error :" + status.error_message());
		}
		return rout;
	}

} // End namespace tweet.