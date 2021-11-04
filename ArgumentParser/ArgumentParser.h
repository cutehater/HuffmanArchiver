#pragma once

#include <vector>
#include <string_view>

class ArgumentParser {
public:
    ArgumentParser(int argc, char** argv);

    bool IsCommandHelp() const;
    bool IsCommandArchive() const;
    bool IsCommandExtract() const;

    std::string_view GetNextFileName();
    std::string_view GetArchiveName();

private:
    std::vector<std::string_view> arguments_;
    std::vector<std::string_view>::iterator last_archived_file_;
};