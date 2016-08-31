#pragma once
#include <gsl/gsl>
#include <chrono>
#include <vector>


// TODO: split in several classes
// TODO: add OrganizationRecord, PlaceRecord, CategoryRecord and etc. for DB

using date_time = std::chrono::time_point<std::chrono::system_clock>;

enum class AvailabilityStatus
{
	AVAILABLE,
	NEVER_WAS,
	OUT_OF_STOCK,
	UNKNOWN,
	DISCONTINUED
};

struct Organization
{
	std::string name;

	Organization(const std::string &name);
};

struct Place 
{
	gsl::not_null<Organization> organization;
	std::string address;

	Place(const std::string &name);
};

class Category
{
	Category* parent;
	std::vector<gsl::owner<Category*>> children_;
	std::string name;


	Category(const std::string &name);
};

struct Thing
{
	std::string name;
	gsl::not_null<Category*> category;

	Thing(const std::string &name, gsl::not_null<Category*> category);
};

struct Item
{
	gsl::not_null<Thing*> thing;
	gsl::not_null<Place*> place;
	AvailabilityStatus status;

	Item(gsl::not_null<Thing*> thing, gsl::not_null<Place*> place, AvailabilityStatus status = AvailabilityStatus::UNKNOWN);
};

struct ItemValue
{
	gsl::not_null<Item*> item;
	date_time date;
	double value;

	ItemValue(gsl::not_null<Item*> item, const date_time &date, double value);
};

struct Purchase
{
	std::vector<gsl::not_null<ItemValue*>> items;
	date_time date;

	Purchase(const std::vector<gsl::not_null<ItemValue*>> &items, const date_time &date);
};