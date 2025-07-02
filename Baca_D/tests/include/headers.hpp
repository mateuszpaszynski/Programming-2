#include <string>

std::string Sum(int count, const std::string* nums);
std::string Sum(int count, ...);
void Sum(std::string* res, int count, const std::string* nums);
void Sum(std::string* res, int count, ...);
void Sum(std::string& res, int count, const std::string* nums);
void Sum(std::string& res, int count, ...);

std::string Mult(int count, const std::string* nums);
std::string Mult(int count, ...);
void Mult(std::string* res, int count, const std::string* nums);
void Mult(std::string* res, int count, ...);
void Mult(std::string& res, int count, const std::string* nums);
void Mult(std::string& res, int count, ...);

std::string Operation(std::string(*op)(int count, const std::string* nums), int count, const std::string* nums);
std::string Operation(std::string(*op)(int count, const std::string* nums), int count, ...);
void Operation(std::string* res, std::string(*op)(int count, const std::string* nums), int count, ...);
void Operation(std::string* res, std::string(*op)(int count, const std::string* nums), int count, const std::string* nums);
void Operation(std::string& res, void(*op)(std::string* res, int count, const std::string* nums), int count, const std::string* nums);
void Operation(std::string& res, void(*op)(std::string* res, int count, const std::string* nums), int count, ...);

