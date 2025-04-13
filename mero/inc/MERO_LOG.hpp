#ifndef MERO_LOG_HPP
#define MERO_LOG_HPP

#include <string>
#include <source_location>

/**
 * Main logger source for MERO
 */
class MERO_LOG
{
public:
    /**
     * Outputs data to the console ( either through the default *nix setup or AllocConsole() )
     * @param data String to output, common to use std::format along with
     * @param err Decides wether to output the special error formatting
     */
    void LOG(std::string data, bool err = false, std::source_location cur = std::source_location::current());

    MERO_LOG(const MERO_LOG&) = delete;
    MERO_LOG& operator=(const MERO_LOG&) = delete;
    
    static MERO_LOG& getInstance() {
        static MERO_LOG instance;
        return instance;
    }
private:
    MERO_LOG();
    ~MERO_LOG(); 
};

#endif // MERO_LOG_HPP