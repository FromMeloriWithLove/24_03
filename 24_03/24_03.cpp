#include <iostream> 
#include <list> 
using namespace std;

// отдельный тип, который берёт на себя задачи по работе с датами (и возможно временем)
class Date
{
	int day;
	int month;
	int year;
public:
	Date() {
		day = 0;
		month = 0;
		year = 0;
	}
	Date(int day, int month, int year) {
		this->day = day;
		this->month = month;
		this->year = year;
	}

	void SetDay(int day)
	{
		if (day < 1 || day > 31)
			throw "Incorrect day!";
		else
			this->day = day;
	}
	void SetMonth(int month) {
		if (month < 12 || month > 12)
			throw "Incorrect month!";
		else
			this->month = month;
	}
	void SetYear(int year) {
		if (year > 2023)
			throw "Incorrect year!";
		else
			this->year = year;
	}

	int GetDay() {
		return day;
	}
	int GetMonth() {
		return month;
	}
	int GetYear() {
		return year;
	}

	void Print() {
		cout << "Day: " << day << "\nMonth: " << month << "\nYear: " << year << endl;
	}
};

class Rate
{
	int value; // 1-12
	Date date;
	string subject;
	string prepod;
	int lesson;
public:
	Rate() {
		value = 0;
		subject = "";
		prepod = "";
		lesson = 0;
	}
	void SetValue(int value) {
		if (value < 1 || value > 12)
			throw "Incorrect value!";
		else
			this->value = value;
	}
	void SetSubject(string subject) {
		this->subject = subject;
	}
	void SetPrepod(string prepod) {
		this->prepod = prepod;
	}
	void SetLesson(int lesson) {
		this->lesson = lesson;
	}

	int GetValue() {
		return value;
	}
	string GetSubject() {
		return subject;
	}
	string GetPrepod() {
		return prepod;
	}
	int GetLesson() {
		return lesson;
	}
};

class RateCollection
{
	list<Rate> rates;
public:
	void AddRate(int rate)
	{
		if (rate < 0 || rate > 12) throw "Error rate!";
		rates.push_back(Rate());
		rates.back().SetValue(rate);
	}
	void DeleteLastRate()
	{
		rates.pop_back();
	}
};

class Group {
	string group_name;
	int kurs;
	string speciality;
public:
	Group() {
		group_name = "";
		kurs = 0;
		speciality = "";
	}
	void SetGroupName(string group_name) {
		this->group_name = group_name;
	}
	void SetKurs(int kurs) {
		this->kurs = kurs;
	}
	void SetSpeciality(string speciality) {
		this->speciality = speciality;
	}

	string GetGroupName() {
		return group_name;
	}
	int GetKurs() {
		return kurs;
	}
	string GetSpeciality() {
		return speciality;
	}
};

class Address {
	string country;
	string region;
	string city;
	string street;
	int house_number;
	int flat_number;
public:
	Address() {
		country = "";
		region = "";
		city = "";
		street = "";
		house_number = 0;
		flat_number = 0;
	}

	void SetCountry(string country) {
		this->country = country;
	}
	void SetRegion(string region) {
		this->region = region;
	}
	void SetCity(string city) {
		this->city = city;
	}
	void SetStreet(string street) {
		this->street = street;
	}
	void SetHouseNumber(int house_number) {
		this->house_number = house_number;
	}
	void SetFlatNumber(int flat_number) {
		this->flat_number = flat_number;
	}

	string GetCountry() {
		return country;
	}
	string GetRegion() {
		return region;
	}
	string GetCity() {
		return city;
	}
	string GetStreet() {
		return street;
	}
	int GetHouseNumber() {
		return house_number;
	}
	int GetFlatNumber() {
		return flat_number;
	}
};

class Student
{
	string name;
	string lastname;
	string fathername;
	Date* birthday;

	// int homeworks[100]; // со статическим массивом есть очень много проблем:
	// 1) память расходуется сразу, при том что изначально оценок нет вообще
	// 2) добавить 101-ый элемент в массив нельзя
	// 3) даже если сделать динамический массив, то возникает вопрос: почему тип данных Студент должен брать на себя ответственность за ВЫДЕЛЕНИЕ ПАМЯТИ под массив, ПЕРЕВЫДЕЛЕНЕИЕ, проверку диапазонов баллов от 1 до 12

	RateCollection homeworks; // гораздо лучше предусмотреть отдельный тип данных для работы с коллекцией оценок (там будут методы ДОБАВЛЕНИЯ, РЕДАКТИРОВАНИЯ, УДАЛЕНИЯ, просмотра)
	RateCollection practices; // сама по себе оценка - это тоже отдельный тип данных со своими деталями
	RateCollection kursachies;
	RateCollection exams;

	Date* StartYear;
	Address* address;
	Group group;
	string university = "IT Step";
	string email = "alex@proton.me";
	string phone_numbers[3] = { "+380630300035", "+380501234567" };
	string avatar = "https://fsx1.itstep.org/api/v1/files/8jjPAOyeLzWLM2qC5UQ9coSV2L43lUYz";
};

int main()
{
	Date date(22, 12, 2002);
	date.Print();
}
