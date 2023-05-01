#include <fstream>

class Printable
{
protected:
    std::string data_;
public:
    virtual ~Printable() = default;

    Printable(std::string data) : data_(std::move(data)) {};

    virtual std::string printAs()  {}

    virtual void saveTo(std::ofstream& file) {};
};

class PrintAsHTML : public Printable
{
public:
    virtual std::string printAs() override
    {
        return "<html>" + data_ + "<html/>";
    }
};

class SaveToHTML : public PrintAsHTML
{
public:
    virtual void saveTo(std::ofstream& file) override
    {
        file << printAs();
    }
};

class PrintAsJSON : public Printable
{
public:
    virtual std::string printAs() override
    {
        return "{ \"data\": \"" + data_ + "\"}";
    }
};

class SaveToJSON : public PrintAsJSON
{
public:
    virtual void saveTo(std::ofstream& file) override
    {
        file << printAs();
    }
};

class PrintAsText : public Printable
{
public:
    virtual std::string printAs() override
    {
        return data_;
    }
};

class SaveToText : public PrintAsText
{
public:
    virtual void saveTo(std::ofstream& file) override
    {
        file << printAs();
    }
};