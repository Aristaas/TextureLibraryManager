#include <filesystem>
#include <vector>
namespace fs = std::filesystem;

class Compare2Vectors
{
public:
	Compare2Vectors (std::vector<fs::path> a, std::vector<fs::path> b, fs::path c);
	void Compare();
private:
	std::vector<fs::path> a_list1;
	std::vector<fs::path> a_list2;
	fs::path a_LibLoc;
};