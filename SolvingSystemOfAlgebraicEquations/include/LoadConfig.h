#include <string>
#include <vector>
#include <map>

class CLoadConfig
{
public:
  CLoadConfig();
  virtual ~CLoadConfig();
  bool ParseFile(std::string& sFileName);
  bool GetParam(const std::string& sName, int& iParam) const;
  bool GetParam(const std::string& sName, double& dParam) const;
  bool GetParam(const std::string& sName, std::string& sParam) const;

private:
  std::string& Strip(std::string& s, const std::string& chars = " ");
  void Split(const std::string& s, std::vector<std::string>& tokens, const std::string& delimiters = " ");
  void Parse(std::string& s, std::map<std::string,std::string>& items);
  std::map<std::string,std::string> m_mKeyValue;
};
