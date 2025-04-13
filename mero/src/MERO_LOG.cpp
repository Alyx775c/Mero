#include "MERO_LOG.hpp"

#include "MERO.hpp"

std::string GET_NAME(const char *file_name)
{
    std::filesystem::path path = file_name;

    return path.filename().string();
}

void MERO_LOG::LOG(std::string data, bool err, std::source_location cur)
{
    if (err)
    {
        std::string out = std::format("[E] [{} : {}] ", GET_NAME(cur.file_name()), cur.line());
        std::cout << out << data << std::endl;
        return;
    }
#ifdef _DEBUG
    std::string out = std::format("[+] [{} : {}] ", GET_NAME(cur.file_name()), cur.line());
    std::cout << out << data << std::endl;
#endif // _DEBUG
}

MERO_LOG::MERO_LOG()
{
    /**
     * TODO: Implement AllocConsole() on Windows
     */
}

MERO_LOG::~MERO_LOG() {
    
}