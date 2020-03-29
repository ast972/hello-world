#include <iostream>
#include <vector>
#include <string>
#include <sstream>



std::vector<std::string> split(std::string text, char separator)
{
    std::stringstream ss(text);
    std::vector<std::string> text_out;
    std::string item;

    while (std::getline(ss, item, separator))
        {
            text_out.push_back(item);
        }

    return text_out;
}

void split2(std::string text, char separator, std::vector<std::string>& tokens)
{
    tokens.clear();

    if (text.empty())
        return;

    std::size_t start{ 0 }, end{ 0 };
    while ((end = text.find(separator, start)) != std::string::npos)
    {
        // 4
        tokens.push_back(text.substr(start, end - start));
        start = end + 1;
    }
    tokens.push_back(text.substr(start));
}



int main1()
{
    std::string test = "this,is,a,test";
    std::vector<std::string> mysplit;
    char separator = ',';
    mysplit = split(test, separator);
    for (int i=0; i<mysplit.size();i++)
        std::cout << mysplit[i] << std::endl;

    // ver 2
    split2(test, ',', mysplit);
    for (int i = 0; i < mysplit.size(); i++)
        std::cout << mysplit[i] << std::endl;

    return 0;
}

