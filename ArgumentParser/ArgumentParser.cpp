#include "ArgumentParser.h"

ArgumentParser::ArgumentParser(int argc, char **argv) {
    for (size_t i = 0; i < static_cast<size_t>(argc); ++i) {
        arguments_.emplace_back(argv[i]);
    }
    if (IsCommandArchive()) {
        last_archived_file_ = arguments_.begin() + 2;
    } else {
        last_archived_file_ = arguments_.end() - 1;
    }
}

bool ArgumentParser::IsCommandHelp() const {
    return (arguments_.size() == 2 && arguments_[1] == "-h");
}

bool ArgumentParser::IsCommandExtract() const {
    return (arguments_.size() == 3 && arguments_[1] == "-d");
}

bool ArgumentParser::IsCommandArchive() const {
    return (arguments_.size() > 3 && arguments_[1] == "-c");
}

std::string_view ArgumentParser::GetNextFileName() {
    if (last_archived_file_ != arguments_.end() - 1) {
        return *(++last_archived_file_);
    } else {
        return "";
    }
}

std::string_view ArgumentParser::GetArchiveName() {
    return arguments_[2];
}
