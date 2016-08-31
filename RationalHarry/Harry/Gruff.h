#pragma once
#include <string>


enum DBAccessProviderRights
{
	AR_READ,
	AR_INSERT,
	AR_UPDATE,
	AR_DELETE,
	AR_MODIFY_SCHEMA,
};

class DBAccessProvider
{
	virtual bool Connected() = 0;
	virtual bool Disconnect() = 0;
	virtual DBAccessProviderRights GetRights() = 0;
};

class GruffApi
{
	virtual void Insert(const DBAccessProvider&, const  ) = 0;

};