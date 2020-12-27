#include "LoadConfig.h"
#include <fstream>
#include <iostream>

CLoadConfig::CLoadConfig()
{

}

CLoadConfig::~CLoadConfig()
{

}

bool CLoadConfig::ParseFile(std::string& sFileName)
{
    using namespace std;
    ifstream ifFile(sFileName);
    if (!ifFile.is_open())
    {
        std::cout << "Can not open file: " << sFileName << std::endl;
        return false;
    }
    while (!ifFile.eof())
    {
        string sLine;
        getline(ifFile, sLine);
        Parse(sLine, m_mKeyValue);
    }
    for (map<string,string>::iterator iter=m_mKeyValue.begin(); iter != m_mKeyValue.end(); iter++) 
    {
        cout << (*iter).first << " " << (*iter).second << endl;
    }
    return true;
}

bool CLoadConfig::GetParam(const std::string& sName, int& iParam) const
{
    std::map<std::string,std::string>::const_iterator iter;
    iter = m_mKeyValue.find(sName);
    if(iter != m_mKeyValue.end())
    {
      iParam = std::stoi(iter->second);
      return true;
    }
    std::cout << "Can't find Parameter: " << sName << std::endl;
    return false;
}

bool CLoadConfig::GetParam(const std::string& sName, double& dParam) const
{
    std::map<std::string,std::string>::const_iterator iter;
    iter = m_mKeyValue.find(sName);
    if(iter != m_mKeyValue.end())
    {
      dParam = std::stod(iter->second);
      return true;
    }
    std::cout << "Can't find Parameter: " << sName << std::endl;
    return false;
}

bool CLoadConfig::GetParam(const std::string& sName, std::string& sParam) const
{
    std::map<std::string,std::string>::const_iterator iter;
    iter = m_mKeyValue.find(sName);
    if(iter != m_mKeyValue.end())
    {
      sParam = iter->second;
      return true;
    }
    std::cout << "Can't find Parameter: " << sName << std::endl;
    return false;
}

std::string& CLoadConfig::Strip(std::string& s, const std::string& chars)
{
  s.erase(s.find_last_not_of(chars.c_str()) + 1);
  return s;
}

void CLoadConfig::Split(const std::string& s, std::vector<std::string>& tokens, const std::string& delimiters)
{
  using namespace std;
  string::size_type lastPos = s.find_first_not_of(delimiters, 0);
  string::size_type pos = s.find_first_of(delimiters, lastPos);
  while (string::npos != pos || string::npos != lastPos) 
  {
      tokens.push_back(s.substr(lastPos, pos - lastPos));
      lastPos = s.find_first_not_of(delimiters, pos);
      pos = s.find_first_of(delimiters, lastPos);
  }
}

void CLoadConfig::Parse(std::string& s, std::map<std::string,std::string>& items)
{
    using namespace std;
    vector<string> kv;
    Split(s, kv, " ");
    if (kv.size() != 2) 
    {
        return;
    }
    items.insert(make_pair(kv[0],Strip(kv[1], ";")));
}
