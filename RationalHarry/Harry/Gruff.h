#pragma once
#include <string>
#include <gsl/gsl>

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