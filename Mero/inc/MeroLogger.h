#ifndef MERO_LOG_HPP
#define MERO_LOG_HPP

#include <string>
#include <source_location>

/**
 * @brief Main logger source for MERO
 */
class MeroLogger
{
public:
    /**
     * @brief Outputs data to the console ( either through the default *nix setup or AllocConsole() )
     * 
     * @param data String to output, common to use std::format along with
     * @param err Decides wether to output the special error formatting
     * @param cur Current location to use in output
     */
    void LOG(std::string data, bool err = false, std::source_location cur = std::source_location::current());

    // Singleton stuff
    
    MeroLogger(const MeroLogger&) = delete;
    MeroLogger& operator=(const MeroLogger&) = delete;
    
    static MeroLogger& getInstance() {
        static MeroLogger instance;
        return instance;
    }
private:
    MeroLogger();
    ~MeroLogger(); 
};

#endif // MERO_LOG_HPP